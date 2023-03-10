#include<iostream>
#include<string>
#include<stdexcept>
#include "List.h"

using namespace std;

int main(){
	
	List A;
	
	//test insertAfter and insertBefore
	A.insertAfter(1);
	A.insertAfter(2);
	A.insertAfter(3);
	A.insertBefore(4);
	A.insertBefore(5);
	A.insertBefore(6);
	
	//test moving cursor and position
	A.moveFront();
	cout << "position = " << A.position() << endl;
	A.moveNext();
	cout << "position = " << A.position() << endl;
	A.moveNext();
	cout << "position = " << A.position() << endl;
	A.moveBack();
	cout << "position = " << A.position() << endl;
	
	//testing set and erase
	A.movePrev();
	A.setAfter(3);
	A.setBefore(8);
	A.eraseAfter();
	A.eraseBefore();
	
	//testing finds
	A.movePrev();
	A.movePrev();
	A.insertAfter(4);
	A.movePrev();
	A.findNext(4);
	A.findPrev(2);
	
	//testing cleanup
	A.cleanup();
	
	//testing concat
	List B;
	B.insertAfter(4);
	B.insertAfter(2);
	B.insertAfter(8);
	B.insertAfter(9);
	
	List C = B.concat(A);
	
	cout << "B and A concat: " << C << endl;
	
	//test length
	cout << "length of B: " << B.length() << endl;
	//test front()
	cout << "front: " << B.front() << endl;
	//test back()
	cout << "back: " << B.back() << endl;

	//test peekNext()
	cout << "peek next A: " << A.peekNext() << endl;
	//test peekPrev()
	cout << "peek prev A: " << A.peekPrev() << endl;
	//test equals
	cout << A.equals(B) << endl;

	//test clear()
	
	C.clear();

	
	cout << "A = " << A << endl;
	
	
	
	/*
	A.moveFront();
	A.insertAfter(2);
	A.moveBack();
	A.insertAfter(3);
	A.moveBack();
	
	
	A.insertAfter(4);
	cout << "elements = " << A.length() << endl;

	
	A.moveFront();
	A.insertBefore(4);
	cout << "position = " << A.position() << endl;

	cout << "value after moveNext() = " << A.moveNext() << endl;

	cout << "position = " << A.position() << endl;
	
	A.setAfter(77);
	
	A.moveBack();
	A.movePrev();
	
	A.setAfter(88);
	A.moveFront();
	A.eraseAfter();
	
	A.moveBack();
	A.eraseBefore();
	


	*/
	
	
	cout << endl;
	cout << "C = " << A << endl;
	cout << "position = " << A.position() << endl;
	cout << "length = " << A.length() << endl;

	return 0;

}