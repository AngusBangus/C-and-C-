#include <iostream>
#include "TimeSupport.h"
#include "RandomSupport.h"

using namespace std;


struct Node {
    long data;
    Node* left;
    Node* right;
};


Node* insert(Node* root, long value){
    // If the tree I'm inserting into is empty
    if (root == NULL){
        // Make a new node and set it to be the root
        root = new Node;
        root->data = value;
        root->left = NULL;
        root->right = NULL;
    }
    else{
        if (value < root->data){
            // Go left
            root->left = insert(root->left, value);
        }
        else{
            // Go right
            root->right = insert(root->right, value);
        }
    }
    
    return root;
}


void traverse(Node* root){
    if (root != NULL){
        traverse(root->left);
        cout << root->data << endl;
        traverse(root->right);
    }
}


bool search(Node* root, long value){
    if (root == NULL){
        // Tree is empty
        return false;
    }
    else{
        // Tree is not empty
        if (root->data == value){
            return true;
        }
        else if (root->data < value){
            // Go to the right
            return search(root->right, value);
        }
        else {
            // Go left
            return search(root->left, value);
        }
    }
}


int main() {
    
    const long N = 10000000;
    
    const long K = 100000;
    
    
    Node* myTree = NULL;
    
    randomizer device = new_randomizer();
    uniform_distribution dist = new_distribution(1, N);
 
    
    timestamp start = current_time();
 
    for (long i = 0; i < N; i++) {
        long rand = sample(dist, device);
        myTree = insert(myTree, rand);
    }
    
    timestamp end = current_time();
    
    long insertDuration = time_diff(start, end);
    
 
    cout << "Took " << insertDuration << " ms" << endl;
   
    timestamp searchStart = current_time();
    for (long i = 0; i < K; i++) {
        bool temp = search(myTree, i);
    }
    
    timestamp searchEnd = current_time();
    
    long searchDuration = time_diff(searchStart, searchEnd);
    
    cout << "Searching Took " << searchDuration << " ms" << endl;
    return 0;
}
