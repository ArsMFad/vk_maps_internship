# Компилятор и флаги
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Iinclude
LDFLAGS = -pthread

# Пути к Google Test
GTEST_DIR = /usr/lib
GTEST_LIBS = $(GTEST_DIR)/libgtest.a $(GTEST_DIR)/libgtest_main.a

# Директории
SRC_DIR = src
GTEST_SRC_DIR = gtest
OBJ_DIR = bin
BIN_DIR = bin
INCLUDE_DIR = include

# Исходные файлы
GRAPH_SRC = $(SRC_DIR)/graph.cpp
MAIN_SRC = $(SRC_DIR)/main.cpp
TEST_SRC = $(GTEST_SRC_DIR)/tests.cpp

# Объектные файлы
GRAPH_OBJ = $(OBJ_DIR)/graph.o
MAIN_OBJ = $(OBJ_DIR)/main.o
TEST_OBJ = $(OBJ_DIR)/tests.o

# Цели
all: $(BIN_DIR)/main $(BIN_DIR)/tests

# Сборка основной программы
$(BIN_DIR)/main: $(MAIN_OBJ) $(GRAPH_OBJ)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $(MAIN_OBJ) $(GRAPH_OBJ)

# Сборка тестов
$(BIN_DIR)/tests: $(TEST_OBJ) $(GRAPH_OBJ)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $(TEST_OBJ) $(GRAPH_OBJ) $(GTEST_LIBS)

# Правило для компиляции .cpp файлов в .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(GTEST_SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Очистка
clean:
	rm -rf $(OBJ_DIR)/*.o $(BIN_DIR)/main $(BIN_DIR)/tests

# Запуск тестов
test: $(BIN_DIR)/tests
	$(BIN_DIR)/tests

# Запуск основной программы
run: $(BIN_DIR)/main
	$(BIN_DIR)/main graph.txt

.PHONY: all clean test run