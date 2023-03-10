//amanda yun akyun@ucsc.edu 1903241 pa6

#include<iostream>
#include<string>
#include "List.h"
#include "BigInteger.h"
 

using namespace std;

int main(int argc, char *argv[]) {
	
	BigInteger A, B, C, D, E;
	BigInteger x, y, z;
	
	A = BigInteger("-221211110000");
	B = BigInteger("-112122223333");
	
	
	cout << "testing add, sumList and normalize: " << A+B << endl;
	cout << "testing sub, sumList and normalize: " << A-B << endl;
	cout << "testing mult, scalMult, sumList and normalize: " << A*B << endl;
	
	cout << "testing operations: " << endl;
	
	
	if(A<B){
		cout << "A<B"<< endl;
	}else {
		cout << "B>A"<<endl;
	}
	
	if(A<=B){
		cout << "A<=B"<< endl;
	}else {
		cout << "B>A"<<endl;
	}
	
	if(A>B){
		cout << "A>B"<< endl;
	}else {
		cout << "B<A"<<endl;
	}
	
	if(A>=B){
		cout << "A>=B"<< endl;
	}else {
		cout << "B<A"<<endl;
	}
	
	if(A==B){
		cout << "A==B"<< endl;
	}else {
		cout << "B!=A"<<endl;
	}
	
	A+=B;
	cout << "A+=B" << A << endl;
	
	A = BigInteger("-221211110000");
	
	A-=B;
	cout << "A-=B" << A << endl;
	
	A = BigInteger("-221211110000");
	
	
	A*=B;
	cout << "A*=B" << A << endl;
	
	cout << "sign of A: " << A.sign() << endl;
	


	


//	cout << B*A << endl;
//	cout << A.sign() << endl;
	

	//if A is less than B : -1
	//if A is greater than B: 1

	

}