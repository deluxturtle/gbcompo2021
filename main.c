#include <gb/gb.h>

//1,000 Km = 1 Mm
const uint16_t kerbin_r = 600;//Mm radius of kerbin
const uint8_t gravity = 10;//roughly close to 9.8 haha

struct ship{
    //meters per second
    //just use this to count to 1,000
    uint16_t mspeed;
    //kilometers per second...Gets updated every 1,000 meters. 
    //fastest ship went 150 km/s
    uint8_t kspeed;
};

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

    struct ship player;
    player.mspeed = 200;//speed of ksp orbit ships.
    player.kspeed = 2;
    //now speed is 2,200 m/s

    SHOW_SPRITES;
    while(1){
        

        wait_vbl_done();
    }
}