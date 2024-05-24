/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC16F1847
        Driver Version    :  2.00
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#include "mcc_generated_files/mcc.h"
#include "functions.h"
#include "variables.h"
#include "custom_math.h"

/*
                         Main application
 */
void main(void)
{
    // initialize the device
    SYSTEM_Initialize();

    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();

    TMR0_SetInterruptHandler(_UIControlISR);
    TMR1_SetInterruptHandler(_LogicControlISR);
    
    while (1)
    {
        bool savedRelay;
        
        // monitor flags set by the ISR's
        if (READ_FLAG)
        {
            READ_FLAG = false;
            _ReadSensor();
        }
        
        if (UART_FLAG)
        {
            UART_FLAG = false;
            if (DEBUG)
                _SendDataToConsole();
        }
        
        if (LOGIC_FLAG)
        {
            LOGIC_FLAG = false;
            
            savedRelay = RELAY_STATUS;
            
            // keep track of time unit has been off or on
            HEAT_CALL_TICKS++;
            if (RELAY_STATUS)
            {
                // cap heat call ticks at min run time
                if (HEAT_CALL_TICKS > (MIN_RUN_TIME * 60))
                    HEAT_CALL_TICKS = MIN_RUN_TIME * 60;
            }
            else
            {
                // cap heat call ticks at min idle time
                if (HEAT_CALL_TICKS > (MIN_IDLE_TIME * 60))
                    HEAT_CALL_TICKS = MIN_IDLE_TIME * 60;
            }
            
            // control the heating logic
            _ControlHeat();
            
            if (savedRelay != RELAY_STATUS)
            {
                // reset timer
                HEAT_CALL_TICKS = 0;
            }
            
            if (RELAY_STATUS)
                HEAT_RL_SetHigh();
            else
                HEAT_RL_SetLow();
        }
    }
}

// this function handles the 3 states that we need to display LED status and handle
// button clicks from the UI. 
void _UIControlISR()
{
    bool btnUpRead, btnDnRead;
    
    // this ISR is called once every 10ms
    switch(DISP_STATE)
    {         
        case DISP_STATE_1:
            // read buttons in this state
            btnUpRead = LED2_5N_GetValue();
            btnDnRead = LED3_4N_GetValue();
            
            if (!btnUpRead)
            {
                // button clicked right now
                if (_LastUpState)
                {
                    // last time we measured it wasn't clicked
                    // trigger a btn click
                    if (CURRENT_MODE > HEAT_MODE_0)
                        CURRENT_MODE--;
                    
                    // trigger buzzer
                    
                }
                else
                {
                    // do nothing we haven't released the button yet
                }
            }
            
            // set last state
            _LastUpState = btnUpRead;
            
            if (!btnDnRead)
            {
                // button clicked right now
                if (_LastDownState)
                {
                    // last time we measured it wasn't clicked
                    // trigger a btn click
                    if (CURRENT_MODE < HEAT_MODE_5)
                        CURRENT_MODE++;
                    
                    // trigger buzzer
                    
                }
                else
                {
                    // do nothing we haven't released the button yet
                }
            }
            
            // set last state
            _LastDownState = btnDnRead;
            
            // setup state for DISP_STATE_2
            DISP_STATE = DISP_STATE_2;
            
            LED2_3P_SetHigh();
            LED4_5P_SetLow();
            
            // set led 2 and 3 states based on heat mode
            if (CURRENT_MODE > HEAT_MODE_1)
            {
                LED2_5N_SetLow();
                
                if (CURRENT_MODE > HEAT_MODE_2)
                    LED3_4N_SetLow();
                else
                    LED3_4N_SetHigh();
            }
            else
            {
                LED2_5N_SetHigh();
                LED3_4N_SetHigh();
            }
            
            // only want led on for one state
            LED1_N_SetHigh();
            
            break;
        case DISP_STATE_2:
            // setup state for DISP_STATE_3
            DISP_STATE = DISP_STATE_3;
            
            LED2_3P_SetLow();
            LED4_5P_SetHigh();
            
            // set led 4 and 5 states based on heat mode
            if (CURRENT_MODE > HEAT_MODE_3)
            {
                LED3_4N_SetLow();
                
                if (CURRENT_MODE > HEAT_MODE_4)
                    LED2_5N_SetLow();
                else
                    LED2_5N_SetHigh();
            }
            else
            {
                LED2_5N_SetHigh();
                LED3_4N_SetHigh();
            }
            
            break;
        case DISP_STATE_3:
            // setup state for DISP_STATE_1
            DISP_STATE = DISP_STATE_1;
            
            LED2_5N_SetDigitalInput();
            LED3_4N_SetDigitalInput();
            
            if (CURRENT_MODE > HEAT_MODE_0)
                LED1_N_SetLow();
            else
                LED1_N_SetHigh();
            break;
            
        default:
            // incase we end up here, reset to default state
            DISP_STATE = DISP_STATE_1;
    }
}

