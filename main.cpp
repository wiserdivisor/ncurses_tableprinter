#include <ncurses.h>
#include <iostream>
#include <string>

#define BOX_HEIGHT 35
#define BOX_WIDTH 101
#define MOTOR_ROWS 6
#define MOTOR_COLS 9
#define XYZ_ROWS 4
#define XYZ_COLS 5 // (5 cols * 10 chars) + 5 seps
#define SPHERICAL_ROWS 5
#define SPHERICAL_COLS 5
#define INTERMEDIATE_ROWS 10
#define INTERMEDIATE_COLS 2
#define CONTROL_ROWS 7
#define CONTROL_COLS 2
#define START_X 1
#define START_Y 1

int main()
{
    initscr();
	noecho();
	curs_set(0);
	WINDOW *table_window = newwin(BOX_HEIGHT,BOX_WIDTH,START_X,START_Y);
	//box(table_window,0,0);

	while (true) {

		for (int i=0; i<MOTOR_ROWS+1; i++) {
			mvwhline(table_window, 0+(2*i), 1, ACS_HLINE, (MOTOR_COLS*10 + MOTOR_COLS-1));
		}

		for (int i=0; i<MOTOR_COLS+1; i++) {
			mvwvline(table_window, 1, 0+(11*i), ACS_VLINE, (MOTOR_ROWS + MOTOR_ROWS-1));
		}

		// VERTICAL HEADERS
		for (int i=0; i<4; i++) {
			std::string x = "   J";
			x.append(std::to_string(i+1));
			mvwprintw(table_window, 5+(2*i), 1, x.c_str());
		}

		// HORIZONTAL HEADERS [ROW1]
		mvwprintw(table_window, 1, 12, "             Actual             ");
		mvwprintw(table_window, 1, 45, "        Target       ");
		mvwprintw(table_window, 1, 67, "        Corrected Target        ");
		// HORIZONTAL HEADERS [ROW2]
		mvwprintw(table_window, 3, 12, "  Counts  ");
		mvwprintw(table_window, 3, 23, " Degrees  ");
		mvwprintw(table_window, 3, 34, " Radians  ");
		mvwprintw(table_window, 3, 45, " Degrees  ");
		mvwprintw(table_window, 3, 56, " Radians  ");
		mvwprintw(table_window, 3, 67, "  Counts  ");
		mvwprintw(table_window, 3, 78, " Degrees  ");
		mvwprintw(table_window, 3, 89, " Radians  ");

		// Filling in numbers
		double data[4][8] = {51,19,38,39,61,30,36,23,64,16,83,45,74,4,80,88,49,57,7,22,76,70,29,75,9,65,42,94,87,93,78,18};
		for (int i=0; i<4; i++) {
			for (int j=0; j<8; j++) {
				mvwprintw(table_window, 5+(2*i), 12+(11*j), std::to_string(data[i][j]).c_str());
			}
		}

		// XYZ table
		for (int i=0; i<XYZ_ROWS+1; i++) {
			mvwhline(table_window, 14+(2*i), 1, ACS_HLINE, (XYZ_COLS*10 + XYZ_COLS-1));
		}

		for (int i=0; i<XYZ_COLS+1; i++) {
			mvwvline(table_window, 15, 0+(11*i), ACS_VLINE, (XYZ_ROWS + XYZ_ROWS-1));
		}

		// rThetaPhi table
		for (int i=0; i<SPHERICAL_ROWS+1; i++) {
			mvwhline(table_window, 24+(2*i), 1, ACS_HLINE, (SPHERICAL_COLS*10 + SPHERICAL_COLS-1));
		}

		for (int i=0; i<SPHERICAL_COLS+1; i++) {
			mvwvline(table_window, 25, 0+(11*i), ACS_VLINE, (SPHERICAL_ROWS + SPHERICAL_ROWS-1));
		}

		// Intermediate values
		for (int i=0; i<INTERMEDIATE_ROWS+1; i++) {
			mvwhline(table_window, 14+(2*i), 59, ACS_HLINE, 16);
		}

		mvwvline(table_window, 15, 58+(11*0), ACS_VLINE, (2*INTERMEDIATE_ROWS-1));
		mvwvline(table_window, 15, 64, ACS_VLINE, (2*INTERMEDIATE_ROWS-1));
		mvwvline(table_window, 15, 64+11, ACS_VLINE, (2*INTERMEDIATE_ROWS-1));

		// Control values
		for (int i=0; i<CONTROL_ROWS+1; i++) {
			mvwhline(table_window, 14+(2*i), 79, ACS_HLINE, (CONTROL_COLS*10 + CONTROL_COLS-1));
		}

		for (int i=0; i<CONTROL_COLS+1; i++) {
			mvwvline(table_window, 15, 78+(11*i), ACS_VLINE, (CONTROL_ROWS + CONTROL_ROWS-1));
		}

		wrefresh(table_window);
	}

	delwin(table_window);
	endwin();	
	return 0;
}