prog: main.o
	g++ -o run main.o
main.o: main.cpp heap.h
	g++ -c -std=c++11 main.cpp -g

clean:
	rm -f run main.o
rebuild:
	make clean
	make
