#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define ARRAY_LENGTH 5
float calc_mean(float *data_array)
{
    float sum;
    for (int i = 0; i < ARRAY_LENGTH; i++)
        sum += data_array[i];
    float avr = (sum / ARRAY_LENGTH);
    return avr;
}
float calc_standard_deviation(float *data_array)
{
    float avr = calc_mean(data_array);
    float var;
    float data[ARRAY_LENGTH];
    for (int i = 0; i < ARRAY_LENGTH; i++)
    {
        data[i] = (float)pow((data_array[i] - avr), 2);
        var += (data[i] / ARRAY_LENGTH);
    }
    return (float)sqrt(var);
}
float calc_cv(float *data_array)
{
    return calc_standard_deviation(data_array) / calc_mean(data_array);
}