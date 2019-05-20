#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
	int lines;
	int typo;
	printf("Enter the number of lines for the punishment: ");
	scanf("%d", &lines);

	if(lines <= 0){
		printf("You entered an incorrect value for the number of lines!");
		return(0);
	}
	printf("Enter the line for which we want to make a typo: ");
	scanf("%d" , &typo);
	if (typo < 0 || typo > lines){
		printf("You entered an incorrect value for the typo: ");
		return(0);
	}
	for(int i = 0; i < lines; i++){
		if(i == typo-1){
			printf("C programming language is the bet!\n");
		}
		else{
			printf("C programming language is the best!\n");
		}}

return(0);
	}
	
