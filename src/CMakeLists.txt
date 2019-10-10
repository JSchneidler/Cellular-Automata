INCLUDE_DIRECTORIES(${Cellular-Automata_SOURCE_DIR})
INCLUDE_DIRECTORIES(${Cellular-Automata_SOURCE_DIR}/include)

SET (wxWidgets_CONFIGURATION mswud)
FIND_PACKAGE (wxWidgets COMPONENTS core base REQUIRED)
INCLUDE (${wxWidgets_USE_FILE})

ADD_EXECUTABLE(Cellular-Automata App.cpp CellularAutomata.cpp RootWindow.cpp LeftPanel.cpp Grid.cpp)
TARGET_LINK_LIBRARIES (${PROJECT_NAME} ${wxWidgets_LIBRARIES})
