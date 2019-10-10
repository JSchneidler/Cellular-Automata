#pragma once

#include "App.h"
#include <array>

typedef std::array<std::array<int, ROW_LENGTH>, DEFAULT_ROWS + 1> t_cells;

class CellularAutomata
{
public:
	CellularAutomata(int rule);

	void execute();
	void reset();
	const t_cells& getCells() const;

private:
	int rule;
	t_cells cells;
};

