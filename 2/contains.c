#include<stdlib.h>

int main(int argc, char* argv[]) {

  int len1 = strlen(argv[1]);
  int len2 = strlen(argv[2]);

  int i = 0;
  int k = 0;
  int l = 0;
  int counter = 0;

  while((l<len1)){
    if(argv[1][l]==argv[2][i] && counter!=len2-1){
      counter++;
      i++;
      l++;
    }
    else if(argv[1][l]!=argv[2][i] && counter!=len2-1){
      counter = 0;
      i = 0;
      l++;
    }
    else if(counter==len2-1){
      l++;
    }
  }
  if(counter == len2-1){
    printf("true\n");
  }
  else if(counter != len2-1){
    printf("false\n");
  }
  return 0;
}
