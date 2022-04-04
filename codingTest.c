#include<stdio.h>

int main(){

    float w, h, b, mb = 0;
    scanf("%f %f %f", &w, &h, &b);
    mb = (w * h * b) / 8 / 1024 / 1024;
    printf("%.2f MB", mb);
    
    return 0;
}