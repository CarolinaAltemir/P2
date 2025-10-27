#include <math.h>
#include "pav_analysis.h"

float compute_power(const float *x, unsigned int N) {
    float suma = 0.0;
    for(unsigned int n=0; n<N; n++){
        suma += x[n]*x[n];
    }
    return 10*log10(suma/N);
}

float compute_am(const float *x, unsigned int N) {
    float suma = 0.0f;
    for(unsigned int n=0; n<N; n++){
        suma += fabsf(x[n]);
    }
    return suma/(float)N;
}

float compute_zcr(const float *x, unsigned int N, float fm) {
    unsigned int cero = 0;
    for(unsigned int n=1; n<N; n++){
        if((x[n-1] > 0 && x[n] < 0) || (x[n-1] < 0 && x[n] >0)){
            cero++;
        }
    }
    float sol = ((float)cero / (float)N) * fm;
    return sol;
}
