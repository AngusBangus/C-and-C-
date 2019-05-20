//  Created by John Villalvazo on 10/30/18.
//  Copyright © 2018 John Villalvazo. All rights reserved.

#include <iostream>
#include "BST.h"
#include "RandomSupport.h"
#include "BSTUtil.h"

using namespace std;

int main(int argc, const char * argv[]) {
    long n = 0;
    cin >> n;

    //myTree is equal to name root on lab report
    Node* myTree = NULL;

    randomizer device = new_randomizer();
    uniform_distribution dist = new_distribution(1, n);


    for(int i = 0; i < n;i++){
        long rand = sample(dist, device);
        myTree = insert(myTree, rand);
    }

    
    myTree = insertSpecialNumber(myTree);
    
    findSpecialNumber(myTree);

  //  cout << &myTree << endl;
}
