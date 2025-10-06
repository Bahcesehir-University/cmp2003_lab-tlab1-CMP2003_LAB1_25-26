all: clean test

helloWorldTest: test_hello_world.cpp catch_amalgamated.cpp main.cpp
	g++ -Wall --std=c++17 test_hello_world.cpp catch_amalgamated.cpp main.cpp -o helloWorldTest

test: helloWorldTest
	./helloWorldTest

clean:
	rm -f helloWorldTest
