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


//const TCHAR A[30] = "��ʿ����ʿ";
char talk_1[70] = "����櫣���ʿ����ʿ�������ѣ���ղű�ʯͷ�����ˣ�����";
char talk_2[70] = "�ң�������������ģ�����˭";
char talk_3[70] = "����櫣���ʿ�����ǰ���櫣�������Ϸ̫������";
char talk_4[70] = "�Ҵ�ʱ�����ڴ��ϣ����ɵ���������ȥ";
char talk_5[70] = "����ȴ�����Ѱ�ľ��������ɵ���հ����������������";
char talk_6[70] = "�⡣�������׷�����ʲô";
char talk_7[70] = "�ң����ˣ�����櫣��㵽����¿�������Ӱ�������";
char talk_8[70] = "����櫣���������������ʿ�������ں�����������";
char talk_9[70] = "��Ϊ�ǰ�������������Ա���Ҫ�����ָж���";

char talk_10[70] = "����ʧ�ܣ��������������ָ����ķ����ǣ�";
char talk_11[70] = "�Ƿ��������һ������������������";
char talk_12[70] = "������Ц����û��ѡ����Ϸ����";

char talk_13[70] = "����ɹ�������Ӯ�ð�������Σ���ķ����ǣ�";
char talk_14[70] = "�ң��¾��٣�����ô���⣿����";
char talk_15[70] = "�ҵ��亹����ʪ͸���ҵ��·�����Ϊ�����¾��پ�ûʲô����";
char talk_16[70] = "��֪���Ҿ��ҾʹӰ��������������";
char talk_17[70] = "�¾��٣���Ȼ���ڣ���ô���ռ����ʵ��¾ͽ�������";
char talk_18[70] = "�ң����ţ��¾��٣�������ô�ռ�������";
char talk_19[70] = "�¾��٣��ܼ򵥣�����һ�����߾�������";
char talk_20[70] = "���棬���棬���޹���������ȥ���������ѣ����棬���档����������";
char talk_21[70] = "��ʱ¥��ͻȻ������ʯ���������������";
char talk_22[70] = "�ң������鷳������ɢ����������������";
char talk_23[70] = "�ң����ˣ�����һ�¶���˹���飬����������������";

char talk_24[70] = "����ϣ����ӭ��������ʿ������������";
char talk_25[70] = "��һ�ص��޵µ��Ϳ�������ϣ�������ļ�����ϣ��һ�����;����˸��ҷ���";
char talk_26[70] = "����ϣ�������Ҹ��������һ��㵱������������Ļ�����һ���";
char talk_27[70] = "�ң�����¶࣬����ϣ�����������������Ǻܲ����";

char talk_28[70] = "���ʵ�����Ļ���";
char talk_temp[3] = { 0 };
int Word_count = 0;

