#include <iostream>
#include <string>
#include <stdexcept>
#include "List.h"

using namespace std;
//create a node
List::Node::Node(ListElement x){ 
	data = x;
//	next = NULL;
//	prev = NULL;
	next = nullptr;
	prev = nullptr;
}

//create a list of nodes
List::List(){
	frontDummy = new Node(-900000);
	backDummy = new Node(900000);
	
//	frontDummy->next = backDummy;
//	frontDummy->prev = nullptr;
//	
//	backDummy->prev = frontDummy;
//	backDummy->next= nullptr;
	
	frontDummy->next = backDummy;
	backDummy->prev = frontDummy;
	
	beforeCursor = frontDummy;
	afterCursor = backDummy;
	
//	beforeCursor->next = backDummy;
//	afterCursor->prev = frontDummy;
//	
	pos_cursor = 0;
	num_elements = 0;

}

List::List(const List& L){
	
	frontDummy = new Node(-900000);
	backDummy = new Node(900000);	
	
	frontDummy->next = backDummy;
	backDummy->prev = frontDummy;
	
	
	beforeCursor = frontDummy;
	afterCursor = backDummy;
	pos_cursor = 0;
	num_elements = 0;
	
//	
//	frontDummy = nullptr;
//	backDummy = nullptr;
	Node* N = L.frontDummy->next;
	while(N!=L.backDummy){
		this->insertBefore(N->data);
		N=N->next;
	}
	

}


List::~List(){
	if(num_elements == 0){
		delete frontDummy;
		delete backDummy;
	}else{
		Node* temp = frontDummy->next;
		while(temp!=backDummy){
			Node* n = temp->next;
			delete temp;
			num_elements--;
			temp = n;
		}
		
		delete frontDummy;
		delete backDummy;

	}
//
//	Node* temp = frontDummy->next;
//	while(temp!=backDummy){
//		Node* n = temp->next;
//		delete temp;
//		num_elements--;
//		temp = n;
//	}

	//num_elements = 0;

}

int List::length() const{
	//cout << "num: " << num_elements << endl;
	return num_elements;
}


ListElement List::front() const{
	if(this->length()==0){
		throw std::length_error("List Error: calling front() on an empty list\n");
	}
	return this->frontDummy->next->data;

}

ListElement List::back() const{
	if(this->length()==0){
		throw std::length_error("List Error: calling back() on an empty list\n");
	}
	return this->backDummy->prev->data;
}

int List::position() const{
	return(pos_cursor);
}

///   9 0 0 0|1 9 

ListElement List::peekNext() const{
	return afterCursor->data;
}
ListElement List::peekPrev() const{
	return beforeCursor->data;
}


void List::clear(){
	if(this->length()>0){
		Node* temp = this->frontDummy->next;
		while(temp!=backDummy){
			Node* newtemp = temp->next;
			delete temp;
			temp = newtemp;
			num_elements--;
		}
	}
//	Node* temp = this->frontDummy->next;
//	while(temp!=backDummy){
//		Node* newtemp = temp->next;
//		delete temp;
//		temp = newtemp;
//		num_elements--;
//	}
	
	pos_cursor = 0;
}


void List::insertAfter(ListElement x){
	Node* N = new Node(x);
	
	N->prev = beforeCursor;
	N->next = afterCursor;
	beforeCursor->next = N;
	afterCursor->prev = N;
	afterCursor = N;
	num_elements++;
	

//	if(num_elements==0){
//		N->next = afterCursor;
//		N->prev=beforeCursor;
//		beforeCursor->next = N;
//		backDummy->prev = N;
//		afterCursor = N;
//
//	}else if(num_elements == pos_cursor){
//		N->prev = beforeCursor;
//		N->next = afterCursor;
//		backDummy->prev->next = N;
//		backDummy->prev = N;
//		
//		beforeCursor = N;
//		
//	}else{
//		N->next=afterCursor;
//		N->prev=beforeCursor;
//		beforeCursor->next=N;
//		afterCursor = N; 
//		afterCursor->prev = N->prev;
//		
//	}
//	num_elements++;
}
//0 1 2 3 | 0


void List::insertBefore(ListElement x){
	
	Node* N = new Node(x);
	
	
	N->prev = beforeCursor;
	N->next = afterCursor;

	beforeCursor->next = N;
	afterCursor->prev = N;
	beforeCursor = N;
	
	num_elements++;
	pos_cursor++;
	
//	if(this->length()==0){
//		frontDummy->next = N;
//		backDummy->prev = N;
//		N->next=backDummy;
//		N->prev=frontDummy;
//	}
//	
//	if(pos_cursor==0){
//		N->prev = frontDummy;
//		N->next = frontDummy->next;
//		frontDummy->next = N;
//		beforeCursor = frontDummy;
//		afterCursor = N;
//	}else{
//		N->next=afterCursor;
//		N->prev=beforeCursor;
//		beforeCursor->next=N;
//		afterCursor->prev = N;
//		beforeCursor = N;
//		afterCursor = N->next;
//	}
	
	
}

