#pragma once
#include <iostream>
//global bit2cash array
//lookup table for faster processing of the cash requests
unsigned short g_bit2cash[32][10];

//populate global array with values
void initBit2Cash() {
	int i = 0;
	int j = 0;
	unsigned int val;
	
	for (i = 0; i < 32; i++) {
		//set val equal to the bit being calculated
		val = 0x01 << i;
		//calculate how many bills this will need
		for (j = 0; j < 10; j++) {
			//while val is larger than this bill value, subtract the value and add a bill to the 
			while (val >= g_denominations[j]) {
				g_bit2cash[i][j]++;
				val = val - g_denominations[j];
			}
		}
		if (val != 0) {
			std::cout << "ERROR: initBit2Cash: val doesn't equal 0. It equals" <<val<< std::endl;
		}
	}
}
//calculate the direct cash equivalent of the input number given the lookup table
void num2Cash(unsigned int num, unsigned short cashArray[]) {
	int i = 0;
	int j = 0;
	for (j = 0; j < 10; j++) {
		cashArray[j] = 0;
	}
	//check each bit in the number to see if it is high
	for (i = 0; i < 32; i++) {
		if (num & (0x01 << i)) {
			//add calculated bills to the out array
			for (j = 0; j < 10; j++) {
				cashArray[j] = cashArray[j] + g_bit2cash[i][j];
			}
		}
	}
	return;
}
//consolidate the bills upward
void consolBills(unsigned short cashArray[]) {
	int i = 0;
	//array for keeping track of how many pieces of currency in the currency one larger than it
	for (i = 9; i > 0; i--) {
		while ((cashArray[i]*g_denominations[i]) >= g_denominations[i - 1]) {
			cashArray[i] = cashArray[i] - (g_denominations[i - 1]/g_denominations[i]);
			cashArray[i - 1]++;
			std::cout << "I am adding to cash array" << cashArray[i] << std::endl;
		}
	}
}