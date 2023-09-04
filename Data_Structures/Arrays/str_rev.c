#include<stdio.h>
#include<string.h>

void str_rev(char str[]);

int main()
{

    char str[100];

    printf("Enter Any Word : ");
    scanf("%s",str);
   

    int length = strlen(str); // It will return no.of characters present in str array
    int loop = length / 2 ;


    printf("Original String in main : ");
    for(int i=0; i<length; i++){
        printf("%c",str[i]);
    }
    printf("\n");

    for(int i=0; i<loop; i++){
        char temp = str[i];
        str[i] = str[length-1-i];
        str[length-1-i] = temp;
    }
    
    printf("Reversed String in main : ");
    for(int i=0; i<length; i++){
        printf("%c",str[i]);
    }
    printf("\n");

    str_rev(str);
    str_rev(str);


}   

void str_rev(char str[])
{
    int length = strlen(str);

    for(int i=0; i < length / 2; i++){
        char temp = str[i];
        str[i] = str[length-1-i];
        str[length-1-i] = temp;
    }

    printf("Reversed in str_rev   : ");
    for(int i=0; i<length; i++){
        printf("%c",str[i]);
    }
    printf("\n");

}
