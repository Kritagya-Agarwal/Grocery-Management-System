all: grocery

grocery: main.o linkedlist.o items.o fruits.o vege.o helper.o
	g++ main.o linkedlist.o items.o fruits.o vege.o helper.o -o grocery

main.o: main.cpp
	g++ -c main.cpp

linkedlist.o: linkedlist.cpp
	g++ -c linkedlist.cpp

items.o: items.cpp
	g++ -c items.cpp

fruits.o: fruits.cpp
	g++ -c fruits.cpp

vege.o: vege.cpp
	g++ -c vege.cpp

helper.o: helper.cpp
	g++ -c helper.cpp

clean:
	rm *.o grocery
