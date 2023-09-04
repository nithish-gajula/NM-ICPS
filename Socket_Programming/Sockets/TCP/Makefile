
all : tcpserver tcpclient
	echo "Server and client ready."
	
tcpserver : tcpserver.c
	gcc tcpserver.c -o tcpserver
	
tcpclient : tcpclient.c
	gcc  tcpclient.c -o tcpclient
	
clean:
	rm tcpserver tcpclient

wireshark : 
	sudo wireshark
