	#ifndef OpStack_h
	#define OpStack_h
	using namespace std;
	// Define the Link struct below...

	struct Link {
	    long data;
	    char op;

	    Link* next;

	};

	// Now define the Stack struct. It should be a stack of Links...

	struct Stack {
		Link* head;
		Link* tail;
		Stack(){head = tail = NULL;}

		void push (long new_data, char new_op){
			Link* node = new Link();
			node -> data = new_data;
			node -> op = new_op;
			node -> next = head;
			head = node;

			//cout << tail -> data << endl;
			//cout << tail -> op;
		}

		Link* pop (){
			if (!isEmpty()){

				Link* tmp = head;
				head = head -> next;
				return tmp;
			}
			return NULL;
		}
		

		bool isEmpty(){
		    if(head == NULL){
		        return true;
		    }
	        else {
	      	    return false;
		    }
		}
	    
	};

	#endif

