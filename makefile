

all: main Creator Reporter

main: main.cpp
	g++ main.cpp -o main

Creator:  Creator.cpp
	g++ Creator.cpp -o Creator

Reporter: Reporter.cpp
	g++ Reporter.cpp -o Reporter