//贪吃蛇
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include <graphics.h>
#include<conio.h>
#include<math.h>
#pragma comment(lib,"Winmm.lib")
#define N 500
#define COMPLETE 100
#include<time.h>
void Interface();//界面函数
int mouse();//鼠标有关函数
void headshow();//蛇头显示函数
void tailshow();//蛇尾显示函数
void withcontrol();//键盘控制函数
void headwithoutcontrol();//蛇头移动函数
void tailwithoutcontrol();//蛇尾移动函数
void food();//食物显示函数
void foodwithoutcontrol();//食物随机变化函数
void walldie();//蛇头撞到墙判断自己死亡函数
void selfdie();//蛇头撞到自己判断自己死亡函数
void fscore();//读取分数的函数
void sscore();//记录分数的函数
int gameover();
int grade = 0;//分数
void judge();//判断分数最高分的函数
void showscore();//显示分数的函数
void transport();
void trans_show();
void trans_init();
void pause();
void end();
IMAGE mbg;//主背景图片
IMAGE bg;//背景图片
IMAGE s;//按钮图片
IMAGE snake;//
IMAGE over;
IMAGE sc;
IMAGE fix;
IMAGE test;
IMAGE start;
IMAGE mide;
int tail_x[N] = { 0 };
int tail_y[N] = { 0 };
int trans_x[3];
int trans_y[3];
int head_x = 410, head_y = 410;
int r = 10;
int n = 3;//记录蛇的节数
int run = 0;//0上 1下 2左 3右
int rember_x[N];
int rember_y[N];
int food_x = 285;
int food_y = 285;
int bfood_x = 295;
int bfood_y = 295;
int v = 100;
int max = 0;
int flag_die = 0;
int flag_exit = 0;

int snaker()
{
	int a;

	tail_x[N] = { 0 };
	tail_y[N] = { 0 };
	//trans_x[3];
	//trans_y[3];
	head_x = 410, head_y = 410;
	r = 10;
	n = 3;//记录蛇的节数
	run = 0;//0上 1下 2左 3右
	food_x = 285;
	food_y = 285;
	bfood_x = 295;
	bfood_y = 295;
	v = 100;
	max = 0;
	flag_die = 0;
	flag_exit = 0;
	grade = 0;

	srand(time(NULL));
	sscore();
	fscore();
	initgraph(640, 480);
	//fflush(stdin);
/*	loadimage(&mbg, _T("finish photo//贪吃蛇界面_副本_副本.jpg"));	
	loadimage(&bg, _T("finish photo//背景.jpg"));
	loadimage(&snake, _T("finish photo//timg.png"));
	loadimage(&over, _T("finish photo//gameover_副本.jpg"));
	loadimage(&sc, _T("finish photo//分数.jpg"));
	loadimage(&fix, _T("finish photo//设置_副本.jpg"));
	loadimage(&test, _T("finish photo//bj.jpg"));
	loadimage(&mide, _T("finish photo//中途退出.jpg"));*/

	loadimage(&mbg, _T("D:\\test_photo\\finish photo\\贪吃蛇界面_副本_副本.jpg"));
	loadimage(&bg, _T("D:\\test_photo\\finish photo\\背景.jpg"));
	loadimage(&snake, _T("D:\\test_photo\\finish photo\\timg.png"));
	loadimage(&over, _T("D:\\test_photo\\finish photo\\gameover_副本.jpg"));
	loadimage(&sc, _T("D:\\test_photo\\finish photo\\分数.jpg"));
	loadimage(&fix, _T("D:\\test_photo\\finish photo\\设置_副本.jpg"));
	loadimage(&test, _T("D:\\test_photo\\finish photo\\bj.jpg"));
	loadimage(&mide, _T("D:\\test_photo\\finish photo\\中途退出.jpg"));
	mciSendString(TEXT("open background.mp3 alias  bkmusic "), NULL, 0, NULL);
	mciSendString(TEXT("play bkmusic"), NULL, 0, NULL);
	Interface();
	BeginBatchDraw();
	fscore();
	while (1)
	{
		Interface();
		FlushBatchDraw();
		a = mouse();
		if (a == 0)
		{
			trans_init();
			while (!flag_die&&a == 0)
			{
				FlushMouseMsgBuffer();/*清空鼠标信息缓冲区*/
				headshow();
				tailshow();
				food();
				FlushBatchDraw();
				Sleep(v);
				foodwithoutcontrol();
				withcontrol();
				if (flag_exit == 1)
				{
					a = 4;
					break;
				}
				headwithoutcontrol();
				tailwithoutcontrol();
				walldie();
				selfdie();
				a = gameover();
			}
		}
		if (a == 1)
		{
			putimage(0, 0, &fix);
			FlushBatchDraw();
			while (1)
			{
				MOUSEMSG w;
				w = GetMouseMsg();
				if (w.mkLButton&&w.x > 291 && w.x < 403 && w.y>74 && w.y < 140)
				{
					v = 500;
					//a = 0;
					break;
				}
				if (w.mkLButton&&w.x > 291 && w.x < 403 && w.y>186 && w.y < 256)
				{
					v = 100;
					//a = 0;
					break;
				}
				if (w.mkLButton&&w.x > 291 && w.x < 403 && w.y>298 && w.y < 362)
				{
					v = 50;
					//a = 0;
					break;
				}
			}
			FlushMouseMsgBuffer();
		}
		if (a == 2)
		{
			closegraph();
		}
		if (a == 3)
		{
			showscore();
			while (1)
			{
				MOUSEMSG q;
				q = GetMouseMsg();
				if (q.mkLButton&&q.x > 314 && q.x < 354 && q.y>364 && q.y < 490)
				{
					a = 0;
					break;
				}
			}
		}
		if (a == 4)
		{
			/*MOUSEMSG e;
			int stop = 0;
			FlushMouseMsgBuffer();
			putimage(0, 0, &test);
			fillrectangle(0, 0, 100, 100);
			FlushBatchDraw();
			while (stop == 0)
			{
				e = GetMouseMsg();
				if (e.mkLButton&&e.x>0 && e.x<100 && e.y>0 && e.y<100)
				{
					stop = 1;
				}
			}
			break;
			Sleep(100);*/
			EndBatchDraw();
			closegraph();
			if (flag_exit == 1)
				return 0;
			if (flag_exit == 0)
				return 3;
			//break;
		}
	}
	EndBatchDraw();
	closegraph();
	//Sleep(2000);
	return 0;
}

