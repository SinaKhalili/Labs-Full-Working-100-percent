#include<stdio.h>
#include<stdlib.h>

int main (){
  int a[80] = {};
  int i = 1;
  int scanTest = scanf("%d", &a[0]);

  while (scanTest != EOF && i<80){
    scanTest = scanf("%d", &a[i]);
    i++;
  }
  int numberOfThings = i-1;

  //printf("There are %d number of things in the array\n", numberOfThings);

  int k = 0;
  int greatest = 0;
  for (k; k< numberOfThings; k++){
    if (a[k] > greatest){
      greatest = a[k];
    }
  }
  //printf("The greatest number is %d\n", greatest );

  k = greatest;
  i = 0;

for (k ; k > 0; k--){
  for (i ; i < numberOfThings; i++){
    if(k-a[i]>0){
      printf(" ");
    }
    else if (k-a[i] <= 0){
      printf("#");
    }
  }
  i=0;
printf("\n");
}
}
