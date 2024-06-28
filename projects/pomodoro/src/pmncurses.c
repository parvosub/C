#include <curses.h>
#include <time.h> //for time function
#include <unistd.h> //sleep function
#include <ncurses.h> //ncurses library
#include <stdlib.h> //for atoi

void countdown(int minutes) {
    int seconds = 0;
    while (minutes > 0 || seconds > 0) {
        clear();
        mvprintw(0, 0, "%.2d:%.2d", minutes, seconds);
        refresh();
        sleep(1);

        if (seconds == 0) {
            if (minutes > 0) {
                minutes--;
                seconds = 59;
            } else {
                break;
            }
        } else {
            seconds--;
        }
    }
    clear();
    mvprintw(0, 0, "Time to stop: 00:00");
    refresh();
    sleep(1);
}

int main() {
    initscr();
    cbreak();
    curs_set(TRUE);

    int rows, cols;
    getmaxyx(stdscr, rows, cols);

    char input[100];
    mvprintw(0, 0, "Enter time in minutes: ");
    refresh();
    getnstr(input, sizeof(input) - 1);
    echo();
    int minutes = atoi(input); //atoi changes string to an int

    countdown(minutes);

    beep(); //trigger system bell

    endwin();
    return 0;
}

