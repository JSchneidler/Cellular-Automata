#include "CellularAutomata.h"
#include <algorithm>

CellularAutomata::CellularAutomata(int rule, int rows)
{
	this->rule = rule;
	this->rows = rows + 1;
	this->row_length = (rows * 2) + 1;

	execute();
}

void CellularAutomata::execute()
{
	reset();
}

void CellularAutomata::setRule(const int rule)
{
	this->rule = rule;
}

void CellularAutomata::setRows(const int rows)
{
	this->rows = rows;
}

const t_cells* CellularAutomata::getCells() const
{
	return &cells;
}

void CellularAutomata::reset()
{
	this->cells = t_cells(rows, std::vector<int>(row_length, 0));

	cells[0][row_length / 2] = 1;

	for (int row_index = 0; row_index < rows - 1; ++row_index)
		for (int column = 0; column < row_length; ++column) simulateCell(row_index, column);
}

void CellularAutomata::simulateCell(const int row_index, const int column)
{
	cells[row_index + 1][column] = 1;
}
