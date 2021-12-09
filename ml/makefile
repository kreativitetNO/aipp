.PHONY=clean

clean:
	rm bin/*

tests: tests/KNearestNeighborTests.cpp
	g++ -o bin/KNearestNeighborTests -std=c++17 tests/KNearestNeighborTests.cpp -lgtest -lgtest_main -lpthread
