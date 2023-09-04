output: add_sub.o mul_div.o main.o
	gcc add_sub.o mul_div.o main.o -o output
	
add_sub.o:
	gcc -c add_sub.c -o add_sub.o
	
mul_div.o:
	gcc -c mul_div.c -o mul_div.o
	
main.o:
	gcc -c main.c -o main.o

clean:
	rm -r add_sub.o mul_div.o main.o
	

