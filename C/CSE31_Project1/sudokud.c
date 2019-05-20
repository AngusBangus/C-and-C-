#include <stdio.h>
#include <stdlib.h>

// Declare printSudoku function
void printSudoku(int ***);
// Declare solveSudoku function
int solveSudoku(int ***);

//Helper functions. You can define any functions that can help your solve the problem

int isDone(int ***block){
    //1 is done, 0 is not done
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            for (int k = 0; k < 8; k++){
                if (*(*(*(block + j) + i) + k) == 0){
                    return 0;
                }
            }
        }
    }
    return 1;
}

int squareArg(int ***block, int num, int i, int j){
    //1 if there is conflict, 0 if no conflict
    //Checks each square for conflict
    for (int k = 0; k < 9; k++){
        if (*(*(*(block + k) + i) + j) == num){
           return 1;
        }
    }
    return 0;
}

int checkRCArg(int ***block, int num, int i, int j){
    //Check row and col for occurence of num
    //1 if another occurence [FALSE], 0 if no others [TRUE]
    int count = 0;
    //Checks row
    for(int k = 0; k < 9; k++){
        if(*(*(*(block+k)+i)) == num){
            return 1;
        }
    }
    //Checks col
    for (int k = 0; k < 9; k++){
        if ((*(*(*(block + k)) + j)) == num)
            return 1;
        }
    return 0;
}

/*
The main program reads a text file containing the block values of the Sudoku grid.
It then saves each 3x3 block into a 2D array. The Sudoku grid is composed of 9 3x3 blocks.
DO NOT MODIFY THE MAIN FUNTION!!!
*/
int main(int argc, char **argv){
    if (argc != 2){
        fprintf(stderr, "Usage: %s <file name>\n", argv[0]);
        return 2;
    }
    int i, j;
    FILE *fptr;
    int ***blocks = (int ***)malloc(9 * sizeof(int **));

    // Open file for reading
    fptr = fopen(argv[1], "r");
    if (fptr == NULL){
        printf("Cannot Open File!\n");
        return 0;
    }

    // Read 9x9 blocks into 2D arrays
    for (i = 0; i < 9; i++){
        *(blocks + i) = (int **)malloc(3 * sizeof(int *));
        printf("Reading numbers in block %d... \n", i + 1);
        for (j = 0; j < 3; j++){
            *(*(blocks + i) + j) = (int *)malloc(3 * sizeof(int));

            fscanf(fptr, "%d %d %d", *(*(blocks + i) + j), *(*(blocks + i) + j) + 1, *(*(blocks + i) + j) + 2);
            printf("%d %d %d\n", *(*(*(blocks + i) + j)), *(*(*(blocks + i) + j) + 1), *(*(*(blocks + i) + j) + 2));
        }
    }

    // Print out original Sudoku grid
    printf("Printing Sudoku before being solved:\n");
    printSudoku(blocks);

    // Call solveSudoku and print out result
    printf("\nSolving Sudoku...\n\n");
    if (solveSudoku(blocks)){
        printf("Sudoku solved!\n");
        printSudoku(blocks);
    }
    else
        printf("This Sudoku cannot be solved!\n");

    return 0;
}

void printSudoku(int ***arr){
    // This function will print out the complete Sudoku grid (arr). It must produce the output in the SAME format as the samples in the instructions.

    // Your implementation here
    //Need to print
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            for (int k = 0; k < 3; k++){
                printf("%d ", *(*(*(arr + j) + i) + k));
            }
        }
        printf("\n");
    }
    for (int i = 0; i < 3; i++){
        for (int j = 3; j < 6; j++){
            for (int k = 0; k < 3; k++){
                printf("%d ", *(*(*(arr + j) + i) + k));
            }
        }
        printf("\n");
    }
    for (int i = 0; i < 3; i++){
        for (int j = 6; j < 9; j++){
            for (int k = 0; k < 3; k++){
                printf("%d ", *(*(*(arr + j) + i) + k));
            }
        }
        printf("\n");
    }
}

int solveSudoku(int ***blocks)
{
    // This is the function to solve the Sudoku (blocks). Feel free to use any helper functions.
    // YOU MUST NOT USE ANY ARRAY NOTATION ([])!

    //Your implementation here
    int num;
    if (isDone(blocks) == 1){ //Zero case
        printf("I am here!");
        return 0;
    }
    else{
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 9; j++){
                for (int k = 0; k < 3; k++){
                    for(num = 1; num < 10; num++){
                        if(*(*(*(blocks+k)+i)+j) == 0){
                            if(checkRCArg(blocks, num, i, j) == 0 && squareArg(blocks, num, i, j) == 0){
                                *(*(*(blocks+k)+i)+j) = num;
                                if(solveSudoku(blocks) == 0){
                                    return 0;
                                }
                                else{
                                    *(*(*(blocks+k)+i)+j) = 0;
                                }         
                            }
                        }
                    }
                }
            }
        }
    }
    return 1;
}
