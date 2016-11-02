#include<stdint.h>
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
                  (Xdistance2*Xdistance2)+(Ydistance2*Ydistance2) < (r*r) ||
                  (Xdistance1*Xdistance1)+(Ydistance1*Ydistance1) < (r*r) ||
                  (Xdistance3*Xdistance3)+(Ydistance3*Ydistance3) < (r*r) ||
                  (Xdistance4*Xdistance4)+(Ydistance4*Ydistance4) < (r*r)
              ){
                img[b*cols + a] = color;
              }

            }
          }
}
