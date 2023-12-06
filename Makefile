all: a.out
	g++ -std=c++11 *.cpp -o a.out

clean:
	rm -f a.out

run: a.out
	./a.out