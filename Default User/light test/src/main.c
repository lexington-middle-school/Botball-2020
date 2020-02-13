#include <kipr/wombat.h>

int main()
{
    wait_for_light(1);
    
    mav(1,100);
    mav(2,100);
    msleep(2000);
    
    
    printf("Hello World\n");
    return 0;
}
