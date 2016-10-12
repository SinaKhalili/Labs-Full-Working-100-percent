void reverse( int arr[], unsigned int len ){
  int i = 0;
  int tmp = 0;
  for(i; i<(len/2); i++){
    tmp = arr[i];
    arr[i] = arr[len-i-1];
    arr[len-i-1]=tmp;
  }
  return;
}
