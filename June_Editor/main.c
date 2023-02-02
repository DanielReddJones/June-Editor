/*
Author: Daniel Jones
Last edited: 2/2/2023 11:37 AM
Editor: Vim
Compiler: GCC
Operating System: WSL2 Windows 10
Purpose: Text editor written in C. Part of a course "How to make your own text editor"(https://viewsourcecode.org/snaptoken/kilo/01.setup.html)
*/

#include <stdio.h>
#include <stdlib.h>


void license(){
    printf("June Editor  Copyright (C) 2023  Daniel Jones\
    \nThis program comes with ABSOLUTELY NO WARRANTY;\
    \nThis is free software, and you are welcome to redistribute\
    \nit under certain conditions; For more details, read the license file\
    \nthat came with this program.\n");

		


}


int main()
{
    license();
    
    return 0;
}
