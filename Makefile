CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11

BIN = bin
SRC = src

PRODUCT = $(BIN)/myvensim
FUNC_TESTS = $(BIN)/funcional_tests
UNIT_TESTS = $(BIN)/unit_tests

all: $(PRODUCT) $(FUNC_TESTS) $(UNIT_TESTS)

$(BIN):
	mkdir -p $(BIN)

$(PRODUCT): $(BIN) $(SRC)/main.cpp $(SRC)/mySim.cpp $(SRC)/mySim.h
	$(CXX) $(CXXFLAGS) $(SRC)/main.cpp $(SRC)/mySim.cpp -o $(PRODUCT)

$(FUNC_TESTS): $(BIN) test/funcional/main.cpp test/funcional/funcional_tests.cpp $(SRC)/mySim.cpp $(SRC)/mySim.h
	$(CXX) $(CXXFLAGS) test/funcional/main.cpp test/funcional/funcional_tests.cpp $(SRC)/mySim.cpp -o $(FUNC_TESTS)

$(UNIT_TESTS): $(BIN) test/unit/main.cpp test/unit/unit_tests.cpp $(SRC)/mySim.cpp $(SRC)/mySim.h
	$(CXX) $(CXXFLAGS) test/unit/main.cpp test/unit/unit_tests.cpp $(SRC)/mySim.cpp -o $(UNIT_TESTS)

run: $(PRODUCT)
	./$(PRODUCT)

run_funcional_tests: $(FUNC_TESTS)
	./$(FUNC_TESTS)

run_unit_tests: $(UNIT_TESTS)
	./$(UNIT_TESTS)

tests: run_funcional_tests run_unit_tests

clean:
	rm -f $(BIN)/*

.PHONY: all run run_funcional_tests run_unit_tests tests clean
