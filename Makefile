all:
	mkdir -p bin
	g++ -Wall -Wextra -std=c++11 src/*.cpp test/funcional/*.cpp -o bin/funcional_tests
	g++ -Wall -Wextra -std=c++11 src/*.cpp test/unit/*.cpp test/funcional/flow_types.cpp -o bin/unit_tests

tests: all
	./bin/funcional_tests
	./bin/unit_tests

funcional:
	mkdir -p bin
	g++ -Wall -Wextra -std=c++11 src/*.cpp test/funcional/*.cpp -o bin/funcional_tests
	./bin/funcional_tests

unit:
	mkdir -p bin
	g++ -Wall -Wextra -std=c++11 src/*.cpp test/unit/*.cpp test/funcional/flow_types.cpp -o bin/unit_tests
	./bin/unit_tests

clean:
	rm -rf bin
