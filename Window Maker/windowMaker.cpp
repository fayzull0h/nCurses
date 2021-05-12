#include "includes.h"

int main() {
    // Initialize screen
    // and start ncurses
    initscr();

    int height, width, startY, startX;
    height = width = 15;
    startY = startX = 10;

    WINDOW * win = newwin(height, width, startY, startX);
    refresh();

    start_color();
    init_pair(1, COLOR_MAGENTA, COLOR_YELLOW);

    attron(COLOR_PAIR(1));
    box(win, '|', '-');
    mvwprintw(win, 1, 1, "Hello");
    wrefresh(win);
    getch();
    attroff(COLOR_PAIR(1));
    wrefresh(win);
    getch();

    endwin();
    // deallocate memory and end ncurses

    return 0;
}
