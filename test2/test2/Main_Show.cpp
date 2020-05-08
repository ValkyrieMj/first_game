#include <tchar.h>
#include<graphics.h>
#include<conio.h>
#include <sstream>

#include<stdio.h>
#include<windows.h>
#include<time.h>
#include<iostream>
#include<Mmsystem.h>
#pragma comment(lib,"winmm.lib")
using namespace std;


//const TCHAR A[30] = "博士，博士";
char talk_1[70] = "阿米娅：博士，博士，快醒醒，你刚才被石头砸晕了！！！";
char talk_2[70] = "我：这是哪里，我在哪，我是谁";
char talk_3[70] = "阿米娅：博士，我是阿米娅，你玩游戏太入迷了";
char talk_4[70] = "我此时正躺在床上，不由得往窗外望去";
char talk_5[70] = "窗外却是灾难般的景象，乌蒙蒙的天空伴随着雷鸣般的闪电";
char talk_6[70] = "这。。。到底发生了什么";
char talk_7[70] = "我：对了，阿米娅，你到底是驴还是兔子啊？？？";
char talk_8[70] = "阿米娅：。。。。。。博士，我现在很生气！！！";
char talk_9[70] = "因为惹阿米娅生气，所以必须要用音乐感动她";

char talk_10[70] = "任务失败，被阿米娅掰断手指，你的分数是：";
char talk_11[70] = "是否继续？按一：继续；按二：继续";
char talk_12[70] = "开个玩笑，你没得选，游戏继续";

char talk_13[70] = "任务成功，重新赢得阿米娅信任，你的分数是：";
char talk_14[70] = "我：陈警官，你怎么在这？？？";
char talk_15[70] = "我的冷汗早已湿透了我的衣服，因为碰到陈警官就没什么好事";
char talk_16[70] = "早知道我就我就从阿米娅那里逃走了";
char talk_17[70] = "陈警官：既然你在，那么，收集物资的事就交给你了";
char talk_18[70] = "我：慢着，陈警官！！！怎么收集啊！！";
char talk_19[70] = "陈警官：很简单，借你一条蛇蛇就行了呗";
char talk_20[70] = "警告，警告，请无关市民马上去避难所避难！警告，警告。。。。。。";
char talk_21[70] = "此时楼层突然崩塌，石块大量掉落了下来";
char talk_22[70] = "我：真是麻烦，出来散个步都遇上了天灾";
char talk_23[70] = "我：算了，先玩一下俄罗斯方块，反正会有人来救我";

char talk_24[70] = "凯尔希：欢迎回来，博士，今天辛苦了";
char talk_25[70] = "我一回到罗德岛就看到凯尔希在整理文件，真希望一回来就就有人给我饭吃";
char talk_26[70] = "凯尔希：今天我给你带来了一点便当，如果不嫌弃的话可以一起吃";
char talk_27[70] = "我：阿里嘎多，凯尔希。看来今天运气还是很不错的";

char talk_28[70] = "最后彩蛋：弹幕射击";
char talk_temp[3] = { 0 };
int Word_count = 0;

IMAGE cg1;//存储背景图片
IMAGE cg2;
IMAGE cg3;

IMAGE shelter;
IMAGE shelter1;
IMAGE white1;
IMAGE maskbitmap(10, 10);

IMAGE cg4;
IMAGE cg5;

IMAGE number0_1;
IMAGE number1_1;
IMAGE number2_1;
IMAGE number3_1;
IMAGE number4_1;
IMAGE number5_1;
IMAGE number6_1;
IMAGE number7_1;
IMAGE number8_1;
IMAGE number9_1;

