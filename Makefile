CFLAGS = -w -g
CC = g++

build: vertex.o edge.o graph.o main.o
	$(CC) $(CFLAGS) vertex.o edge.o graph.o main.o -o graph 

vertex.o: vertex.cpp
edge.o: edge.cpp
graph.o: graph.cpp
main.o: main.cpp

.PHONY: clean
clean:
	rm -f *~ a.out *.o
git:
	git add *.cpp *.h README.md Makefile
	git commit -m "Pushing to github from Makefile
	git push origin master
 
