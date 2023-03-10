//amanda yun akyun@ucsc.edu 1903241 pa6

#include<iostream>
#include<string>
#include "List.h"
#include "BigInteger.h"
#include <sstream>
#include <iomanip>



const ListElement base = 1000000000;
const int power = 9;


long removeZeros(long k){
	
	
	std::string str_number = std::to_string(k);
	
	str_number.erase(str_number.length()-9);

	
	
//	str_number.erase(str_number.find_last_not_of('0')+1, std::string::npos);
	
	long newNum = std::stol(str_number);
//	long newNum = std::stol(new_string);
	
	
	return newNum;
	
}

std::string checkQ(long x){
	std::string str_number = std::to_string(x);
	while(str_number.length()<9){
		str_number = str_number.insert(0, "0");
	}
	
	return str_number;
}

void normalize(List& L){


	ListElement carryIn, carryOut;
	ListElement q;
	ListElement x;
	ListElement c;
	if(L.length() > 0){
		L.moveBack();
	}
	//L.moveBack();
	carryOut=0;
	
//	while(L.position()>0){
//		carryIn = carryOut;
//		col = L.movePrev();
//		col+=carryIn;
//		if(col > base){
//			while(col>base){
//				col-=10000000000;
//				r++;
//			}
//		}
//	}
//	
	



//what i had before...	
	while(L.position()>0){
		x = L.movePrev();
		//changed from x<0
		if(x<-base){
			
//			q = x%1000000000;
//			
//			carryOut = removeZeros(x-q);
//			
//			L.eraseAfter();
//			L.insertAfter(q+10000000000);
			carryOut = -1;
			x+=1000000000;
			L.setAfter(x);
			//std::cout << "if x < 0: " << x << std::endl;
		}
		
		
		else if(x>base){ 			
			q = x%1000000000;
			
			carryOut = removeZeros(x-q);
	
			L.eraseAfter();
			
//			q = checkQ(q);
//			std::cout <<"after check: " << q << std::endl;
			
			L.insertAfter(q);
			//good but slow;
//			while(x>base){
//				carryOut++;
//				x-=1000000000;
//				L.eraseAfter();
//				L.insertAfter(x);
//			}

//			carryOut = 1;
//			x-=10000000000;
//			L.eraseAfter();
//			L.insertAfter(x);
			//**changed from setbefore to setafter
			//		L.setAfter(x);
			
			//L.setBefore(x);
		}else{
			carryOut = 0;
		}
		
		if(L.position()==0 && carryOut>0){
			L.insertBefore(carryOut);
			break;
		}else if(L.position() ==0 && carryOut<1){
			break;
		}
		carryIn = carryOut;
		c = L.peekPrev();
		c+=carryIn;
		L.eraseBefore();
		L.insertBefore(c);
		carryOut = 0;
		//L.setBefore(c);
	}
	

	
}
//Mike's pseudocode
void shiftList(List& L, int p){
	L.moveBack();
	for(int i = 1; i<=p; i++){
		L.insertBefore(0);
		L.movePrev();
	}
}

void scalarMult(List& L, ListElement m){
	ListElement x;
	if(m!=1){
		L.moveFront();
		while(L.position() < L.length()){
			x = L.moveNext();
			if(x != 0){
//				L.eraseAfter();
//				L.insertAfter(x*m);
				L.eraseBefore();
				L.insertBefore(x*m);
				
			}
			
		}
		
	}
}

BigInteger::BigInteger(){
	signum = 0;
	List A;
	digits = A;
}

BigInteger::BigInteger(std::string s){
	if(s == ""){
		throw std::invalid_argument("Argument error: String S cannot be empty\n");
	}
	//check if s consists of at least base 10 digit {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}
	ListElement x;
	int n = s.length();
	int p = power;
	
	//check signs
	if(s[0] == '-'){
		signum = -1;
		s.erase(0, 1);
		n--;
	}else if(s[0] == '+'){
		signum = 1;
		s.erase(0, 1);
		n--;
	}else{
		signum = 1;
	}
	
	//get rid of leading 0's
	int i = 0;
	while(i<s.length() && s[i] == '0'){
		i++;
	}
	s.erase(0, i);
	//changed from s.length()>0
//	while(s[i]==0 && n>0){
//		s.erase(0, 1);
//		n--;
//		i++;
//	}
	if(s.length()==0){
		signum = 0;
	}
	
	for(int i = 0; i<s.length(); i++){
		if(!std::isdigit(s[i])){
			throw std::invalid_argument("Argument error: String s contains non-numerical characters\n");
		}
	}
	n = s.length();
	int r;
	if(s[0] != 0 && s.length()>0){
		r = n%p;
		for(int i = s.length()-p; i>=0; i-=p){
			x = std::stol(s.substr(i, p));
			this->digits.insertAfter(x);
			//this->digits.insertBefore(x);
		}
		if(r>0){
			//set x and cast the substring of "s" from 0->r
			//insert "x" into the digits list
			x = std::stol(s.substr(0, r));
			this->digits.insertAfter(x);
			//this->digits.insertBefore(x);
		}
		
	}

}