void print_Score(int Score)
{
	if (Score % 10 == 0)
		putimage(550, 140, &number0_1);//在窗口上个位数字0图片
	if (Score % 10 == 1)
		putimage(550, 140, &number1_1);//在窗口上个位数字1图片
	if (Score % 10 == 2)
		putimage(550, 140, &number2_1);//在窗口上个位数字2图片
	if (Score % 10 == 3)
		putimage(550, 140, &number3_1);//在窗口上个位数字3图片
	if (Score % 10 == 4)
		putimage(550, 140, &number4_1);//在窗口上个位数字4图片
	if (Score % 10 == 5)
		putimage(550, 140, &number5_1);//在窗口上个位数字5图片
	if (Score % 10 == 6)
		putimage(550, 140, &number6_1);//在窗口上个位数字6图片
	if (Score % 10 == 7)
		putimage(550, 140, &number7_1);//在窗口上个位数字7图片
	if (Score % 10 == 8)
		putimage(550, 140, &number8_1);//在窗口上个位数字8图片
	if (Score % 10 == 9)
		putimage(550, 140, &number9_1);//在窗口上个位数字9图片

	if (Score / 10 % 10 == 0)
		putimage(500, 140, &number0_1);//在窗口上十位数字0图片
	if (Score / 10 % 10 == 1)
		putimage(500, 140, &number1_1);//在窗口上十位数字1图片
	if (Score / 10 % 10 == 2)
		putimage(500, 140, &number2_1);//在窗口上十位数字2图片
	if (Score / 10 % 10 == 3)
		putimage(500, 140, &number3_1);//在窗口上十位数字3图片
	if (Score / 10 % 10 == 4)
		putimage(500, 140, &number4_1);//在窗口上十位数字4图片
	if (Score / 10 % 10 == 5)
		putimage(500, 140, &number5_1);//在窗口上十位数字5图片
	if (Score / 10 % 10 == 6)
		putimage(500, 140, &number6_1);//在窗口上十位数字6图片
	if (Score / 10 % 10 == 7)
		putimage(500, 140, &number7_1);//在窗口上十位数字7图片
	if (Score / 10 % 10 == 8)
		putimage(500, 140, &number8_1);//在窗口上十位数字8图片
	if (Score / 10 % 10 == 9)
		putimage(500, 140, &number9_1);//在窗口上十位数字9图片

}

void print_Score_1(int Score)
{
	if (Score % 10 == 0)
		putimage(500, 100, &number0_1);//在窗口上个位数字0图片
	if (Score % 10 == 1)
		putimage(500, 100, &number1_1);//在窗口上个位数字1图片
	if (Score % 10 == 2)
		putimage(500, 100, &number2_1);//在窗口上个位数字2图片
	if (Score % 10 == 3)
		putimage(500, 100, &number3_1);//在窗口上个位数字3图片
	if (Score % 10 == 4)
		putimage(500, 100, &number4_1);//在窗口上个位数字4图片
	if (Score % 10 == 5)
		putimage(500, 100, &number5_1);//在窗口上个位数字5图片
	if (Score % 10 == 6)
		putimage(500, 100, &number6_1);//在窗口上个位数字6图片
	if (Score % 10 == 7)
		putimage(500, 100, &number7_1);//在窗口上个位数字7图片
	if (Score % 10 == 8)
		putimage(500, 100, &number8_1);//在窗口上个位数字8图片
	if (Score % 10 == 9)
		putimage(500, 100, &number9_1);//在窗口上个位数字9图片

	if (Score / 10 % 10 == 0)
		putimage(450, 100, &number0_1);//在窗口上十位数字0图片
	if (Score / 10 % 10 == 1)
		putimage(450, 100, &number1_1);//在窗口上十位数字1图片
	if (Score / 10 % 10 == 2)
		putimage(450, 100, &number2_1);//在窗口上十位数字2图片
	if (Score / 10 % 10 == 3)
		putimage(450, 100, &number3_1);//在窗口上十位数字3图片
	if (Score / 10 % 10 == 4)
		putimage(450, 100, &number4_1);//在窗口上十位数字4图片
	if (Score / 10 % 10 == 5)
		putimage(450, 100, &number5_1);//在窗口上十位数字5图片
	if (Score / 10 % 10 == 6)
		putimage(450, 100, &number6_1);//在窗口上十位数字6图片
	if (Score / 10 % 10 == 7)
		putimage(450, 100, &number7_1);//在窗口上十位数字7图片
	if (Score / 10 % 10 == 8)
		putimage(450, 100, &number8_1);//在窗口上十位数字8图片
	if (Score / 10 % 10 == 9)
		putimage(450, 100, &number9_1);//在窗口上十位数字9图片

}