void Interface()
{
	putimage(0, 0, &mbg);
}

int mouse()
{
	while (1)
	{
		MOUSEMSG m;
		m = GetMouseMsg();
		if (m.mkLButton&&m.x >= 275 && m.x <= 375 && m.y > 90 && m.y < 190)
		{
			return 0;
		}
		if (m.mkLButton&&m.x >= 275 && m.x <= 375 && m.y > 190 && m.y < 290)
		{
			return 1;
		}
		if (m.mkLButton&&m.x >= 275 && m.x <= 375 && m.y > 290 && m.y < 390)
		{
			return 2;
		}
		if (m.mkLButton&&m.x > 447 && m.x < 645 && m.y>182 && m.y < 353)
		{
			return 3;
		}
	}
}

void headshow()
{
	putimage(0, 0, &bg);
	trans_show();
	setcolor(WHITE);
	setfillcolor(RED);
	fillcircle(head_x, head_y, r);
}

void headwithoutcontrol()
{
	if (head_x == trans_x[1] && head_y == trans_y[1] && (tail_x[2] != trans_x[2] || tail_y[2] != trans_y[2]))
	{
		head_x = trans_x[2];
		head_y = trans_y[2];
	}
	else if (head_x == trans_x[2] && head_y == trans_y[2] && (tail_x[2] != trans_x[1] || tail_y[2] != trans_y[1]))
	{
		head_x = trans_x[1];
		head_y = trans_y[1];
	}
	else
	{
		if (run == 0)
		{
			head_y -= 20;
		}
		if (run == 1)
		{
			head_y += 20;
		}
		if (run == 2)
		{
			head_x -= 20;
		}
		if (run == 3)
		{
			head_x += 20;
		}
	}

}
void withcontrol()
{
	char input;
	MOUSEMSG clk;
	if (_kbhit())
	{
		input = _getch();
/*		if ((input == 'w' || input == 72) && run != 1)
		{
			run = 0;
		}
		if ((input == 's' || input == 80) && run != 0)
		{
			run = 1;
		}
		if ((input == 'a' || input == 75) && run != 3)
		{
			run = 2;
		}
		if ((input == 'd' || input == 77) && run != 2)
		{
			run = 3;
		}*/

		//if ((input == 72) && run != 1)
		if (GetAsyncKeyState(VK_UP) && run != 1)
		{
			run = 0;
		}
		//if ((input == 80) && run != 0)
		else if (GetAsyncKeyState(VK_DOWN) && run != 0)
		{
			run = 1;
		}
		//if ((input == 75) && run != 3)
		else if (GetAsyncKeyState(VK_LEFT) && run != 3)
		{
			run = 2;
		}
		//if ((input == 77) && run != 2)
		else if (GetAsyncKeyState(VK_RIGHT) && run != 2)
		{
			run = 3;
		}

		//if (input == ' ')
		else if (GetAsyncKeyState(VK_SPACE))
		{
			pause();
			while (GetAsyncKeyState(VK_SPACE));
		}
		//if (input == 27)
		else if (GetAsyncKeyState(VK_ESCAPE))
		{
			end();
		}

		else
		{
			;
		}
	}
	if (MouseHit())
	{
		clk = GetMouseMsg();
		if (clk.mkLButton)
		{
			if ((clk.x >= head_x) && (abs(clk.y - head_y) <= clk.x - head_x) && (run != 2))
			{
				run = 3;
			}
			else if ((clk.x <= head_x) && (abs(clk.y - head_y) <= head_x - clk.x) && (run != 3))
			{
				run = 2;
			}
			else if (clk.y < head_y && run != 1)
			{
				run = 0;
			}
			else
			{
				run = 1;
			}
		}
	}



}
void tailwithoutcontrol()
{
	tail_x[0] = head_x;
	tail_y[0] = head_y;
	for (int i = 1; i <= n; i++)
	{
		rember_x[i] = tail_x[i - 1];
		rember_y[i] = tail_y[i - 1];
	}

	for (int i = 1; i <= n; i++)
	{
		tail_x[i] = rember_x[i];
		tail_y[i] = rember_y[i];
	}

}
void tailshow()
{
	setcolor(WHITE);
	setfillcolor(GREEN);
	for (int i = 2; i <= n; i++)
		fillcircle(tail_x[i], tail_y[i], r);
}
void food()
{
	setcolor(WHITE);
	setfillcolor(LIGHTMAGENTA);
	fillrectangle(food_x, food_y, bfood_x, bfood_y);
}
void foodwithoutcontrol()
{
	int l, L;
	l = (food_x - head_x)*(food_x - head_x) + (food_y - head_y)*(food_y - head_y);
	L = (bfood_x - head_x)*(bfood_x - head_x) + (bfood_y - head_y)*(bfood_y - head_y);
	if (l <= 100 || L <= 100)
	{
		n++;
		grade += 10;
		while (l <= 100 || L <= 100)
		{
			food_x = (rand() % 30 + 1) * 20 + 5;
			food_y = (rand() % 20 + 1) * 20 + 5;
			bfood_x = food_x + 10;
			bfood_y = food_y + 10;
			l = (food_x - head_x)*(food_x - head_x) + (food_y - head_y)*(food_y - head_y);
			L = (bfood_x - head_x)*(bfood_x - head_x) + (bfood_y - head_y)*(bfood_y - head_y);
		}


	}
}
void walldie()
{
	TCHAR aa[10];
	judge();
	sscore();
	if (head_x > 640 || head_x < 0 || head_y>480 || head_y < 0)
	{
		Sleep(1500);
		_stprintf_s(aa, _T("%d"), grade);
		while (1)
		{
			putimage(0, 0, &over);
			settextcolor(GREEN);
			settextstyle(30, 30, _T("宋体"));
			outtextxy(560, 176, aa);
			FlushBatchDraw();
			MOUSEMSG z;
			z = GetMouseMsg();
			if (z.mkLButton&&z.x >= 328 && z.x <= 368 && z.y >= 333 && z.y <= 460)
			{
				run = 0;
				n = 3;
				head_x = head_y = 410;
				FlushMouseMsgBuffer();
				grade = 0;
				break;
			}
		}
	}

}
void selfdie()
{
	int i, l;
	TCHAR aa[10];
	for (i = 3; i <= n; i++)
	{
		l = (head_x - tail_x[i])*(head_x - tail_x[i]) + (head_y - tail_y[i])*(head_y - tail_y[i]);
		if (l < 200)
		{
			judge();
			sscore();
			_stprintf_s(aa, _T("%d"), grade);
			Sleep(1500);
			while (1)
			{
				putimage(0, 0, &over);
				settextcolor(GREEN);
				settextstyle(30, 30, _T("宋体"));
				outtextxy(560, 176, aa);
				FlushBatchDraw();
				MOUSEMSG z;
				z = GetMouseMsg();
				if (z.mkLButton&&z.x >= 328 && z.x <= 368 && z.y >= 333 && z.y <= 460)
				{
					run = 0;
					n = 3;
					head_x = head_y = 410;
					FlushMouseMsgBuffer();
					grade = 0;
					break;
				}
			}
		}
	}
}
void fscore()
{
	FILE *fs;
	fs = fopen("D://score.txt", "rb");
	fscanf(fs, "%d", &max);
	fclose(fs);

}

