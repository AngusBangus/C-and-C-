#ifndef BSTOps_h
#define BSTOps_h

#include "BSTComplete.h"

int occurrences(Node* root, int value){
    int count = 0;
    
    if(root == NULL)
    {
        return 0;
    }
    
    if(root->data == value)
    {
        return 1 + occurrences(root->left,value) + occurrences(root->right,value);
    }
    
    else if(value < root->data)
    
    {
        return occurrences(root->left,value);
    }
    
    else
    {
        return occurrences(root->right,value);
    }
    return count;
}


#endif
