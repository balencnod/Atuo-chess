#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "chessman.h"



void check_chess_pool() {
	extern int chess_pool[10];
	extern int money;
	extern int level;
	printf("以下是你的金币：%d\n", money);
	printf("以下是你的等级：%d\n", level);
	printf("以下是你的棋子槽：");
	for (int i = 0; i < 10; i++) {
		switch (chess_pool[i]) {
		case 0:
			printf("%d.\t", chess_pool[i]);
			break;
		case 1:
			printf("%d.kn1\t", chess_pool[i]);
			break;
		case 2:
			printf("%d.kn2\t", chess_pool[i]);
			break;
		case 3:
			printf("%d.wt1\t", chess_pool[i]);
			break;
		case 4:
			printf("%d.wt2\t", chess_pool[i]);
			break;
		case 5:
			printf("%d.cg1\t", chess_pool[i]);
			break;
		case 6:
			printf("%d.cg2\t", chess_pool[i]);
			break;
		case 7:
			printf("%d.as1\t", chess_pool[i]);
			break;
		case 8:
			printf("%d.as2\t", chess_pool[i]);
			break;
		case 9:
			printf("%d.kn1+\t", chess_pool[i]);
			break;
		case 10:
			printf("%d.kn2+\t", chess_pool[i]);
			break;
		case 11:
			printf("%d.wt1+\t", chess_pool[i]);
			break;
		case 12:
			printf("%d.wt2+\t", chess_pool[i]);
			break;
		case 13:
			printf("%d.cg1+\t", chess_pool[i]);
			break;
		case 14:
			printf("%d.cg2+\t", chess_pool[i]);
			break;
		case 15:
			printf("%d.as1+\t", chess_pool[i]);
			break;
		case 16:
			printf("%d.as2+\t", chess_pool[i]);
			break;
		}
	}
	printf("\n");
}

void shop(){
	extern int level;
	extern int money;
	extern int chess_pool[10];
	float kn1_weight, kn2_weight, wt1_weight, wt2_weight, cg1_weight, cg2_weight, as1_weight, as2_weight;

	printf("请购买所需物品:\n");

	if (level <= 3) {
		kn1_weight = 7 - level;
		kn2_weight = 0;
		wt1_weight = 7 - level;
		wt2_weight = 0;
		cg1_weight = 7 - level;
		cg2_weight = 0;
		as1_weight = 7 - level;
		as2_weight = 0;
	}
	else if(3 < level <= 7) {
		kn1_weight = 7 - level;
		kn2_weight = level - 3;
		wt1_weight = 7 - level;
		wt2_weight = level - 3;
		cg1_weight = 7 - level;
		cg2_weight = level - 3;
		as1_weight = 7 - level;
		as2_weight = level - 3;
	}
	else {
		kn1_weight = 0;
		kn2_weight = level - 3;
		wt1_weight = 0;
		wt2_weight = level - 3;
		cg1_weight = 0;
		cg2_weight = level - 3;
		as1_weight = 0;
		as2_weight = level - 3;
	}

	float total_weight = kn1_weight + kn2_weight + wt1_weight + wt2_weight + cg1_weight + cg2_weight + as1_weight + as2_weight;

	float kn1_referee = kn1_weight / total_weight;
	float kn2_referee = (kn2_weight / total_weight) + kn1_referee;
	float wt1_referee = (wt1_weight / total_weight) + kn2_referee;
	float wt2_referee = (wt2_weight / total_weight) + wt1_referee;
	float cg1_referee = (cg1_weight / total_weight) + wt2_referee;
	float cg2_referee = (cg2_weight / total_weight) + cg1_referee;
	float as1_referee = (as1_weight / total_weight) + cg2_referee;
	float as2_referee = (as2_weight / total_weight) + as1_referee;

	int goods[3];

	for (int i = 0; i < 3; i++) {
		float a = rand() % 100 + 1;
		float referee = a / 100;
		if (referee < kn1_referee){
			goods[i] = 1;
			printf("%d.kn1\n",i);
		}
		else if (referee < kn2_referee) {
			goods[i] = 2;
			printf("%d.kn2\n", i);
		}
		else if (referee < wt1_referee) {
			goods[i] = 3;
			printf("%d.wt1\n", i);
		}
		else if (referee < wt2_referee) {
			goods[i] = 4;
			printf("%d.wt2\n", i);
		}
		else if (referee < cg1_referee) {
			goods[i] = 5;
			printf("%d.cg1\n", i);
		}
		else if (referee < cg2_referee) {
			goods[i] = 6;
			printf("%d.cg2\n", i);
		}
		else if (referee < as1_referee) {
			goods[i] = 7;
			printf("%d.as1\n", i);
		}
		else {
			goods[i] = 8;
			printf("%d.as2\n", i);
		}
	}

	printf("3.刷新商店界面\n");
	printf("4.提升等级\n");
	printf("5.购物完毕\n");
	check_chess_pool();

	int bhv;

reshop:

	scanf_s("%d", &bhv);

	switch (bhv) {
	case 0:
		for (int i = 0; i < 10; i++) {
			if (chess_pool[0] * chess_pool[1] * chess_pool[2] * chess_pool[3] * chess_pool[4] * chess_pool[5] * chess_pool[6] * chess_pool[7] * chess_pool[8] * chess_pool[9] != 0) {
				printf("你没有空的棋子槽！\n");
				goto reshop;
			}
			if (chess_pool[i] == 0) {
				money = money - chessman_num[goods[0]].price;
				chess_pool[i] = goods[0];
				check_chess_pool();
				goto reshop;
			}
		}
		break;
	case 1:
		for (int i = 0; i < 10; i++) {
			if (chess_pool[0] * chess_pool[1] * chess_pool[2] * chess_pool[3] * chess_pool[4] * chess_pool[5] * chess_pool[6] * chess_pool[7] * chess_pool[8] * chess_pool[9] != 0) {
				printf("你没有空的棋子槽！\n");
				goto reshop;
			}
			if (chess_pool[i] == 0) {
				money = money - chessman_num[goods[1]].price;
				chess_pool[i] = goods[1];
				check_chess_pool();
				goto reshop;
			}
		}
		break;
	case 2:
		for (int i = 0; i < 10; i++) {
			if (chess_pool[0] * chess_pool[1] * chess_pool[2] * chess_pool[3] * chess_pool[4] * chess_pool[5] * chess_pool[6] * chess_pool[7] * chess_pool[8] * chess_pool[9] != 0) {
				printf("你没有空的棋子槽！\n");
				goto reshop;
			}
			if (chess_pool[i] == 0) {
				money = money - chessman_num[goods[2]].price;
				chess_pool[i] = goods[2];
				check_chess_pool();
				goto reshop;
			}
		}
		break;
	case 3:
		shop();
		break;
	case 4:
		level++;
		printf("以下是你的等级：%d\n", level);
		money = money - 5;
		goto reshop;
		break;
	case 5:
		return;
		break;
	}
}
