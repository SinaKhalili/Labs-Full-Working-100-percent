#include<stdio.h>
#include <math.h>

int main(){
	int scanTester = 0;
	float a = 0.0;
	scanTester = scanf("%f", &a);
	if (scanTester == 1){
		int b = floorf(a);
		int c = roundf(a);
		int d = ceilf(a);
		printf("%d %d %d\n", b,c,d);
			return 0;
	}
	else{
		printf("scanf error: (%d)\n", scanTester);
			return 0;			
	}
}
