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
        HEAT_MODE_3 = 2,
        HEAT_MODE_4 = 2,
        HEAT_MODE_5 = 2,
    };
    
    // current mode is read from eeprom on startup to resume
    // last state heater was in before shut down
    int CURRENT_MODE = HEAT_MODE_0;
    int DISP_STATE = DISP_STATE_1;
    
    // all setpoints are in degrees F
    const float SETPOINTS[5] = {65.0, 68.0, 71.0, 74.0, 77.0};
    
    // in degrees F, temperature above setpoint the heat will shut off
    const float SHUT_OFF = 2.0;
    
    // in degrees F, temperature below setpoint the heat will turn back on
    const float TURN_ON = 2.0;
    
    // global averaged temperature
    float TEMP;
    
    // number of samples that our average is sampled from
    const int AVERAGE_SIZE = 10;
    float TEMP_READINGS[AVERAGE_SIZE];
    
    // reading iterator is used to keep track of our position in the readings array
    int READING_ITER = 0;
    // full sample is set to true after we read a full average_size number of readings
    // ensure heat isn't called on startup until we are sure we need to
    bool FULL_SAMPLE = false;
    
    // in minutes minimum amount of time we should run, this is a measure
    // to prevent rapid cycling heater elements, which can lead to short 
    // service life
    const int MIN_RUN_TIME = 3;
    
    // in minutes, minimum amount of time in between heat calls. This helps
    // ensure heating elements have cooled back down to room temperature
    const int MIN_IDLE_TIME = 3;
    
    // tick count (in seconds) that indicates how long we have been idle or running
    // this is capped at the min run or min idle time to prevent overrun
    uint16_t HEAT_CALL_TICKS;
    
    
    // number of logic control isr ticks that equal 1 second
    const int ONE_SECOND = 10;
    
    // tick count that keep track of how many times logic control ISR has ticked
    // this is reset once 1 second is hit
    uint8_t LOGIC_TICK = 0;

#ifdef	__cplusplus
}
#endif

#endif	/* VARIABLES_H */

