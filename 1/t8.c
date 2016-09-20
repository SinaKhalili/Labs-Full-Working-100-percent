#include<stdio.h>
#include<math.h>
int main(){
  int xValue = 0;
  int yValue = 0;
  int bValue = 0;
  int i = 0;
  int c = 0;
  int scanTester = scanf("%d%d%d",&xValue, &yValue, &bValue );
  while(scanTester != EOF){
    for (i; i < xValue; i++) {
      printf("#");
    }
    printf("\n");
    i = 0;

    for(i; i<(yValue-2); i++){
      printf("#");
      for(c; c<(xValue-2); c++){
        printf(".");
      }
      printf("#\n");
      c = 0;
    }
    i = 0;
    if (!(yValue<2)){
      for (i; i < xValue; i++) {
        printf("#");
      }
      printf("\n");
    }

    scanTester = scanf("%d%d%d\n",&xValue, &yValue, &bValue );
  }
}