int Show_cg1(void)
{
	int i, color;
	int count = 0;
	Word_count = 0;

	IMAGE cg1_1;
	IMAGE cg2_1;
	IMAGE cg3_1;

	loadimage(&cg1_1, _T("D:\\test_photo\\cg1.jpg"), 800, 400);//加载背景图片
	loadimage(&cg2_1, _T("D:\\test_photo\\cg2_1.jpg"), 800, 400);
	loadimage(&cg3, _T("D:\\test_photo\\cg3.jpg"), 400, 400);
	loadimage(&cg3_1, _T("D:\\test_photo\\cg3_1.jpg"), 400, 400);
	loadimage(&shelter, _T("D:\\test_photo\\black.jpg"), 600, 20);
	loadimage(&shelter1, _T("D:\\test_photo\\black.jpg"), 800, 400);


	initgraph(800, 400);//根据背景图片的长和宽初始化窗口，使之铺满窗


	putimage(0, 0, &cg1_1);//在窗口上绘制背景图片

						 //color = GetBkColor(hdc);
	settextcolor(WHITE);
	setbkcolor(RGB(0, 0, 0));

	//setbkcolor(color);

	while (Word_count<53)
	{
		count++;
		for (i = 0; i<2; i++)
		{
			talk_temp[i] = talk_1[Word_count];
			Word_count++;
		}
		outtextxy(50 + count * 16, 350, talk_temp);
		Sleep(100);
		if (GetAsyncKeyState(VK_SPACE))
			break;
		if (GetAsyncKeyState(VK_RETURN))
			return 0;
	}

	Sleep(500);
	putimage(30, 350, &shelter);//涂黑对话
	Word_count = 0;
	count = 0;


	while (Word_count<29)
	{
		count++;
		for (i = 0; i<2; i++)
		{
			talk_temp[i] = talk_2[Word_count];
			Word_count++;
		}
		outtextxy(50 + count * 16, 350, talk_temp);
		Sleep(100);
		if (GetAsyncKeyState(VK_SPACE))
			break;
		if (GetAsyncKeyState(VK_RETURN))
			return 0;
	}
	Sleep(500);
	putimage(30, 350, &shelter);//涂黑对话
	Word_count = 0;
	count = 0;

	while (Word_count<43)
	{
		count++;
		for (i = 0; i<2; i++)
		{
			talk_temp[i] = talk_3[Word_count];
			Word_count++;
		}
		outtextxy(50 + count * 16, 350, talk_temp);
		Sleep(100);
		if (GetAsyncKeyState(VK_SPACE))
			break;
		if (GetAsyncKeyState(VK_RETURN))
			return 0;
	}

	Sleep(1000);
	putimage(0, 0, &cg2_1);
	Sleep(500);
	Word_count = 0;
	count = 0;

	while (Word_count<35)
	{
		count++;
		for (i = 0; i<2; i++)
		{
			talk_temp[i] = talk_4[Word_count];
			Word_count++;
		}
		outtextxy(50 + count * 16, 350, talk_temp);
		Sleep(100);
		if (GetAsyncKeyState(VK_SPACE))
			break;
		if (GetAsyncKeyState(VK_RETURN))
			return 0;
	}

	Sleep(500);
	putimage(30, 350, &shelter);//涂黑对话
	Word_count = 0;
	count = 0;

	while (Word_count<53)
	{
		count++;
		for (i = 0; i<2; i++)
		{
			talk_temp[i] = talk_5[Word_count];
			Word_count++;
		}
		outtextxy(50 + count * 16, 350, talk_temp);
		Sleep(100);
		if (GetAsyncKeyState(VK_SPACE))
			break;
		if (GetAsyncKeyState(VK_RETURN))
			return 0;
	}

	Sleep(500);
	putimage(30, 350, &shelter);//涂黑对话
	Word_count = 0;
	count = 0;

	while (Word_count<23)
	{
		count++;
		for (i = 0; i<2; i++)
		{
			talk_temp[i] = talk_6[Word_count];
			Word_count++;
		}
		outtextxy(50 + count * 16, 350, talk_temp);
		Sleep(100);
		if (GetAsyncKeyState(VK_SPACE))
			break;
		if (GetAsyncKeyState(VK_RETURN))
			return 0;
	}

	Sleep(1000);
	putimage(0, 0, &cg1_1);//开始第三张图片CG
	Sleep(500);
	Word_count = 0;
	count = 0;

	while (Word_count<45)
	{
		count++;
		for (i = 0; i<2; i++)
		{
			talk_temp[i] = talk_7[Word_count];
			Word_count++;
		}
		outtextxy(50 + count * 16, 350, talk_temp);
		Sleep(100);
		if (GetAsyncKeyState(VK_SPACE))
			break;
		if (GetAsyncKeyState(VK_RETURN))
			return 0;
	}

	Sleep(1000);
	putimage(0, 0, &shelter1);
	putimage(150, 0, &cg3_1);//开始第三张图片CG
	Sleep(500);
	Word_count = 0;
	count = 0;

	while (Word_count<45)
	{
		count++;
		for (i = 0; i<2; i++)
		{
			talk_temp[i] = talk_8[Word_count];
			Word_count++;
		}
		outtextxy(50 + count * 16, 350, talk_temp);
		Sleep(100);
		if (GetAsyncKeyState(VK_SPACE))
			break;
		if (GetAsyncKeyState(VK_RETURN))
			return 0;
	}

	Sleep(500);
	putimage(30, 350, &shelter);//涂黑对话
	Word_count = 0;
	count = 0;
	while (Word_count<41)
	{
		count++;
		for (i = 0; i<2; i++)
		{
			talk_temp[i] = talk_9[Word_count];
			Word_count++;
		}
		outtextxy(50 + count * 16, 350, talk_temp);
		Sleep(100);
		if (GetAsyncKeyState(VK_SPACE))
			break;
		if (GetAsyncKeyState(VK_RETURN))
			return 0;
	}

//	Sleep(1000);
//	putimage(0, 0, &shelter1);
//	putimage(150, 0, &cg3); //开始第四张图片

	Sleep(2000);

	//system("pause");
	return 0;
}

