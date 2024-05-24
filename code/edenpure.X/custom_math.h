/* 
 * File:   custom_math.h
 * Author: colby
 *
 * Created on May 21, 2024, 9:32 PM
 */

#ifndef CUSTOM_MATH_H
#define	CUSTOM_MATH_H

#ifdef	__cplusplus
extern "C" {
#endif

// Approximation of Euler's number
#define E 2.718281828459045f

// Custom function to compute natural log using Taylor series expansion
float my_log(float x);

    
#ifdef	__cplusplus
}
#endif

#endif	/* CUSTOM_MATH_H */

