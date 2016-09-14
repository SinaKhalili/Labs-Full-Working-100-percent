#include<stdio.h>
#include <math.h>

int main(){
	float a = 0.0;
	scanf("%f", &a);
	int b = floorf(a);
	int c = roundf(a);
	int d = ceilf(a);
	printf("%d %d %d\n", b,c,d);
	return 0;
}
