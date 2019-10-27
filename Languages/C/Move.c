/* Ncurses example where you just move around and collect points*/
/* compile using GCC: gcc -lncurses Move.c -o Move */

#include <ncurses.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 10
#define ORIGINAL 'x'
#define POINTS '+'
void print2D(char arr[HEIGHT][WIDTH], int height, int width);
struct coords
{
	int x;
	int y;
}pos;


int main(int argc, char *argv[])
{
	int cnt = 0;
	srand((unsigned int) &time);
	char grid[HEIGHT][WIDTH];
	for (int i = 0; i < HEIGHT; i++)
		memset(grid[i], (int)'o', WIDTH);
	char op = ORIGINAL;
	for (int i = 0; i < 6; i++)
	{
		int y = rand()%10, x = rand()%20;
		//printf("%d %d\n", y, x);
		if (grid[y][x] == POINTS) i--;
		grid[y][x] = POINTS;
	}
	grid[pos.y][pos.x] = op;
	initscr();
	start_color();
	init_pair(1, COLOR_RED, COLOR_GREEN);
	init_pair(2, COLOR_GREEN, COLOR_GREEN);
	init_pair(3, COLOR_BLACK, COLOR_GREEN);
	init_pair(5, COLOR_CYAN, COLOR_BLACK);
	curs_set(0);
	print2D(grid, HEIGHT, WIDTH);
	refresh();
	while (true)
	{
		char c = getch();
		if (c == 'Q' || c == 'q') break;
		if (c == '\040' && op == ORIGINAL) op = '-';
		else if (c == '\040' && op == '-') op = ORIGINAL;
		if (c == '\033')
		{
			getch();
			char i = getch();
			grid[pos.y][pos.x] = 'o';
			if (i == 'A' && pos.y!=0) pos.y--;
			else if (i == 'B' && pos.y != HEIGHT-1) pos.y++;			
			else if (i == 'C' && pos.x != WIDTH-1) pos.x++;
			else if (i == 'D' && pos.x != 0) pos.x--;
			if (grid[pos.y][pos.x] == POINTS) cnt++;
		}
		
		clear();
		grid[pos.y][pos.x] = op;
		print2D(grid, HEIGHT, WIDTH);
		attron(COLOR_PAIR(5));
		printw("\n\t %d\n",cnt);
		refresh();
	}
	endwin();
}

void print2D(char arr[HEIGHT][WIDTH], int height, int width)
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (i == pos.y && j == pos.x) 
				attron(COLOR_PAIR(1));
			else if (arr[i][j] == POINTS)
				attron(COLOR_PAIR(3));
			else attron(COLOR_PAIR(2));
			printw("%c", arr[i][j]);
		}
		printw("\n");
	}
}
