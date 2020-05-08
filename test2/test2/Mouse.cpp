#include<stdio.h>
#include <graphics.h>
#include<conio.h>
#pragma comment(lib,"Winmm.lib")
//IMAGE start_m;
int mouse_start1();
int mouse_start2();
int mouse_start3();
int mouse_start4();
int area(MOUSEMSG a, int x_s, int x_b, int y_s, int y_b);

int mouse1()
{
	int select;
	IMAGE start_m;
	//loadimage(&start, _T("Photo//start_size_a.jpg"));
	loadimage(&start_m, _T("D:\\test_photo\\start.jpg"),640,480);
	initgraph(640, 480);
//	BeginBatchDraw();
	putimage(0, 0, &start_m);
//	FlushBatchDraw();
	select = mouse_start1();
	closegraph();
	return select;
}

int mouse2()  //钢琴块成功界面鼠标
{
	int select;
	select = mouse_start2();
	closegraph();
	return select;
}

int mouse3()  //钢琴块失败界面鼠标
{
	int select;
	select = mouse_start3();
	closegraph();
	return select;
}

int mouse4()  //游戏目录界面鼠标
{
	int select;
	IMAGE start_x;
	loadimage(&start_x, _T("D:\\test_photo\\start2.jpg"), 640, 480);
	initgraph(640, 480);
	putimage(0, 0, &start_x);
	select = mouse_start4();
	closegraph();
	return select;
}

int mouse_start1()
{
	while (1)
	{
		MOUSEMSG a;
		a = GetMouseMsg();
		if (area(a, 170, 440, 170, 260))
		{
			return 1;
		}
		if (area(a, 170, 440, 325, 415))
		{
			return 3;
		}
		if (area(a, 518, 589, 182, 406))
		{
			return 4;
		}
	}
}

int mouse_start2()    //钢琴块成功按钮
{
	while (1)
	{
		MOUSEMSG a;
		a = GetMouseMsg();
		if (area(a, 467, 593, 247, 287))
		{
			return 1;
		}
		if (area(a, 467, 593, 298, 335))
		{
			return 2;
		}
	}
}

int mouse_start3()    //钢琴块失败按钮
{
	while (1)
	{
		MOUSEMSG a;
		a = GetMouseMsg();
		if (area(a, 410, 600, 234, 290))
		{
			return 1;
		}
		if (area(a, 410, 600, 341, 392))
		{
			return 2;
		}
	}
}

int mouse_start4()    //游戏界面按钮
{
	while (1)
	{
		MOUSEMSG a;
		a = GetMouseMsg();
		if (area(a, 290, 554, 159, 204))   //跳到俄罗斯方块
		{
			return 1;
		}
		if (area(a, 282, 597, 225, 271))
		{
			return 2;
		}
		if (area(a, 278, 597, 295, 338))   //按钮3
		{
			return 3;
		}
		if (area(a, 3, 169, 24, 60))   //按钮4
		{
			return 4;
		}
		if (area(a, 549, 606, 343, 376))  //游戏返回按钮
		{
			return 5;
		}

	}
	return 0;
}


int area(MOUSEMSG a, int x_s, int x_b, int y_s, int y_b)
{
	if (a.mkLButton && a.x >= x_s && a.x <= x_b && a.y >= y_s && a.y <= y_b)
	{
		return 1;
	}
	return 0;
}
