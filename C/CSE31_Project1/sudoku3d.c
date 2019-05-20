#include <stdio.h>
#include <stdlib.h>

// Declare printSudoku function
void printSudoku(int***);
// Declare solveSudoku function

int column (int *** blocks, int i, int j, int num){
    if(i%3 == 0){  
        i=0;  
    }
    else if ( i%3 == 1){
        i=1;       
    }
    else{
        i=2;   
    }

    for( i; i<9; i+=3){ 
        for( int k =0; k<3; k++){ 
            if(  *(*(*(blocks+ i)+k)+j)   == num  ){ 
                return 1;  // 
            } 
        }
    }

    return 0;
}

int row (int *** blocks, int b, int k, int num){
   if (b<3){
       b=0;
       for( int i=b; i<3; i++){ 
         for(int j =0; j<3; j++) {
             if(   blocks[i][k][j]  == num  ){   
                 return 1;
             }
         }
     }
 }
 else if(b>=3 && b<6){
   b=3;
   for( int i=b; i<6; i++){ 
     for(int j =0; j<3; j++) {
         if(   blocks[i][k][j]  == num  ){   
             return 1;
         }
     }
 }
}    

else if (b>=6 && b<9){
   b=6;
   for( int i=b; i<9; i++){ 
    for(int j =0; j<3; j++) {
        if(   blocks[i][k][j]  == num  ){   
            return 1;
        } 
    }
}
}
return 0;
}

int square(int *** blocks, int i, int num){
    for(int k = 0; k< 3; k++){
        for(int j = 0; j<3; j++){
            if(  blocks[i][k][j] == num  ){
                return 1;
            }
        }
    }
    return 0;
}

int StillZero(int*** blocks){
    int i =0, j=0, k =0, a=0;
    for(i=0; i<9; i++){
        for(j=0; j<3; j++){
            for(k=0; k<3; k++){
                a = *(*(*(blocks+i)+j)+k);
                if(a == 0){
                    return 0;
                }
            }
        }
    }
    return 1;
}

int legal(int ***blocks, int i, int k, int j, int num){
    if(!column(blocks, i, j, num) && !row(blocks, i, k,num) && !square(blocks, i, num)   ){
        return 1;
    }
    else{
       return 0;
   }
}

/*
The main program reads a text file containing the block values of the Sudoku grid.
It then saves each 3x3 block into a 2D array. The Sudoku grid is composed of 9 3x3 blocks.
DO NOT MODIFY THE MAIN FUNTION!!!
*/
int main(int argc, char **argv) {
	if (argc != 2) {
		fprintf(stderr, "Usage: %s <file name>\n", argv[0]);
		return 2;
	}
    int i, j;
    FILE *fptr;
    int ***blocks = (int***)malloc(9 * sizeof(int**));

    // Open file for reading
    fptr = fopen(argv[1], "r");
    if (fptr == NULL) {
        printf("Cannot Open File!\n");
        return 0;
    }

	// Read 9x9 blocks into 2D arrays
    for(i=0; i<9; i++)
    {
        *(blocks+i) = (int**)malloc(3 * sizeof(int*));
        printf("Reading numbers in block %d... \n", i+1);
        for(j=0; j<3; j++)
        {
            *(*(blocks+i)+j) = (int*)malloc(3 * sizeof(int));

            fscanf(fptr, "%d %d %d", *(*(blocks+i)+j), *(*(blocks+i)+j)+1, *(*(blocks+i)+j)+2);
            printf("%d %d %d\n", *(*(*(blocks+i)+j)), *(*(*(blocks+i)+j)+1), *(*(*(blocks+i)+j)+2));
        }
    }

	// Print out original Sudoku grid
    printf("Printing Sudoku before being solved:\n");
    printSudoku(blocks);

	// Call solveSudoku and print out result
    printf("\nSolving Sudoku...\n\n");
    if(solveSudoku(blocks)){
        printf("Sudoku solved!\n");
        printSudoku(blocks);
    }
    else
        printf("This Sudoku cannot be solved!\n");

    return 0;
}


void printSudoku(int*** arr){
	// This function will print out the complete Sudoku grid (arr). It must produce the output in the SAME format as the samples in the instructions. 	
	int i =0, j = 0;
    for(i =0; i < 9; i++){
        for(j=0; j<3; j++){ 
            printf("%d %d %d |" , *(*(*(arr+i)+j)), *(*(*(arr+i)+j)+1), *(*(*(arr+i)+j)+2)); 
            printf("%d %d %d |" , *(*(*(arr+i+1)+j)), *(*(*(arr+i+1)+j)+1), *(*(*(arr+i+1)+j)+2));
            printf("%d %d %d |\n", *(*(*(arr+i+2)+j)), *(*(*(arr +i+2)+j)+1), *(*(*(arr +i+2)+j)+2));
        }
        printf("---------------------\n");
        i = i+ 2;
    }
    printf("");
}
int solveSudoku(int*** blocks){
	// This is the function to solve the Sudoku (blocks). Feel free to use any helper functions.
    if(StillZero(blocks)){
        return 1;
    }
    for(int i =0; i <9; i++){
        for(int j=0; j<3; j++){
            for(int k=0; k<3; k++){
                if( *(*(*(blocks+i)+j)+k) == 0 ){

                    for(int num =1; num<=9; num++){
                        int checkit;
                        if(legal(blocks, i, j,k,num)){
                            *(*(*(blocks+i)+j)+k) =num;
                            if(solveSudoku(blocks)){
                                return 1;
                            }
                        }

                    }
                    *(*(*(blocks+i)+j)+k)=0;
                    return 0;
                }
            }
        }
    }
    return 1;
}
