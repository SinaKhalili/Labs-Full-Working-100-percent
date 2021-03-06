/*
 * imageops.c - Simple operations on images
 *
 * C laboratory exercises.
 * Richard Vaughan, 2014.
 */

#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/* PAIR SECTION BEGINS - WORK WITH YOUR PARTNER ON THESE TASKS */

/*-------------------------------------------------
  PART 0: DEMONSTRATION
*/


// get the value in the array at coordinate (x,y)
uint8_t get_pixel( const uint8_t array[],
           unsigned int cols,
           unsigned int rows,
           unsigned int x,
           unsigned int y )
{
    assert( x < cols );
    assert( y < rows );
    return array[ y*cols + x ];
}

// set the pixel at coordinate {x,y} to the specified color
void set_pixel( uint8_t array[],
        unsigned int cols,
        unsigned int rows,
        unsigned int x,
        unsigned int y,
        uint8_t color )
{
    assert( x < cols );
    assert( y < rows );
    array[ y * cols + x ] = color;
}

// Set every pixel to 0 (black)
void zero( uint8_t array[],
	   unsigned int cols,
	   unsigned int rows )
{
  memset( array, 35, cols * rows * sizeof(uint8_t) );

  // your code here.
}

// Returns a pointer to a freshly allocated array that contains the
// same values as the original array, or a null pointer if the
// allocation fails. The caller is responsible for freeing the array
// later.
//uint8_t* copy( const uint8_t array[],
           //unsigned int cols,
           //unsigned int rows )
//{

  //int* array = malloc( cols * rows * sizeof(int) );
  //return array;
  // your code here
  //return NULL;
//}



/*-------------------------------------------------
  PART 1: OPERATIONS ON THE WHOLE IMAGE
*/

/* TASK 1 - three easy functions to get started */

// Return the darkest color that appears in the array; i.e. the
// smallest value
uint8_t min( const uint8_t array[],
	     unsigned int cols,
	     unsigned int rows )
{
  int i = 0;
  int greatest = 500;
  for(  i = 0 ; i<cols*rows; i++ ){
  if (array[i] < greatest){
    greatest = array[i];
    }
  }
  // your code here
  return greatest;
}


// Return the lightest color that appears in the array; i.e. the
// largest value
uint8_t max( const uint8_t array[],
		 unsigned int cols,
		 unsigned int rows )
{
  int i = 0;
  int greatest = -500;
  for(  i = 0 ; i<cols*rows; i++ ){
  if (array[i] > greatest){
    greatest = array[i];
    }
  }
  // your code here
  return greatest;
  // your code here
}

// TASK 2

//  Replace every instance of pre_color with post_color.
void replace_color(  uint8_t array[],
		     unsigned int cols,
		     unsigned int rows,
		     uint8_t pre_color,
		     uint8_t post_color )
{
  int i = 0;
  for (i = 0; i<cols*rows; i++){
    if (array[i] == pre_color){
      array[i] = post_color;
    }
  }
  // your code here
}

/* TASK 3  - two functions */


// flip the image, left-to-right, like in a mirror.
void flip_horizontal( uint8_t array[],
              unsigned int cols,
              unsigned int rows )
{
  int k = 0;
  int i = 0;
  int j = cols-1;
  uint8_t tmp = 0;
  for (k =0 ; k < rows; k++){
    j = (k+1)*cols - 1;
    i = (k)*cols;
    while(i<=j){
      tmp = array[i];
      array[i] = array[j];
      array[j] = tmp;
      j--;
      i++;
    }
  }
  // your code here
}

// flip the image top-to-bottom.
void flip_vertical( uint8_t array[],
            unsigned int cols,
            unsigned int rows )
{
  int counter = 0;
  int k = (cols*rows) - (counter+1)*cols;
  int i = 0;
  int j = counter*cols;

  uint8_t tmp = 0;
  while(j<k){
    //printf("Im goin' into the while loop boss\n");
    i = 0;
    for(i = 0; i<cols; i++){
      //printf("Im goin' into the for loop boss\n");
      tmp = array[j+i];
      array[j+i] = array[k+i];
      array[k+i] = tmp;
    }
    i=0;
    counter++;
    k-=cols;
    j+=cols;
  }

    // your code here
}

