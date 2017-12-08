default: c

link.o: Link.cpp Link.h
	g++ -c Link.cpp -o link.o

node.o: Node.cpp
	g++ -c Node.cpp -o node.o

c.o: c.cpp Link.h
	g++ -c c.cpp -o c.o

c: c.o link.o node.o
	g++ c.o link.o node.o -o c

clean:
	-rm -f c.o
	-rm -f link.o
	-rm -f node.o
	-rm -f c
