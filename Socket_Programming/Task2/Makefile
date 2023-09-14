all : server.o client.o
	echo "Server and client ready."
server.o : 
	gcc server.c -o server
client.o :
	gcc  client.c -o client

wireshark : 
	sudo wireshark
