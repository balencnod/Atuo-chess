#include <stdio.h>
#include <math.h>
#include "shop.h"

void chess_levelup(){
	extern int chess_pool[10];
	int i1, i2, i3;//i1:棋子代号  i2：棋子槽值   i3：同类棋子数量
	int j[3] = { -1,-1,-1 };
	for (i1 = 1; i1 < 8; i1++) {
		i3 = 0;
		for (i2 = 0; i2 < 10; i2++) {
			if (chess_pool[i2] == i1) {
				j[i3] = i2;
				i3++;
			}
			if (i3 == 3) {
				chess_pool[j[0]] = chess_pool[j[0]] + 8;
				chess_pool[j[1]] = 0;
				chess_pool[j[2]] = 0;
				i3 = 0;
				j[0] = -1;
				j[1] = -1;
				j[2] = -1;
				check_chess_pool();
			}
		}
	}
}