IMAGE cg1;//�洢����ͼƬ
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
		putimage(550, 140, &number0_1);//�ڴ����ϸ�λ����0ͼƬ
	if (Score % 10 == 1)
		putimage(550, 140, &number1_1);//�ڴ����ϸ�λ����1ͼƬ
	if (Score % 10 == 2)
		putimage(550, 140, &number2_1);//�ڴ����ϸ�λ����2ͼƬ
	if (Score % 10 == 3)
		putimage(550, 140, &number3_1);//�ڴ����ϸ�λ����3ͼƬ
	if (Score % 10 == 4)
		putimage(550, 140, &number4_1);//�ڴ����ϸ�λ����4ͼƬ
	if (Score % 10 == 5)
		putimage(550, 140, &number5_1);//�ڴ����ϸ�λ����5ͼƬ
	if (Score % 10 == 6)
		putimage(550, 140, &number6_1);//�ڴ����ϸ�λ����6ͼƬ
	if (Score % 10 == 7)
		putimage(550, 140, &number7_1);//�ڴ����ϸ�λ����7ͼƬ
	if (Score % 10 == 8)
		putimage(550, 140, &number8_1);//�ڴ����ϸ�λ����8ͼƬ
	if (Score % 10 == 9)
		putimage(550, 140, &number9_1);//�ڴ����ϸ�λ����9ͼƬ

	if (Score / 10 % 10 == 0)
		putimage(500, 140, &number0_1);//�ڴ�����ʮλ����0ͼƬ
	if (Score / 10 % 10 == 1)
		putimage(500, 140, &number1_1);//�ڴ�����ʮλ����1ͼƬ
	if (Score / 10 % 10 == 2)
		putimage(500, 140, &number2_1);//�ڴ�����ʮλ����2ͼƬ
	if (Score / 10 % 10 == 3)
		putimage(500, 140, &number3_1);//�ڴ�����ʮλ����3ͼƬ
	if (Score / 10 % 10 == 4)
		putimage(500, 140, &number4_1);//�ڴ�����ʮλ����4ͼƬ
	if (Score / 10 % 10 == 5)
		putimage(500, 140, &number5_1);//�ڴ�����ʮλ����5ͼƬ
	if (Score / 10 % 10 == 6)
		putimage(500, 140, &number6_1);//�ڴ�����ʮλ����6ͼƬ
	if (Score / 10 % 10 == 7)
		putimage(500, 140, &number7_1);//�ڴ�����ʮλ����7ͼƬ
	if (Score / 10 % 10 == 8)
		putimage(500, 140, &number8_1);//�ڴ�����ʮλ����8ͼƬ
	if (Score / 10 % 10 == 9)
		putimage(500, 140, &number9_1);//�ڴ�����ʮλ����9ͼƬ

}

void print_Score_1(int Score)
{
	if (Score % 10 == 0)
		putimage(500, 100, &number0_1);//�ڴ����ϸ�λ����0ͼƬ
	if (Score % 10 == 1)
		putimage(500, 100, &number1_1);//�ڴ����ϸ�λ����1ͼƬ
	if (Score % 10 == 2)
		putimage(500, 100, &number2_1);//�ڴ����ϸ�λ����2ͼƬ
	if (Score % 10 == 3)
		putimage(500, 100, &number3_1);//�ڴ����ϸ�λ����3ͼƬ
	if (Score % 10 == 4)
		putimage(500, 100, &number4_1);//�ڴ����ϸ�λ����4ͼƬ
	if (Score % 10 == 5)
		putimage(500, 100, &number5_1);//�ڴ����ϸ�λ����5ͼƬ
	if (Score % 10 == 6)
		putimage(500, 100, &number6_1);//�ڴ����ϸ�λ����6ͼƬ
	if (Score % 10 == 7)
		putimage(500, 100, &number7_1);//�ڴ����ϸ�λ����7ͼƬ
	if (Score % 10 == 8)
		putimage(500, 100, &number8_1);//�ڴ����ϸ�λ����8ͼƬ
	if (Score % 10 == 9)
		putimage(500, 100, &number9_1);//�ڴ����ϸ�λ����9ͼƬ

	if (Score / 10 % 10 == 0)
		putimage(450, 100, &number0_1);//�ڴ�����ʮλ����0ͼƬ
	if (Score / 10 % 10 == 1)
		putimage(450, 100, &number1_1);//�ڴ�����ʮλ����1ͼƬ
	if (Score / 10 % 10 == 2)
		putimage(450, 100, &number2_1);//�ڴ�����ʮλ����2ͼƬ
	if (Score / 10 % 10 == 3)
		putimage(450, 100, &number3_1);//�ڴ�����ʮλ����3ͼƬ
	if (Score / 10 % 10 == 4)
		putimage(450, 100, &number4_1);//�ڴ�����ʮλ����4ͼƬ
	if (Score / 10 % 10 == 5)
		putimage(450, 100, &number5_1);//�ڴ�����ʮλ����5ͼƬ
	if (Score / 10 % 10 == 6)
		putimage(450, 100, &number6_1);//�ڴ�����ʮλ����6ͼƬ
	if (Score / 10 % 10 == 7)
		putimage(450, 100, &number7_1);//�ڴ�����ʮλ����7ͼƬ
	if (Score / 10 % 10 == 8)
		putimage(450, 100, &number8_1);//�ڴ�����ʮλ����8ͼƬ
	if (Score / 10 % 10 == 9)
		putimage(450, 100, &number9_1);//�ڴ�����ʮλ����9ͼƬ

}

