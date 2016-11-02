#include<stdint.h>
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
                  //printArray(array, cols, rows);    }
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
