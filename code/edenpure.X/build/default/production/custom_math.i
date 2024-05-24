# 1 "custom_math.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "C:/Program Files/Microchip/MPLABX/v6.05/packs/Microchip/PIC12-16F1xxx_DFP/1.3.90/xc8\\pic\\include\\language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "custom_math.c" 2
# 1 "./custom_math.h" 1
# 19 "./custom_math.h"
float my_log(float x);
# 1 "custom_math.c" 2



float my_log(float x) {
    if (x <= 0) {
        return 0.0f;
    }


    float result = 0.0f;
    while (x > 1.5f) {
        x /= 2.718281828459045f;
        result += 1.0f;
    }

    x -= 1.0f;


    float term = x;
    float sum = 0.0f;
    int n = 1;

    while (term > 1e-7f || term < -1e-7f) {
        sum += term;
        n++;
        term *= -x * (n - 1) / n;
    }

    return result + sum;
}
