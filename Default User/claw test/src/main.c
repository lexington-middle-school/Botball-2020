#include <kipr/wombat.h>

int main()
{

    enable_servos();

    set_servo_position(1,25);//claw open
    set_servo_position(0,1750);//claw down
    
    mav(1,500);
    mav(2,500);
    msleep(200);
    
    msleep(2000);
    set_servo_position(1,682);//claw close
    msleep(10000);
    
    set_servo_position(0,481);//claw up
    set_servo_position(0,1600);

    return 0;
}
