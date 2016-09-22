int identical(int a[], int b[], unsigned int len){
  int i = 0;
  for(i; i<len; i++){
    if(a[i]!=b[i]){
      return 0;
    }
  }
  return 1;
}
