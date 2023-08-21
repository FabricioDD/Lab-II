#include <stdio.h>
#include <math.h>

void calc_esfera (float r, float *area, float *volume)
{
    double pi=3.14;
    *area=4*pi*(pow(r,2));
    *volume=(4*pi*(pow(r,3)))/3;
}


int main() {
    float x,y,z;
    printf("Digite o raio da esfera:\n");
    scanf("%f",&x);
    calc_esfera(x,&y,&z);
    printf("area: %.3f, volume: %.3f", y,z);
    return 0;
}
