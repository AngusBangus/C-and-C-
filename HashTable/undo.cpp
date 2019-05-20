#include <iostream>
#include "OpStack.h"

using namespace std;

int main(int argc, const char * argv[]) {
	Stack* myStack = new Stack();
	char input;
	bool run = true;
	long number;
	long total = 0;

	while(run){
		cin >> input;
		switch(input){
			case 'a' :
				cin >> number;
				total += number;
				cout << "Total: " << total << endl;
				myStack->push(number, input);
				break;
			case 's' :
				cin >> number;
				total -= number;
				cout << "Total: " << total << endl;
				myStack->push(number, input);
				break;
			case 'z' :
				Link* undo;
				if(!myStack->isEmpty()){
					undo = myStack->pop();
					char op = undo->op;

					if(op == 'a'){
						total -= undo->data;
						cout << "Total: " << total << endl;
					}
					else if(op == 's'){
						total += undo->data;
						cout << "Total: " << total << endl;
					}
				}
				else{
					cout << "Nothing to undo..." << endl;
				}

				break;
			case 'q' :
				run = false;
				cout << "Total: " << total << endl;
				break;

			default:
				return 0;
				break;
		}
	}
	return 0;
}