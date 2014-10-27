exe:	main.o integer.o object.o tdalist.o node.o fsarraylist.o slinkedlist.o cursor.o slnode.o
	g++ main.o integer.o node.o object.o tdalist.o fsarraylist.o slinkedlist.o slnode.o cursor.o -o exe

main.o:	main.cpp tdalist.h integer.h fsarraylist.h slinkedlist.h cursor.h
	g++ -c main.cpp

integer.o:	integer.cpp integer.h object.h
	g++ -c integer.cpp

node.o:	node.cpp node.h
	g++ -c node.cpp

tdalist.o:	tdalist.h tdalist.cpp object.h
	g++ -c tdalist.cpp

cursor.o:	cursor.cpp cursor.h tdalist.h object.h
	g++ -c cursor.cpp

object.o:	object.h object.cpp
	g++ -c object.cpp

slnode.o:	slnode.cpp slnode.h
	g++ -c slnode.cpp

slinkedlist.o:	slinkedlist.cpp slinkedlist.h object.h tdalist.h
	g++ -c slinkedlist.cpp

fsarraylist.o:	fsarraylist.cpp fsarraylist.h object.h tdalist.h
	g++ -c fsarraylist.cpp

clean:
	rm *.o tda