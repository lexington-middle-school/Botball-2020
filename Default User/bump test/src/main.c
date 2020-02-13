#include <kipr/wombat.h>

int main()
{
    
 
    
    while(digital(0) == 0)
    {
    mav(1,-300);
    mav(2,-300);
   msleep(500);
    }
   msleep(500);
    mav(1,300);
    mav(2,300);
    msleep(3000);
    return 0;
}
