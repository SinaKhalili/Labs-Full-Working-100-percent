void draw_rectangle( uint8_t array[],
		          unsigned int cols,
		          unsigned int rows,
		          int x,
		          int y,
		          int rect_width,
		          int rect_height,
		          uint8_t color ){
      if (rect_height<0 && rect_width<0){
        //printf("both negatives!\n");
        x += rect_width;
        y += rect_height;
        draw_rectangle(array, cols, rows, x,y, abs(rect_width),abs(rect_height), color );

      }
      else if (rect_width<0 && rect_height>0){
        //printf("width negative!\n");
        x += rect_width;
        draw_rectangle(array, cols, rows, x,y, abs(rect_width),abs(rect_height), color );
      }
      else if (rect_height<0 && rect_width>0){
        //printf("height negative!\n");
        y += rect_height;
        draw_rectangle(array, cols, rows, x,y, abs(rect_width),abs(rect_height), color );
      }
      int i = y;
      int k = x;

     if(rect_height > 0 && rect_width > 0 ){
      for(i = y; i<=(y + rect_height); i++){

        array[i*cols+k] = color;


        for (k = x; k < (x + rect_width); k++){

          if( i == y || i == (y+rect_height)){

            array[i*cols+k] = color;

          }

        }


        array[i*cols+k] = color;

        k=x;
      }
    }
}
