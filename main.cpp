#include <stdio.h>
#include <math.h>
#include <conio.h>
#include "shop.h"
#include "levelup.h"

int level = 1;
int money = 0;
int rpg_exp = 0;
int chess_pool[10] = { 0,0,0,0,0,0,0,0,0,0 };

int main() {
	printf("欢迎游玩软院一班自走棋\t 制作者：张瀚文\n");
	for (int i = 1; i <= 10; i++) {
		shop();
		chess_levelup();

	}
	_getch();
	return 0;
}
