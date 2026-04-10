#include <stdio.h>
#include <conio.h>
#include <Windows.h>
//推箱子

#define MAP_ROW 10
#define MAP_COL 10

char map[MAP_ROW][MAP_COL] = {

	1,1,1,1,1,1,1,1,1,1,
	1,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,1,
	1,0,0,0,4,0,0,0,0,1,
	1,0,0,4,0,0,0,0,0,1,
	1,0,0,0,3,0,3,0,0,1,
	1,0,0,0,2,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,1,
	1,1,1,1,1,1,1,1,1,1
};

enum { map_null, map_wall, map_man, map_box, map_destination, map_manAnddestination = 6, map_boxAnddestination };
enum { up = 'w', down = 's', left = 'a', right = 'd' };

void drawGame();
void playGame();
int isWin();

int main()
{
	drawGame();
	while (1)
	{
		playGame();
		drawGame();
		if (isWin())
		{
			printf("游戏胜利\n");
			break;
		}

	}
	getchar();
	return 0;
}

void drawGame()
{
	system("cls");
	for (int i = 0; i < MAP_ROW; i++)
	{
		for (int j = 0; j < MAP_COL; j++)
		{
			switch (map[i][j])
			{
			case map_null:
				printf("  ");
				break;
			case map_wall:
				printf("墙");
				break;
			case map_man:
				printf("人");
				break;
			case map_box:
				printf("箱");
				break;
			case map_destination:
				printf("地");
				break;
			case map_manAnddestination:
				printf("人");
				break;
			case map_boxAnddestination:
				printf("箱");
				break;
			}
		}
		printf("\n");
	}
}

void playGame()
{
	int x, y;//人的坐标
	for (int i = 0; i < MAP_ROW; i++)
	{
		for (int j = 0; j < MAP_COL; j++)
		{
			if (map[i][j] == map_man || map[i][j] == map_manAnddestination)
			{
				x = i;
				y = j;
			}
		}
	}

	switch (_getch())
	{
	case up:
		if (map[x - 1][y] == map_null || map[x - 1][y] == map_destination)
		{
			map[x - 1][y] += 2;
			map[x][y] -= 2;
		}
		else if (map[x - 1][y] == map_box || map[x - 1][y] == map_boxAnddestination)
		{
			if (map[x - 2][y] == map_null || map[x - 2][y] == map_destination)
			{
				map[x - 2][y] += 3;
				map[x - 1][y] -= 1;
				map[x][y] -= 2;
			}
		}
		break;
	case down:
		if (map[x + 1][y] == map_null || map[x + 1][y] == map_destination)
		{
			map[x + 1][y] += 2;
			map[x][y] -= 2;
		}
		else if (map[x + 1][y] == map_box || map[x + 1][y] == map_boxAnddestination)
		{
			if (map[x + 2][y] == map_null || map[x + 2][y] == map_destination)
			{
				map[x + 2][y] += 3;
				map[x + 1][y] -= 1;
				map[x][y] -= 2;
			}
		}
		break;
	case left:
		if (map[x][y - 1] == map_null || map[x][y - 1] == map_destination)
		{
			map[x][y - 1] += 2;
			map[x][y] -= 2;
		}
		else if (map[x][y - 1] == map_box || map[x][y - 1] == map_boxAnddestination)
		{
			if (map[x][y - 2] == map_null || map[x][y - 2] == map_destination)
			{
				map[x][y - 2] += 3;
				map[x][y - 1] -= 1;
				map[x][y] -= 2;
			}
		}
		break;
	case right:
		if (map[x][y + 1] == map_null || map[x][y + 1] == map_destination)
		{
			map[x][y + 1] += 2;
			map[x][y] -= 2;
		}
		else if (map[x][y + 1] == map_box || map[x][y + 1] == map_boxAnddestination)
		{
			if (map[x][y + 2] == map_null || map[x][y + 2] == map_destination)
			{
				map[x][y + 2] += 3;
				map[x][y + 1] -= 1;
				map[x][y] -= 2;
			}
		}
		break;
	}
}

int isWin()
{
	for (int i = 0; i < MAP_ROW; i++)
	{
		for (int j = 0; j < MAP_COL; j++)
		{
			if (map[i][j] == map_box)
			{
				return 0;
			}
		}
	}
	return 1;
}