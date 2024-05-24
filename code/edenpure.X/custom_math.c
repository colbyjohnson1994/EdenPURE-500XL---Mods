#include "custom_math.h"

// Function to compute natural log using Taylor series expansion
float my_log(float x) {
    if (x <= 0) {
        return 0.0f; // Return NaN for non-positive numbers
    }
    
    // Adjust the value of x to be within the convergence range of the Taylor series
    float result = 0.0f;
    while (x > 1.5f) {
        x /= E;
        result += 1.0f;
    }
    
    x -= 1.0f; // Use ln(1 + x)
    
    // Compute Taylor series
    float term = x;
    float sum = 0.0f;
    int n = 1;
    
    while (term > 1e-7f || term < -1e-7f) { // Tolerance for convergence
        sum += term;
        n++;
        term *= -x * (n - 1) / n;
    }
    
    return result + sum;
}
