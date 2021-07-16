#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265
// PI/180
#define deg2rad 0.017453 //deg*deg2rad = radian

void main(){
    int max = 90;
    double angle = 0;
    int result;
    char hex[10];
    //sprintf(&hex, "%x", angle);
    int width = 8;
    int i = 0;
    double anglestep = 0.3515625;//90/255
    
    while(angle < max){
        result = cos(angle*deg2rad)*256;
        sprintf(hex, "%x", result);
        
        
        angle += anglestep;
        if(i < width){
            printf("0x%s, ", hex);
            i++;
        }
        else{
            printf("0x%s,\n", hex);
            i = 0;
        }
    }
}