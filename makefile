all: main.o
	g++ -std=c++11 -Wno-deprecated -framework GLUT -framework OpenGL -framework Cocoa \
	main.o -o main
	
main.o: main.cpp
	g++ -std=c++11 -c main.cpp
	
clean:
	rm *.o main
