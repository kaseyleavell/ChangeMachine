#include "BillCounter.h"

using namespace std;

void printCash(unsigned short c[]);
void countBills(unsigned int num, unsigned short outputArray[]);

unsigned int g_denominations[10] = { 10000,5000,2000,1000,500,100,25,10,5,1 };

int main() {
	//initialize variables
	unsigned int number;
	float inputNumber;
	unsigned short outputArray[10];

	while (1) {
		//request input
		cout << "Pease enter the amount you would like to change to bills:" << endl;
		cin >> inputNumber;

		//check input value to see if it is valid
		if (inputNumber > 42949672.95) {
			cout << "This number is too large for the current system to process, please input a number less than 42949672.95" << endl;
			cin >> inputNumber;
		}
		else if (inputNumber < 0) {
			cout << "This number is a negative number, there is no such thing as negative cash! Please input a positive number" << endl;
			cin >> inputNumber;
		}

		//caste float input to int for quicker processing
		number = (unsigned int)(inputNumber * 100);
		
		//calc bill output
		countBills(number, outputArray);
		
		//write output to console
		printCash(outputArray);
	}
	return 0;
}
