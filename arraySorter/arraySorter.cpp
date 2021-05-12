#include "funcs.h"

void sleep(int s) {
    std::this_thread::sleep_for(std::chrono::milliseconds(s));
}

void drawLine(int pos, int length, char unit) {
    for (int i = 0; i < length; i++) {
        mvaddch(pos, i, unit);
    }
    refresh();
}

void drawAll(int c, std::vector<int> _nums, char unit) {
    for (int i = 0; i < c; i++) {
        drawLine(i, _nums[i], unit);
    }
}

void loopThru(int _size, std::vector<int>& _nums, char unit) {
    int temp;
    for (int i = 0; i < _size - 1; i++) {
        if (_nums[i] > _nums[i+1]) {
            drawLine(i+1, _nums[i+1], unit);
            move(i+1, 0);
            clrtoeol();
            drawLine(i+1, _nums[i], unit);
            move(i, 0);
            clrtoeol();
            drawLine(i, _nums[i+1], unit);
            temp = _nums[i+1];
            _nums[i+1] = _nums[i];
            _nums[i] = temp;
	    if (LINES < 100) {
		sleep(7);
	    } else if (LINES < 200) {
		sleep(3);
	    }
	}
	refresh();
    }
    move(LINES - 1, 0);
}



int main() {
    initscr();
    cbreak();
    noecho();
    clear();

    unsigned char unit = 'o';
    
    start_color();
    init_pair(1, COLOR_YELLOW, COLOR_BLACK);

    std::vector<int> nums;
    srand(time(NULL));
    int vSize = LINES - 1;
    for (int i = 0; i < vSize; i++) {
        nums.push_back(rand() % COLS + 1);
    }
    attron(COLOR_PAIR(1));
    drawAll(vSize, nums, unit);

    sleep(1000);
    for (int i = 0, buffer = vSize; i < buffer; i++) {
        loopThru(vSize--, nums, unit);
	refresh();
    }
    attroff(COLOR_PAIR(1));
    getch();
    endwin();
    
    return 0;
}
