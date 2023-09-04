
all : tcpserver.o tcpclient.o
	echo "Server and client ready."
	
tcpserver.o : tcpserver.c
	gcc tcpserver.c -o tcpserver
	
tcpclient.o : tcpclient.c
	gcc  tcpclient.c -o tcpclient
	
clean:
	rm tcpserver tcpclient

wireshark : 
	sudo wireshark
