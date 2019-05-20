#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Seconds.h"
#include "Support.h"

using namespace std;


int main(){
	int num1;
	int num2;
	int c =0;

	long N = 10000000;
	long searches = 1000;
	long* arr = new long[N];
	randomizer device = new_randomizer();
	uniform_distribution dist = new_distribution(1,N);
	timestamp insertStart = current_time();
	for (long i = 0; i < N; i++){
		
		long rand = sample(dist, device);
		arr[i] = rand;

	}
	timestamp insertEnd = current_time();
	cout << "Welcome to MathSkills!"<< endl;
	for (int i=0; i<=10; i++){
		num1 = (rand()%10)+1;
		num2 = (rand()%10)+1;
		timestamp start = current_time();
		cout << i << ". "<<num1<<" + "<< num2 << " = ";
		cin >> c;
		timestamp end = current_time();
	

		if ( c == num1 + num2){
			cout << "Correct! " <<endl;
			long duration = time_diff(start, end);
			long insertDuration = time_diff(insertStart, insertEnd);
			cout << "Took " << ( insertDuration /=1000) << " seconds to solve." << endl;

			}
			
		
		else{
			cout << "Incorrect!" <<endl;
			long duration = time_diff(start, end);
			long insertDuration = time_diff(insertStart, insertEnd);
			cout << "Took " << ( insertDuration /= 1000) << " seconds to solve." << endl;
		}
	}}
	