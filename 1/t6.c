#include<stdio.h>
#include<math.h>

int main(){
	float largestValue = -100000;
	float smallestValue = 100000;
	float total = 0.0; 
	float mean = 0.0;
	int counter = 1; 
	float enteredValue = 0.0;
	int scanTester = scanf ("%f", &enteredValue);
	while(scanTester == 1){
		if(enteredValue>largestValue){
			largestValue = enteredValue;
		}
		if(enteredValue<smallestValue){
			smallestValue = enteredValue; 
		}
		total+=enteredValue;
		mean = total/counter;
		counter++;
		scanTester = scanf ("%f", &enteredValue);
	}
	if(scanTester == EOF){
		printf("%.2f %.2f %.2f\n", smallestValue, largestValue, mean);
	}
}
