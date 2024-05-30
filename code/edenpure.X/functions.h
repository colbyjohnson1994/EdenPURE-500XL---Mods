/* 
 * File:   functions.h
 * Author: colby
 *
 * Created on May 3, 2024, 9:29 PM
 */

#ifndef FUNCTIONS_H
#define	FUNCTIONS_H

#ifdef	__cplusplus
extern "C" {
#endif

    void _UIControlISR();
    void _LogicControlISR();
    void _SpkrControlISR();
    
    void _ReadSensor();
    void _ControlHeat();
    void _SendDataToConsole();


#ifdef	__cplusplus
}
#endif

#endif	/* FUNCTIONS_H */

