#pragma once

#include "App.h"
#include <vector>

typedef std::vector<std::vector<int>> t_cells;

class CellularAutomata
{
public:
	CellularAutomata(int rule, int rows);

	void execute();
	void setRule(const int rule);
	void setRows(const int rows);

	const t_cells* getCells() const;

private:
	void reset();
	void simulateCell(const int row_index, const int column);

	int rule;
	int rows;
	int row_length;
	t_cells cells;
};