/* TASK 4 */

// Find the first coordinate of the first pixel with a value that
// equals color. Search from left-to-right, top-to-bottom. If it is
// found, store the coordinates in *x and *y and return 1. If it is
// not found, return 0.
int locate_color(  const uint8_t array[],
		   unsigned int cols,
		   unsigned int rows,
		   uint8_t color,
		   unsigned int *x,
		   unsigned int *y )
{
  int i = 0;
  int columCounter = 0;
  int counter = 0;

  for (i = 0 ; i<cols*rows; i++){
    if(array[i]==color){
      *y = counter;
      *x = columCounter;
      //printf("%d %d\n", counter, columCounter);
      return 1;
    }

    if(columCounter == cols){
      columCounter = 0;
      counter++;
    }

    columCounter++;

  }
    // your code here
    return 0;
}


/* TASK 5 */

// Invert the image, so that black becomes white and vice versa, and
// light shades of grey become the corresponding dark shade.
void invert( uint8_t array[],
         unsigned int cols,
         unsigned int rows )
{
  int i = 0;
  for (i = 0; i<cols*rows; i++){
    array[i] = 255 - array[i];
  }
    // your code here
}

/* TASK 6 */

// Multiply every pixel by scale_factor, in order to brighten or
// darken the image. Any resulting value over 255 is
// thresholded to 255.
void scale_brightness( uint8_t array[],
            unsigned int cols,
            unsigned int rows,
            double scale_factor )
{
  int i = 0;
  for (i = 0; i<cols*rows; i++){
    if(array[i]*scale_factor>255){
      array[i] = 255;
    }
    else{
      array[i]= round(array[i] * scale_factor);
    }

  }
  // your code here
}


/* TASK 7 */

// Normalize the dynamic range of the image, i.e. Shift and scale the
// pixel colors so that that darkest pixel is 0 and the lightest pixel
// is 255. Hint: you already wrote min() and max().
void normalize( uint8_t array[],
        unsigned int cols,
        unsigned int rows )
{
  uint8_t maxPixel = max(array, cols, rows);
  uint8_t minPixel = min(array, cols, rows);

  int i = 0;
  //printf("The difference is %f\n", difference);
  float tmp = 0.0;
  float diff = maxPixel-minPixel;
  for (i = 0; i<cols*rows; i++){
    printf("The number %d was changed to ", array[i]);
    tmp = (array[i] - minPixel)*(255)/diff;

    printf("Either this %f or ", tmp );
    array[i] = round(tmp);
    printf("%d\n", array[i] );
  /*  if(array[i] == maxPixel){
        printf("The number %d is now ",  array[i]);
      array[i] = 255;
        printf("This : %d\n", array[i] );
    }
    else if(array[i] == minPixel){
        printf("The number %d is now ",  array[i]);
      array[i] = 0;
        printf("This : %d\n", array[i] );
    }
    else{
      printf("The number %d is now ",  array[i]);
      tmp = array[i];
      if(tmp<difference){
        array[i] = round((tmp/difference)*255);
        printf("This : %d\n", array[i] );
      }
      else if(tmp>difference){
        array[i] = round((tmp/maxPixel)*255);
        printf("This : %d\n", array[i] );
      }
    }*/
  }
    // your code here
}

/* TASK 8 */