int Show_cg1(void)
{
	int i, color;
	int count = 0;
	Word_count = 0;

	IMAGE cg1_1;
	IMAGE cg2_1;
	IMAGE cg3_1;

	loadimage(&cg1_1, _T("D:\\test_photo\\cg1.jpg"), 800, 400);//���ر���ͼƬ
	loadimage(&cg2_1, _T("D:\\test_photo\\cg2_1.jpg"), 800, 400);
	loadimage(&cg3, _T("D:\\test_photo\\cg3.jpg"), 400, 400);
	loadimage(&cg3_1, _T("D:\\test_photo\\cg3_1.jpg"), 400, 400);
	loadimage(&shelter, _T("D:\\test_photo\\black.jpg"), 600, 20);
	loadimage(&shelter1, _T("D:\\test_photo\\black.jpg"), 800, 400);


	initgraph(800, 400);//���ݱ���ͼƬ�ĳ��Ϳ��ʼ�����ڣ�ʹ֮������


	putimage(0, 0, &cg1_1);//�ڴ����ϻ��Ʊ���ͼƬ

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
	putimage(30, 350, &shelter);//Ϳ�ڶԻ�
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
	putimage(30, 350, &shelter);//Ϳ�ڶԻ�
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
	putimage(30, 350, &shelter);//Ϳ�ڶԻ�
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
	putimage(30, 350, &shelter);//Ϳ�ڶԻ�
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
	putimage(0, 0, &cg1_1);//��ʼ������ͼƬCG
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
	putimage(150, 0, &cg3_1);//��ʼ������ͼƬCG
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
	putimage(30, 350, &shelter);//Ϳ�ڶԻ�
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
//	putimage(150, 0, &cg3); //��ʼ������ͼƬ

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



	loadimage(&cg4, _T("D:\\test_photo\\cg3_1.jpg"), 400, 400);//���ر���ͼƬ

	loadimage(&shelter, _T("D:\\test_photo\\black.jpg"), 600, 20);
	loadimage(&shelter1, _T("D:\\test_photo\\black.jpg"), 800, 400);

	initgraph(800, 400);//���ݱ���ͼƬ�ĳ��Ϳ��ʼ�����ڣ�ʹ֮������

	putimage(200, 0, &cg4);//�ڴ����ϻ��Ʊ���ͼƬ

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
	putimage(30, 350, &shelter);//Ϳ�ڶԻ�
	Word_count = 0;
	count = 0;*/


	outtextxy(50 + count * 16+10, 350, temps);	
	Sleep(500);
	putimage(30, 350, &shelter);//Ϳ�ڶԻ�
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
	putimage(30, 350, &shelter);//Ϳ�ڶԻ�
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

int Show_cg3(int score_sum)   //������Ϸ�ɹ�����
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
	loadimage(&cg4_1, _T("D:\\test_photo\\cg4.jpg"), 700, 350);//���ر���ͼƬ
	loadimage(&shelter, _T("D:\\test_photo\\black.jpg"), 600, 20);
	loadimage(&shelter1, _T("D:\\test_photo\\black.jpg"), 800, 400);


	loadimage(&number0_1, _T("D:\\test_photo\\0_1.jpg"), 50, 50);//��������0ͼƬ����ָ����С�洢
	loadimage(&number1_1, _T("D:\\test_photo\\1_1.jpg"), 50, 50);//��������1ͼƬ����ָ����С�洢
	loadimage(&number2_1, _T("D:\\test_photo\\2_1.jpg"), 50, 50);//��������2ͼƬ����ָ����С�洢
	loadimage(&number3_1, _T("D:\\test_photo\\3_1.jpg"), 50, 50);//��������3ͼƬ����ָ����С�洢
	loadimage(&number4_1, _T("D:\\test_photo\\4_1.jpg"), 50, 50);//��������4ͼƬ����ָ����С�洢
	loadimage(&number5_1, _T("D:\\test_photo\\5_1.jpg"), 50, 50);//��������5ͼƬ����ָ����С�洢
	loadimage(&number6_1, _T("D:\\test_photo\\6_1.jpg"), 50, 50);//��������6ͼƬ����ָ����С�洢
	loadimage(&number7_1, _T("D:\\test_photo\\7_1.jpg"), 50, 50);//��������7ͼƬ����ָ����С�洢
	loadimage(&number8_1, _T("D:\\test_photo\\8_1.jpg"), 50, 50);//��������8ͼƬ����ָ����С�洢
	loadimage(&number9_1, _T("D:\\test_photo\\9_1.jpg"), 50, 50);//��������9ͼƬ����ָ����С�洢

	initgraph(700, 380);//���ݱ���ͼƬ�ĳ��Ϳ��ʼ�����ڣ�ʹ֮������

	putimage(0, 0, &cg1_1);//�ڴ����ϻ��Ʊ���ͼƬ
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
	//putimage(30, 350, &shelter);//Ϳ�ڶԻ�
	Word_count = 0;
	count = 0;



	Sleep(1000);


	return 0;
}  

