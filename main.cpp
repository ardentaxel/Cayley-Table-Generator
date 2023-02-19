#include <iostream>
#include "Cayley.h"
using namespace std;


int main() {

	Cayley cayley1(12, {0,13}, {1,2,3,4,5,6,7,8,9,10,11,12});
	cayley1.fillTable();
	cayley1.applyOperation();
	cayley1.drawTable();
	
   


	return 0;
}