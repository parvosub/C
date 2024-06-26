#include <curses.h>
#include <unistd.h> //sleep function
#include <ncurses.h> //ncurses library
#include <string.h> //for strcmp function
#include <stdlib.h> //for atoi

int main() {
    initscr();
    cbreak();
    noecho();
    curs_set(TRUE);

    char input[100];
    int seconds;

    mvprintw(0, 0, "Enter time in seconds: ");
    refresh();
    mvgetstr(1, 0, input);
    seconds = atoi(input);

    while (seconds > 0) {
        clear();
        mvprintw(0, 0,"Time remaining: %d seconds", seconds);
        refresh();
        sleep(1);
        seconds--;
     }

    clear();
    mvprintw(0, 0,"Time is up!");
    refresh();
    sleep(2);

    endwin();
    return 0;
}

