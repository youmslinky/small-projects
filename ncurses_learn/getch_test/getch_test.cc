#include <ncurses.h>

int main(){

    initscr();
    int c;
    move(8,0);
    printw("Write something (ESC to escape): ");
    while((c=getch())!=27){
        move(10,0);
        printw("Keycode: %d, and the character: %c",c,c);
        move(8,0);
        printw("Write something (ESC to escape): ");
    }

    endwin();
    return 0;
}