// Return a new image of size rows/2 by cols/2 If the original image
// has an odd number of columns, ignore its rightmost column. If the
// original image has an odd number of rows, ignore its bottom row.
// The value of a pixel at (p,q) in the new image is the average of
// the four pixels at (2p,2q), (2p+1,2q), (2p+1,2q+1), (2p,2q+1) in
// the original image.
uint8_t* half( const uint8_t array[],
	       unsigned int cols,
	       unsigned int rows )
{
  uint8_t *arr = malloc((cols/2)*(rows/2)*sizeof(uint8_t));
  int i = 0;


  int k = 0;

  float sum = 0.0;

  for (i = 0; i< rows/2; i++){
    for ( k = 0; k < cols/2; k++ ){
      sum = (     array[  2*i    * cols + (2*k+1) ] +
                  array[  2*i    * cols +  2*k ]    +
                  array[ (2*i+1) * cols + (2*k+1) ] +
                  array[ (2*i+1) * cols +  2*k ]);
      sum = sum/4.0;
      arr[i*(cols/2) + k] = (round(sum));
    }
  }
  /*for(i = 0; i<(cols/2)*(rows/2); i++){
    y = i/cols;
    x = i % rows;
    sum = (     array[  2*y    * cols + (2*x+1) ] +
                array[  2*y    * cols +  2*x ]    +
                array[ (2*y+1) * cols + (2*x+1) ] +
                array[ (2*y+1) * cols +  2*x ]);
    sum = sum/4.0;
    printf("this is the sum: %d \n", sum );
    arr[i] = (round(sum));
    //printf("Into %d \n", arr[i]);
  }*/

  return arr;

  // your code here
  return NULL;
}

void printArray( const uint8_t array[],
	       unsigned int cols,
	       unsigned int rows ){
      int columCounter = 0;
      int i = 0;
      for(i=0; i<cols*rows; i++){
        columCounter++;
        printf(" %d ", array[i] );
        if(columCounter == cols){
          columCounter = 0;
          printf("\n");
        }
      }
      printf("\n");
      printf("\n");

}



/*-------------------------------------------------
  PART 2: OPERATIONS ON IMAGE SUB-REGIONS

  These functions operate only on a rectangular region of the array
  defined by a (left,top) corner (i.e. closer to the image origin) and
  (right,bottom) corner (i.e. further from the image origin).

  The region includes all the columns from [left, right-1] inclusive,
  and allthe rows from [top, bottom-1] inclusive.

  In every case, you may assume that left <= right and top <= bottom:
  do not need to test for this.

  The area of the region is right-left * bottom-top pixels, which
  implies that if left == right or top == bottom, the region has no
  area and is defined as "empty". Each function notes how to handle
  empty regions.

  In every function, use assert() to test bounds on the region
  corners.
*/

/* TASK 9 */

// Set every pixel in the region to color. If the region is empty, the
// image must be unchanged.
void region_set( uint8_t array[],
         unsigned int cols,
         unsigned int rows,
         unsigned int left,
         unsigned int top,
         unsigned int right,
         unsigned int bottom,
         uint8_t color )
{
  if(right-left * bottom-top  == 0){
    return;
  }

  int i = 0;
  int k = 0;
  for (i = 0; i< rows; i++){
    for ( k = 0; k < cols; k++ ){
      if (k >= left && k < right
       && i >= top  && i < bottom )
        {
          array[i*(cols) + k] = color;
        }
    }
  }
}

