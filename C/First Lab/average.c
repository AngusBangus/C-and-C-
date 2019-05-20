/*
PSEUDOCODE:
while input does not equal 0
user inputs value 
if input is positive add input to positive average
otherwise add input to negative average

When input = 0
print out positive average if positive average is greater than 0
print out negative average if negative average is less than 0







*/

#include <stdio.h>


int main(){
	int input = 1;
	int pos_avg = 0;
	int neg_avg = 0;
	int pos_sum = 0;
	int neg_sum = 0;
	int pos_ctr = 0;
	int neg_ctr = 0;
	

	while(input != 0){
		printf("Please enter an integer: \n");
		scanf("%d", &input);
		
			if(input > 0){
				pos_ctr = pos_ctr + 1;
				pos_sum = (pos_sum + input);
				

			}
			if(input < 0){
				neg_ctr = neg_ctr + 1;
				neg_sum = (neg_sum + input);
				
			}
		}
	
	if(input == 0){

		
		
		if(pos_ctr > 0){
			pos_avg = pos_sum/pos_ctr;
			printf("Positive average: %d\n", pos_avg);

	}	
		if(neg_ctr > 0){
			neg_avg = neg_sum/neg_ctr;
			printf("Negative average: %d\n", neg_avg);
		}
		
		
	}

	return(0);
}








