#include <stdio.h>
#include <math.h>

int hurt(int atk, int rpg_int, int def, int res) {
	int hurt = (atk * 5 - def * 2) + (rpg_int * 5 - res * 2);
	return hurt;
}

void kn_ai() {

}
