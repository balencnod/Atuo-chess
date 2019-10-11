#pragma once

struct chessman{
	int hp;//生命
	int mp;//魔法
	int atk;//物理攻击
	int rpg_int;//魔法攻击
	int def;//物理防御
	int res;//魔法防御
	int dex;//敏捷
	int sp;//攻击距离
	int price;//价格
};

struct chessman knight1_1{};//1
struct chessman knight1_2 {};//9

struct chessman knight2_1 {};//2
struct chessman knight2_2 {};//10

struct chessman witch1_1 {};//3
struct chessman witch1_2 {};//11

struct chessman witch2_1 {};//4
struct chessman witch2_2 {};//12

struct chessman clergy1_1 {};//5
struct chessman clergy1_2 {};//13

struct chessman clergy2_1 {};//6
struct chessman clergy2_2 {};//14

struct chessman assassin1_1 {};//7
struct chessman assassin1_2 {};//15

struct chessman assassin2_1 {};//8
struct chessman assassin2_2 {};//16

struct chessman chessman_num[17] = { knight1_1,knight2_1,witch1_1,witch2_1,clergy1_1,clergy2_1,assassin1_1,assassin2_1,knight1_2,knight2_2,witch1_2,witch2_2,clergy1_2,clergy2_2,assassin1_2,assassin2_2 };