int Show_cg2(int score_sum)
{
	int i;
	int count = 0;

	char temps[3] = { 0 };
	int number1 = score_sum/10%10;
	int number2 = score_sum % 10;
	temps[0] = number1 + '0';
	temps[1] = number2 + '0';



	loadimage(&cg4, _T("D:\\test_photo\\cg3_1.jpg"), 400, 400);//加载背景图片

	loadimage(&shelter, _T("D:\\test_photo\\black.jpg"), 600, 20);
	loadimage(&shelter1, _T("D:\\test_photo\\black.jpg"), 800, 400);

	initgraph(800, 400);//根据背景图片的长和宽初始化窗口，使之铺满窗

	putimage(200, 0, &cg4);//在窗口上绘制背景图片

	settextcolor(WHITE);
	setbkcolor(RGB(0, 0, 0));

	//setbkcolor(color);

	while (Word_count<41)
	{
		count++;
		for (i = 0; i<2; i++)
		{
			talk_temp[i] = talk_10[Word_count];
			Word_count++;
		}
		outtextxy(50 + count * 16, 350, talk_temp);
		Sleep(100);
	}
/*	Sleep(500);
	putimage(30, 350, &shelter);//涂黑对话
	Word_count = 0;
	count = 0;*/


	outtextxy(50 + count * 16+10, 350, temps);	
	Sleep(500);
	putimage(30, 350, &shelter);//涂黑对话
	Word_count = 0;
	count = 0;


	while (Word_count<33)
	{
		count++;
		for (i = 0; i<2; i++)
		{
			talk_temp[i] = talk_11[Word_count];
			Word_count++;
		}
		outtextxy(50 + count * 16, 350, talk_temp);
		Sleep(100);
	}

	Sleep(500);
	putimage(30, 350, &shelter);//涂黑对话
	Word_count = 0;
	count = 0;

	while (Word_count<29)
	{
		count++;
		for (i = 0; i<2; i++)
		{
			talk_temp[i] = talk_12[Word_count];
			Word_count++;
		}
		outtextxy(50 + count * 16, 350, talk_temp);
		Sleep(100);
	}
	Sleep(1000);

	Word_count = 0;
	count = 0;


	return 0;
}

