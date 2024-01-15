all : timer run

timer : timer.cpp
	g++ -o timer timer.cpp

run :
	clear
	./timer


