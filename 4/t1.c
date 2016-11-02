#include<stdint.h>
void draw_circle( uint8_t img[],
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
}
