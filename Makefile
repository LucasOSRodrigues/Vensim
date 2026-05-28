all:
	mkdir -p bin
	g++ -Wall -Wextra -std=c++11 test/*.cpp test/funcional/*.cpp src/*.cpp -o bin/funcional_tests

test: all
	./bin/funcional_tests

clean:
	rm -rf bin