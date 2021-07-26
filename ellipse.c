#include "ellipse.h"

uint16_t angle;
Vector2d8 temp;
uint8_t i;

void CalculateEllipse(struct Ellipse *ellipse){
    //8+1 = 9
    
    for(i = 0; i < ellipse->seg_count; i++){
        angle = (i*30);
        getvector_from_degrees(&angle, &temp);
        ellipse->points[i].x = ellipse->pos.x + temp.x;
        ellipse->points[i].y = ellipse->pos.y + temp.y;
        // uint8_t x = sinlup[angle] * ellipse->xAxis;
        // uint8_t y = sinlup[255-angle] * ellipse->yAxis;
        // points[i].x = x;
        // points[i].y = y;
    }
    ellipse->points[ellipse->seg_count] = ellipse->points[0];
    
}




