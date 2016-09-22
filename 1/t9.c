#include<stdio.h>
#include<math.h>

int main(){
  float xValue = 0;
  float yValue = 0;
  float height = 0;
  int i = 0;
  int left = 0;
  int right =0;
  int k = 0;
  int j= 0;

  scanf("%f%f%f", &xValue, &yValue, &height);
  j = height-1;

  for(j; j>0; j--){
    left = floor( j * (xValue/(2.0*height)) );
    right = ceil( (xValue-1) + -j * (xValue/(2.0*height)) );
    for (k; k<left; k++){
      printf(" ");
    }
    k=0;
    if (j == height-1){
      for(k; k<right-left+1; k++){
        printf("#");
      }
      printf("\n");
    }
    else if (j != height-1){
      for(k; k<right-left-1; k++){
        printf("#");
        for(k; k<right-left-1; k++){
          printf(".");
        }
        printf("#\n");
      }

      }
      k = 0;
  }
  k = 0;
  for(k; k<xValue; k++){
    printf("#");
  }
  printf("\n");
}
































/*

  int incrementAndTopLayer = ceil(xValue/height);
  int spaceOnSide = (xValue-incrementAndTopLayer)/2;
  for(i ; i<incrementAndTopLayer; i++)
  {
    for(j ; j<spaceOnSide; j++)
    {
        printf(" ");
    }
    printf("#");
  }
  printf("\n");
  for(k; k<(height-2); k++)
  {
    incrementAndTopLayer += ceil(xValue/height);
    spaceOnSide = (xValue-incrementAndTopLayer)/2;
    i =0;
    j = 0;
    for (i; i< spaceOnSide; i++)
    {
      printf(" ");
    }
    printf("#");
    for (j ; j<(incrementAndTopLayer-2); j++){
      printf(".");
    }
    printf("#\n");
  }
  i=0;
  for(i; i<xValue; i++){
    printf("#");
  }
  printf("\n");

}
*/
