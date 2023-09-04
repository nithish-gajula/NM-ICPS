
all : tcpserver.o tcpclient.o
	echo "Server and client ready."
tcpserver.o : 
	gcc tcpserver.c -o tcpserver
tcpclient.o :
	gcc  tcpclient.c -o tcpclient
	
clean:
	rm -r tcpclient tcpserver

wireshark : 
	sudo wireshark
