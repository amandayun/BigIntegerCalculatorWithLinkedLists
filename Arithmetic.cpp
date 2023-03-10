//amanda yun akyun@ucsc.edu 1903241 pa6

#include<iostream>
#include<string>
#include "List.h"
#include "BigInteger.h"
#include <fstream>
 

using namespace std;

int main(int argc, char* argv[]) {
	if(argc < 3){
		cerr << "Error: Input file name not specified" << endl;
		return 1;
	}
	
	ifstream inputFile(argv[1]);
	ofstream outputFile(argv[2]);
	string firstNum;
	string secNum;
	string line;
	
	//get the values
	int count = 0;
	while(count<3){
		getline(inputFile, line);
		if(count==0){
			firstNum = line;
		}else if(count == 2){
			secNum = line;
		}
		count++;
	}
	
//A, B, A+B, A-B, A-A, 3A-2B, AB, A^2, B^2 9A^4+16B^5
	BigInteger A = BigInteger(firstNum);
	BigInteger B = BigInteger(secNum);
	
	outputFile << A << endl;
	outputFile << endl;
	outputFile << B << endl;
	
	outputFile << endl;
	outputFile << A+B << endl;
	
	outputFile << endl;
	outputFile << A-B << endl;
	
	outputFile << endl;
	outputFile << A-A << endl;
	
	outputFile << endl;
	BigInteger C = BigInteger("3");
	A = A*C;
	C = BigInteger("2");
	B = B*C;
	outputFile << A-B << endl;
	
	A = BigInteger(firstNum);
	B = BigInteger(secNum);
	outputFile << endl;
	outputFile << A*B << endl;
	
	outputFile << endl;
	outputFile << A*A << endl;
	
	outputFile << endl;
	outputFile << B*B <<endl;
	
	C = BigInteger("9");
	BigInteger D = BigInteger("16");
	BigInteger g, h;
	
	BigInteger E;
	BigInteger F;
	E = A*A*A*A;
	F = B*B*B*B*B;
	h = E*C;
	g = F*D;
	
	
	outputFile << h+g << endl;
	
	
	
	
	
	inputFile.close();
	outputFile.close();
		
	return 0;
	
	
	
	
//print in same order on their own line, separated by blank lines
	
}