//0 1 2 3 5 | 12 0

void List::eraseAfter(){
	if(this->length()==0){
		throw std::length_error("List Error: calling eraseAfter() on an empty list\n");
	}
	
	if(this->position()==this->num_elements){
		throw std::length_error("List Error: calling eraseAfter() when afterCursor is backDummy\n");
	}
	
	if(this->position()!=this->num_elements){
		Node* N = afterCursor;
		
		//afterCursor = afterCursor->next;
		afterCursor = N->next;
		afterCursor->prev = beforeCursor;
		beforeCursor->next = afterCursor;
//		if(this->length()==1){
//			frontDummy->next = nullptr;
//			backDummy->prev = nullptr;
//		}else{
//			afterCursor = afterCursor->next;
//			afterCursor->prev = beforeCursor;
//			beforeCursor->next = afterCursor;
//		}
	
		num_elements--;
		delete N;
	}
// 0   9  | 0	

	
}


void List::eraseBefore(){
	if(this->length()==0){
		throw std::length_error("List Error: calling eraseBefore() on an empty list\n");
	}
	if(this->position()==0){
		throw std::length_error("List Error: calling eraseBefore() when afterCursor is frontDummy\n");
	}
	
	Node* N = beforeCursor;
	beforeCursor = N->prev;
	beforeCursor->next = afterCursor;
	afterCursor->prev = beforeCursor;
	pos_cursor--;
	
	
//	if(this->length()==1){
//		frontDummy->next = nullptr;
//		backDummy->prev = nullptr;
//	}else{
//		beforeCursor->prev->next = afterCursor;
//		beforeCursor = beforeCursor->prev;
//		afterCursor->prev = beforeCursor;
//	}
//	
	num_elements--;
	delete N;
	
}
///   9 0  0 0 9 


int List::findNext(ListElement x){
	if(this->length()==0){
		throw std::length_error("List Error: calling findNext() on an empty list\n");
	}
	
	//finds the position of the next element with the same value of x starting from the current cursor position
	
	//find first instance of x

	
	//cout << "pos: " << this->position() << endl;
//	moveNext();
//	N= N->next;
//	N = afterCursor;
//
//	while(N!=this->backDummy){
//		if(N->data == x){
//			end = this->position();
//	//		cout << "second occurrence: " << end << endl;
//
//			break;
//		}
//		moveNext();
//		N = N->next;
//	}
//	
//	return end-start;
	
	
//	if(pos_cursor!=this->length()){
//		while(start<this->length()){
//			if(beforeCursor->data == x){
//				this->moveNext();
//				end = pos_cursor;
//				break;
//			}
//			moveNext();
//		}
//		
//		return end-start;
//	}
	
	Node* N = afterCursor;
	while(N!=backDummy){
		if(N->data == x){
			this->moveNext();
			return pos_cursor;
		}
		this->moveNext();
		N=N->next;
	}
	
	

	
	
//	if(pos_cursor!=this->length()){
//		while(pos_cursor<this->length()){
//			if(beforeCursor->data == x){
//				this->moveNext();
//				return pos_cursor;
//			}
//			moveNext();
//		}
//	}
	

	
	return -1;
	
}

int List::findPrev(ListElement x){
	if(this->length()==0){
		throw std::length_error("List Error: calling findNext() on an empty list\n");
	}
	
	//finds the position of the next element with the same value of x starting from the current cursor position
	
	if(pos_cursor!=0){
		while(pos_cursor>0){
			if(beforeCursor->data == x){
				this->movePrev();
				return pos_cursor;
			}
			movePrev();
		}
	}
	

	
	return -1;
	
}

void List::moveFront(){
	if(this->length()==0){
		throw std::length_error("List Error: calling moveFront() on an empty list\n");
	}
	
	pos_cursor = 0;
	beforeCursor = frontDummy;
	afterCursor = frontDummy->next;
	
}

void List::moveBack(){
	if(this->length()==0){
		throw std::length_error("List Error: calling moveBack() on an empty list\n");
	}
	pos_cursor = num_elements;
	beforeCursor = backDummy->prev;
	afterCursor = backDummy;
	
}

ListElement List::moveNext(){
	if(this->length()==0){
		throw std::length_error("List Error: calling moveNext() on an empty list\n");
	}
	
	
	pos_cursor++;
	Node* N = afterCursor;
	beforeCursor = beforeCursor->next;
	afterCursor = afterCursor->next;
	
	return N->data;

}

//0 1 2 3 5 | 12 0

ListElement List::movePrev(){
	if(this->length()==0){
		throw std::length_error("List Error: calling movePrev() on an empty list\n");
	}
	
	pos_cursor--;
	Node* N = beforeCursor;
	
	beforeCursor = beforeCursor->prev;
	afterCursor = afterCursor->prev;
	
	return N->data;
}

void List::setAfter(ListElement x){
	if(this->length()==0){
		throw std::length_error("List Error: calling setAfter() on an empty list\n");
	}

	afterCursor->data = x;
	
}

