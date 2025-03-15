CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Iinclude
LDFLAGS = -pthread


GTEST_DIR = /usr/lib
GTEST_LIBS = $(GTEST_DIR)/libgtest.a $(GTEST_DIR)/libgtest_main.a


SRC_DIR = src
GTEST_SRC_DIR = gtest
OBJ_DIR = bin
BIN_DIR = bin
INCLUDE_DIR = include


GRAPH_SRC = $(SRC_DIR)/graph.cpp
MAIN_SRC = $(SRC_DIR)/main.cpp
TEST_SRC = $(GTEST_SRC_DIR)/tests.cpp


GRAPH_OBJ = $(OBJ_DIR)/graph.o
MAIN_OBJ = $(OBJ_DIR)/main.o
TEST_OBJ = $(OBJ_DIR)/tests.o


all: $(BIN_DIR)/main $(BIN_DIR)/tests


$(BIN_DIR)/main: $(MAIN_OBJ) $(GRAPH_OBJ)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $(MAIN_OBJ) $(GRAPH_OBJ)


$(BIN_DIR)/tests: $(TEST_OBJ) $(GRAPH_OBJ)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $(TEST_OBJ) $(GRAPH_OBJ) $(GTEST_LIBS)


$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(GTEST_SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@


clean:
	rm -rf $(OBJ_DIR)/*.o $(BIN_DIR)/main $(BIN_DIR)/tests


test: $(BIN_DIR)/tests
	$(BIN_DIR)/tests


run: $(BIN_DIR)/main
	$(BIN_DIR)/main graph.txt

.PHONY: all clean test run