/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC16F1827
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.36 and above
        MPLAB 	          :  MPLAB X 6.00	
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

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set BUZZ aliases
#define BUZZ_TRIS                 TRISAbits.TRISA1
#define BUZZ_LAT                  LATAbits.LATA1
#define BUZZ_PORT                 PORTAbits.RA1
#define BUZZ_ANS                  ANSELAbits.ANSA1
#define BUZZ_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define BUZZ_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define BUZZ_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define BUZZ_GetValue()           PORTAbits.RA1
#define BUZZ_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define BUZZ_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define BUZZ_SetAnalogMode()      do { ANSELAbits.ANSA1 = 1; } while(0)
#define BUZZ_SetDigitalMode()     do { ANSELAbits.ANSA1 = 0; } while(0)

// get/set HEAT_RL aliases
#define HEAT_RL_TRIS                 TRISAbits.TRISA2
#define HEAT_RL_LAT                  LATAbits.LATA2
#define HEAT_RL_PORT                 PORTAbits.RA2
#define HEAT_RL_ANS                  ANSELAbits.ANSA2
#define HEAT_RL_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define HEAT_RL_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define HEAT_RL_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define HEAT_RL_GetValue()           PORTAbits.RA2
#define HEAT_RL_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define HEAT_RL_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define HEAT_RL_SetAnalogMode()      do { ANSELAbits.ANSA2 = 1; } while(0)
#define HEAT_RL_SetDigitalMode()     do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set LED4_5P aliases
#define LED4_5P_TRIS                 TRISAbits.TRISA3
#define LED4_5P_LAT                  LATAbits.LATA3
#define LED4_5P_PORT                 PORTAbits.RA3
#define LED4_5P_ANS                  ANSELAbits.ANSA3
#define LED4_5P_SetHigh()            do { LATAbits.LATA3 = 1; } while(0)
#define LED4_5P_SetLow()             do { LATAbits.LATA3 = 0; } while(0)
#define LED4_5P_Toggle()             do { LATAbits.LATA3 = ~LATAbits.LATA3; } while(0)
#define LED4_5P_GetValue()           PORTAbits.RA3
#define LED4_5P_SetDigitalInput()    do { TRISAbits.TRISA3 = 1; } while(0)
#define LED4_5P_SetDigitalOutput()   do { TRISAbits.TRISA3 = 0; } while(0)
#define LED4_5P_SetAnalogMode()      do { ANSELAbits.ANSA3 = 1; } while(0)
#define LED4_5P_SetDigitalMode()     do { ANSELAbits.ANSA3 = 0; } while(0)

// get/set LED2_5N aliases
#define LED2_5N_TRIS                 TRISAbits.TRISA4
#define LED2_5N_LAT                  LATAbits.LATA4
#define LED2_5N_PORT                 PORTAbits.RA4
#define LED2_5N_ANS                  ANSELAbits.ANSA4
#define LED2_5N_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define LED2_5N_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define LED2_5N_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define LED2_5N_GetValue()           PORTAbits.RA4
#define LED2_5N_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define LED2_5N_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define LED2_5N_SetAnalogMode()      do { ANSELAbits.ANSA4 = 1; } while(0)
#define LED2_5N_SetDigitalMode()     do { ANSELAbits.ANSA4 = 0; } while(0)

// get/set LED3_4N aliases
#define LED3_4N_TRIS                 TRISBbits.TRISB0
#define LED3_4N_LAT                  LATBbits.LATB0
#define LED3_4N_PORT                 PORTBbits.RB0
#define LED3_4N_WPU                  WPUBbits.WPUB0
#define LED3_4N_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define LED3_4N_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define LED3_4N_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define LED3_4N_GetValue()           PORTBbits.RB0
#define LED3_4N_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define LED3_4N_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define LED3_4N_SetPullup()          do { WPUBbits.WPUB0 = 1; } while(0)
#define LED3_4N_ResetPullup()        do { WPUBbits.WPUB0 = 0; } while(0)

// get/set LED2_3P aliases
#define LED2_3P_TRIS                 TRISBbits.TRISB1
#define LED2_3P_LAT                  LATBbits.LATB1
#define LED2_3P_PORT                 PORTBbits.RB1
#define LED2_3P_WPU                  WPUBbits.WPUB1
#define LED2_3P_ANS                  ANSELBbits.ANSB1
#define LED2_3P_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define LED2_3P_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define LED2_3P_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define LED2_3P_GetValue()           PORTBbits.RB1
#define LED2_3P_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define LED2_3P_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define LED2_3P_SetPullup()          do { WPUBbits.WPUB1 = 1; } while(0)
#define LED2_3P_ResetPullup()        do { WPUBbits.WPUB1 = 0; } while(0)
#define LED2_3P_SetAnalogMode()      do { ANSELBbits.ANSB1 = 1; } while(0)
#define LED2_3P_SetDigitalMode()     do { ANSELBbits.ANSB1 = 0; } while(0)

