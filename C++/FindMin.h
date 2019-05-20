#ifndef FindMin_h
#define FindMin_h

// Declare and define the findMin function here
using namespace std;

int findMin (int N[],int x,int y){
  
 
    
    int minIndex = N[x];
    
    int p = x;
    
    for (int i = x; i < y; i++){
        
        if (N[i] < minIndex){
            minIndex = N[i];
            p = i;
       
}
    }
        return p;
        }

        
    
// Do not write any code below this line
#endif
