#include "ellipse.h"


void CalculateEllipse(struct Ellipse *ellipse){
    //8+1 = 9
    Vector2d8 points[9];
    uint8_t i;
    for(i = 0; i < 8; i++){
        uint8_t angle = (i*30);
        // uint8_t x = sinlup[angle] * ellipse->xAxis;
        // uint8_t y = sinlup[255-angle] * ellipse->yAxis;
        // points[i].x = x;
        // points[i].y = y;
    }
    points[8] = points[0];
    
}

