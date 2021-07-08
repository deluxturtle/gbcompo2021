#ifndef PLANET_H
#define PLANET_H
#include <gb/gb.h>

typedef struct Planet{

    uint8_t radius;// km/16
    uint8_t atmosphere;// km/16
    uint8_t gravity;
}Planet;

#endif