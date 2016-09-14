#include<stdio.h>
int main(){
	printf("%lu %lu %lu %lu %lu %lu %lu %lu %lu\n", 
	8*sizeof(char), 
	8*sizeof(unsigned char), 
	8*sizeof(int), 
	8*sizeof(unsigned int), 
	8*sizeof(long), 
	8*sizeof(unsigned long), 
	8*sizeof(float), 
	8*sizeof(double), 
	8*sizeof(long double));
	return 0;
}