void List::setBefore(ListElement x){
	if(this->length()==0){
		throw std::length_error("List Error: calling setBefore() on an empty list\n");
	}
	if(this->position()==0){
		throw std::length_error("Position Error: calling setBefore() when position of cursor is 0\n");
	}
	
	beforeCursor->data = x;
}

bool List::equals(const List& R) const{
	
	Node* N = nullptr;
	Node* M = nullptr;
	
	if(this->length() != R.length()){
		return false;
	}
	N = this->frontDummy->next;
	M = R.frontDummy->next;
	while(N!=backDummy){
		if(N->data!=M->data){
			return false;
		}
		N = N->next;
		M = M->next;
	}
	
	return true;

	
	
}





std::string List::to_string() const{
	
	Node* N = nullptr;
	std::string s;
	if(this->length() == 0){
		s+="()";
		return s;
	}
	s+="(";
	for(N=frontDummy->next; N!=backDummy->prev; N=N->next){
		s+=std::to_string(N->data)+", ";
	}
	//N=N->next;
	s+=std::to_string(N->data);
	s+=")";
	return s;
	
}



std::ostream& operator<< (std::ostream& O, const List& L){
	
	//prints the list like in pa3
	//calls to string on every node
	
	//return O<<L.List::to_string();
	
	
	return O << L.List::to_string();
}


bool operator==( const List& A, const List& B){
	return A.List::equals(B);
}

List& List::operator=(const List& L){
	
	if(this!=&L){
		List temp = L;
	
	
	std::swap(frontDummy, temp.frontDummy);
	std::swap(backDummy, temp.backDummy);
	std::swap(beforeCursor, temp.beforeCursor);	
	std::swap(afterCursor, temp.afterCursor);	
	std::swap(pos_cursor, temp.pos_cursor);
	std::swap(num_elements, temp.num_elements);
	
	}
	
	return *this;
	
//	if(this!= &L){
//		List temp = L;
//		
//		Node* t = this->frontDummy->next;
//		while(t != nullptr){
//			Node* next = t->next;
//			delete t;
//			t = next;
//		}
//		
//		this->frontDummy->next = nullptr;
//		this->backDummy->prev = nullptr;
//		
//		t = L.frontDummy->next;
//		
//		while(t!=nullptr){
//			insertAfter(t->data);
//			t = t->next;
//		}
//		
//		return *this;
//	
//	}
	
	
}


List List::concat(const List& L) const{
	//returns a new List with the same elements of this list followed by the elements of the List L
	//set cursor to 0 and return this long list
	List C;
//	if(this->length()==0 && L.length()>0){
//		return L;
//	}
	
	Node* N = this->frontDummy->next;

	while(N!=this->backDummy){
		int d = N->data;
		C.insertAfter(d);
		N = N->next;


	}
	
	Node* k = L.frontDummy->next;
	while(k!=L.backDummy){
		int d = k->data;
		C.insertAfter(d);
		k=k->next;
	}
	
	C.pos_cursor = 0;

	
	return C;
	
}


void List::cleanup(){
	//deletes all duplicates
	/*
	for(each node)
		for(each node after i)
			if i==k
				deleteNode(k) //or erase
	*/

	int toFind;
	int pos1 = 0;
	int pos2 = 0;

	Node* temp = this->frontDummy->next;
	Node* temp2;
	while(temp!=backDummy){
		temp2 = temp->next;
		pos2 = pos1+1;
		while(temp2!=backDummy){
			toFind = temp2->data;
			if(temp->data == toFind){
				if(temp2==beforeCursor){
					beforeCursor = beforeCursor->prev;
				}else if(temp2 == afterCursor){
					afterCursor = afterCursor->next;
				}
				Node* t = temp2;
				t->next->prev = t->prev;
				t->prev->next = t->next;
				temp2 = temp2->prev;
				
				delete t;
				
				
//				temp2->prev->next = t->next;
//				temp2->next->prev = t->prev;
//				temp2 = temp2->prev;
//				delete temp2;
				if(pos2<pos_cursor){
					pos_cursor--;
				}
				
				num_elements--;
				pos2--;
	
			}
			pos2++;
			temp2 = temp2->next;
	
		}
		temp = temp->next;
		pos1++;
	}
	
//	int counter = 0;
//	Node* N = this->frontDummy->next;
//	while(N!=backDummy){
//		if(N->data == valBefore && N->next->data == valAfter){
//			this->pos_cursor = counter;
//			break;
//		}
//		N= N->next;
//		counter++;
//	}

//	Node* temp = this->frontDummy;
//	Node* temp2;
//	for(int i = 0; i<num_elements; i++){
//		temp = temp->next;
//		temp2 = temp;
//		for(int k = i; k<num_elements; k++){
//			temp2 = temp2->next;
//			if(temp->data == temp2->data){
//				delete temp2;
//				num_elements--;
//				pos_cursor--;			
//			}
//		}
//	}
}



/*
move next
aftercursor = aftercursor.next
beforecursor = beforecursor.next
increase cursor value by one

if at the beginning then beforecursor points to dummyfront
and if at the end then aftercursor points to dummback

*/