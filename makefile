all:
	
	g++ -c llist.cpp
	g++ -c listcode.cpp
	g++ llist.o listcode.o 

clean:

	rm a.out