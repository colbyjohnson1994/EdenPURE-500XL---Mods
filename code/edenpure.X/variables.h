/* 
 * File:   variables.h
 * Author: colby
 *
 * Created on May 3, 2024, 9:29 PM
 */

#ifndef VARIABLES_H
#define	VARIABLES_H

#ifdef	__cplusplus
extern "C" {
#endif

    enum
    {
        DISP_STATE_1 = 0,
        DISP_STATE_2 = 1,
        DISP_STATE_3 = 2
    };
    
    enum
    {
        HEAT_MODE_0 = 0,    // off mode
        HEAT_MODE_1 = 1,
        HEAT_MODE_2 = 2,
        HEAT_MODE_3 = 3,
        HEAT_MODE_4 = 4,
        HEAT_MODE_5 = 5,
    };
    
    // current mode is read from eeprom on startup to resume
    // last state heater was in before shut down
    int CURRENT_MODE = HEAT_MODE_0;
    int DISP_STATE = DISP_STATE_1;
    bool RELAY_STATUS = false;
    
    bool _LastUpState = false; // default to last state was clicked
    bool _LastDownState = false; // default to last state was clicked
    bool _SaveMemory = false;
    
    // all setpoints are in degrees F
    const int SETPOINTS[6] = {0, 65, 68, 71, 74, 77};
    
    // in degrees F, temperature above setpoint the heat will shut off
    const int SHUT_OFF = 2;
    
    // in degrees F, temperature below setpoint the heat will turn back on
    const int TURN_ON = 1;
    
    // global averaged temperature
    int TEMP = 0;
    
    // reading iterator is used to keep track of our position in the readings array
    int READING_ITER = 0;
    // full sample is set to true after we read a full average_size number of readings
    // ensure heat isn't called on startup until we are sure we need to
    bool FULL_SAMPLE = false;
    
    // in minutes minimum amount of time we should run, this is a measure
    // to prevent rapid cycling heater elements, which can lead to short 
    // service life
    const int MIN_RUN_TIME = 1;
    
    // in minutes, minimum amount of time in between heat calls. This helps
    // ensure heating elements have cooled back down to room temperature
    const int MIN_IDLE_TIME = 1;
    
    // tick count (in seconds) that indicates how long we have been idle or running
    // this is capped at the min run or min idle time to prevent overrun
    uint16_t HEAT_CALL_TICKS = MIN_IDLE_TIME * 60;
    
    
    // number of logic control isr ticks that equal 1 second
    const int ONE_SECOND = 10;
    
    // tick count that keep track of how many times logic control ISR has ticked
    // this is reset once 1 second is hit
    uint8_t LOGIC_TICK = 0;
    
    uint8_t SPKR_DURATION = 2; // in 100ms increments
    uint8_t SPKR_COUNT = 100; // counts how long the speaker has been active
    uint8_t SPKR_DC = 0;    //speaker duty cycle for changing frequency on button type
    bool DN_CLICKED = false;
    
#define DEBUG       1   // determines what type of data is shown on console
                        // 0 - nothing
                        // 1 - temp, mode and relay status
                        // 2 - heat control states
                        // 3 - button read adc
                        // 4 - eeprom debug
#define READ_PERIOD 3   // number of 100ms ticks often we read from the sensor
#define UART_PERIOD 5   // number of 100ms ticks often we send data out on console
    
#define EEPROM_VAL_OFFSET  25  //randomly picked value to make sure value read back on blank memory
                        // doesn't cause issue.
#define EEPROM_ADDRESS      10
#define TEMP_OFFSET         -3  // temperature offset to calibrate the NTC
    
    bool READ_FLAG = false;     // read/average from sensor flag
    bool UART_FLAG = false;     // send uart data flag
    bool LOGIC_FLAG = false;    // control heating logic flag
    
    // Steinhart-Hart coefficients for a 5k NTC thermistor
    const float A = 1.281740088e-03;
    const float B = 2.366791957e-04;
    const float C = 0.9133782384e-07;

#ifdef	__cplusplus
}
#endif

#endif	/* VARIABLES_H */

