#include "CellularAutomata.h"
#include <algorithm>

CellularAutomata::CellularAutomata(int rule)
{
	this->rule = rule;
	execute();
}

void CellularAutomata::reset()
{
	std::array<int, ROW_LENGTH> cols{};
	cells.fill(cols);
}

void CellularAutomata::execute()
{
	cells[0][ROW_LENGTH / 2] = 1;
}

const t_cells& CellularAutomata::getCells() const
{
	return cells;
}
