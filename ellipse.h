#ifndef ELLIPSE_H
#define ELLIPSE_H

#include <gb/gb.h>
#include "sinlup.h"
#include "vector2d.h"

struct Ellipse {
    uint8_t segments;//how many sprites to show ellipse
    Vector2d8 *points;
    uint8_t xAxis;
    uint8_t yAxis;
};

void CalculateEllipse(struct Ellipse *ellipse);

#endif