int Show_cg3(int score_sum)   //钢琴游戏成功界面
{
	int i;
	IMAGE cg4_1;
	IMAGE cg1_1;
	int count = 0;
	Word_count = 0;

	char temps[3] = { 0 };
	int number1 = score_sum / 10 % 10;
	int number2 = score_sum % 10;
	temps[0] = number1 + '0';
	temps[1] = number2 + '0';

	loadimage(&cg1_1, _T("D:\\test_photo\\white.jpg"), 700, 380);
	loadimage(&cg4_1, _T("D:\\test_photo\\cg4.jpg"), 700, 350);//加载背景图片
	loadimage(&shelter, _T("D:\\test_photo\\black.jpg"), 600, 20);
	loadimage(&shelter1, _T("D:\\test_photo\\black.jpg"), 800, 400);


	loadimage(&number0_1, _T("D:\\test_photo\\0_1.jpg"), 50, 50);//加载数字0图片，按指定大小存储
	loadimage(&number1_1, _T("D:\\test_photo\\1_1.jpg"), 50, 50);//加载数字1图片，按指定大小存储
	loadimage(&number2_1, _T("D:\\test_photo\\2_1.jpg"), 50, 50);//加载数字2图片，按指定大小存储
	loadimage(&number3_1, _T("D:\\test_photo\\3_1.jpg"), 50, 50);//加载数字3图片，按指定大小存储
	loadimage(&number4_1, _T("D:\\test_photo\\4_1.jpg"), 50, 50);//加载数字4图片，按指定大小存储
	loadimage(&number5_1, _T("D:\\test_photo\\5_1.jpg"), 50, 50);//加载数字5图片，按指定大小存储
	loadimage(&number6_1, _T("D:\\test_photo\\6_1.jpg"), 50, 50);//加载数字6图片，按指定大小存储
	loadimage(&number7_1, _T("D:\\test_photo\\7_1.jpg"), 50, 50);//加载数字7图片，按指定大小存储
	loadimage(&number8_1, _T("D:\\test_photo\\8_1.jpg"), 50, 50);//加载数字8图片，按指定大小存储
	loadimage(&number9_1, _T("D:\\test_photo\\9_1.jpg"), 50, 50);//加载数字9图片，按指定大小存储

	initgraph(700, 380);//根据背景图片的长和宽初始化窗口，使之铺满窗

	putimage(0, 0, &cg1_1);//在窗口上绘制背景图片
	putimage(0, 0, &cg4_1);

	print_Score(score_sum);

	settextcolor(BLACK);
	setbkcolor(RGB(255, 255, 255));

	//setbkcolor(color);

	while (Word_count<43)
	{
		count++;
		for (i = 0; i<2; i++)
		{
			talk_temp[i] = talk_13[Word_count];
			Word_count++;
		}
		outtextxy(50 + count * 16, 360, talk_temp);
		Sleep(100);
	}

	outtextxy(50 + count * 16 + 10, 360, temps);
	Sleep(500);
	//putimage(30, 350, &shelter);//涂黑对话
	Word_count = 0;
	count = 0;



	Sleep(1000);


	return 0;
}  

int Show_cg4(int score_sum)   //钢琴游戏失败结束界面
{
	int i;
	int count = 0;
	Word_count = 0;

	char temps[3] = { 0 };
	int number1 = score_sum / 10 % 10;
	int number2 = score_sum % 10;
	temps[0] = number1 + '0';
	temps[1] = number2 + '0';



	loadimage(&cg4, _T("D:\\test_photo\\cg3_1_2.jpg"), 640, 480);//加载背景图片

	loadimage(&shelter, _T("D:\\test_photo\\black.jpg"), 600, 20);
	loadimage(&shelter1, _T("D:\\test_photo\\black.jpg"), 640, 480);

	loadimage(&number0_1, _T("D:\\test_photo\\0.jpg"), 50, 50);//加载数字0图片，按指定大小存储
	loadimage(&number1_1, _T("D:\\test_photo\\1.jpg"), 50, 50);//加载数字1图片，按指定大小存储
	loadimage(&number2_1, _T("D:\\test_photo\\2.jpg"), 50, 50);//加载数字2图片，按指定大小存储
	loadimage(&number3_1, _T("D:\\test_photo\\3.jpg"), 50, 50);//加载数字3图片，按指定大小存储
	loadimage(&number4_1, _T("D:\\test_photo\\4.jpg"), 50, 50);//加载数字4图片，按指定大小存储
	loadimage(&number5_1, _T("D:\\test_photo\\5.jpg"), 50, 50);//加载数字5图片，按指定大小存储
	loadimage(&number6_1, _T("D:\\test_photo\\6.jpg"), 50, 50);//加载数字6图片，按指定大小存储
	loadimage(&number7_1, _T("D:\\test_photo\\7.jpg"), 50, 50);//加载数字7图片，按指定大小存储
	loadimage(&number8_1, _T("D:\\test_photo\\8.jpg"), 50, 50);//加载数字8图片，按指定大小存储
	loadimage(&number9_1, _T("D:\\test_photo\\9.jpg"), 50, 50);//加载数字9图片，按指定大小存储

	initgraph(640, 480);//根据背景图片的长和宽初始化窗口，使之铺满窗

	putimage(0, 0, &cg4);//在窗口上绘制背景图片

	print_Score_1(score_sum);

	settextcolor(WHITE);
	setbkcolor(RGB(0, 0, 0));

	while (Word_count<41)
	{
		count++;
		for (i = 0; i<2; i++)
		{
			talk_temp[i] = talk_10[Word_count];
			Word_count++;
		}
		outtextxy(30 + count * 16, 420, talk_temp);
		Sleep(100);
	}

	outtextxy(30 + count * 16 + 10, 420, temps);
	Sleep(500);
	//putimage(30, 350, &shelter);//涂黑对话
	Word_count = 0;
	count = 0;

	return 0;
}

