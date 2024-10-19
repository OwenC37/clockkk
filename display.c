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

void colons_displayed(void);

void hours_displayed(int hours);

void minutes_displayed(int minutes);

void seconds_displayed(int seconds);

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

    colons_displayed();

    return 1;
}
void colons_displayed(void) {
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

void hours_displayed(int hours) {
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

void minutes_displayed(int minutes) {
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



void seconds_displayed(int seconds) {
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

    // Displaying each component(hours, minutes, and seconds )  on the LED matrix
    hours_displayed(hours);   // Display hours (column 6) the numbers that will appear are 1-24
    minutes_displayed(minutes); // Display minutes (column 3) the numbers that will appear are 0-59
    seconds_displayed(seconds); // Display seconds (column 0) the numbers that will appaear are 0-59
    colons_displayed();
}


void close_display(void) {

    pi_framebuffer_t *fb=getFrameBuffer();

    clearFrameBuffer(fb,BLACK);

    sleep(1);

    freeFrameBuffer(fb);

}
