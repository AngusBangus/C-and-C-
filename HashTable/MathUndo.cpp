#include <iostream>
#include "OpStack.h"

using namespace std;

int main(){
	char choice;
	Stack s;
	long total = 0,num1;
	Link *popped;

	while(true){
		cin >> choice;
		if(choice == 'a'){
			cin >> num1;
			total += num1;
			s.push(num1, 'a');
			cout << "Total: " << total << endl;
		}else if(choice == 's'){
			if(!s.isEmpty()){
				cin >> num1;
				total -= num1;
				s.push(num1, 's');
				cout << "Total: " << total << endl;
			}
		}else if(choice == 'z'){
			popped = s.pop();
			if(popped == NULL){
				cout << "Nothing to undo..." << endl;
				cout << "Total: " << total << endl;
			}else{
				if(popped->op == 'a'){
					total = total - popped->data;
					cout << "Total: " << total << endl;
				}else if(popped->op == 's'){
					total = total + popped->data;
					cout << "Total: " << total << endl;
				}
			}
		}else if(choice == 'q'){
			return 0;
		}
	}	
}
