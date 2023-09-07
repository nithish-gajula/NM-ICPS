#include<stdio.h>
void func1();
void func2();

struct AA{
	unsigned char a;
	unsigned char b;
};

int main(){

	func1();
	func2();
	
	return 0;
}

void func1(){

	int a = 10;
	if(a>>1){
		printf("%d\n",a);
	}
}

void func2(){
	
	struct AA st;
	
	st.a = 10;
	st.b = 356;
	
	printf("%d ",st.a);
	printf("%d ",st.b);

	
	
	



}
