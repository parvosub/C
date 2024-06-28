#include <ncurses.h>
#include <string.h>

// Function to print a string centered in the terminal
void print_centered(WINDOW *win, int start_row, const char *message) {
    int rows, cols;
    getmaxyx(win, rows, cols);  // Get the size of the window

    int start_col = (cols - strlen(message)) / 2; // Calculate the column to start printing
    mvwprintw(win, start_row, start_col, "%s", message); // Print the message at the center
}

int main() {
    initscr();            // Initialize the ncurses mode
    cbreak();             // Disable line buffering
    noecho();             // Disable echoing of typed characters

    int rows, cols;
    getmaxyx(stdscr, rows, cols);  // Get the size of the standard screen

    // Example messages to print
    const char *message1 = "Hello, World!";
    const char *message2 = "Welcome to the centered program!";
    const char *message3 = "Press any key to exit.";

    // Calculate the starting rows for each message
    int start_row1 = rows / 2 - 1;
    int start_row2 = rows / 2;
    int start_row3 = rows / 2 + 1;

    // Print the messages centered in the terminal
    print_centered(stdscr, start_row1, message1);
    print_centered(stdscr, start_row2, message2);
    print_centered(stdscr, start_row3, message3);

    refresh();            // Refresh the screen to show the output

    getch();              // Wait for user input
    endwin();             // End ncurses mode

    return 0;
}

