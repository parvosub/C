#include <curses.h>
#include <stdio.h>
#include <ncurses.h>

int main(void)
{
initscr(); // Initialize the ncurses library
    int x, y;
    x = y = 10;

    move(y, x);

    printw("Hello, World!"); // Print a message

    refresh(); // Refresh the screen to display the message
               
    getch(); // Wait for user input

    endwin(); // Clean up and restore the termina


return 0;
}
