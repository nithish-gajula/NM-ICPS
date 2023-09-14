all : tcpserver.o tcpclient.o
	echo "Server and client ready."
tcpserver.o : 
	gcc tcpserver.c -o tcpserver
tcpclient.o :
	gcc  tcpclient.c -o tcpclient

wireshark : 
	sudo wireshark
