#include<stdint.h>
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

        if(k>=0 && i>=0){
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
