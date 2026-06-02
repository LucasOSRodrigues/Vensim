all:
	mkdir -p bin
	g++ -Wall -Wextra -std=c++11 test/*.cpp test/funcional/*.cpp src/*.cpp -o bin/funcional_tests
	g++ -Wall -Wextra -std=c++11 test/*.cpp test/unit/*.cpp src/*.cpp -o bin/unit_tests

tests: all
	./bin/funcional_tests
	./bin/unit_tests

funcional_test:
	mkdir -p bin
	g++ -Wall -Wextra -std=c++11 test/*.cpp test/funcional/*.cpp src/*.cpp -o bin/funcional_tests
	./bin/funcional_tests

unit_test: 
	mkdir -p bin
	g++ -Wall -Wextra -std=c++11 test/*.cpp test/unit/*.cpp src/*.cpp -o bin/unit_tests
	./bin/unit_tests

clean:
	rm -rf bin