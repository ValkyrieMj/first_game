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

int main()   //������
{
	int select;  //������¼�
	int flag;   //��ϷĿ¼����

	while(1)
	{
		select = mouse1();		//������Ϸ��ʼ����

tetris_m:     //����˹������Ϸ
		if (select == 1)
		{
			closegraph();
			Show_cg6();
			select = tetris();   //��select = 1,������һ����Ϸ;select=2,����������
		}
		
piano_m:      //���ٿ���Ϸ
		if (select == 1)  //���ѡ��ť1��ʼ������Ϸ
		{
			closegraph();
			Show_cg1();  //��ʼCG1
			while (1) //��һ����Ϸ
			{				
				score_sum = piano_M();  //��ʼ������Ϸ
				if (score_sum >= 20)
				{
					Show_cg3(score_sum);   //������Ϸ�ɹ�����
					select = mouse2();      //����¼�
					if (select == 1)   //�������
					{
						break;
					}

					if (select == 2)
						break;

				}
				else
				{
					Show_cg4(score_sum);     //������Ϸʧ�ܽ�������CG
					select = mouse3();
					//��ʵselect == 1�����¿�ʼ��Ҳ����break���ã����Բ�д��
					if (select == 2)
						break;
				}

			}
			
		}

snaker_m:     //̰������Ϸ
		if (select == 1)
		{
			Show_cg5();  //������һ����Ϸ���ɵ�CG
			flag = snaker();
			select = 2;
			if (flag == 3)
			{
				select = 1;
				Show_cg7();
			}
		}

stg_gjl:      //��Ļ�����Ϸ
		if(select == 1)  
		{
			Show_cg8();
			stg();
			closegraph();
		}

		
		if (select == 3)   //�˳�����
		{
			closegraph();
			break;
			printf("GJLSB");
		}
		if (select == 4)    //��Ϸ�������ѡ��
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