int Show_cg5(void)
{
	int i, color;
	IMAGE cg1_1;
	IMAGE cg5_1;
	int count = 0;
	Word_count = 0;

	loadimage(&cg1_1, _T("D:\\test_photo\\cg4_1.jpg"), 640, 480);//加载背景图片
	loadimage(&cg5_1, _T("D:\\test_photo\\cg4_2.jpg"), 400, 400);
	loadimage(&shelter, _T("D:\\test_photo\\black.jpg"), 640, 20);
	loadimage(&shelter1, _T("D:\\test_photo\\black.jpg"), 640, 480);
	loadimage(&white1, _T("D:\\test_photo\\white.jpg"), 640, 480);

	initgraph(640, 480);//根据背景图片的长和宽初始化窗口，使之铺满窗

	putimage(0, 0, &cg1_1);//在窗口上绘制背景图片



	settextcolor(WHITE);
	setbkcolor(RGB(0, 0, 0));

	//setbkcolor(color);

	while (Word_count<29)
	{
		count++;
		for (i = 0; i<2; i++)
		{
			talk_temp[i] = talk_14[Word_count];
			Word_count++;
		}
		outtextxy(100 + count * 16, 420, talk_temp);
		Sleep(100);
		if (GetAsyncKeyState(VK_SPACE))
			break;
		if (GetAsyncKeyState(VK_RETURN))
			return 0;
	}
	Sleep(500);
	putimage(30, 420, &shelter);//涂黑对话
	Word_count = 0;
	count = 0;


	while (Word_count<55)
	{
		count++;
		for (i = 0; i<2; i++)
		{
			talk_temp[i] = talk_15[Word_count];
			Word_count++;
		}
		outtextxy(100 + count * 16, 420, talk_temp);
		Sleep(100);
		if (GetAsyncKeyState(VK_SPACE))
			break;
		if (GetAsyncKeyState(VK_RETURN))
			return 0;
	}
	Sleep(500);
	putimage(30, 420, &shelter);//涂黑对话
	Word_count = 0;
	count = 0;

	while (Word_count<33)
	{
		count++;
		for (i = 0; i<2; i++)
		{
			talk_temp[i] = talk_16[Word_count];
			Word_count++;
		}
		outtextxy(100 + count * 16, 420, talk_temp);
		Sleep(100);
		if (GetAsyncKeyState(VK_SPACE))
			break;
		if (GetAsyncKeyState(VK_RETURN))
			return 0;
	}
	Sleep(500);
	putimage(30, 420, &shelter);//涂黑对话
	Word_count = 0;
	count = 0;

	while (Word_count<47)
	{
		count++;
		for (i = 0; i<2; i++)
		{
			talk_temp[i] = talk_17[Word_count];
			Word_count++;
		}
		outtextxy(100 + count * 16, 420, talk_temp);
		Sleep(100);
		if (GetAsyncKeyState(VK_SPACE))
			break;
		if (GetAsyncKeyState(VK_RETURN))
			return 0;
	}
	Sleep(500);
	putimage(30, 420, &shelter);//涂黑对话
	Word_count = 0;
	count = 0;

	while (Word_count<37)
	{
		count++;
		for (i = 0; i<2; i++)
		{
			talk_temp[i] = talk_18[Word_count];
			Word_count++;
		}
		outtextxy(100 + count * 16, 420, talk_temp);
		Sleep(100);
		if (GetAsyncKeyState(VK_SPACE))
			break;
		if (GetAsyncKeyState(VK_RETURN))
			return 0;
	}

	Sleep(500);
	putimage(0, 0, &white1);
	putimage(120, 40, &cg5_1);  //放CG2
	Word_count = 0;
	count = 0;
	settextcolor(BLACK);
	setbkcolor(RGB(255, 255, 255));

	while (Word_count<37)
	{
		count++;
		for (i = 0; i<2; i++)
		{
			talk_temp[i] = talk_19[Word_count];
			Word_count++;
		}
		outtextxy(100 + count * 16, 450, talk_temp);
		Sleep(100);
		if (GetAsyncKeyState(VK_SPACE))
			break;
		if (GetAsyncKeyState(VK_RETURN))
			return 0;
	}

	Sleep(2000);

	//system("pause");
	return 0;
}

