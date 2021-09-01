#include <gb/gb.h>
#include <stdlib.h>
#include "orbit.h"
#include "planet.h"
//test mockup
#include "tilemap.h"
#include "tileset.h"
#include "ellipse.h"
#include "math.h"


const unsigned char circle_data[] = {

	//  circle.png 1 x 1 tiles 

	0x24,0xc3,0x7e,0x81,0xff,0x00,0x7f,0x00,0x7f,0x00,0xff,0x00,0x7e,0x81,0x3c,0xc3
};


struct Ship{
    //meters per second
    //just use this to count to 1,000
    uint16_t mspeed;
    //kilometers per second...Gets updated every 1,000 meters. 
    //fastest irl craft went 150 km/s
    uint8_t kspeed;
    uint8_t mass;//tons
};

struct Ship player;
struct Planet kerbin;
uint8_t *result;


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
    //OBP0_REG = 0b11010000;
    
    player.mass = 1;//1 ton? = 907kg?
    player.mspeed = 200;//speed of ksp orbit ships.
    player.kspeed = 2;
    //now speed is 2,200 m/s

    kerbin.gravity = 10;
    kerbin.radius = 19;

    SHOW_BKG;
    set_bkg_data(0, TILESET_TILE_COUNT, TILESET);
    set_bkg_tiles(0,0, TILEMAP_WIDTH, TILEMAP_HEIGHT, TILEMAP);
    set_sprite_data(0, 1, circle_data);
    set_sprite_tile(5, 0);
    
    SHOW_SPRITES;
    struct Ellipse ellipse;
    ellipse.pos.x = 55;
    ellipse.pos.y = 55;
    ellipse.seg_count = 8;
    ellipse.xAxis = 10;
    ellipse.yAxis = 10;
    ellipse.displayIndex = 0;
    CalculateEllipse(&ellipse);

    

    while(1){
        if (sys_time % 3 == 0)
        {
            ShowNextEllipsePoint(&ellipse);
        }

        wait_vbl_done();
    }
}
//orbit stuff
    //E (energy) = -GM/(r_a+r_p)
    //L(angular momentum) = sqrt(2GM * r_a *r_p / (r_a+r_p))
    //semi major axis
    //= (r_a+r_p)/2 
    //eccentricity is (r_a-r_p)/(r_a+r_p)
    // S = -GM/e
    // P = -L^2/(2E)
    // r_a+r_p=S
    // r_a*r_p=P

    //r_a=(S+/-Sqrt(s^2-4P))/2
    //r_a=(S+Sqrt(s^2-4P))/2
    //r_p=(S-Sqrt(s^2-4P))/2