/*void draw_circle( uint8_t img[],
                  unsigned int cols,
                  unsigned int rows,
		              int x,
		              int y,
		              int r,
		              uint8_t color ){
          float Xdistance = 0;
          float Ydistance = 0;
          int a = 0;
          int b = 0;
          for (b = 0; b<rows; b++){
            for(a = 0; a<cols; a++){
              Xdistance = abs(a-x);
              Ydistance = abs(b-y);

              if(
                  round(sqrt((Xdistance*Xdistance)+(Ydistance*Ydistance))) < r
              ){
                img[b*cols + a] = color;
              }

            }
          }

}*/
void draw_rectangle( uint8_t array[],
		          unsigned int cols,
		          unsigned int rows,
		          int x,
		          int y,
		          int rect_width,
		          int rect_height,
		          uint8_t color ){

      if(rect_width == 0 ||rect_height == 0){return;}

      if (rect_height<0 && rect_width<0){
        /*printf("both negatives!\n");
        printf("x used to be %d ", x);*/
        x++;
        x += rect_width;
        y++;
        y += rect_height;
        //printf("and now its %d\n", x);
        draw_rectangle(array, cols, rows, x,y, abs(rect_width),abs(rect_height), color );
        return;

      }
      else if (rect_width<0 && rect_height>0){
        //printf("width negative!\n");
        x++;
        x += rect_width;
        draw_rectangle(array, cols, rows, x,y, abs(rect_width),abs(rect_height), color );
        return;
      }
      else if (rect_height<0 && rect_width>0){
        //printf("height negative!\n");
        y++;
        y += rect_height;
        draw_rectangle(array, cols, rows, x,y, abs(rect_width),abs(rect_height), color );
        return;
      }
      int i = y;
      int k = x;

      if(rect_height > 0 && rect_width > 0 ){
      for(i = y; i<(y + rect_height); i++){

        if(k>=0 && i>=0 && i*cols + x){
          array[i*cols + x] = color;
        }

        for (k = x; k <x+rect_width-1; k++){

          if( i == y || i == (y+rect_height)-1){

            if(k>=0 && i>=0){
              array[i*cols+k] = color;
            }
          }

        }


        if(k>=0 && i>=0){
          array[i*cols+k] = color;
        }

        k=x;
      }
    }
}

    // your code here

/* TASK 10 */

// Return the sum of all the pixels in the region. Notice the large
// return type to handle potentially large numbers. Empty regions
// return the sum 0.
unsigned long int region_integrate( const uint8_t array[],
                    unsigned int cols,
                    unsigned int rows,
                    unsigned int left,
                    unsigned int top,
                    unsigned int right,
                    unsigned int bottom )
{
  unsigned long int sum = 0;
  if(right-left * bottom-top  == 0){
    return sum;
  }

  int i = 0;
  int k = 0;
  for (i = 0; i< rows; i++){
    for ( k = 0; k < cols; k++ ){
      if (k >= left && k <= right-1

        && i>=top && i<= bottom-1 )

        {
          sum += array[i*(cols) + k];
        }

    }
  }



  return sum;
}
void draw_circle( uint8_t img[],
                  unsigned int cols,
                  unsigned int rows,
		              int x,
		              int y,
		              int r,
		              uint8_t color ){

          int a = 0;
          int b = 0;
          for (b = 0; b<rows; b++){
            for(a = 0; a<cols; a++){
              float Xdistance1 = (a-0.5)-(x);
              float Xdistance2 = (a+0.5)-(x);
              float Xdistance3 = (a-0.5)-(x);
              float Xdistance4 = (a+0.5)-(x);
              float Ydistance1 = (b+0.5)-(y);
              float Ydistance2 = (b+0.5)-(y);
              float Ydistance3 = (b-0.5)-(y);
              float Ydistance4 = (b-0.5)-(y);
              if(
                  (Xdistance2*Xdistance2)+(Ydistance2*Ydistance2) < r*r ||
                  (Xdistance1*Xdistance1)+(Ydistance1*Ydistance1) < r*r ||
                  (Xdistance3*Xdistance3)+(Ydistance3*Ydistance3) < r*r ||
                  (Xdistance4*Xdistance4)+(Ydistance4*Ydistance4) < r*r
              ){
                img[b*cols + a] = color;
              }

            }
          }
}





/* TASK 11 */

// Get a new image which is a copy of the region. Empty regions return
// a null pointer. If memory allocation fails, return a null
// pointer. The caller is responsible for freeing the returned array
// later.
uint8_t* region_copy( const uint8_t array[],
              unsigned int cols,
              unsigned int rows,
              unsigned int left,
              unsigned int top,
              unsigned int right,
              unsigned int bottom )
{
  if(!((right-left)*(bottom-top)>0 ))
  {
    return NULL;
  }

  uint8_t *newArr = malloc((right-left)*(bottom-top)*sizeof(uint8_t));

  int i = 0;
  int k = 0;
  int j = 0;
  for (i = 0; i< rows; i++){
    for ( k=0; k < cols; k++ ){
      if (k>=left && k<= right-1 &&

          i>=top  && i<=bottom-1)

          {

          newArr[j] = array[i*(cols) + k];
          j++;

          }
        }
  }

  return newArr;
}












