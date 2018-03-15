default: point

point.o: Point.cpp Point.h
	g++ -c Point.cpp -o point.o

main.o: main.cpp Point.h
	g++ -c main.cpp -o main.o

point: main.o point.o
	g++ main.o point.o -o point

clean:
	-rm -f *.o
	-rm -f point
