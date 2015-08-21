CXX = g++

#compile Targets

all:
	$(CXX) trieTree.cpp trieTest.cpp -o trieTest
	$(CXX) main.cpp trieTree.cpp wordCount.cpp -o main
