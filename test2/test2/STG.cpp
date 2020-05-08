#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <graphics.h>
#include<conio.h>
#include<math.h>
#include<time.h>
#pragma comment(lib,"Winmm.lib")
#define N 500
#define COMPLETE 100
#define GAKS GetAsyncKeyState
#define Self_Speed 2


typedef struct point
{
	double x;
	double y;
	double direct_x;
	double direct_y;
	int kind;
}P_gjl;

typedef struct enemy
{
	int hp;
	double x;
	double y;
	double direct_x;
	double direct_y;
}E_gjl;

typedef struct disappear
{
	E_gjl point;
	int time;
}D_gjl;

IMAGE start_1;
IMAGE start_2;
int num_bullet = 0;
int num_block = 0;
int num_dis = 0;
int miss[1201][901] = { 0 };
P_gjl player = { 150,320,0,0 };
P_gjl bullet[1000];
E_gjl block[100];
D_gjl block_dis[100];
int count_gjl[5];
int score = 0;
TCHAR score_s[100];
char fenshu[10] = "Score:";


void Initial();
void Game_Start();
int Area_M(MOUSEMSG a, int flag, int x_s, int x_b, int y_s, int y_b);
void Act_1();
void KeyBoard();
void Move();
void Draw_Bullet();
void Create_Block();
void Draw_Block();
void Defeat_B();
void Dis_B(D_gjl a);
int Distance(int x_1, int y_1, int x_2, int y_2);
void Score_gjl();
void Self_Die();



int stg()
{
	player.x = 150;
	player.y = 320;
	score = 0;
	num_bullet = 0;
	num_block = 0;
	num_dis = 0;
	//fenshu[10] = "Score:";

	Initial();
	initgraph(640, 480);
	BeginBatchDraw();
	setlinecolor(WHITE);
	setfillcolor(WHITE);
	fillrectangle(45, 45, 315, 445);
	setlinecolor(BLACK);
	setfillcolor(BLACK);
	fillrectangle(50, 50, 310, 440);
	FlushBatchDraw();
	Game_Start();
	fillrectangle(50, 50, 310, 440);
	FlushBatchDraw();
	setfillcolor(WHITE);
	EndBatchDraw();
	Act_1();
	BeginBatchDraw();

	while (true)
	{
		player.direct_x = 0;
		player.direct_y = 0;
		POINT pts[] = { { player.x + 7, player.y },{ player.x - 7, player.y },{ player.x, player.y - 15 } };
		setlinecolor(BLACK);
		setfillcolor(BLACK);
		fillrectangle(0, 0, 640, 480);
		setfillcolor(WHITE);
		fillrectangle(45, 45, 315, 445);
		setfillcolor(BLACK);
		fillrectangle(50, 50, 310, 440);
		setfillcolor(WHITE);
		fillpolygon(pts, 3);
		if (count_gjl[1] % 200 == 0)
		{
			Create_Block();
		}
		Draw_Bullet();
		Draw_Block();
		for (int i = 1; i <= num_dis; i++)
		{
			if (block_dis[i].time <= 0)
			{
				for (int k = i; k <= num_block; k++)
				{
					block_dis[k] = block_dis[k + 1];
				}
				num_dis--;
				i--;
			}
			if (i <= num_dis)
			{
				block_dis[i].time--;
				Dis_B(block_dis[i]);
			}

		}
		setlinecolor(BLACK);
		setfillcolor(BLACK);
		fillrectangle(0, 0, 44, 640);
		fillrectangle(0, 0, 480, 44);
		fillrectangle(0, 446, 640, 480);
		fillrectangle(316, 0, 640, 480);
		Score_gjl();
		FlushBatchDraw();
		KeyBoard();
		Move();
		Defeat_B();
		//Self_Die();
		Sleep(5);
		count_gjl[1]++;
		if (score > 20)
		{
			break;
		}
	}
	EndBatchDraw();
	cleardevice();
	closegraph();
	return 0;
}

void Initial()
{
	FlushMouseMsgBuffer();
	loadimage(&start_1, _T("‪D:\\c++_projects\\test2\\test2\\Photo\\游戏开始_1.jpg"), 260, 390);
	loadimage(&start_2, _T("D:\\c++_projects\\test2\\test2\\Photo\\游戏开始_2.jpg"), 260, 390);
	srand(time(NULL));
}

void Game_Start()
{
	MOUSEMSG begin_0;
	putimage(50, 50, &start_1);
	FlushBatchDraw();
	while (true)
	{
		begin_0 = GetMouseMsg();
		if (Area_M(begin_0, 0, 130, 230, 200, 280))
		{
			putimage(50, 50, &start_2);
			FlushBatchDraw();
			while (begin_0.mkLButton)
			{
				begin_0 = GetMouseMsg();
			}
			if (Area_M(begin_0, 1, 130, 230, 200, 280))
			{
				break;
			}
			putimage(50, 50, &start_1);
			FlushBatchDraw();
		}
	}

}

