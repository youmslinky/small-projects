#include <ncurses.h>

int main(){

    initscr();
    int c;
    while((c=getch())!=27){
        //addch(c);
        if(c == 10){
            addch(10);
        }
    }

    endwin();
    return 0;
}
