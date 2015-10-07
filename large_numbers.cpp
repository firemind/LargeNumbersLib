#include "large_numbers.h"
#include <vector>
#include <iostream>
#include <iterator>
#include <string>
#include <sstream>
#include <deque>
#include <string>
#include <algorithm>

const std::vector<std::vector<std::string>> numbers = {
		{
		" - ",
		"| |",
		"   ",
		"| |",
		" - "
		},
		{
		"   ",
		"  |",
		"   ",
		"  |",
		"   "
		},
		{
		" - ",
		"  |",
		" - ",
		"|  ",
		" - "
		},
		{
		" - ",
		"  |",
		" - ",
		"  |",
		" - "
		},
		{
		"   ",
		"| |",
		" - ",
		"  |",
		"   "
		},
		{
		" - ",
		"|  ",
		" - ",
		"  |",
		" - "
		},
		{
		" - ",
		"|  ",
		" - ",
		"| |",
		" - "
		},
		{
		"-- ",
		"  |",
		"   ",
		"  |",
		"   "
		},
		{
		" - ",
		"| |",
		" - ",
		"| |",
		" - "
		},
		{
		" - ",
		"| |",
		" - ",
		"  |",
		" - "
		},
		{
		"   ",
		"   ",
		" - ",
		"   ",
		"   "
		}

};

void printLargeDigit(int i, std::ostream &out){
	std::vector<std::string> chars = numbers.at(i);
	std::copy(chars.begin(), chars.end(), std::ostream_iterator<std::string>(out, "\n"));
}
void printLargeNumber(int i, std::ostream &out){
	printLargeNumber(i, out, 1);
}

void printLargeNumber(int i, std::ostream &out, int scale){

	/*	std::deque<int> digits;
	do{
		digits.push_front( i % 10);
		i /= 10;
	}while(i);*/

	std::string s = std::to_string(i);
	std::vector<int> digits (s.length());
	transform(s.begin(), s.end(), digits.begin(), [](char c){ return (c == '-') ? 10 : (c-'0');});

	int rows;
	for(auto j=0;j<5;j++){
		rows = (j == 1 || j == 3) ? scale : 1;
		for (auto k=0; k<rows; k++) {

			for(auto d : digits) {
				std::string seq = numbers.at(d).at(j);
				out << seq[0];
				for (int i=0; i<scale; i++) {
					out << seq[1];
				}
				out << seq[2];

			}
			out  << "\n";
		}
	}
}
