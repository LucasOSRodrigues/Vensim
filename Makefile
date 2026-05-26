all:
	mkdir -p bin
	g++ -Wall -Wextra -std=c++11 test/funcional/*.cpp src/*.cpp -o bin/funcional_tests
	g++ -Wall -Wextra -std=c++11 test/unit/*.cpp src/*.cpp -o bin/unit_tests

test: all
	./bin/funcional_tests
	./bin/unit_tests

clean:
	rm -rf bin