// this function handles setting flags that are monitored in the main while loop
// flags are set when we need to read and control the heating logic
// when debug is enabled, data is sent out over the console port periodically
void _LogicControlISR()
{
    // this ISR is called once every 100ms
    LOGIC_TICK++;
    
    if (LOGIC_TICK >= READ_PERIOD)
        READ_FLAG = true;
    
    if (LOGIC_TICK >= UART_PERIOD)
        UART_FLAG = true;
    
    if (LOGIC_TICK >= ONE_SECOND)
    {
        LOGIC_FLAG = true;
        LOGIC_TICK = 0; // reset counter
    }
}

void _ReadSensor()
{
    // Read the ADC value
    uint16_t adcValue = ADC_GetConversion(NTC);
    float Vout = adcValue * (5.0f / 1023.0f); // Convert ADC value to voltage
    
    // Calculate the thermistor resistance
    float Rpullup = 10000.0;
    float Vcc = 5.0;
    float Rntc = Rpullup * (Vcc / Vout - 1.0f);

    // Calculate approximate logarithm of the resistance
    float logR = my_log(Rntc);

    // Calculate temperature using the Steinhart-Hart equation with the approximate log
    float invT = A + B * logR + C * logR * logR * logR;
    float T = 1.0f / invT; // Temperature in Kelvin
    float Tc = T - 273.15f; // Convert Kelvin to Celsius
    float Tf = (1.8f * Tc) + 32.0f;
    
    TEMP = (int)Tf;
}
void _ControlHeat()
{
    if (CURRENT_MODE == HEAT_MODE_0)
    {
        RELAY_STATUS = false;
        return;
    }
    
    // if we are above our setpoint + shut off and our heater has run
    // long enough, shut down
    if (TEMP > (SETPOINTS[CURRENT_MODE] + SHUT_OFF))
    {
        if (HEAT_CALL_TICKS > (MIN_RUN_TIME * 60))
        {
            RELAY_STATUS = false;
            return;
        }
        
        // do nothing we cant shut down yet
    }
    
    if (TEMP < (SETPOINTS[CURRENT_MODE] - TURN_ON))
    {
        // we are below our setpoint
        // check if we have been off long enough
        if (HEAT_CALL_TICKS > (MIN_IDLE_TIME * 60))
        {
            RELAY_STATUS = true;
            return;
        }
        
        // do nothing we can't turn on yet
    }
}
    
void _SendDataToConsole()
{
    // sprintf is too expensive
    // take all of our variables and display them to console for debugging
    int huns, tens, ones;
    
    huns = TEMP / 100;
    tens = (TEMP - huns * 100) / 10;
    ones = (TEMP - huns * 100 - tens * 10);
    
    // current temp
    EUSART_Write('T');
    EUSART_Write(':');
    EUSART_Write(huns + 48);
    EUSART_Write(tens + 48);
    EUSART_Write(ones + 48);
    EUSART_Write('\t');
    EUSART_Write('M');
    EUSART_Write(':');
    EUSART_Write(CURRENT_MODE + 48);
    EUSART_Write('\t');
    EUSART_Write('H');
    EUSART_Write(':');
    EUSART_Write(RELAY_STATUS + 48);
    EUSART_Write('\r');
    EUSART_Write('\n');
}
/**
 End of File
*/