// get/set LED1_N aliases
#define LED1_N_TRIS                 TRISBbits.TRISB2
#define LED1_N_LAT                  LATBbits.LATB2
#define LED1_N_PORT                 PORTBbits.RB2
#define LED1_N_WPU                  WPUBbits.WPUB2
#define LED1_N_ANS                  ANSELBbits.ANSB2
#define LED1_N_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define LED1_N_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define LED1_N_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define LED1_N_GetValue()           PORTBbits.RB2
#define LED1_N_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define LED1_N_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define LED1_N_SetPullup()          do { WPUBbits.WPUB2 = 1; } while(0)
#define LED1_N_ResetPullup()        do { WPUBbits.WPUB2 = 0; } while(0)
#define LED1_N_SetAnalogMode()      do { ANSELBbits.ANSB2 = 1; } while(0)
#define LED1_N_SetDigitalMode()     do { ANSELBbits.ANSB2 = 0; } while(0)

// get/set NTC_N aliases
#define NTC_N_TRIS                 TRISBbits.TRISB3
#define NTC_N_LAT                  LATBbits.LATB3
#define NTC_N_PORT                 PORTBbits.RB3
#define NTC_N_WPU                  WPUBbits.WPUB3
#define NTC_N_ANS                  ANSELBbits.ANSB3
#define NTC_N_SetHigh()            do { LATBbits.LATB3 = 1; } while(0)
#define NTC_N_SetLow()             do { LATBbits.LATB3 = 0; } while(0)
#define NTC_N_Toggle()             do { LATBbits.LATB3 = ~LATBbits.LATB3; } while(0)
#define NTC_N_GetValue()           PORTBbits.RB3
#define NTC_N_SetDigitalInput()    do { TRISBbits.TRISB3 = 1; } while(0)
#define NTC_N_SetDigitalOutput()   do { TRISBbits.TRISB3 = 0; } while(0)
#define NTC_N_SetPullup()          do { WPUBbits.WPUB3 = 1; } while(0)
#define NTC_N_ResetPullup()        do { WPUBbits.WPUB3 = 0; } while(0)
#define NTC_N_SetAnalogMode()      do { ANSELBbits.ANSB3 = 1; } while(0)
#define NTC_N_SetDigitalMode()     do { ANSELBbits.ANSB3 = 0; } while(0)

// get/set RB5 procedures
#define RB5_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define RB5_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define RB5_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define RB5_GetValue()              PORTBbits.RB5
#define RB5_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define RB5_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define RB5_SetPullup()             do { WPUBbits.WPUB5 = 1; } while(0)
#define RB5_ResetPullup()           do { WPUBbits.WPUB5 = 0; } while(0)
#define RB5_SetAnalogMode()         do { ANSELBbits.ANSB5 = 1; } while(0)
#define RB5_SetDigitalMode()        do { ANSELBbits.ANSB5 = 0; } while(0)

// get/set NTC_P aliases
#define NTC_P_TRIS                 TRISBbits.TRISB6
#define NTC_P_LAT                  LATBbits.LATB6
#define NTC_P_PORT                 PORTBbits.RB6
#define NTC_P_WPU                  WPUBbits.WPUB6
#define NTC_P_ANS                  ANSELBbits.ANSB6
#define NTC_P_SetHigh()            do { LATBbits.LATB6 = 1; } while(0)
#define NTC_P_SetLow()             do { LATBbits.LATB6 = 0; } while(0)
#define NTC_P_Toggle()             do { LATBbits.LATB6 = ~LATBbits.LATB6; } while(0)
#define NTC_P_GetValue()           PORTBbits.RB6
#define NTC_P_SetDigitalInput()    do { TRISBbits.TRISB6 = 1; } while(0)
#define NTC_P_SetDigitalOutput()   do { TRISBbits.TRISB6 = 0; } while(0)
#define NTC_P_SetPullup()          do { WPUBbits.WPUB6 = 1; } while(0)
#define NTC_P_ResetPullup()        do { WPUBbits.WPUB6 = 0; } while(0)
#define NTC_P_SetAnalogMode()      do { ANSELBbits.ANSB6 = 1; } while(0)
#define NTC_P_SetDigitalMode()     do { ANSELBbits.ANSB6 = 0; } while(0)

// get/set NTC aliases
#define NTC_TRIS                 TRISBbits.TRISB7
#define NTC_LAT                  LATBbits.LATB7
#define NTC_PORT                 PORTBbits.RB7
#define NTC_WPU                  WPUBbits.WPUB7
#define NTC_ANS                  ANSELBbits.ANSB7
#define NTC_SetHigh()            do { LATBbits.LATB7 = 1; } while(0)
#define NTC_SetLow()             do { LATBbits.LATB7 = 0; } while(0)
#define NTC_Toggle()             do { LATBbits.LATB7 = ~LATBbits.LATB7; } while(0)
#define NTC_GetValue()           PORTBbits.RB7
#define NTC_SetDigitalInput()    do { TRISBbits.TRISB7 = 1; } while(0)
#define NTC_SetDigitalOutput()   do { TRISBbits.TRISB7 = 0; } while(0)
#define NTC_SetPullup()          do { WPUBbits.WPUB7 = 1; } while(0)
#define NTC_ResetPullup()        do { WPUBbits.WPUB7 = 0; } while(0)
#define NTC_SetAnalogMode()      do { ANSELBbits.ANSB7 = 1; } while(0)
#define NTC_SetDigitalMode()     do { ANSELBbits.ANSB7 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/