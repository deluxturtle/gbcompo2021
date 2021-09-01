#ifndef ELLIPSE_H
#define ELLIPSE_H

#include <gb/gb.h>
#include "vector2d.h"
#include "math.h"


struct Ellipse {
    Vector2d16 pos;
    uint8_t seg_count;//how many sprites to show ellipse
    Vector2d8 points[4];
    uint8_t displayIndex;
    uint8_t xAxis;
    uint8_t yAxis;
};




void CalculateEllipse(struct Ellipse *ellipse);

void ShowNextEllipsePoint(struct Ellipse *ellipse);

#endif