void life( uint8_t array[],
           unsigned int cols,
           unsigned int rows ){

            int y = 0;
            int x = 0;
            int yPlusOne = 0;
            int xPlusOne = 0;
            int yMinusOne = 0;
            int xMinusOne = 0;
            int counter = 0;
              //printArray(array, cols, rows);
            //int *tmpArr = malloc(cols*rows*sizeof(uint8_t));
            for (y = 0; y<rows; y++){
                for( x = 0; x<cols; x++){
                  if(array[y*cols +x] == 0){//it's dead

                    yPlusOne = y+1;
                    yMinusOne = y-1;
                    xPlusOne = x+1;
                    xMinusOne = x-1;

                    if(x == cols-1){
                      xPlusOne = 0;
                    }
                    if(x == 0){
                      xMinusOne = cols-1;
                    }
                    if(y == rows-1){
                      yPlusOne = 0;
                    }
                    if(y == 0){
                      yMinusOne = rows-1;
                    }
                    //Checks all eight surrounding elements
                    if(array[ (yPlusOne)* cols+ xMinusOne] > 1){ counter++; }
                    if(array[ (yPlusOne)* cols+ x]         > 1){ counter++; }
                    if(array[ (yPlusOne)* cols+ xPlusOne]  > 1){ counter++; }
                    if(array[  y        * cols+ xMinusOne] > 1){ counter++; }
                    if(array[  y        * cols+ xPlusOne]  > 1){ counter++; }
                    if(array[(yMinusOne)* cols+ xMinusOne] > 1){ counter++; }
                    if(array[(yMinusOne)* cols+ x]         > 1){ counter++; }
                    if(array[(yMinusOne)* cols+ xPlusOne]  > 1){ counter++; }
                    //Now to see if it's born
                    if(counter == 3){
                      array[y*cols +x] = 1;//One means it's alive next turn, so for others it's effectively dead
                    }
                    else{
                      array[y*cols +x] = 0;
                    }
                    counter = 0; //reset the counter for the next element
                  }
                  else if (array[y*cols +x] != 0){//it's alive
                    //Checks all eight surrounding elements
                    yPlusOne = y+1;
                    yMinusOne = y-1;
                    xPlusOne = x+1;
                    xMinusOne = x-1;

                    if(x == cols-1){
                      xPlusOne = 0;
                    }
                    if(x == 0){
                      xMinusOne = cols-1;
                    }
                    if(y == rows-1){
                      yPlusOne = 0;
                    }
                    if(y == 0){
                      yMinusOne = rows-1;
                        }
                    //Checks all eight surrounding elements
                    if(array[ (yPlusOne)* cols+ xMinusOne] > 1){ counter++; }
                    if(array[ (yPlusOne)* cols+ x]         > 1){ counter++; }
                    if(array[ (yPlusOne)* cols+ xPlusOne]  > 1){ counter++; }
                    if(array[  y        * cols+ xMinusOne] > 1){ counter++; }
                    if(array[  y        * cols+ xPlusOne]  > 1){ counter++; }
                    if(array[(yMinusOne)* cols+ xMinusOne] > 1){ counter++; }
                    if(array[(yMinusOne)* cols+ x]         > 1){ counter++; }
                    if(array[(yMinusOne)* cols+ xPlusOne]  > 1){ counter++; }
                    //Now to see if it dies
                    if(counter < 2 || counter > 3){
                      array[y*cols +x] = 3;//This means it's effectively alive
                    }
                    else{
                      array[y*cols +x] = 255;//4;
                    }
                    counter = 0;
                  }
                }
            }
            //printArray(array, cols, rows);
          int i = 0;
          for(i = 0; i<cols*rows; i++){
            if (array[i] == 1){
              array[i]  = 255;//4;
            }
            if(array[i] == 3){
              array[i] = 0;
            }
          }
          //  printArray(array, cols, rows);
     }