int Show_cg6(void)
{
	int i, color;
	IMAGE cg1_1;
	int count = 0;
	Word_count = 0;

	loadimage(&cg1_1, _T("D:\\test_photo\\cg5.jpg"), 640, 480);//加载背景图片
	loadimage(&shelter, _T("D:\\test_photo\\black.jpg"), 640, 20);
	loadimage(&shelter1, _T("D:\\test_photo\\black.jpg"), 640, 480);

	initgraph(640, 480);//根据背景图片的长和宽初始化窗口，使之铺满窗

	putimage(0, 0, &cg1_1);//在窗口上绘制背景图片



	settextcolor(WHITE);
	setbkcolor(RGB(0, 0, 0));

	//setbkcolor(color);

	while (Word_count<63)
	{
		count++;
		for (i = 0; i<2; i++)
		{
			talk_temp[i] = talk_20[Word_count];
			Word_count++;
		}
		outtextxy(50 + count * 16, 450, talk_temp);
		Sleep(100);
		if (GetAsyncKeyState(VK_SPACE))
			break;
		if (GetAsyncKeyState(VK_RETURN))
			return 0;
	}
	Sleep(500);
	putimage(30, 450, &shelter);//涂黑对话
	Word_count = 0;
	count = 0;


	while (Word_count<37)
	{
		count++;
		for (i = 0; i<2; i++)
		{
			talk_temp[i] = talk_21[Word_count];
			Word_count++;
		}
		outtextxy(50 + count * 16, 450, talk_temp);
		Sleep(100);
		if (GetAsyncKeyState(VK_SPACE))
			break;
		if (GetAsyncKeyState(VK_RETURN))
			return 0;
	}
	Sleep(500);
	putimage(30, 450, &shelter);//涂黑对话
	Word_count = 0;
	count = 0;

	while (Word_count<37)
	{
		count++;
		for (i = 0; i<2; i++)
		{
			talk_temp[i] = talk_22[Word_count];
			Word_count++;
		}
		outtextxy(50 + count * 16, 450, talk_temp);
		Sleep(100);
		if (GetAsyncKeyState(VK_SPACE))
			break;
		if (GetAsyncKeyState(VK_RETURN))
			return 0;
	}
	Sleep(500);
	putimage(30, 450, &shelter);//涂黑对话
	Word_count = 0;
	count = 0;

	while (Word_count<47)
	{
		count++;
		for (i = 0; i<2; i++)
		{
			talk_temp[i] = talk_23[Word_count];
			Word_count++;
		}
		outtextxy(50 + count * 16, 450, talk_temp);
		Sleep(100);
		if (GetAsyncKeyState(VK_SPACE))
			break;
		if (GetAsyncKeyState(VK_RETURN))
			return 0;
	}
	Sleep(500);
	//putimage(30, 450, &shelter);//涂黑对话
	Word_count = 0;
	count = 0;

	Sleep(2000);

	//system("pause");
	return 0;
}

