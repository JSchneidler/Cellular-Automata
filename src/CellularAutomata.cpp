#include "CellularAutomata.h"
#include <algorithm>

CellularAutomata::CellularAutomata(int rule, int rows)
	: rule(rule)
	, rows(rows + 1)
	, row_length((rows * 2) + 1)
{
	execute();
}

void CellularAutomata::execute()
{
	reset();

	for (int row_index = 0; row_index < rows - 1; ++row_index)
		for (int column = 0; column < row_length; ++column) simulateCell(row_index, column);
}

void CellularAutomata::setRule(const int rule)
{
	this->rule = rule;
}

int CellularAutomata::getRule()
{
	return rule;
}

void CellularAutomata::setRows(const int rows)
{
	this->rows = rows + 1;
	this->row_length = (rows * 2) + 1;
}

int CellularAutomata::getRows()
{
	return rows;
}

const t_cells* CellularAutomata::getCells() const
{
	return &cells;
}

void CellularAutomata::reset()
{
	this->cells = t_cells(rows, std::vector<int>(row_length, 0));
	cells[0][row_length / 2] = 1;
}

void CellularAutomata::simulateCell(const int row_index, const int column)
{
	int rule_index = 0, mask = 1;

	if (column == 0)
	{
		rule_index = writeBit(rule_index, 2, cells[row_index][column]);
		rule_index = writeBit(rule_index, 3, cells[row_index][column + 1]);
		rule_index = writeBit(rule_index, 4, cells[row_index][column + 2]);
	}
	else if (column == 1)
	{
		rule_index = writeBit(rule_index, 1, cells[row_index][column - 1]);
		rule_index = writeBit(rule_index, 2, cells[row_index][column]);
		rule_index = writeBit(rule_index, 3, cells[row_index][column + 1]);
		rule_index = writeBit(rule_index, 4, cells[row_index][column + 2]);
	}
	else if (column == row_length - 2)
	{
		rule_index = writeBit(rule_index, 0, cells[row_index][column - 2]);
		rule_index = writeBit(rule_index, 1, cells[row_index][column - 1]);
		rule_index = writeBit(rule_index, 2, cells[row_index][column]);
		rule_index = writeBit(rule_index, 3, cells[row_index][column + 1]);
	}
	else if (column == row_length - 1)
	{
		rule_index = writeBit(rule_index, 0, cells[row_index][column - 2]);
		rule_index = writeBit(rule_index, 1, cells[row_index][column - 1]);
		rule_index = writeBit(rule_index, 2, cells[row_index][column]);
	}
	else {
		rule_index = writeBit(rule_index, 0, cells[row_index][column - 2]);
		rule_index = writeBit(rule_index, 1, cells[row_index][column - 1]);
		rule_index = writeBit(rule_index, 2, cells[row_index][column]);
		rule_index = writeBit(rule_index, 3, cells[row_index][column + 1]);
		rule_index = writeBit(rule_index, 4, cells[row_index][column + 2]);

	}

	mask <<= rule_index;
	cells[row_index + 1][column] = ((rule & mask) == 0) ? 0 : 1;
}

int CellularAutomata::writeBit(int number, int index, int value)
{
	if (index > 4) throw "Cannot write past 5th bit";

	value = value >= 1 ? 1 : 0;

	switch (index)
	{
		case 0:
			value <<= 4;
			break;
		case 1:
			value <<= 3;
			break;
		case 2:
			value <<= 2;
			break;
		case 3:
			value <<= 1;
			break;
	}

	number = number | value;
	return number;
}