#include<stdio.h>
#include <math.h>
int main(){
	int scanTester = 0;
	float a = 0.0;
	scanTester = scanf("%f", &a);
	while (scanTester == 1){
		int b = floorf(a);
		int c = roundf(a);
		int d = ceilf(a);
		printf("%d %d %d\n", b,c,d);
		scanTester = scanf("%f", &a);
	}
	if(scanTester == EOF){
		printf("Done.\n");
	}
	else{
		printf("scanf error: (%d)\n", scanTester);			
	}
}
