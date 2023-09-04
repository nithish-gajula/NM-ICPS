#include <stdio.h>

int main() {
    printf("Hello, world!\n");  // Newline
    printf("First part\tSecond part\n");  // Horizontal tab
    printf("One\rTwo\n");  // Carriage return
    printf("Before\fAfter\n");  // Form feed
    printf("Vertical\vtab\n");
    printf("Double Quote \"Marks\"\n");


    newline_func();


    return 0;
}

void newline_func(){
    printf("-------------------------\n");
    printf("Lorem ipsum dolor sit amet, \nconsectetur adipiscing elit. \nSed do eiusmod tempor incididunt ut labore et dolore magna aliqua. \nUt enim ad minim veniam, \nquis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. \nDuis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. \nExcepteur sint occaecat cupidatat non proident, \nsunt in culpa qui officia deserunt mollit anim id est laborum.\n");
    printf("-------------------------\n");
}

