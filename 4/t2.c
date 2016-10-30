#include <stdio.h>
#include <math.h>

void draw_rectangle( uint8_t array[],
		          unsigned int cols,
		          unsigned int rows,
		          int x,
		          int y,
		          int rect_width,
		          int rect_height,
		          uint8_t color ){
//this code is bad check the imgops.c on lab 3 for the better version (that version isn't even perfect tbh)
      int i = y;
      int k = x;

      for(i; i<=(y + rect_height); i++){

        array[i*cols+k] = color;


        for (k = x+1; k < (x + rect_width); k++){

          if( i == y || i == (y+rect_height)){

            array[i*cols+k] = color;

          }

        }

        array[i*cols+k] = color;
      }



}
