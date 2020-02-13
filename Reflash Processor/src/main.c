#include <kipr/botball.h>

int main()
{
    printf("Flashing Processor, This should take 5-60 seconds...\n");
    system("cd /home/pi && sudo ./wallaby_flash");
    printf("Finished...");
    return 0;
}
