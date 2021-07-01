#include <gb/gb.h>

const uint16_t kerbin_r = 600;//thousand kilometers in radius
const uint8_t gravity = 10;//roughly close to 9.8 lol



void main(){
    // remaps the palette
    // Bit 7-6 - Color for index 3
    // Bit 5-4 - Color for index 2
    // Bit 3-2 - Color for index 1
    // Bit 1-0 - Color for index 0
    // 0	White
    // 1	Light gray
    // 2	Dark gray
    // 3	Black
    //           3 1 0 transparent
    OBP0_REG = 0b11010000;
    SHOW_SPRITES;
    while(1){
        //lets get a value from 0 to 1

        wait_vbl_done();
    }
}