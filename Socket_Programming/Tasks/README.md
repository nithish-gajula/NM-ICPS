Wireshark:
	Wireshark is a network packet analyzer.It captures network traffic on the network and we can filter the data, we can store that data for analysis.It captures network traffic on the local network and stores that data for offline analysis. Wireshark is an open source software project, and is released under the GNU General Public License (GPL).

How to Install Wireshark?
1) $ sudo apt update
2) $ sudo apt install wireshark

Note: Apply either display filter or capture filter to filter the network packets. For example, tcp.port == 5566 to filter out the packets which are using TCP protocol and using port number 5566.

System calls:
1. socket() - creates an endpoint for communication and returns a file descriptor that refers to that endpoint.
    Syntax:
    #include <sys/types.h> 
           #include <sys/socket.h>
           int socket(int domain, int type, int protocol);
The domain argument specifies a communication domain. This decides the protocol family which will be used for communication. 
       Name                                        Purpose                                  Man page
       AF_UNIX, AF_LOCAL                          Local communication                       unix(7)
       AF_INET                                    IPv4 Internet protocols           	    ip(7)
       AF_INET6                                   IPv6 Internet protocols                   ipv6(7)

The socket has the indicated type, which specifies the communication semantics.
          SOCK_DGRAM - Supports datagrams (connectionless, unreliable messages of a fixed maximum length)     
          SOCK_STREAM - Provides sequenced, reliable, two-way, connection-based byte streams.  An out-of-band data transmission mechanism may be supported.
          SOCK_SEQPACKET - Provides  a  sequenced,  reliable, two-way connection-based data transmission path for datagrams of fixed maximum length; a consumer is required to read an entire packet with each input system call.
The type argument serves a second purpose: in addition to specifying a socket type, it may include the bitwise OR of any of the following values, to modify the behavior of socket().
       SOCK_NONBLOCK
       SOCK_CLOEXEC

The  protocol specifies a particular protocol to be used with the socket.  Normally only a single protocol exists to support a particular socket type within a given protocol family, in which case protocol can be specified as 0.  However, it is possible that many protocols may exist, in which case a particular protocol must be specified in this manner.  The protocol number to use is specific to the “communication domain” in which communication is to take place; see protocols(5).

     Return value:
    Success - File descriptor
    Error - -1.

2. bind() - binding/assigning a name to the socket.
    Syntax:
    	   #include <sys/types.h>  
           #include <sys/socket.h>
           int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
When a socket is created with socket(), it exists in a namespace (address family) but has no address assigned to it.  bind() assigns the address specified by addr to the socket referred to by the file descriptor sockfd.  addrlen specifies the size, in bytes, of the address structure pointed to by addr. 
    Return value:
    Success - 0.
    Error - -1.

3. connect() - initiate a connection on a socket.
    Syntax:
              #include <sys/types.h>      
              #include <sys/socket.h>
              int connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
The connect() system call connects the socket referred to by the file descriptor sockfd to the address specified by addr. The addrlen argument specifies the size of addr. The format of the address in addr is determined by the address space of the socket sockfd.
 

      Return value:
    Success - 0.
    Error - -1.

4. listen() - The listen() function applies only to stream sockets. It indicates a readiness to accept client connection requests, and creates a connection request queue of length backlog to queue incoming connection requests. Once full, additional connection requests are rejected.
    Syntax:
            #include <sys/types.h>       
            #include <sys/socket.h>
            int listen(int sockfd, int backlog);
Backlog argument - defines the maximum length for the queue of pending connections. 
     Return value:
    Success - 0.
    Error - -1.

5. accept() - accept a connection on socket.
    Syntax:
        #include <sys/types.h>        
           #include <sys/socket.h>
           int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
  It extracts the first connection request on the queue of pending connections for the listening socket, sockfd, creates a new connected socket, and returns a new file descriptor referring to that socket.  The newly created socket is not in the listening state. The original socket sockfd is unaffected by this call.
    Return value:
    Success - File descriptor
    Error - -1.

6. send(), sendto(), sendmsg() - send message on a socket.
    Syntax:
        #include <sys/types.h>
        #include <sys/socket.h>
        send(int sockfd, const void *buf, size_t len, int flags);
        sendto(int sockfd, const void *buf, size_t len, int flags,const struct sockaddr *dest_addr, socklen_t addrlen);
        sendmsg(int sockfd, const struct msghdr *msg, int flags);
The send() call may be used only when the socket is in a connected state (so that the intended recipient is known).
 Return value:
         Success - Number of bytes sent.
         Error - -1.

7. recv(), recvfrom(), recvmsg() - receive message on socket.
    Syntax:
     #include <sys/types.h>
            #include <sys/socket.h>
            ssize_t recv(int sockfd, void *buf, size_t len, int flags);
            ssize_t recvfrom(int sockfd, void *buf, size_t len, int flags,struct sockaddr *src_addr, socklen_t *addrlen);
            ssize_t recvmsg(int sockfd, struct msghdr *msg, int flags);
  Return value:
         Success - Number of bytes received.
         Error - -1.
8. close() - close the socket file.
    Syntax:
    #include <unistd.h>
           int close(int sockfd);
      Return value:
         Success - 0.
         Error - -1.
Library calls:

1. inet_addr() - The  inet_addr() function converts the Internet host address cp from IPv4 numbers-and-dots notation into binary data in network byte order. 
   Syntax:
               #include <sys/socket.h>
                #include <netinet/in.h>
               #include <arpa/inet.h>
            in_addr_t inet_addr(const char *cp);
    Return value:
           -1 - Invalid address. If the input is invalid, INADDR_NONE (usually -1) is returned. Use of this function is problematic because -1 is a valid address (255.255.255.255).

2. htons() , ntohs() - The htons() function converts the unsigned short integer hostshort from host byte order to network byte order. The ntohs() function converts the unsigned short integer netshort from network byte order to host byte order.
   Syntax:
        #include <arpa/inet.h>
                       uint16_t htons(uint16_t hostshort);
                       uint16_t ntohs(uint16_t netshort);
3 . inet_ntoa() , inet_aton() - inet_aton()  converts  the  Internet  host  address  cp  from  the  IPv4 numbers-and-dots notation into binary form (in network byte order) and stores it in the structure that inp points to.
    Syntax:
               #include <sys/socket.h>
                #include <netinet/in.h>
               #include <arpa/inet.h>
                                   int inet_aton(const char *cp, struct in_addr *inp);
                              char *inet_ntoa(struct in_addr in);


       
Return value: 
                    Success - Nonzero value.
                     Error - 0.
The inet_ntoa() function converts the Internet host address in, given in network byte order, to a string in IPv4 dotted-decimal notation. The string is returned in a statically allocated buffer, which subsequent calls will overwrite.

4. bzero - zero a byte string.The bzero() function erases the data in the n bytes of the memory starting at the location pointed to by s, by writing zeros (bytes containing '\0') to that area.
    Syntax:
           #include <strings.h>
           void bzero(void *s, size_t n);
    Return value:
        None.
   5. memset() - fill memory with a constant byte.The memset() function fills the first n bytes of the memory area pointed to by s with the constant byte c.
    Syntax:
           #include <string.h>
           void *memset(void *s, int c, size_t n);
    Return value:
                    The memset() function returns a pointer to the memory area s.
