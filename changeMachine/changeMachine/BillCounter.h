#pragma once
#include <iostream>
using namespace std;

//predefine denominations array
extern unsigned int g_denominations[];

//prints the array to the console in a readible fashion
void printCash(unsigned short c[]) {
	//print all values in this "cash" instance to console
	cout << "+++++++++++++++++++++++++++++++++++++++++++" << endl;
	cout << "Hundreds:" << c[0] << endl;
	cout << "Fifties:" << c[1] << endl;
	cout << "Twenties:" << c[2] << endl;
	cout << "Tens:" << c[3] << endl;
	cout << "Fives:" << c[4] << endl;
	cout << "Ones:" << c[5] << endl;
	cout << "Quarters:" << c[6] << endl;
	cout << "Dimes" << c[7] << endl;
	cout << "Nickels:" << c[8] << endl;
	cout << "Pennies:" << c[9] << endl;
	cout << "+++++++++++++++++++++++++++++++++++++++++++" << endl;
}

//Calculates the least amount of bills needed to equal the number input
void countBills(unsigned int num, unsigned short outputArray[]) {
	int j = 0;
	for (j = 0; j < 10; j++) {
		outputArray[j] = 0;
	}
	//calculate how many bills this will need
	for (j = 0; j < 10; j++) {
		//while val is larger than this bill value, subtract the value and add a bill to the 
		while (num >= g_denominations[j]) {
			outputArray[j]++;
			num = num - g_denominations[j];
		}
	}
}