int Show_cg4(int score_sum)   //������Ϸʧ�ܽ�������
{
	int i;
	int count = 0;
	Word_count = 0;

	char temps[3] = { 0 };
	int number1 = score_sum / 10 % 10;
	int number2 = score_sum % 10;
	temps[0] = number1 + '0';
	temps[1] = number2 + '0';



	loadimage(&cg4, _T("D:\\test_photo\\cg3_1_2.jpg"), 640, 480);//���ر���ͼƬ

	loadimage(&shelter, _T("D:\\test_photo\\black.jpg"), 600, 20);
	loadimage(&shelter1, _T("D:\\test_photo\\black.jpg"), 640, 480);

	loadimage(&number0_1, _T("D:\\test_photo\\0.jpg"), 50, 50);//��������0ͼƬ����ָ����С�洢
	loadimage(&number1_1, _T("D:\\test_photo\\1.jpg"), 50, 50);//��������1ͼƬ����ָ����С�洢
	loadimage(&number2_1, _T("D:\\test_photo\\2.jpg"), 50, 50);//��������2ͼƬ����ָ����С�洢
	loadimage(&number3_1, _T("D:\\test_photo\\3.jpg"), 50, 50);//��������3ͼƬ����ָ����С�洢
	loadimage(&number4_1, _T("D:\\test_photo\\4.jpg"), 50, 50);//��������4ͼƬ����ָ����С�洢
	loadimage(&number5_1, _T("D:\\test_photo\\5.jpg"), 50, 50);//��������5ͼƬ����ָ����С�洢
	loadimage(&number6_1, _T("D:\\test_photo\\6.jpg"), 50, 50);//��������6ͼƬ����ָ����С�洢
	loadimage(&number7_1, _T("D:\\test_photo\\7.jpg"), 50, 50);//��������7ͼƬ����ָ����С�洢
	loadimage(&number8_1, _T("D:\\test_photo\\8.jpg"), 50, 50);//��������8ͼƬ����ָ����С�洢
	loadimage(&number9_1, _T("D:\\test_photo\\9.jpg"), 50, 50);//��������9ͼƬ����ָ����С�洢

	initgraph(640, 480);//���ݱ���ͼƬ�ĳ��Ϳ��ʼ�����ڣ�ʹ֮������

	putimage(0, 0, &cg4);//�ڴ����ϻ��Ʊ���ͼƬ

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
	//putimage(30, 350, &shelter);//Ϳ�ڶԻ�
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

	loadimage(&cg1_1, _T("D:\\test_photo\\cg4_1.jpg"), 640, 480);//���ر���ͼƬ
	loadimage(&cg5_1, _T("D:\\test_photo\\cg4_2.jpg"), 400, 400);
	loadimage(&shelter, _T("D:\\test_photo\\black.jpg"), 640, 20);
	loadimage(&shelter1, _T("D:\\test_photo\\black.jpg"), 640, 480);
	loadimage(&white1, _T("D:\\test_photo\\white.jpg"), 640, 480);

	initgraph(640, 480);//���ݱ���ͼƬ�ĳ��Ϳ��ʼ�����ڣ�ʹ֮������

	putimage(0, 0, &cg1_1);//�ڴ����ϻ��Ʊ���ͼƬ



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
	putimage(30, 420, &shelter);//Ϳ�ڶԻ�
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
	putimage(30, 420, &shelter);//Ϳ�ڶԻ�
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
	putimage(30, 420, &shelter);//Ϳ�ڶԻ�
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
	putimage(30, 420, &shelter);//Ϳ�ڶԻ�
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
	putimage(120, 40, &cg5_1);  //��CG2
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

	loadimage(&cg1_1, _T("D:\\test_photo\\cg5.jpg"), 640, 480);//���ر���ͼƬ
	loadimage(&shelter, _T("D:\\test_photo\\black.jpg"), 640, 20);
	loadimage(&shelter1, _T("D:\\test_photo\\black.jpg"), 640, 480);

	initgraph(640, 480);//���ݱ���ͼƬ�ĳ��Ϳ��ʼ�����ڣ�ʹ֮������

	putimage(0, 0, &cg1_1);//�ڴ����ϻ��Ʊ���ͼƬ



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
	putimage(30, 450, &shelter);//Ϳ�ڶԻ�
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
	putimage(30, 450, &shelter);//Ϳ�ڶԻ�
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
	putimage(30, 450, &shelter);//Ϳ�ڶԻ�
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
	//putimage(30, 450, &shelter);//Ϳ�ڶԻ�
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

	loadimage(&cg2_1, _T("D:\\test_photo\\kex.jpg"), 640, 480);//���ر���ͼƬ
	loadimage(&shelter_1, _T("D:\\test_photo\\white.jpg"), 640, 20);
	loadimage(&shelter_2, _T("D:\\test_photo\\white.jpg"), 640, 480);

	initgraph(640, 480);//���ݱ���ͼƬ�ĳ��Ϳ��ʼ�����ڣ�ʹ֮������

	putimage(0, 0, &cg2_1);//�ڴ����ϻ��Ʊ���ͼƬ



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
	putimage(30, 450, &shelter_2);//Ϳ�׶Ի�
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
	putimage(30, 450, &shelter_2);//Ϳ�ڶԻ�
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
	putimage(30, 450, &shelter_2);//Ϳ�ڶԻ�
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
	//putimage(30, 450, &shelter);//Ϳ�ڶԻ�
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

	loadimage(&cg2_1, _T("D:\\test_photo\\ending.jpg"), 640, 480);//���ر���ͼƬ
	loadimage(&shelter_1, _T("D:\\test_photo\\black.jpg"), 640, 20);
	loadimage(&shelter_2, _T("D:\\test_photo\\black.jpg"), 640, 480);

	initgraph(640, 480);//���ݱ���ͼƬ�ĳ��Ϳ��ʼ�����ڣ�ʹ֮������

	putimage(0, 0, &cg2_1);//�ڴ����ϻ��Ʊ���ͼƬ



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
	putimage(30, 450, &shelter_2);//Ϳ�ڶԻ�
	Word_count = 0;
	count = 0;

	Sleep(2000);
	return 0;
}