BigInteger::BigInteger(const BigInteger& N){
	this->signum = N.signum;
	List A;
	A = N.digits;
	this->digits = A;
}


int BigInteger::sign() const{
	return this->signum;
}

//return -1, 1, 0 whether BigInteger is less, greater or equal to N
//-1 if this is < N
//1 if "this" is greater than N
int BigInteger::compare(const BigInteger& N) const{
	int val;
	
//	if(this->sign() > N.sign()){
//		return 1;
//	}else if(this->sign() < N.sign()){
//		return 1;
//	}
	
	if(this->signum == 0 && N.signum == 0){
		return 0;
	}
//	if(this->signum>N.signum){
//		return 1;
//	}else if(this->signum<N.signum){
//		return -1;
//	}

	List L = this->digits;
	List R = N.digits;


	if(L.length()<R.length()){
		return -1;
	}else if(L.length()>R.length()){
		return 1;
	}
	
	L.moveFront();
	R.moveFront();
	
	while(L.position() < L.length() && R.position() < R.length()){
		int valL = L.moveNext();
		int valR = R.moveNext();
		if(valL < valR){
			return -1;
		}else if(valL > valR){

			return 1;
		}else{
			val = 0;
		}
	}


	if(val == 0){
		if(this->sign() > N.sign()){
			return 1;
		}else if(this->sign() < N.sign()){
			return -1;
		}
	}
	
	return val;
	
}

void BigInteger::makeZero(){
	//call clear 
	this->digits.clear();
	this->signum = 0;
}

void BigInteger::negate(){
	if(this->signum == 1){
		this->signum = -1;
	}else if(this->signum == -1){
		this->signum = 1;
	}
}

void sumList(List& s, List A, List B, int sgn){
	ListElement x;
	
	//performing addition
	//a***dd condition to check if length of A or B is 0

	if(sgn == 1){
	
		while(A.position() > 0 && B.position() > 0){
			x = A.movePrev() + B.movePrev();
			s.insertAfter(x);
		}
		if(A.position()>0 && B.position()==0){
			while(A.position()>0){
				x = A.movePrev();
				//s.insertBefore(x);
				s.insertAfter(x);
			}
			
		}else if(B.position()>0 && A.position()==0){
			while(B.position()>0){
				x = B.movePrev();
				//s.insertBefore(x);
				s.insertAfter(x);
				//**changed from insertafter to insertbefore
			}
		}
		
		
		normalize(s);
		//commented this out
		s.moveFront();
		while(s.position()<s.length()){
			x = s.peekNext();
			if(x<0){
				s.setAfter((-1)*x);
			}
			s.moveNext();
		}
		
	}else if(sgn == -1){
		B.moveFront();
		while(B.position()<B.length()){
			x = B.peekNext();
			B.setAfter((-1)*x);
			B.moveNext();
		}

		sumList(s, A, B, 1);
	}
}

bool checkZero(List s){
	ListElement x; 
	if(s.length() >0){
		s.moveFront();
		x= s.moveNext();
		if(x!=0){
			return false;
		}
	}
	return true;
}

BigInteger BigInteger::add(const BigInteger& N)const{
	BigInteger sum;
	ListElement x;
	List A, B;
	A = this->digits;
	B = N.digits;
	List& s = sum.digits;

	
	//s.moveBack();
	if(A.length()>0){
		A.moveBack();
	}
	if(B.length()>0){
		B.moveBack();
	}
//	A.moveBack();
//	B.moveBack();
	if(this->sign() == 1 && N.sign()==1){
		//add normally
		sumList(s, A, B, 1);
		
		sum.signum = this->sign();
	}else if(this->sign()==1 && N.sign() == -1){
		sumList(s, A, B, -1);
		//check which is bigger?
		//add or subtract?
		if(checkZero(s)){
			sum.signum = 0;
		}else if(this->compare(N)==1){
			sum.signum = this->sign();
		}else if(this->compare(N)==-1){
			sum.signum = N.sign();
		}else{
			sum.signum = 0;
		}
	}else if(this->sign() ==-1 && N.sign()==1){
		//-A+B = B-A
		sumList(s, B, A, -1);
		if(this->compare(N)==1){
			sum.signum = this->sign();
		}else if(this->compare(N)==-1){
			sum.signum = N.sign();
		}else{
			sum.signum = 0;
		}
	}else if(this->sign() == -1 && N.sign() == -1){
		//-A+(-B) = -A-B
		A.moveFront();
		while(A.position()<A.length()){
			x = A.peekNext();
			A.setAfter((-1)*x);
			A.moveNext();
		}
		sumList(s, A, B, -1);
		if(this->compare(N)==-1){
			sum.signum = this->sign();
		}else if(this->compare(N)==1){
			sum.signum = N.sign();
		}else{
			sum.signum = 0;
		}
	}
	//prepend
	


	normalize(s);
	
	
	return sum;

}

