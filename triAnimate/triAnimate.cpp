#include "includes.h"

void Triangle(int _size, int y, int x, char unit) {
    for (int i = 0; i <= _size; i++) {
        mvaddch((i + y) % LINES, (i + x) % COLS, unit);
        mvaddch(y % LINES, (i + x) % COLS, unit);
        mvaddch((_size - i + y) % LINES, (_size + i + x) % COLS, unit);
        mvaddch(y % LINES, (_size + i + x) % COLS, unit);
    }
}

int main() {
    initscr();
    cbreak();
    noecho();
    clear();

    int size = (LINES - 1)/4;
    int pos = 0;
    char unit = 'k';

    while (pos <= LINES * 4) {
        clear();
        Triangle(size, pos, 0, unit);
        Triangle(size, pos, 2 * size, unit);
        Triangle(size, pos, 4 * size, unit);
        Triangle(size, pos, 6 * size, unit);

        Triangle(size, pos + size, size, unit);
        Triangle(size, pos + size, 3 * size, unit);
        Triangle(size, pos + size, 5 * size, unit);

        Triangle(size, pos + 2 * size, 2 * size, unit);
        Triangle(size, pos + 2 * size, 4 * size, unit);

        Triangle(size, pos + 3 * size, 3 * size, unit);
        refresh();
        // sleep(25);
        getch();
        pos++;
    }
    
    getch();
    endwin();
    return 0;
}
