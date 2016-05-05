driver: main.cpp graph.o vertex.o
	g++ main.cpp graph.o vertex.o -o driver

graph.o: graph.cpp graph.h
	g++ -c graph.cpp

vertex.o: vertex.cpp vertex.h
	g++ -c vertex.cpp

clean:
	rm -rf *.o driver