BigInteger BigInteger::sub(const BigInteger& N)const{
	BigInteger A  = BigInteger(N);
	A.negate();
	
	BigInteger diff;
	diff = this->add(A);
	

	
	//A-B
	if(this->sign() == 1 && N.sign()==1){
		if(this->compare(N)==1){
			diff.signum = this->sign();
		}else if(this->compare(N)==-1){
			diff.signum = -1;
		}else{
			diff.signum = 0;
		}
	}
	
	//A-(-B)
	if(this->sign() == 1 && N.sign() == -1){
		if(this->compare(N)==1){
			diff.signum = this->sign();
		}else if(this->compare(N)==1){
			diff.signum = this->sign();
		}else{
			diff.signum = 0;
		}
	}
	
	//-A-B
	if(this->sign() == -1 && N.sign() == 1){
		if(this->compare(N)==-1){
			diff.signum = this->sign();
		}else if(this->compare(N)==1){
			diff.signum = this->sign();
		}else{
			diff.signum = 0;
		}
	}
	
	//-A-(-B)
	if(this->sign() == -1 && N.sign() == -1){
		if(this->compare(N)==1){
			diff.signum = this->sign();
		}else if(this->compare(N)==-1){
			diff.signum = 1;
		}else{
			diff.signum = 0;
		}
	}
	//added this

	normalize(diff.digits);
	
	return diff;
}



//(tutor mike's pseudocode
BigInteger BigInteger::mult(const BigInteger& N)const{
	
	BigInteger prod;
	if(this->sign()==0|| N.sign() == 0){
		prod.signum = 0;
		return prod;
	}
	int col = 0;
	List A = this->digits;
	List B = N.digits;
	List C;
	ListElement x;
	
		
	List& P = prod.digits;

	
	if(this->sign() == -1 && N.sign() == -1){
		prod.signum = 1;
	}else if(this->sign() == 1 && N.sign() ==1){
		prod.signum = 1;
	}else if(this->sign() ==-1 || N.sign() == -1){
		prod.signum = -1;
	}else if(this->sign() == 0 || N.sign() == 0){
		prod.signum = 0;
	}
	
	
	B.moveBack();
	while(B.position() > 0){
		List k;
		C = A;
		x = B.movePrev();
		
		scalarMult(C, x);

		
		shiftList(C, col);
		
		if(P.length()>0){
			P.moveBack();
		}
		if(C.length()>0){
			C.moveBack();
		}
		sumList(k, C, P, 1);
		P=k;

		normalize(P);

		k.clear();
		col++;
	}
	
	return prod;
}


//normalize
/*
in sub, if negative then add 100 and carry -1

*/

std::string BigInteger::to_string(){
	ListElement x;
	std::string s;
	if(this->signum == -1){
		s.append("-");
	}else if(this->signum == 1){
		s.append("");
	}
	if(this->signum == 0){
		s.append("0");
	}else{
		
		//this->digits.moveBack();
		this->digits.moveFront();
		while(this->digits.position()<digits.length()){
			x = this->digits.moveNext();
			//s.append(std::to_string(x));
			std::ostringstream ss;
			ss << std::setw(power)<<std::setfill('0')<<x;
			s.append(ss.str());
		}
//		x = this->digits.peekPrev();
//		s.append(std::to_string(x));
//		this->digits.movePrev();
//		while(this->digits.position()>0){
//			x = this->digits.peekPrev();
//			s.append(std::to_string(x));
//			std::ostringstream ss;
//			ss << std::setw(power)<<std::setfill('0')<<x;
//		}
	}
	
	int i = 0;
	if(s[0]=='-'){
		i=1;
	}
	while(i<s.length() && s[i] == '0'){
		i++;
	}
	s.erase(0, i);
	
	if(this->signum == -1){
		s="-" + s;
	}else if(this->signum == 1){
		s ="" + s;
	}
	if(this->signum == 0){
		s="0"+s;
	}

//	s = s.substr(s.find_first_not_of('0'));
	return s;
}

std::ostream& operator<<(std::ostream& stream, BigInteger N){
	return stream << N.BigInteger::to_string();
}

bool operator==(const BigInteger& A, const BigInteger& B){
	return A.compare(B)==0;
	
}

bool operator<(const BigInteger& A, const BigInteger& B){
	return A.compare(B)==-1;
}

bool operator<=(const BigInteger& A, const BigInteger& B){
	return (A.compare(B)==-1 || A.compare(B)==0);
}

bool operator>(const BigInteger& A, const BigInteger& B){
	return A.compare(B)==1;
}

bool operator>=(const BigInteger& A, const BigInteger& B){
	return (A.compare(B)==1 || A.compare(B) == 0);
}

BigInteger operator+(const BigInteger& A, const BigInteger& B){
	return A.add(B);
}

BigInteger operator+=(BigInteger& A, const BigInteger& B){
	A = A.add(B);
	return A;
}

BigInteger operator-(const BigInteger& A, const BigInteger& B){
	return A.sub(B);
}

BigInteger operator-=(BigInteger& A, const BigInteger& B){
	A = A.sub(B);
	return A;
}

BigInteger operator*(const BigInteger& A, const BigInteger& B){
	return A.mult(B);
}

BigInteger operator*=(BigInteger& A, const BigInteger& B){
	A = A.mult(B);
	return A;
}