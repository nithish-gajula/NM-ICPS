all : udpserver.o udpclient.o
	echo "Server and client ready."
	
udpserver.o : udpserver.c
	gcc udpserver.c -o udpserver
	
udpclient.o : udpclient.c
	gcc  udpclient.c -o udpclient

clean:
	rm udpserver udpclient

wireshark : 
	sudo wireshark

