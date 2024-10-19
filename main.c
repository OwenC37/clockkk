#include "display.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


#define BLACK 0x0000

int main(void) {
    int hours, minutes, seconds;

    //  starting the display
    
    if (!open_display()) {
        return 1; // Exit if error occurs 
    }


    while (scanf("%d:%d:%d", &hours, &minutes, &seconds) == 3) {
        pi_framebuffer_t *fb=getFrameBuffer();

        clearFrameBuffer(fb,BLACK);

        freeFrameBuffer(fb);

        display_time(hours, minutes, seconds); // The time will display on the the LED matrix
        
        sleep(1); // wait one second wait
    }

    close_display();

    return 0;
}
