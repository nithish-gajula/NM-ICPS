output: file1.o file2.o file3.o main.o
	gcc file1.o file2.o file3.o main.o -o output

file1.o:
	gcc -c file1.c -o file1.o

file2.o:
	gcc -c file2.c -o file2.o

file3.o:
	gcc -c file3.c -o file3.o

main.o:
	gcc -c main.c -o main.o

clean:
	rm -r file1.o file2.o file3.o main.o