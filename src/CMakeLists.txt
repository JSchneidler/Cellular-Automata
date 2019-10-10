INCLUDE_DIRECTORIES(${Cellular-Automata_SOURCE_DIR})
INCLUDE_DIRECTORIES(${Cellular-Automata_SOURCE_DIR}/include)

ADD_EXECUTABLE(Cellular-Automata App.cpp CellularAutomata.cpp RootWindow.cpp LeftPanel.cpp Grid.cpp)
