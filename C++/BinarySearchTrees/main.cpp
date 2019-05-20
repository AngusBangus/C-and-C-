#include <iostream>
#include "BST.h"
#include "RandomSupport.h"
#include "BSTUtil.h"

using namespace std;




int main(int argc, const char * arg[]) {
    long n = 0;
    cin >> n;
    
    Node* myTree = NULL;
    
    
    randomizer device = new_randomizer();
    uniform_distribution dist = new_distribution(1, N);
    
    for ( int i = 0; i < n; i++){
        long rand = sample(dst, device)
        myTree = insert(myTree, rand);
    }
    
    
    
    
    
    myTree = insertSpecialNumber(root);
    
    findSpecialNumber(myTree);
    


   
}
