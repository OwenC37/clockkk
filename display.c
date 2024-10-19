#include "display.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "sense.h"
#include <math.h>

#define WHITE 0xFFFF
#define BLUE  0x001F
#define GREEN 0x07E0
#define RED   0xF800
#define BLACK 0x0000

    //pi_framebuffer_t *fb=getFrameBuffer();
    //sense_fb_bitmap_t *bm=fb->bitmap;

int open_display(void);
void display_time(int hours, int minutes, int seconds);
void display_colons(void);
void display_hours(int hours);
void display_minutes(int minutes);
void display_seconds(int seconds);
void close_display(void);


pi_framebuffer_t* fb = NULL;

int open_display(void) {
    if(fb != NULL) {
        return 0;
    }
    fb = getFrameBuffer();
    if(fb == NULL) {
        return 0;
    }
    clearFrameBuffer(fb, BLACK);
    display_colons();
    return 1;
}
void display_colons(void) {
    if(fb == NULL) {
        return;
    }
    sense_fb_bitmap_t *bm = fb->bitmap;
    bm->pixel[1][1] = WHITE;
    bm->pixel[2][1] = WHITE;
    bm->pixel[4][1] = WHITE;
    bm->pixel[5][1] = WHITE;
    bm->pixel[1][2] = WHITE;
    bm->pixel[2][2] = WHITE;
    bm->pixel[4][2] = WHITE;
    bm->pixel[5][2] = WHITE;
    bm->pixel[1][4] = WHITE;
    bm->pixel[2][4] = WHITE;
    bm->pixel[4][4] = WHITE;
    bm->pixel[5][4] = WHITE;
    bm->pixel[1][5] = WHITE;
    bm->pixel[2][5] = WHITE;
    bm->pixel[4][5] = WHITE;
    bm->pixel[5][5] = WHITE;

}

void display_hours(int hours) {
    if(fb == NULL) {
        return;
    }
    sense_fb_bitmap_t *bm = fb->bitmap;

	int B;
    

	for (int c = 7; c >= 0; c--){
		B = hours >> c;
		if(B & 1){
            bm->pixel[6][abs(7-c)]=BLUE;
		}	
	}
    
}




void display_minutes(int minutes) {
    if(fb == NULL) {
        return;
    }
    sense_fb_bitmap_t *bm = fb->bitmap;

	int B;

	for (int c = 7; c >= 0; c--){
		B = minutes >> c;
		if(B & 1){
            bm->pixel[3][abs(7-c)]=GREEN;
		}	
	}
}



void display_seconds(int seconds) {
    if(fb == NULL) {
        return;
    }
    sense_fb_bitmap_t *bm = fb->bitmap;

	int B;
	for (int c = 7; c >= 0; c--){
		B = seconds >> c;
		if(B & 1){
            bm->pixel[0][abs(7-c)]=RED;
		}	
	}
}



void display_time(int hours, int minutes, int seconds) {
    // Clearing and initializing handled outside this function, or within specific display functions

    // Display each component of the time on the LED matrix
    display_hours(hours);   // Display hours in the specified columns (e.g., column 6)
    display_minutes(minutes); // Display minutes in the specified column (e.g., column 3)
    display_seconds(seconds); // Display seconds in the specified column (e.g., column 0)
    display_colons();
     // Optional: Display colons between hours and minutes, and minutes and seconds
}


void close_display(void) {

    pi_framebuffer_t *fb=getFrameBuffer();
    clearFrameBuffer(fb,BLACK);
    sleep(1);
    freeFrameBuffer(fb);

}
