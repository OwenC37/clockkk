#include "display.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


#define BLACK 0x0000
int main(void) {
    int hours, minutes, seconds;

    // Initialize the display
    if (!open_display()) {
        return 1; // Exit with an error code if the display cannot be opened
    }


    while (scanf("%d:%d:%d", &hours, &minutes, &seconds) == 3) {
        pi_framebuffer_t *fb=getFrameBuffer();
        clearFrameBuffer(fb,BLACK);
        freeFrameBuffer(fb);
        display_time(hours, minutes, seconds); // Display the time on the LED matrix
        sleep(1); // Wait for a second before reading the next time input
    }

    close_display();

    return 0;
}
