#include<stdio.h>
 
 
int main(){
 
    float h, b ,c, s, mb = 0;

    scanf("%f %f %f %f", &h, &b, &c, &s);
    mb = (h * b * c * s) / 8 / 1024 / 1024;
    printf("%.1f MB", mb);
 
    return 0;
}