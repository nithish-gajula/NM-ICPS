struct {
	unsigned long preamble: 62 ; 
	unsigned short sofd : 2 ;	
	unsigned long destination : 48 ; 
	unsigned long source : 48 ;	
	unsigned short length : 16 ;	
} Ethernet_Header; // (long) 8 Bytes * 3 = 24 bytes

struct {
	unsigned short version: 4 ;
	unsigned short IHL: 4;
	unsigned short ToS: 8;
	unsigned short T_length:16; 	
	unsigned short Identification: 16;
	unsigned short flags : 3;
	unsigned short fragment_offset:13;	
	unsigned short Time_to_Live: 8;
	unsigned short protocol : 8;
	unsigned short header_checksum: 16;
	unsigned int source_address: 32;	
	unsigned int destination_address: 32;	
	unsigned int options: 24;
	unsigned short padding: 8;		
} IPv4_Header; // ==> (int) 4 bytes * 6 = 24 bytes

struct {
	unsigned int source_port: 16 ;
	unsigned int destination_port: 16;
	unsigned int total_length: 16;
	unsigned int checksum:16; 		
	
} UDP_Header; // ==> (int) 4 bytes * 2 = 8 bytes

struct {

	unsigned int source_port: 16;
	unsigned int destination_port: 16;	
	unsigned int sequence_number: 32;	
	unsigned int acknowledgment: 32; 	
	unsigned int data_offset: 4;
	unsigned int reserved: 4;
	unsigned int CWR: 1;
	unsigned int ECE: 1;
	unsigned int URG: 1;
	unsigned int ACK: 1;
	unsigned int PSH: 1;
	unsigned int RST: 1;
	unsigned int SYN: 1;
	unsigned int FIN: 1;
	unsigned int window_size: 16;		
	unsigned int checksum: 16; 
	unsigned int urgent_pointer: 16;	
	unsigned int options: 24;
	unsigned int padding: 8;		

} TCP_Header; // ==> (int) 4 bytes * 6 = 24 bytes


struct {
	unsigned short ICMP_type : 8;
	unsigned short ICMP_code : 8;
	unsigned short ICMP_checksum: 16;
	unsigned short Identifier : 16; 
	unsigned short sequence : 16;		
	unsigned int ICMP_data : 32;	
} ICMP_format; // ==> (int) 4 bytes * 3  = 12 bytes

struct {
	unsigned int hardware_type : 2;
	unsigned int protocol_type: 2;
	unsigned int hardware_address_length: 1;
	unsigned int protocol_address_length: 1;
	unsigned int operation_code: 2;
	unsigned int source_harware_address: 32;	
	unsigned int source_protocol_address: 32;	
	unsigned int target_hardware_address: 32;	
	unsigned int target_protocol_address: 32;	
} ARP_format; // ==> (int) 4  bytes * 5 = 20 bytes

struct {
	unsigned int v2 : 2;
	unsigned int p : 1;
	unsigned int x : 1;
	unsigned int cc : 4;
	unsigned int m : 1;
	unsigned int pt : 7;
	unsigned int sequence_number : 16; 
} RTF_format ; // ==> (int) 4 bytes * 1 = 4 bytes

struct {
	
	unsigned int CRC: 32;			
	unsigned int data; 		
	unsigned long source_mac_address: 48;	
	unsigned int sequence_control: 16;	
	unsigned long destination_mac_address: 48;	
	unsigned int duration: 16;			
	unsigned long router_mac_address: 48;	
	unsigned int frame_control : 16;
	unsigned long access_point_mac_address: 48;	

	
} wifi_frame_format	; // ==> (long) 8 bytes * 5 = 40 Bytes






