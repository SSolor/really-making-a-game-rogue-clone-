//sebastian solorzano -making some sort of game
//it'll be an rpg of some sort i guess

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <conio.h>



typedef struct player {
	int hp;
	int mp;
}PLAYER;

typedef struct creature {
	void* type;
	int id;
}CREATURE;

typedef struct character {
	CREATURE attributes;
	char appearance;
	int x;
	int y;
}CHARACTER;


CHARACTER createCharacter(char v, CREATURE a, int x, int y) {
	CHARACTER c;
	c.appearance = v;
	c.attributes = a;
	c.x = x;
	c.y = y;
	return c;
}

lowerhp(PLAYER* p) {
	p->hp -= 10;
}

void determine(CREATURE c) {
	if (c.id = 3)
		lowerhp(c.type);
}


/*
int main(void) {
	PLAYER p;
	p.hp = 30;
	p.mp = 20;
	CREATURE pi;
	pi.id = 3;
	pi.type = &p;

	printf("%d", p.hp);
	CHARACTER player = createCharacter('V', pi, 5, 15);
	determine(player.attributes);
	printf("%d", p.hp);

}
*/


int main(void) {

	//init
	char bg[31] = " . . . . . . . . . . . . . . .";
	char vga[10][31];
	for (int i = 0; i < 10;i++) {
		strncpy(vga[i], bg, 31);
	}
	//char wall[31]=" . | . . . . . . . . . . . . .";
	//strncpy(vga[2], wall, 31);


	char player = 'V';
	int starth = 5;
	int startl = 15;
	vga[starth][startl] = player;


	for (int i = 0; i < 10;i++) {
		printf("%s\n", vga[i]);
	}

	char input='0';
	while (input !='\033') {
		printf("\033[5;50Hmove? ");
		input = _getch();
		//scanf("%c", &input);
		printf("\033[0;0H");

		strncpy(vga[starth], bg, 31);
		switch (input) {
		case 'a':
		

			startl -= 2;
			if (startl <0)
				startl = 29;
			//printf("\033[6;50H%c\033[0;0H",vga[starth][startl]);
			if (vga[starth][startl] == '|')
				startl += 2;
			break;
		case 'd':
			startl += 2;
			break;
		case 'w':
			starth -= 1;
			if (starth == -1)
				starth = 9;
			break;
		case 's':
			starth += 1;
			break;
		}
		starth = starth % 10;
		startl = startl % 30;
		vga[starth][startl] = player;
		for (int i = 0; i < 10;i++) {
			printf("%s\n", vga[i]);
		}
	}

	return 0;
}
