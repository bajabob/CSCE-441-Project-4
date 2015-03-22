all: ant_leg.o ant_body.o ant.o main.o
	g++ -std=c++11 -Wno-deprecated -Wdeprecated-declarations -framework GLUT -framework OpenGL -framework Cocoa \
	main.o ant.o ant_body.o ant_leg.o -o main

ant.o: ant.cpp
	g++ -std=c++11 -c ant.cpp

ant_body.o: ant_body.cpp
	g++ -std=c++11 -c ant_body.cpp

ant_leg.o: ant_leg.cpp
	g++ -std=c++11 -c ant_leg.cpp
	
main.o: main.cpp
	g++ -std=c++11 -c main.cpp
	
clean:
	rm *.o main
