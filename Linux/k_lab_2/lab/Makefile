binary: main.o libf.so
	gcc -lpng -o binary main.o -L. -lf -Wl,-rpath,.

main.o: main.c
	gcc -c main.c

libf.so: f.o
	gcc -shared -o libf.so f.o

f.o: f.c
	gcc -c -fPIC f.c

clean:
	rm -f *.o *.so binary