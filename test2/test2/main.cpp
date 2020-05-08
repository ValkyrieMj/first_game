#define _CRT_SECURE_NO_DEPRECATE
#include <tchar.h>
#include<graphics.h>
#include<conio.h>

#include<stdio.h>
#include<windows.h>
#include<time.h>
#include<iostream>
#include<Mmsystem.h>
#pragma comment(lib,"winmm.lib")
using namespace std;
#include"Main_Show.cpp"
#include"piano.cpp"
#include"Mouse.cpp"
#include"Tetris.cpp"
#include"Snaker.cpp"
#include"STG.cpp"

int score_sum;

using namespace std;
/*int main()
{
	//int a;
//	Show_cg1();
//	while (1)
//	{
		//score_sum = 20;
//		score_sum = piano_M();
//		if (score_sum > 30)
//			break;
//		else
//			Show_cg3(score_sum);
//	}
	
	//Show_cg7();
	//tetris();
	//snaker();
	stg();
	system("pause");
	return 0;
}*/

int main()   //主界面
{
	int select;  //鼠标点击事件
	int flag;   //游戏目录界面

	while(1)
	{
		select = mouse1();		//加载游戏开始界面

tetris_m:     //俄罗斯方块游戏
		if (select == 1)
		{
			closegraph();
			Show_cg6();
			select = tetris();   //当select = 1,进行下一个游戏;select=2,跳回主界面
		}
		
piano_m:      //钢琴块游戏
		if (select == 1)  //如果选择按钮1开始钢琴游戏
		{
			closegraph();
			Show_cg1();  //开始CG1
			while (1) //第一个游戏
			{				
				score_sum = piano_M();  //开始钢琴游戏
				if (score_sum >= 20)
				{
					Show_cg3(score_sum);   //钢琴游戏成功界面
					select = mouse2();      //点击事件
					if (select == 1)   //点击继续
					{
						break;
					}

					if (select == 2)
						break;

				}
				else
				{
					Show_cg4(score_sum);     //钢琴游戏失败结束界面CG
					select = mouse3();
					//其实select == 1是重新开始，也就是break不用，所以不写了
					if (select == 2)
						break;
				}

			}
			
		}

snaker_m:     //贪吃蛇游戏
		if (select == 1)
		{
			Show_cg5();  //跳到下一个游戏过渡的CG
			flag = snaker();
			select = 2;
			if (flag == 3)
			{
				select = 1;
				Show_cg7();
			}
		}

stg_gjl:      //弹幕射击游戏
		if(select == 1)  
		{
			Show_cg8();
			stg();
			closegraph();
		}

		
		if (select == 3)   //退出函数
		{
			closegraph();
			break;
			printf("GJLSB");
		}
		if (select == 4)    //游戏界面鼠标选择
		{
			flag = mouse4();
			if (flag == 1)   
			{
				select = 1;
				goto tetris_m;
			}				
			if (flag == 2)
			{
				select = 1;
				goto piano_m;
			}
				
			if (flag == 3)
			{
				select = 1;
				goto snaker_m;
			}
			if(flag == 4)
			{
				select = 1;
				goto stg_gjl;
			}
				
		}
	}


	closegraph();
	//Show_cg5();     
	return 0;
}
