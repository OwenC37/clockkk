#ifndef DISPLAY_H
#define DISPLAY_H

#include "sense.h" // Include if its in library structures

int open_display(void);
void display_time(int hours, int minutes, int seconds);
void colons_displayed(void);
void hours_displayed(int hours);
void minutes_displayed(int minutes);
void seconds_displayed(int seconds);
void close_display(void);

#endif // DISPLAY_H
