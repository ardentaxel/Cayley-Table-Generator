#pragma once
#include <vector>
class Cayley
{
public:
	Cayley();
	Cayley(int order, std::vector<int> operation, std::vector<int> set);

	enum OPERATIONS {
		MULTIPLICATION_MOD_N,
		ADDITION_MOD_N
	};
	int multiplicationModN(int num1, int num2, int modulus);
	int additionModN(int num1, int num2, int modulus);
	void drawTable() const;
	void fillTable();
	void applyOperation();

	std::vector<int> _set;
	~Cayley();

private:
	void makeTable();
	int _rows;
	int _cols;
	int** _table;
	std::vector<int> _operation;
	
};

