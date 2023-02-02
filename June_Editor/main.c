/*
Author: Daniel Jones
Last edited: 2/2/2023 11:37 AM
Editor: Vim
Compiler: GCC
Operating System: WSL2 Windows 10
Purpose: Text editor written in C. Part of a course "How to make your own text editor"(https://viewsourcecode.org/snaptoken/kilo/01.setup.html)
*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>

struct termios orig_termios;

void license(){
    printf("June Editor  Copyright (C) 2023  Daniel Jones\
    \nThis program comes with ABSOLUTELY NO WARRANTY;\
    \nThis is free software, and you are welcome to redistribute\
    \nit under certain conditions; For more details, read the license file\
    \nthat came with this program.\n");
}

void exit_raw_mode(){
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios);
}

void enter_raw_mode(){

    tcgetattr(STDIN_FILENO, &orig_termios);
    atexit(exit_raw_mode);
    struct termios raw;

    tcgetattr(STDIN_FILENO, &raw);
    raw.c_lflag &= ~(ECHO | ICANON);
    tcsetattr(STDIN_FILENO, TCSAFLUSH,&raw);

}

int main()
{
    license();
    enter_raw_mode();
    
    //reads input until letter q pressed
    char c;
    while(read(STDIN_FILENO, &c, 1) == 1 && c != 'q'){
    	if(iscntrl(c)){
            printf("%d\n", c);
	}
	else{
	    printf("%d ('%c')\n", c, c);
	}

    }
    printf("\n");

    return 0;
}
