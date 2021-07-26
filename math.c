#include "math.h"

uint16_t denominator;
uint16_t quotient;

uint16_t tempvalue;
uint8_t *divide_result;

//how many values in array
const uint8_t resolution = 45;

void divide(uint8_t x, uint8_t y, uint8_t *result){
    if(y == 0){
        *result = 0;
    }
    
    denominator= y;
    quotient = 1;

    while(x > denominator){
        denominator *= 2;
        quotient *= 2;

    }

    while(denominator > x){
        denominator -= y;
        quotient -= 1;
    }

    //remainder would be x - denominator.

    *result = quotient;
}

void getangle_fromxy(uint8_t adjacent, uint8_t opposite, uint8_t *result){
    //edge cases
    if(adjacent==opposite){
        *result = 45;
        return;
    }
    if(adjacent <= 0){
        *result = 90;
        return;
    }
    if(opposite <= 0){
        *result = 0;
        return;
    }

    
    //smaller than 45 degrees
    if(adjacent > opposite){
        tempvalue = opposite*resolution;
        divide(tempvalue, adjacent, divide_result);
    }
    //greater than 45
    else{
        tempvalue = adjacent*resolution;
        divide(adjacent, tempvalue, divide_result);
        *divide_result = 90-*divide_result;
    }
    *result = *divide_result;
}

void getvector_from_degrees(uint16_t *degrees, Vector2d8 *result){

    if(*degrees <= 90){
        if(*degrees <= 45){
            result->x = vector_from_angle_table[*degrees][0];
            result->y = vector_from_angle_table[*degrees][1];    
        }
        else{
            *degrees -= 45;
            result->x = vector_from_angle_table[*degrees][1];
            result->y = vector_from_angle_table[*degrees][0];
        }
    }
    else if(*degrees <= 180){
        if(*degrees <= 135){
            *degrees -= 90;
            result->x = -vector_from_angle_table[*degrees][1];
            result->y = vector_from_angle_table[*degrees][0];
        }
        else{
            *degrees -= 135;
            result->x = -vector_from_angle_table[*degrees][0];
            result->y = vector_from_angle_table[*degrees][1];    
        }
    }
    else if(*degrees <= 270){
        if(*degrees <= 225){
            *degrees -= 180;
            result->x = -vector_from_angle_table[*degrees][0];
            result->y = -vector_from_angle_table[*degrees][1]; 
        }
        else{
            *degrees -= 225;
            result->x = -vector_from_angle_table[*degrees][1];
            result->y = -vector_from_angle_table[*degrees][0];
        }
    }
    else{
        if(*degrees <= 315){
            *degrees -= 270;
            result->x = vector_from_angle_table[*degrees][1];
            result->y = -vector_from_angle_table[*degrees][0];
        }
        else{
            *degrees -= 315;
            result->x = vector_from_angle_table[*degrees][1];
            result->y = -vector_from_angle_table[*degrees][0];
        }
    }
}

