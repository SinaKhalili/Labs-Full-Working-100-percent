/*
 * test.cc - functions, arrays, pointers, image representation
 * Richard Vaughan 2014
 */

#include <stdlib.h> // for random()
#include <stdint.h> // for explicit integer types, eg. uint8_t
#include <string.h> // for memset()
#include <assert.h>
#include <stdio.h>

// image drawing functions
#include "draw.h"

// load PNG image function
#include "png.h"

// image manipulation functions
#include "imgops.h"


int main( int argc, char* argv[] )
{
  const unsigned int winwidth  = 400;
  const unsigned int winheight = 400;

  unsigned int imgwidth  = winwidth / 4;
  unsigned int imgheight = winheight / 4 ;

  // initialize the graphics system
  draw_startup( (char*)"Grey Array", winwidth, winheight );

  uint8_t* img = NULL;

  if( argc == 2 ) // if a filename was specified
    {
      uint32_t depth=0;
      int alpha=0;
      if( LoadPngImage( argv[1], &imgwidth, &imgheight, &depth, &alpha, &img ) == 0 )
	{
	  printf( "failed to load image %s\n", argv[1] );
	  exit(1);
	}
    }
  else // no filename specified: create a blank image
    {
      // allocate an array for our image
      img = malloc( imgwidth * imgheight * sizeof(uint8_t) );
      if( img == NULL )
	{
	  printf( "failed to allocate memory for image.\n" );
	  exit(1);
	}

      // set the whole array to zero (black)
      memset( img, 0, imgwidth * imgheight * sizeof(img[0] ));
    }


































  // todo: this is a good place to use some image-modifying functions from imgops.c
/*  zero (img, imgwidth, imgheight);

  int goofyNumber = min(img, imgwidth, imgheight);
  printf("%d \n", goofyNumber); */

  const uint8_t arrJuan[225] ={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                               0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                               0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                               0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                               0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                               0,0,0,0,0,5,0,0,0,0,0,0,0,0,0,
                               0,0,0,0,0,0,0,5,0,0,0,0,0,0,0,
                               0,0,0,0,5,5,0,0,5,5,5,0,0,0,0,
                               0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                               0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                               0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                               0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                               0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                               0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
uint8_t arrJose[68598] = {};
draw_rectangle( arrJose, 193,  96,  -49,    2,  -48,  -36,  5 ) ;
printArray(arrJose, 193, 96);
draw_image_grey( arrJose ,193,  96);

//draw_rectangle( arrJuan, 15,  15,   3,   0,    -2,  4,  5 );
//printArray(arrJuan,15,15);
//draw_rectangle( arrJose, 193,  96,   10,   10,    5,    -5,  255 );
/*draw_rectangle( arrJuan, 7, 7, 4, 3, 2, 3, 5);
draw_rectangle( arrJuan, 7, 7, 4, 3, -2, -3, 5);
draw_rectangle( arrJuan, 7, 7, 4, 3, 2, -3, 5);
draw_rectangle( arrJuan, 7, 7, 4, 3, -  2, 3, 5);
draw_rectangle( arrJuan, 15, 15, 7, 7, -5, -5, 128 );
draw_rectangle( arrJose, 193,  96,   10,   10,    5,   -5,  5 );
draw_rectangle( arrJuan, 15, 15, 7, 7, 5, 5, 255 );*/
//draw_rectangle( arrJose, 206, 333,  277,  318,  110, -225,  207 );
//draw_rectangle( arrJose, 193,  96,   256,  115,  -151,  -69,  213);
//draw_rectangle( arrJose, 193,  96,  127,  -25,    5,   73,   173 );

/*  int sina = 0;
  draw_image_grey( arrJuan, 7, 5 );
  for (sina = 0; sina < 10; sina++){
     life(arrJuan, 7, 5);
     draw_image_grey( arrJuan, 7, 5 );
  }*/
 /*int glider[][2] = { {1,0}, {2,1}, {0,2}, {1,2}, {2,2} };

  for( int i=0; i<5; i++ )
    set_pixel( arrJose, 193, 96, glider[i][0], glider[i][1], 255 );

  for( int i=0; i<100; i++ )
    {
      draw_image_grey( arrJuan, 15, 15 );
      life( arrJuan, 15, 15 );
    }
*/
//draw_image_grey( arrJose, 206, 333);
  /*draw_circle( img,
               imgwidth,
               imgheight,
               imgwidth/2,
               imgheight/2,
               33,
               4);*/

      /*for( int i=10; i>0; i-- )
                  draw_circle( img, imgwidth, imgheight, imgwidth/2, imgheight/2, 2*i, 200/i+55);*/



/*  region_set( img,
              imgwidth,
              imgheight,
              20,
              50,
              150,
              200,
              74);

*/

 /*draw_rectangle( img,
           imgwidth,
          imgheight,
           imgwidth/2,
           imgheight/2,
           -50,
           -50,
            0);
            draw_rectangle( img,
                      imgwidth,
                     imgheight,
                      imgwidth/2,
                      imgheight/2,
                      -50,
                      50,
                       0);
                       draw_rectangle( img,
                                 imgwidth,
                                imgheight,
                                 imgwidth/2,
                                 imgheight/2,
                                 50,
                                 -50,
                                  0);
  draw_rectangle( img,
                  imgwidth,
                 imgheight,
                imgwidth/2,
              imgheight/2,
             50,
            50,
          0);
*/

  // draw the array as a grey-scale image in the window
  // This function returns after a user clicks or presses a button in the window
  // finalize the graphics system, freeing its resources
  draw_shutdown();

  // every malloc() should have a matching free()
  //free(img);


  return 0;



























}
