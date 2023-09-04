#include<stdio.h>

struct Dictionary{
	int key;
	int value;
};

void append(struct Dictionary *dict,int key,int val);

int main(){
	struct Dictionary dict[5];
	
	for(int i=0; i<5; i++){
		append(&dict[i],i,i+10);
	}

	for(int i=0;i<5;i++){
		printf("%d Key = %d, Value = %d\n",i+1,dict[i].key,dict[i].value);
	}


	return 0;
}


void append(struct Dictionary *dict,int key,int val){

	dict->key = key;
	dict->value = val;
}