void Act_1()
{
	for (int i = 439; i >= -101; i = i - 10)
	{
		for (int j = 309; j >= 50; j--)
		{

			if (i <= 429 && i >= 49)
			{
				setfillcolor(WHITE);
				setlinecolor(WHITE);
				fillrectangle(j, i, j + 1, i + 11);
			}
			if (i <= 279 && i >= -101)
			{
				setfillcolor(BLACK);
				setlinecolor(BLACK);
				fillrectangle(j, i + 150, j + 1, i + 161);
			}
			if (j % 50 == 0)
			{
				Sleep(1);
			}
		}
	}
	setfillcolor(WHITE);
	setlinecolor(WHITE);
	//fillrectangle(49, 49, 590, 50);
	Sleep(1000);
}

int Area_M(MOUSEMSG a, int flag, int x_s, int x_b, int y_s, int y_b)
{
	if ((a.mkLButton || flag) && a.x >= x_s && a.x <= x_b && a.y >= y_s && a.y <= y_b)
	{
		return 1;
	}
	return 0;
}

int Area_P(P_gjl a, int x_s, int x_b, int y_s, int y_b)
{
	if (a.x >= x_s && a.x <= x_b && a.y >= y_s && a.y <= y_b)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int Area_E(E_gjl a, int x_s, int x_b, int y_s, int y_b)
{
	if (a.x >= x_s && a.x <= x_b && a.y >= y_s && a.y <= y_b)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void KeyBoard()
{
	if (GAKS(VK_UP))
	{
		player.direct_y -= Self_Speed;
	}
	if (GAKS(VK_DOWN))
	{
		player.direct_y += Self_Speed;
	}
	if (GAKS(VK_LEFT))
	{
		player.direct_x -= Self_Speed;
	}
	if (GAKS(VK_RIGHT))
	{
		player.direct_x += Self_Speed;
	}
	if (GAKS(0x5A))
	{
		if (GAKS(VK_LSHIFT))
		{
			num_bullet += 15;
			for (int j = 0; j < 3; j++)
			{
				for (int i = 0; i < 5; i++)
				{
					bullet[num_bullet - i - j * 5].x = player.x - 20 + 10 * i;
					bullet[num_bullet - i - j * 5].y = player.y - j * 5;
					bullet[num_bullet - i - j * 5].direct_x = 0;
					bullet[num_bullet - i - j * 5].direct_y = -8;
					bullet[num_bullet - i - j * 5].kind = 2;
				}
			}

		}
		else
		{
			for (int i = 0; i < 5; i++)
			{
				num_bullet += 5;
				bullet[num_bullet - i].x = player.x;
				bullet[num_bullet - i].y = player.y;
				bullet[num_bullet - i].direct_x = 0.75 - 0.375 * i;
				bullet[num_bullet - i].direct_y = -1;
				bullet[num_bullet - i].kind = 1;
			}
		}
	}
	if (GAKS(VK_LSHIFT))
	{
		player.direct_x /= 2;
		player.direct_y /= 2;
	}
}

void Move()
{
	player.x += player.direct_x;
	player.y += player.direct_y;
	if (player.x < 55)
	{
		player.x = 55;
	}
	if (player.x > 310)
	{
		player.x = 310;
	}
	if (player.y < 60)
	{
		player.y = 60;
	}
	if (player.y > 445)
	{
		player.y = 445;
	}
	for (int i = 1; i <= num_bullet; i++)
	{
		if (bullet[i].kind == 1)
		{
			bullet[i].direct_x += (block[1].x - bullet[i].x) / 1000;
			bullet[i].direct_y += (block[1].y - bullet[i].y) / 2000;
			if (bullet[i].direct_x >= 3)
			{
				bullet[i].direct_x /= 1.5;
			}
			if (bullet[i].direct_y >= 3)
			{
				bullet[i].direct_y /= 1.5;
			}
		}

		bullet[i].x += bullet[i].direct_x;
		bullet[i].y += bullet[i].direct_y;
		if (!(Area_P(bullet[i], 50, 310, 50, 445)))
		{
			for (int j = i; j <= num_bullet; j++)
			{
				bullet[j] = bullet[j + 1];
			}
			num_bullet--;
			i--;
		}
	}
	for (int i = 1; i <= num_block; i++)
	{
		block[i].x += block[i].direct_x;
		block[i].y += block[i].direct_y;
		if (!(Area_E(block[i], 0, 360, 0, 495)))
		{
			for (int j = i; j <= num_block; j++)
			{
				block[j] = block[j + 1];
			}
			num_block--;
			i--;
		}
	}
}

void Draw_Bullet()
{
	setlinecolor(WHITE);
	setfillcolor(WHITE);
	for (int i = 1; i <= num_bullet; i++)
	{
		fillcircle(bullet[i].x, bullet[i].y, 2);
	}
}

void Create_Block()
{
	int num_block_b = num_block;
	num_block = num_block + rand() % 5 + rand() % 5 + 5;
	for (int i = num_block_b + 1; i <= num_block; i++)
	{
		block[i].hp = rand() % 300 + 150;
		block[i].y = rand() % 20 + 65;
		block[i].x = rand() % 150 + 75;
		block[i].direct_x = rand() % 3 - 1;
		block[i].direct_y = rand() % 3 + 1;
		block[i].direct_x = block[i].direct_x / 4.0;
		block[i].direct_y = block[i].direct_y / 4.0;
	}
}

void Draw_Block()
{
	setlinecolor(LIGHTRED);
	setfillcolor(LIGHTRED);
	for (int i = 1; i <= num_block; i++)
	{
		fillrectangle(max(block[i].x - 30, 50), max(block[i].y - 30, 50), min(block[i].x + 30, 315), min(block[i].y + 30, 445));
	}
}

void Defeat_B()
{
	for (int i = 1; i <= num_block; i++)
	{
		for (int j = 1; j <= num_bullet; j++)
		{
			if (Distance(bullet[j].x, bullet[j].y, block[i].x, block[i].y) <= 1000)
			{

				if (bullet[j].kind = 1)
				{
					block[i].hp -= 5;
					for (int k = j; k <= num_bullet; k++)
					{
						bullet[k] = bullet[k + 1];
					}
					num_bullet--;
					j--;
				}
				else
				{
					block[i].hp--;
				}
				if (block[i].hp <= 0)
				{
					num_dis++;
					block_dis[num_dis].point = block[i];
					block_dis[num_dis].time = 200;
					for (int k = i; k <= num_block; k++)
					{
						block[k] = block[k + 1];

					}
					num_block--;
					i--;
					score++;
					break;
				}
			}
		}
	}
}

int Distance(int x_1, int y_1, int x_2, int y_2)
{
	int distance;
	distance = (x_1 - x_2)*(x_1 - x_2) + (y_1 - y_2)*(y_1 - y_2);
	return distance;
}

void Dis_B(D_gjl a)
{
	setfillcolor(LIGHTGRAY);
	setlinecolor(LIGHTGRAY);
	if (a.time > 125)
	{
		fillrectangle(max(a.point.x - 25, 50), max(a.point.y - 25, 50), min(a.point.x + 25, 315), min(a.point.y + 25, 445));
	}
	else if (a.time > 50)
	{
		fillrectangle(max(a.point.x - 25, 50), max(a.point.y - 25, 50), min(a.point.x + 25, 315), min(a.point.y - 20, 445));
		fillrectangle(max(a.point.x - 25, 50), max(a.point.y - 25, 50), min(a.point.x - 20, 315), min(a.point.y + 25, 445));
		fillrectangle(max(a.point.x - 25, 50), max(a.point.y + 20, 50), min(a.point.x + 25, 315), min(a.point.y + 25, 445));
		fillrectangle(max(a.point.x + 20, 50), max(a.point.y - 25, 50), min(a.point.x + 25, 315), min(a.point.y + 25, 445));
	}
	else
	{
		if (Area_E(a.point, 50, 315, 50, 445))
		{
			fillrectangle(max(a.point.x - 35, 50), max(a.point.y - 35, 50), min(a.point.x - 30, 315), min(a.point.y - 30, 445));
			fillrectangle(max(a.point.x + 30, 50), max(a.point.y - 35, 50), min(a.point.x + 35, 315), min(a.point.y - 30, 445));
			fillrectangle(max(a.point.x - 35, 50), max(a.point.y + 30, 50), min(a.point.x - 30, 315), min(a.point.y + 35, 445));
			fillrectangle(max(a.point.x + 30, 50), max(a.point.y + 30, 50), min(a.point.x + 35, 315), min(a.point.y + 35, 445));
		}

	}
}

void Score_gjl()
{
	TCHAR sc[100];
	settextcolor(WHITE);
	settextstyle(16, 0, _T("宋体"));
	_stprintf(sc, _T("%d"), score);
	outtextxy(350, 50, fenshu);
	outtextxy(400, 50, sc);
}

void Self_Die()
{
	for (int i = 1; i <= num_block; i++)
	{
		if (Distance(player.x, player.y, block[i].x, block[i].y) <= 2500)
		{
			Sleep(1000);
		}
	}
}