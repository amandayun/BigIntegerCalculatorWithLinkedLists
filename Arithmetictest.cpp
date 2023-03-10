//amanda yun akyun@ucsc.edu 1903241 pa6

#include<iostream>
#include<string>
#include "List.h"
#include "BigInteger.h"
#include <fstream>
#include <string>
 

using namespace std;

int main() {
	
	
	ifstream inputFile("in1.txt");
	ofstream outputFile("out1.txt");
	string line;
	string firstNum;
	string secNum;
	
	int count = 0;
	while(count<3){
		getline(inputFile, line);
		if(!line.empty()){
			if(count == 0){
				firstNum = line;
			}else if(count == 2){
				secNum = line;
			}
			count++;
		}
	}
	BigInteger A = BigInteger(firstNum);
	BigInteger B = BigInteger(secNum);
	
	cout << "A = " << A << endl;
	cout << endl;
	cout << "B = " << B << endl;
	
	cout << endl;
	//A+B
	cout << "A + B = " << A+B << endl;
	
	cout << endl;
	//A-B
	cout << "A - B = " << A-B << endl;
	
	cout << endl;
	//A-A
	cout << "A - A = " << A-A << endl;
	
	cout << endl;
	//3A-2B
	BigInteger C = BigInteger("3");
	BigInteger D = BigInteger("2");
	A = A*C;
	B = B*D;
	cout << "3A - 2B = " << A-B << endl;
	
	cout << endl;

	
	A = BigInteger(firstNum);
	B = BigInteger(secNum);
	
	cout << "AB = " << A*B << endl;
	
	cout << endl;
	//A*A
	
	cout << "AA = " << A*A<< endl;
	
	
	cout << endl;

	cout<< "BB = " << B*B << endl;
	
	C = BigInteger("9");
	D = BigInteger("16");
	BigInteger g, h;
	
	BigInteger E;
	BigInteger F;
	E = A*A*A*A;
	F = B*B*B*B*B;
	
	//A = A*A
	//A = (A*A)*A
	//A = (A*A*A)*A
	h = E*C;
	g = F*D;
	
	cout << endl;
	cout << "E: " << E << endl;
	cout << "F: " << h << endl;
	cout << "F: " << g << endl;
	cout << "9A^4 + 16B^5 = " << h+g<< endl;


	long hu = -9877;
	long r = hu%100;
	
	cout << hu-r << endl;
	
	
	
	
	
	
	
	
	
	
	inputFile.close();
	outputFile.close();
	
	
	return 0;
	
	
	
	
//print in same order on their own line, separated by blank lines
	
}