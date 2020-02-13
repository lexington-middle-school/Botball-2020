#include <kipr/wombat.h>

int main()
{
    int ballArea = 4000;
    int foundObject = 0;

    camera_open();
    set_servo_position(1,100);
    set_servo_position(0,970);
    enable_servos();

    // raise arm to grabbing height and open claw

    while (digital(0)== 0)
    {
        camera_update();
        msleep(100);
        if (get_object_count(0) > 0)
        {
            ballArea = get_object_area(0,0);
            printf("area is %d hit button if good.\n",ballArea);
        }
        else 
        {
            printf("where is ball?\n");
        }

    }

    printf("all done and area is %d\n",ballArea); 
    msleep(3000);

    // put robot back into start box and orient it for game
    //  wait_for_light(0);
    //  shut_down_in(119);

    // Light is on - GAME is ON!
    // start driving around
    camera_close();
    msleep(1000);
    camera_open();
    msleep(1000);

    // find the orange ball and turn so it is in center of view and STOP
    // ignore any objects with area < 100
    while ( foundObject == 0 )
    {
        camera_update();
        msleep(50);
        if (get_object_count(0) > 0)
        {
            if (get_object_area(0,0) > 100)
            {
                printf(" found value inside %d (%d)\n",foundObject,get_object_area(0,0));
                if ( get_object_center_x(0,0) < 60 )
                {
                    printf(" object on left\n");
                    mav(1,200);
                    mav(2,100);
                }
                else if(get_object_center_x(0,0) > 100)
                {
                    printf("object is on right\n");
                    mav(1,100);
                    mav(2,200);
                }
                else
                {
                    foundObject =  1;
                }
            }
        }
        else
        {
            mav(1,250);
            mav(2,-250);   
        }
    }

    printf("found object in center of view\n");
    // now drive forward until object area > (ballArea - 200) then stop
    camera_update();
    while ( get_object_area(0,0) < (ballArea - 200) )
    {
        mav(1,200);
        mav(2,200);
        camera_update();
    }
    ao();

    // now close claw and cross fingers we got it
    set_servo_position(1,600);// close claw
    mav(1,-200);
    mav(2,-300);
    msleep(5000);
    
    set_servo_position(1,100);

    // now backup and turn around and go drop the ball whereever it gets us most points

    // and then all done
    camera_close();
    return 0;
}