int Show_cg7(void)
{
	int i, color;
	IMAGE cg2_1;
	IMAGE shelter_1;
	IMAGE shelter_2;
	int count = 0;
	Word_count = 0;

	loadimage(&cg2_1, _T("D:\\test_photo\\kex.jpg"), 640, 480);//加载背景图片
	loadimage(&shelter_1, _T("D:\\test_photo\\white.jpg"), 640, 20);
	loadimage(&shelter_2, _T("D:\\test_photo\\white.jpg"), 640, 480);

	initgraph(640, 480);//根据背景图片的长和宽初始化窗口，使之铺满窗

	putimage(0, 0, &cg2_1);//在窗口上绘制背景图片



	settextcolor(BLACK);
	setbkcolor(RGB(255, 255, 255));

	//setbkcolor(color);

	while (Word_count<35)
	{
		count++;
		for (i = 0; i<2; i++)
		{
			talk_temp[i] = talk_24[Word_count];
			Word_count++;
		}
		outtextxy(50 + count * 16, 450, talk_temp);
		Sleep(100);
		if (GetAsyncKeyState(VK_SPACE))
			break;
		if (GetAsyncKeyState(VK_RETURN))
			return 0;
	}
	Sleep(500);
	putimage(30, 450, &shelter_2);//涂白对话
	Word_count = 0;
	count = 0;


	while (Word_count<67)
	{
		count++;
		for (i = 0; i<2; i++)
		{
			talk_temp[i] = talk_25[Word_count];
			Word_count++;
		}
		outtextxy(50 + count * 16, 450, talk_temp);
		Sleep(100);
		if (GetAsyncKeyState(VK_SPACE))
			break;
		if (GetAsyncKeyState(VK_RETURN))
			return 0;
	}
	Sleep(500);
	putimage(30, 450, &shelter_2);//涂黑对话
	Word_count = 0;
	count = 0;

	while (Word_count<59)
	{
		count++;
		for (i = 0; i<2; i++)
		{
			talk_temp[i] = talk_26[Word_count];
			Word_count++;
		}
		outtextxy(50 + count * 16, 450, talk_temp);
		Sleep(100);
		if (GetAsyncKeyState(VK_SPACE))
			break;
		if (GetAsyncKeyState(VK_RETURN))
			return 0;
	}
	Sleep(500);
	putimage(30, 450, &shelter_2);//涂黑对话
	Word_count = 0;
	count = 0;

	while (Word_count<47)
	{
		count++;
		for (i = 0; i<2; i++)
		{
			talk_temp[i] = talk_27[Word_count];
			Word_count++;
		}
		outtextxy(50 + count * 16, 450, talk_temp);
		Sleep(100);
		if (GetAsyncKeyState(VK_SPACE))
			break;
		if (GetAsyncKeyState(VK_RETURN))
			return 0;
	}
	Sleep(500);
	//putimage(30, 450, &shelter);//涂黑对话
	Word_count = 0;
	count = 0;

	Sleep(2000);

	//system("pause");
	return 0;
}

int Show_cg8(void)
{
	int i, color;
	IMAGE cg2_1;
	IMAGE shelter_1;
	IMAGE shelter_2;
	int count = 0;
	Word_count = 0;

	loadimage(&cg2_1, _T("D:\\test_photo\\ending.jpg"), 640, 480);//加载背景图片
	loadimage(&shelter_1, _T("D:\\test_photo\\black.jpg"), 640, 20);
	loadimage(&shelter_2, _T("D:\\test_photo\\black.jpg"), 640, 480);

	initgraph(640, 480);//根据背景图片的长和宽初始化窗口，使之铺满窗

	putimage(0, 0, &cg2_1);//在窗口上绘制背景图片



	settextcolor(WHITE);
	setbkcolor(RGB(0, 0, 0));

	//setbkcolor(color);

	while (Word_count<19)
	{
		count++;
		for (i = 0; i<2; i++)
		{
			talk_temp[i] = talk_28[Word_count];
			Word_count++;
		}
		outtextxy(50 + count * 16, 450, talk_temp);
		Sleep(100);
		if (GetAsyncKeyState(VK_SPACE))
			break;
		if (GetAsyncKeyState(VK_RETURN))
			return 0;
	}
	Sleep(500);
	putimage(30, 450, &shelter_2);//涂黑对话
	Word_count = 0;
	count = 0;

	Sleep(2000);
	return 0;
}






