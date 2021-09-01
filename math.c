#include "math.h"

int16_t denominator;
int16_t quotient;

uint16_t tempvalue;
uint8_t *divide_result;

//how many values in array
const uint8_t resolution = 45;

const uint8_t RIGHT = 0;
const uint8_t UPRIGHT = 45;
const uint8_t UP = 90;
const uint8_t UPLEFT = 135;
const uint8_t LEFT = 180;
const uint8_t DOWNLEFT = 225;
const uint16_t DOWN = 270;
const uint16_t DOWNRIGHT = 315;

void divide(uint16_t x, int16_t y, int8_t *result){
    uint8_t negative = 0;//0= positive 1 = neg
    if(y == 0){
        *result = RIGHT;
        return;
    }
    else if(y < 0){
        negative = 1;
        y *= -1;
    }
    
    denominator = y;
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
    if(negative > 0){
        quotient *= -1;
    }

    *result = (int8_t)quotient;
}

void getangle_fromxy(uint8_t adjacent, uint8_t opposite, uint8_t *result){
    //edge cases
    if(adjacent == opposite){
        *result = UPRIGHT;
        return;
    }
    if(adjacent <= RIGHT){
        *result = UP;
        return;
    }
    if(opposite <= RIGHT){
        *result = RIGHT;
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

void getvector_from_degrees(int16_t *degrees, Vector2d8 *result){

    if(*degrees <= UP){
        if(*degrees <= UPRIGHT){
            result->x = vector_from_angle_table[*degrees][0];
            result->y = vector_from_angle_table[*degrees][1];    
        }
        else{
            *degrees -= UPRIGHT;
            result->x = vector_from_angle_table[UPRIGHT-*degrees][1];
            result->y = vector_from_angle_table[UPRIGHT-*degrees][0];
        }
    }
    else if(*degrees <= LEFT){
        if(*degrees <= UPLEFT){
            *degrees -= UP;
            result->x = -vector_from_angle_table[*degrees][1];
            result->y = vector_from_angle_table[*degrees][0];
        }
        else{
            *degrees -= UPLEFT;
            result->x = -vector_from_angle_table[UPRIGHT-*degrees][0];
            result->y = vector_from_angle_table[UPRIGHT-*degrees][1];    
        }
    }
    else if(*degrees <= DOWN){
        if(*degrees <= DOWNLEFT){
            *degrees -= LEFT;
            result->x = -vector_from_angle_table[*degrees][0];
            result->y = -vector_from_angle_table[*degrees][1]; 
        }
        else{
            *degrees -= DOWNLEFT;
            result->x = -vector_from_angle_table[UPRIGHT-*degrees][1];
            result->y = -vector_from_angle_table[UPRIGHT-*degrees][0];
        }
    }
    else{
        if(*degrees <= DOWNRIGHT){
            *degrees -= DOWN;
            result->x = vector_from_angle_table[*degrees][1];
            result->y = -vector_from_angle_table[*degrees][0];
        }
        else{
            *degrees -= DOWNRIGHT;
            result->x = vector_from_angle_table[UPRIGHT-*degrees][1];
            result->y = -vector_from_angle_table[UPRIGHT-*degrees][0];
        }
    }
}

