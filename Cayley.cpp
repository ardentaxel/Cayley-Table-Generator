#include "Cayley.h"
//#include "fort.hpp"
#include <iostream>
#include <iomanip>



Cayley::Cayley(){

}

Cayley::Cayley(int order, std::vector<int> operation, std::vector<int> set)
{
	_operation = operation;
	_set = set;
	_rows = order + 1;
	_cols = order + 1;
	makeTable();
	
}

Cayley::~Cayley() {
	for (auto r = 0; r < _rows; r++)
	{
		delete[] _table[r];
	}
	delete[] _table;
}

void Cayley::makeTable() {
	_table = new int* [_rows];
	for (auto r = 0; r < _rows; r++)
	{
		_table[r] = new int[_cols];
		for (auto c = 0; c < _cols; c++)
		{
			_table[r][c] = 0;
		}
	}
}

void Cayley::Cayley::drawTable() const {
	std::cout << "Set = {";
	for (auto i : _set)
	{
		std::cout << i << ",";
	}
	std::cout << "}" << std::endl;
	std::cout << "Binary operation: ";
	switch (_operation[0])
	{
		case MULTIPLICATION_MOD_N:
		{
			std::cout << "Multiplication mod " << _operation[1] << std::endl;
			break;
		}
		case ADDITION_MOD_N:
		{
			std::cout << "Addition mod " << _operation[1] << std::endl;
			break;
		}
	}
	for (auto r = 0; r < _rows; r++)
	{
		if (r == 1)
		{
			for (auto i = 0; i < _rows + 2; i++)
			{
				std::cout << std::setw(5);
				std::cout << "__________";
			}
		}
		
		std::cout << std::endl;
		for (auto c = 0; c < _cols; c++)
		{
			std::cout << std::setw(7);
			std::cout << _table[r][c] << "  ";
			if (c == 0)
			{
				std::cout << "| ";
			}
		}
		std::cout << std::endl;
	}
}

void Cayley::fillTable() {
	for (auto i = 1; i <= _set.size(); i++)
	{
		_table[0][i] = _set[i-1];
	}

	for (auto i = 1; i <= _set.size(); i++)
	{
		_table[i][0] = _set[i-1];
	}
}

int Cayley::multiplicationModN(int num1, int num2, int modulus)
{
	return ((num1 * num2) % modulus);
}

int Cayley::additionModN(int num1, int num2, int modulus)
{
	return ((num1 + num2) % modulus);
}

void Cayley::applyOperation() {
	int mod = _operation[1];
	switch (_operation[0])
	{
	case MULTIPLICATION_MOD_N:
	{
		int identityCounter = 0;
		for (auto r = 1; r < _rows; r++)
		{
			for (auto c = 1; c < _cols; c++)
			{
				int ans = multiplicationModN(_table[0][c], _table[r][0], mod);
				_table[r][c] = ans;
			}
		}
		break;
	}
	case ADDITION_MOD_N:
	{
		for (auto r = 1; r < _rows; r++)
		{
			for (auto c = 1; c < _cols; c++)
			{
				int ans = additionModN(_table[0][c], _table[r][0], mod);
				_table[r][c] = ans;
			}
		}
		break;
	}
	default:
	{

	}
	}
}







