#include <gb/gb.h>
#include "vector2d.h"

//Divide no fraction.
//Required that x > y
//If y > x return 0;
void divide(uint16_t x, int16_t y, int8_t *result);

void getangle_fromxy(uint8_t adjacent, uint8_t opposite, uint8_t *result);

void getvector_from_degrees(int16_t *degrees, Vector2d8 *result);