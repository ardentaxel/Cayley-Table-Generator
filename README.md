# Cayley Table Generator
A C++ table that outputs a Cayley Table for for a given finite set under a binary operation. Can be used to determine if the set is a group under that binary operation.

A Cayley table describes the structure of a finite group by arranging all the possible products of all the group's elements in a square table reminiscent of an addition or multiplication table. Many properties of a group – such as whether or not it is abelian, which elements are inverses of which elements, and the size and contents of the group's center – can be discovered from its Cayley table.

## Installation

Simply place the .h and .cpp files in your src directory and #include the Cayley.h header where you wish to use it.

```c++
#include "Cayley.h"
```

## Usage case

```c++
int main() {
    
    /*Instantiate Cayley object with the following:
        - The order of the set
        - A vector with 2 elements. The first element is a 0 or 1 corresponding to multiplication mod n and addition mod n respectively. The second is the modulus
        - A vector whose elements are elements of the set you wish to generate a cayley table for. 
    */

	Cayley U13(12, {0,13}, {1,2,3,4,5,6,7,8,9,10,11,12});

    // Fill the table with the elements of the set
	cayley1.fillTable();

    // Apply the desired binary operation throughout.
	cayley1.applyOperation();

    // Output the table to the console
	cayley1.drawTable();
	
	return 0;
}
```
