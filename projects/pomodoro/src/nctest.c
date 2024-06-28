#include <curses.h>
#include <ncurses.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

// Function to print a string centered in the terminal
void print_centered(WINDOW *win, int start_row, const char *message) {
    int rows, cols;
    getmaxyx(win, rows, cols);  // Get the size of the window

    int start_col = (cols - strlen(message)) / 2; // Calculate the column to start printing
    mvwprintw(win, start_row, start_col, "%s", message); // Print the message at the center
}

//countdown loop function
void countdown(int minutes) {
    int seconds = 0;
    while (minutes > 0 || seconds > 0) {
        clear();
        int rows, cols;
        getmaxyx(stdscr, rows, cols);
        int start_row = rows / 2;
        int start_cols = cols / 2;
        mvprintw(start_row, start_cols, "%.2d:%.2d", minutes, seconds);
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
    int rows, cols;
    getmaxyx(stdscr, rows, cols);
    int start_row = rows / 2;
    int start_cols = cols / 2;
    mvprintw(start_row, start_cols, "Time to stop: 00:00");
    refresh();
    sleep(1);
}

int main() {
    initscr();
    cbreak();
    curs_set(true);

    int rows, cols;
    getmaxyx(stdscr, rows, cols);

    char input[100];
    mvprintw(0, 0, "Enter time in minutes: ");
    refresh();
    getnstr(input, sizeof(input) - 1);
    echo();

    int minutes = atoi(input); //atoi changes string to an input
    int start_rows = rows / 2;
    countdown(minutes);

    beep(); //system bell

    endwin();

return 0 ;
}







