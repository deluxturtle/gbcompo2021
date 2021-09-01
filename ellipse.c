#include "ellipse.h"

uint16_t angle;
Vector2d8 temp;
uint16_t tempDeg;
uint8_t tempval;
uint8_t i;

const uint8_t UNITMAGNITUDE = 127;

void CalculateEllipse(struct Ellipse *ellipse){
    //8+1 = 9
    
    // for(i = 0; i < ellipse->seg_count; i++){
    //     angle = (i*30);
    //     getvector_from_degrees(&angle, &temp);
    //     ellipse->points[i].x = ellipse->pos.x + temp.x;
    //     ellipse->points[i].y = ellipse->pos.y + temp.y;
    //     // uint8_t x = sinlup[angle] * ellipse->xAxis;
    //     // uint8_t y = sinlup[255-angle] * ellipse->yAxis;
    //     // points[i].x = x;
    //     // points[i].y = y;
    // }
    // ellipse->points[ellipse->seg_count] = ellipse->points[0];
    tempDeg = 0;
    getvector_from_degrees(&tempDeg, &temp);
    //scale vector down to add to position.
    divide(UNITMAGNITUDE, temp.x, &temp.x);
    divide(UNITMAGNITUDE, temp.y, &temp.y);
    ellipse->points[0].x = ellipse->pos.x + temp.x * ellipse->xAxis;
    ellipse->points[0].y = ellipse->pos.y - temp.y * ellipse->yAxis;

    tempDeg = 90;
    getvector_from_degrees(&tempDeg, &temp);
    divide(UNITMAGNITUDE, temp.x, &temp.x);
    divide(UNITMAGNITUDE, temp.y, &temp.y);
    ellipse->points[1].x = ellipse->pos.x + temp.x * ellipse->xAxis;
    ellipse->points[1].y = ellipse->pos.y - temp.y * ellipse->yAxis;

    tempDeg = 180;
    getvector_from_degrees(&tempDeg, &temp);
    divide(UNITMAGNITUDE, temp.x, &temp.x);
    divide(UNITMAGNITUDE, temp.y, &temp.y);
    ellipse->points[2].x = ellipse->pos.x + temp.x * ellipse->xAxis;
    ellipse->points[2].y = ellipse->pos.y - temp.y * ellipse->yAxis;

    tempDeg = 270;
    getvector_from_degrees(&tempDeg, &temp);
    divide(UNITMAGNITUDE, temp.x, &temp.x);
    divide(UNITMAGNITUDE, temp.y, &temp.y);
    ellipse->points[3].x = ellipse->pos.x + temp.x * ellipse->xAxis;
    ellipse->points[3].y = ellipse->pos.y - temp.y * ellipse->yAxis;

}



void ShowNextEllipsePoint(struct Ellipse *ellipse){
    move_sprite(0, ellipse->points[ellipse->displayIndex].x, ellipse->points[ellipse->displayIndex].y);
    ellipse->displayIndex++;
    if(ellipse->displayIndex > 3){
        ellipse->displayIndex = 0;
    }
}