void sscore()
{
	FILE *fb;
	fb = fopen("D://score.txt", "wb");
	fprintf(fb, "%d", max);
	fclose(fb);
}

void judge()
{
	if (grade > max)
	{
		max = grade;
	}
}

void showscore()
{
	TCHAR aa[10];
	_stprintf_s(aa, _T("%d"), max);
	putimage(0, 0, &sc);
	settextcolor(RED);
	settextstyle(30, 30, _T("宋体"));
	outtextxy(300, 275, aa);
	FlushBatchDraw();

}

int gameover()
{
	TCHAR aa[10];
	judge();
	sscore();
	if (grade >= COMPLETE)
	{
		return 4;
	}
	return 0;
}

void trans_show()
{
	setcolor(WHITE);
	setfillcolor(BLUE);
	fillcircle(trans_x[1], trans_y[1], r*1.2);
	fillcircle(trans_x[2], trans_y[2], r*1.2);
	setfillcolor(GREEN);
	fillcircle(trans_x[1], trans_y[1], r);
	fillcircle(trans_x[2], trans_y[2], r * 1);
	setfillcolor(CYAN);
	fillcircle(trans_x[1], trans_y[1], r*0.8);
	fillcircle(trans_x[2], trans_y[2], r*0.8);
}

void trans_init()
{
	int l, L;
	trans_x[1] = (rand() % 30 + 1) * 20 + 10;
	trans_y[1] = (rand() % 20 + 1) * 20 + 10;
	l = (trans_x[1] - head_x)*(trans_x[1] - head_x) + (trans_y[1] - head_y)*(trans_y[1] - head_y);
	while (l <= 800)
	{
		trans_x[1] = (rand() % 30 + 1) * 20 + 10;
		trans_y[1] = (rand() % 20 + 1) * 20 + 10;
		l = (trans_x[1] - head_x)*(trans_x[1] - head_x) + (trans_y[1] - head_y)*(trans_y[1] - head_y);
	}
	trans_x[2] = (rand() % 30 + 1) * 20 + 10;
	trans_y[2] = (rand() % 20 + 1) * 20 + 10;
	l = (trans_x[2] - head_x)*(trans_x[2] - head_x) + (trans_y[2] - head_y)*(trans_y[2] - head_y);
	L = (trans_x[2] - trans_x[1])*(trans_x[2] - trans_x[1]) + (trans_y[2] - trans_y[1])*(trans_y[2] - trans_y[1]);
	while (l <= 100 || L <= 1000)
	{
		trans_x[2] = (rand() % 30 + 1) * 20 + 10;
		trans_y[2] = (rand() % 20 + 1) * 20 + 10;
		l = (trans_x[2] - head_x)*(trans_x[2] - head_x) + (trans_y[2] - head_y)*(trans_y[2] - head_y);
		L = (trans_x[2] - trans_x[1])*(trans_x[2] - trans_x[1]) + (trans_y[2] - trans_y[1])*(trans_y[2] - trans_y[1]);
	}
}

void pause()
{
	char input;
	char p[100] = "Game Pause";
	outtextxy(200, 200, p);
	FlushBatchDraw();
	while (true)
	{
		input = _getch();
		if (input == ' ')
		{
			break;
		}
	}
	headshow();
	tailshow();
}

void end()
{
	MOUSEMSG e;
	putimage(0, 0, &mide);
	FlushBatchDraw();
	while (true)
	{
		e = GetMouseMsg();
		if (e.mkLButton && e.x > 200 && e.x < 460 && e.y>200 && e.y < 260)
		{
			flag_exit = 0;
			break;
		}
		if (e.mkLButton && e.x > 200 && e.x < 460 && e.y>300 && e.y < 350)
		{
			flag_exit = 1;
			break;
		}
	}
}