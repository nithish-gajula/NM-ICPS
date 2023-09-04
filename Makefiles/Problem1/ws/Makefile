output: main.o funcA.o funcB.o funcC.o
	gcc main.o ./module1/funcA.o ./module2/funcB.o ./module3/funcC.o -o output

main.o:
	gcc -c main.c -o main.o

funcA.o:
	cd ./module1/ && make && cd ../
	
funcB.o:
	cd ./module2/ && make && cd ../
	
funcC.o:
	cd ./module3/ && make && cd ../
	
module1_clean:
	rm ./module1/funcA.o
	
module2_clean:
	rm ./module2/funcB.o
	
module3_clean:
	rm ./module3/funcC.o
	
clean:
	rm main.o output
	
clean_all:
	rm main.o output ./module1/funcA.o ./module2/funcB.o ./module3/funcC.o
