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


typedef struct white_1   //����׿�����1
{
	int x;   //�������λ��
	int y[12];   //��������λ��

}  white_1;


char key;
int Score;  //�÷�
int Miss;  //ʧ��
int cnt = 0;
/*��������*/

IMAGE background;//����
IMAGE amy;       //�������ͼ
IMAGE amy2;       //�����������ͼ
IMAGE black;     //���ڵ�͸��ͼƬ
IMAGE white;     //������Ƭ
//IMAGE maskbitmap(40, 40);
IMAGE number_0;
IMAGE number_1;
IMAGE number_2;
IMAGE number_3;
IMAGE number_4;
IMAGE number_5;
IMAGE number_6;
IMAGE number_7;
IMAGE number_8;
IMAGE number_9;
IMAGE botton1;  //��ť��ͼ
IMAGE botton1_1;  //��ť������ͼ
IMAGE botton2;  //�ɹ���ť��ͼ


void SetPos(int x, int y);
void createmap();
//int main();
int piano_M();
void getkey();
void print_Score();

white_1 A;
white_1 B;
white_1 C;
white_1 D;

/*------*/
/*
��������void SetPos(int x,int y)
��������:�������
������x��yλ������
����ֵ����
*/

void SetPos(int x, int y)                            ///��������
{
	COORD tempCrd;                                  ///��������--�������
	HANDLE Houtput;                                 ///��������--���
	tempCrd.X = x;                                    ///coord position
	tempCrd.Y = y;                                    ///coord position
	Houtput = GetStdHandle(STD_OUTPUT_HANDLE);        ///ʹ��GetStdHandle(STD_OUTPUT_HANDLE)����ȡ��׼����ľ��
	SetConsoleCursorPosition(Houtput, tempCrd);     ///���ù��λ��
}
/*
��������void createmap()
��������:������ͼ
��������
����ֵ����
*/
void createmap()
{
	int i, j;
	for (i = 8; i<21; i += 3) //x ��
	{
		SetPos(i, 9);
		printf("==");
	}
	for (j = 0; j < 10; j++)  // y ��
	{
		SetPos(5, j);
		printf("||");
		SetPos(24, j);
		printf("||");
	}
}

/*
��������Piece *createpiece()
��������:�������ٿ�
��������
����ֵ����
*/

white_1 Create_piece_A(white_1 A)
{
	A.x = 8;
	return A;
}

white_1 Create_piece_B(white_1 B)
{
	B.x = 11;
	return B;
}

white_1 Create_piece_C(white_1 C)
{
	C.x = 14;
	return C;
}
white_1 Create_piece_D(white_1 D)
{
	D.x = 17;
	return D;
}

white_1 Piece_move(white_1 A)
{
	Sleep(25);
	int i;
	for (i = 12; i>0; i--)
	{
		A.y[i] = A.y[i - 1];
	}
	// getkey();
	return A;
}


void print_white(white_1 A)
{
	int i, j, z;
	for (i = 0; i<10; i++)
	{

		//SetPos(A.x, i);
		j = i * 40;
		z = A.x * 30;
		if (A.y[i])
		{
			putimage(z, j, &amy2, SRCAND);
			putimage(z, j, &amy, SRCPAINT);//�ڴ����ϻ��Ʊ���ͼƬ

										   //cout << "��";
		}

		else
		{
		}

	}
	getkey();
	print_Score();
}


void print_Score()
{
	if (Score % 10 == 0)
		putimage(110, 100, &number_0);//�ڴ����ϸ�λ����0ͼƬ
	if (Score % 10 == 1)
		putimage(110, 100, &number_1);//�ڴ����ϸ�λ����1ͼƬ
	if (Score % 10 == 2)
		putimage(110, 100, &number_2);//�ڴ����ϸ�λ����2ͼƬ
	if (Score % 10 == 3)
		putimage(110, 100, &number_3);//�ڴ����ϸ�λ����3ͼƬ
	if (Score % 10 == 4)
		putimage(110, 100, &number_4);//�ڴ����ϸ�λ����4ͼƬ
	if (Score % 10 == 5)
		putimage(110, 100, &number_5);//�ڴ����ϸ�λ����5ͼƬ
	if (Score % 10 == 6)
		putimage(110, 100, &number_6);//�ڴ����ϸ�λ����6ͼƬ
	if (Score % 10 == 7)
		putimage(110, 100, &number_7);//�ڴ����ϸ�λ����7ͼƬ
	if (Score % 10 == 8)
		putimage(110, 100, &number_8);//�ڴ����ϸ�λ����8ͼƬ
	if (Score % 10 == 9)
		putimage(110, 100, &number_9);//�ڴ����ϸ�λ����9ͼƬ

	if (Score / 10 % 10 == 0)
		putimage(50, 100, &number_0);//�ڴ�����ʮλ����0ͼƬ
	if (Score / 10 % 10 == 1)
		putimage(50, 100, &number_1);//�ڴ�����ʮλ����1ͼƬ
	if (Score / 10 % 10 == 2)
		putimage(50, 100, &number_2);//�ڴ�����ʮλ����2ͼƬ
	if (Score / 10 % 10 == 3)
		putimage(50, 100, &number_3);//�ڴ�����ʮλ����3ͼƬ
	if (Score / 10 % 10 == 4)
		putimage(50, 100, &number_4);//�ڴ�����ʮλ����4ͼƬ
	if (Score / 10 % 10 == 5)
		putimage(50, 100, &number_5);//�ڴ�����ʮλ����5ͼƬ
	if (Score / 10 % 10 == 6)
		putimage(50, 100, &number_6);//�ڴ�����ʮλ����6ͼƬ
	if (Score / 10 % 10 == 7)
		putimage(50, 100, &number_7);//�ڴ�����ʮλ����7ͼƬ
	if (Score / 10 % 10 == 8)
		putimage(50, 100, &number_8);//�ڴ�����ʮλ����8ͼƬ
	if (Score / 10 % 10 == 9)
		putimage(50, 100, &number_9);//�ڴ�����ʮλ����9ͼƬ

//��ʾʧ��
	if (Miss % 10 == 0)
		putimage(110, 240, &number_0);//�ڴ����ϸ�λ����0ͼƬ
	if (Miss % 10 == 1)
		putimage(110, 240, &number_1);//�ڴ����ϸ�λ����1ͼƬ
	if (Miss % 10 == 2)
		putimage(110, 240, &number_2);//�ڴ����ϸ�λ����2ͼƬ
	if (Miss % 10 == 3)
		putimage(110, 240, &number_3);//�ڴ����ϸ�λ����3ͼƬ
	if (Miss % 10 == 4)
		putimage(110, 240, &number_4);//�ڴ����ϸ�λ����4ͼƬ
	if (Miss % 10 == 5)
		putimage(110, 240, &number_5);//�ڴ����ϸ�λ����5ͼƬ
	if (Miss % 10 == 6)
		putimage(110, 240, &number_6);//�ڴ����ϸ�λ����6ͼƬ
	if (Miss % 10 == 7)
		putimage(110, 240, &number_7);//�ڴ����ϸ�λ����7ͼƬ
	if (Miss % 10 == 8)
		putimage(110, 240, &number_8);//�ڴ����ϸ�λ����8ͼƬ
	if (Miss % 10 == 9)
		putimage(110, 240, &number_9);//�ڴ����ϸ�λ����9ͼƬ

	if (Miss / 10 % 10 == 0)
		putimage(50, 240, &number_0);//�ڴ�����ʮλ����0ͼƬ
	if (Miss / 10 % 10 == 1)
		putimage(50, 240, &number_1);//�ڴ�����ʮλ����1ͼƬ
	if (Miss / 10 % 10 == 2)
		putimage(50, 240, &number_2);//�ڴ�����ʮλ����2ͼƬ
	if (Miss / 10 % 10 == 3)
		putimage(50, 240, &number_3);//�ڴ�����ʮλ����3ͼƬ
	if (Miss / 10 % 10 == 4)
		putimage(50, 240, &number_4);//�ڴ�����ʮλ����4ͼƬ
	if (Miss / 10 % 10 == 5)
		putimage(50, 240, &number_5);//�ڴ�����ʮλ����5ͼƬ
	if (Miss / 10 % 10 == 6)
		putimage(50, 240, &number_6);//�ڴ�����ʮλ����6ͼƬ
	if (Miss / 10 % 10 == 7)
		putimage(50, 240, &number_7);//�ڴ�����ʮλ����7ͼƬ
	if (Miss / 10 % 10 == 8)
		putimage(50, 240, &number_8);//�ڴ�����ʮλ����8ͼƬ
	if (Miss / 10 % 10 == 9)
		putimage(50, 240, &number_9);//�ڴ�����ʮλ����9ͼƬ

}

void getkey()   //��ʾ�ɹ�
{

	if (GetAsyncKeyState('A') && (A.y[11] == 1))
	{
		Score += 1;
		A.y[11] = 0;
		putimage(240, 400, &botton2);
		SetPos(7, 15);    //ȷ������ַ�λ��
		printf("��������                ");
	}
	if (!GetAsyncKeyState('A') && (A.y[11] == 1))
	{
		Miss = Miss+1;
		A.y[11] = 0;
	}

	if (GetAsyncKeyState('S') && (B.y[11] == 1))
	{
		Score += 1;
		B.y[11] = 0;
		putimage(330, 400, &botton2);
		SetPos(7, 15);    //ȷ������ַ�λ��
		printf("���ʺ��                ");
	}
	if (!GetAsyncKeyState('S') && (B.y[11] == 1))
	{
		Miss = Miss + 1;
		B.y[11] = 0;
	}

	if (GetAsyncKeyState('K') && (C.y[11] == 1))
	{
		Score += 1;
		C.y[11] = 0;
		putimage(420, 400, &botton2);
		SetPos(7, 15);    //ȷ������ַ�λ��
		printf("��������                ");
	}
	if (!GetAsyncKeyState('K') && (C.y[11] == 1))
	{
		Miss = Miss + 1;
		C.y[11] = 0;
	}

	if (GetAsyncKeyState('L') && (D.y[11] == 1))
	{
		Score += 1;
		D.y[11] = 0;
		putimage(510, 400, &botton2);
		SetPos(7, 15);    //ȷ������ַ�λ��
		printf("���ʺ��                ");
	}
	if (!GetAsyncKeyState('L') && (D.y[11] == 1))
	{
		Miss = Miss + 1;
		D.y[11] = 0;
	}

}


void help()   //��Ϸ�淨˵��
{
	SetPos(30, 3);
	printf("��1  --- 1");
	SetPos(30, 11);
	printf("�㹲�����ʧ�����");
	SetPos(30, 4);
	printf("��2  --- 2");
	SetPos(30, 5);
	printf("��3  --- 3");
	SetPos(30, 6);
	printf("��4  --- 4");
	SetPos(30, 7);
	printf("F1��  --- ��ͣ");
	SetPos(30, 9);
	printf("�������ҵȺ����ζ�Ӧ1 2 3 4 ");
}
int piano_M(void)
{
	int i, j;

	SetPos(30, 1);
	printf("����:%d", Score);
	createmap();
	help();
	Score = 0;
	Miss = 0;
	A = Create_piece_A(A);
	B = Create_piece_B(B);
	C = Create_piece_C(C);
	D = Create_piece_D(D);

	initgraph(640, 480);//����ͳһΪ800*600
	//FlushBatchDraw();
	loadimage(&background, _T("D:\\test_photo\\background_piano1_2.jpg"), 640, 480);//���ر���ͼƬ

	loadimage(&amy, _T("D:\\test_photo\\amy.jpg"), 40, 40);//���ذ����ͼƬ����ָ����С�洢
	loadimage(&amy2, _T("D:\\test_photo\\amy2.jpg"), 40, 40);//���ذ��������ͼƬ����ָ����С�洢

	loadimage(&black, _T("D:\\test_photo\\black.jpg"), 40, 40);//���غڰ�ͼƬ����ָ����С�洢
	loadimage(&white, _T("D:\\test_photo\\white.jpg"), 40, 40);//���ذ�ɫͼƬ����ָ����С�洢

	loadimage(&number_0, _T("D:\\test_photo\\0.jpg"), 30, 30);//��������0ͼƬ����ָ����С�洢
	loadimage(&number_1, _T("D:\\test_photo\\1.jpg"), 30, 30);//��������1ͼƬ����ָ����С�洢
	loadimage(&number_2, _T("D:\\test_photo\\2.jpg"), 30, 30);//��������2ͼƬ����ָ����С�洢
	loadimage(&number_3, _T("D:\\test_photo\\3.jpg"), 30, 30);//��������3ͼƬ����ָ����С�洢
	loadimage(&number_4, _T("D:\\test_photo\\4.jpg"), 30, 30);//��������4ͼƬ����ָ����С�洢
	loadimage(&number_5, _T("D:\\test_photo\\5.jpg"), 30, 30);//��������5ͼƬ����ָ����С�洢
	loadimage(&number_6, _T("D:\\test_photo\\6.jpg"), 30, 30);//��������6ͼƬ����ָ����С�洢
	loadimage(&number_7, _T("D:\\test_photo\\7.jpg"), 30, 30);//��������7ͼƬ����ָ����С�洢
	loadimage(&number_8, _T("D:\\test_photo\\8.jpg"), 30, 30);//��������8ͼƬ����ָ����С�洢
	loadimage(&number_9, _T("D:\\test_photo\\9.jpg"), 30, 30);//��������9ͼƬ����ָ����С�洢

	loadimage(&botton1, _T("D:\\test_photo\\botton3.jpg"), 40, 40);//����ͼƬ��ť��ָ����С�洢
	loadimage(&botton2, _T("D:\\test_photo\\botton4.jpg"), 40, 40);//����ͼƬ��ť��ָ����С�洢

	putimage(0, 0, &background);//�ڴ����ϻ��Ʊ���ͼƬ
								//putimage(240, 440, &botton1_1, SRCAND);
								//putimage(240, 440, &botton1, SRCPAINT);
	putimage(240, 400, &botton1);
	putimage(330, 400, &botton1);
	putimage(420, 400, &botton1);
	putimage(510, 400, &botton1);



	for (i = 0; i<12; i++)
	{

		A = Piece_move(A);
		B = Piece_move(B);
		C = Piece_move(C);
		D = Piece_move(D);
		if (i == 1 || i == 10)
			A.y[0] = 1;
		else
			A.y[0] = 0;

		if (i == 1 || i == 10)
			B.y[0] = 1;
		else
			B.y[0] = 0;

		if (i == 6)
			C.y[0] = 1;
		else
			C.y[0] = 0;

		if (i == 6)
			D.y[0] = 1;
		else
			D.y[0] = 0;

		putimage(0, 0, &background);

		//putimage(240, 440, &botton1_1, SRCAND);
		//putimage(240, 440, &botton1, SRCPAINT);
		putimage(240, 400, &botton1);
		putimage(330, 400, &botton1);
		putimage(420, 400, &botton1);
		putimage(510, 400, &botton1);

		print_white(A);
		print_white(B);
		print_white(C);
		print_white(D);



		SetPos(30, 1);
		printf("����:%d", Score);
	}
	PlaySound(TEXT("C:\\Free-Converter.com-hoyo-mix_-_ace-61340641.wav"), NULL, SND_FILENAME | SND_ASYNC);
	//mciSendString(_T("open C:\\Free-Converter.com-hoyo-mix_-_ace-61340641.wav alias music"), NULL, 0, NULL);
	//mciSendString(_T("play music repeat"), NULL, 0, NULL);//�ظ�����
		//A.y[0] = 1;

	for (i = 0; i<12; i++)
	{

		A = Piece_move(A);
		B = Piece_move(B);
		C = Piece_move(C);
		D = Piece_move(D);
		if (i == 3 || i == 10)
			A.y[0] = 1;
		else
			A.y[0] = 0;

		if (i == 3 || i == 10)
			B.y[0] = 1;
		else
			B.y[0] = 0;

		if (i == 6)
			C.y[0] = 1;
		else
			C.y[0] = 0;

		if (i == 6)
			D.y[0] = 1;
		else
			D.y[0] = 0;

		putimage(0, 0, &background);

		//putimage(240, 440, &botton1_1, SRCAND);
		//putimage(240, 440, &botton1, SRCPAINT);
		putimage(240, 400, &botton1);
		putimage(330, 400, &botton1);
		putimage(420, 400, &botton1);
		putimage(510, 400, &botton1);

		print_white(A);
		print_white(B);
		print_white(C);
		print_white(D);


		SetPos(30, 1);
		printf("����:%d", Score);
	}

	//getkey();
	for (i = 0; i<12; i++)
	{
		A = Piece_move(A);
		B = Piece_move(B);
		C = Piece_move(C);
		D = Piece_move(D);

		if (i == 2)
			C.y[0] = 1;
		else
			C.y[0] = 0;

		if (i == 5)
			C.y[0] = 1;
		else
			C.y[0] = 0;

		if (i == 7)
			C.y[0] = 1;
		else
			C.y[0] = 0;

		if (i == 10)
			D.y[0] = 1;
		else
			D.y[0] = 0;

		putimage(0, 0, &background);
		//putimage(240, 440, &botton1_1, SRCAND);
		//putimage(240, 440, &botton1, SRCPAINT);
		putimage(240, 400, &botton1);
		putimage(330, 400, &botton1);
		putimage(420, 400, &botton1);
		putimage(510, 400, &botton1);

		print_white(A);
		print_white(B);
		print_white(C);
		print_white(D);

		SetPos(30, 1);
		printf("����:%d", Score);
	}

	for (i = 0; i<12; i++)
	{
		A = Piece_move(A);
		B = Piece_move(B);
		C = Piece_move(C);
		D = Piece_move(D);

		A.y[0] = 0;
		B.y[0] = 0;

		if (i == 2 || i == 9)
			C.y[0] = 1;
		else
			C.y[0] = 0;

		if (i == 5 || i == 7)
			D.y[0] = 1;
		else
			D.y[0] = 0;

		putimage(0, 0, &background);
		//putimage(240, 440, &botton1_1, SRCAND);
		//putimage(240, 440, &botton1, SRCPAINT);
		putimage(240, 400, &botton1);
		putimage(330, 400, &botton1);
		putimage(420, 400, &botton1);
		putimage(510, 400, &botton1);

		print_white(A);
		print_white(B);
		print_white(C);
		print_white(D);

		SetPos(30, 1);
		printf("����:%d", Score);
	}

	for (i = 0; i<12; i++)
	{
		A = Piece_move(A);
		B = Piece_move(B);
		C = Piece_move(C);
		D = Piece_move(D);

		if (i == 3 || i == 11)
			A.y[0] = 1;
		else
			A.y[0] = 0;

		if (i == 3 || i == 11)
			B.y[0] = 1;
		else
			B.y[0] = 0;

		if (i == 6)
			C.y[0] = 1;
		else
			C.y[0] = 0;

		if (i == 6)
			D.y[0] = 1;
		else
			D.y[0] = 0;

		putimage(0, 0, &background);
		//putimage(240, 440, &botton1_1, SRCAND);
		//putimage(240, 440, &botton1, SRCPAINT);
		putimage(240, 400, &botton1);
		putimage(330, 400, &botton1);
		putimage(420, 400, &botton1);
		putimage(510, 400, &botton1);

		print_white(A);
		print_white(B);
		print_white(C);
		print_white(D);

		SetPos(30, 1);
		printf("����:%d", Score);
	}

	for (i = 0; i<12; i++)
	{

		A = Piece_move(A);
		B = Piece_move(B);
		C = Piece_move(C);
		D = Piece_move(D);
		if (i == 1 || i == 10)
			A.y[0] = 1;
		else
			A.y[0] = 0;

		if (i == 5 || i == 8)
			B.y[0] = 1;
		else
			B.y[0] = 0;

		if (i == 3)
			C.y[0] = 1;
		else
			C.y[0] = 0;

		if (i == 2 || i == 5)
			D.y[0] = 1;
		else
			D.y[0] = 0;

		putimage(0, 0, &background);

		//putimage(240, 440, &botton1_1, SRCAND);
		//putimage(240, 440, &botton1, SRCPAINT);
		putimage(240, 400, &botton1);
		putimage(330, 400, &botton1);
		putimage(420, 400, &botton1);
		putimage(510, 400, &botton1);

		print_white(A);
		print_white(B);
		print_white(C);
		print_white(D);


		SetPos(30, 1);
		printf("����:%d", Score);
	}

	for (i = 0; i<40; i++)
	{

		A = Piece_move(A);
		B = Piece_move(B);
		C = Piece_move(C);
		D = Piece_move(D);
		if (i==3 || i==9 || i==14 || i==16 || i==24 || i==30 ||i==32)
			A.y[0] = 1;
		else
			A.y[0] = 0;

		if (i==3 || i==9 || i==16 || i==26 || i==30 )
			B.y[0] = 1;
		else
			B.y[0] = 0;

		if (i==8 || i==5 || i==10 || i==20 || i==32 ||i==36)
			C.y[0] = 1;
		else
			C.y[0] = 0;

		if (i == 2 || i == 7 || i == 10 ||i==16 ||i==23 ||i==33)
			D.y[0] = 1;
		else
			D.y[0] = 0;

		putimage(0, 0, &background);

		//putimage(240, 440, &botton1_1, SRCAND);
		//putimage(240, 440, &botton1, SRCPAINT);
		putimage(240, 400, &botton1);
		putimage(330, 400, &botton1);
		putimage(420, 400, &botton1);
		putimage(510, 400, &botton1);

		print_white(A);
		print_white(B);
		print_white(C);
		print_white(D);


		SetPos(30, 1);
		printf("����:%d", Score);
	}

	for (i = 0; i<40; i++)
	{

		A = Piece_move(A);
		B = Piece_move(B);
		C = Piece_move(C);
		D = Piece_move(D);
		if (i == 3 || i == 9 || i == 14 || i == 24 || i == 32)
			A.y[0] = 1;
		else
			A.y[0] = 0;

		if (i == 3 || i == 9 || i == 16 || i == 26 || i == 30)
			B.y[0] = 1;
		else
			B.y[0] = 0;

		if (i == 8 || i == 5 || i == 10 || i == 20 || i == 32)
			C.y[0] = 1;
		else
			C.y[0] = 0;

		if (i == 2 || i == 7 || i == 10 || i == 16 || i == 20 || i == 33)
			D.y[0] = 1;
		else
			D.y[0] = 0;

		putimage(0, 0, &background);

		//putimage(240, 440, &botton1_1, SRCAND);
		//putimage(240, 440, &botton1, SRCPAINT);
		putimage(240, 400, &botton1);
		putimage(330, 400, &botton1);
		putimage(420, 400, &botton1);
		putimage(510, 400, &botton1);

		print_white(A);
		print_white(B);
		print_white(C);
		print_white(D);


		SetPos(30, 1);
		printf("����:%d", Score);
	}

	for (i = 0; i<40; i++)
	{

		A = Piece_move(A);
		B = Piece_move(B);
		C = Piece_move(C);
		D = Piece_move(D);
		if (i == 5 || i == 8|| i == 16 || i == 24 || i == 32)
			A.y[0] = 1;
		else
			A.y[0] = 0;

		if (i == 3 || i == 16 || i == 24 || i == 32)
			B.y[0] = 1;
		else
			B.y[0] = 0;

		if (i == 8 || i == 5 || i == 10 || i == 32 || i == 36)
			C.y[0] = 1;
		else
			C.y[0] = 0;

		if (i == 2 || i == 10 || i == 16 || i == 23)
			D.y[0] = 1;
		else
			D.y[0] = 0;

		putimage(0, 0, &background);

		//putimage(240, 440, &botton1_1, SRCAND);
		//putimage(240, 440, &botton1, SRCPAINT);
		putimage(240, 400, &botton1);
		putimage(330, 400, &botton1);
		putimage(420, 400, &botton1);
		putimage(510, 400, &botton1);

		print_white(A);
		print_white(B);
		print_white(C);
		print_white(D);


		SetPos(30, 1);
		printf("����:%d", Score);
	}

	for (i = 0; i<25; i++)
	{

		A = Piece_move(A);
		B = Piece_move(B);
		C = Piece_move(C);
		D = Piece_move(D);
		if (i == 7 ||  i == 14 || i == 16 || i == 23)
			A.y[0] = 1;
		else
			A.y[0] = 0;

		if (i == 7 ||  i == 16 || i == 23 )
			B.y[0] = 1;
		else
			B.y[0] = 0;

		if (i == 8 || i == 5 || i == 20)
			C.y[0] = 1;
		else
			C.y[0] = 0;

		if (i == 2 || i == 7 || i == 10 || i == 16)
			D.y[0] = 1;
		else
			D.y[0] = 0;

		putimage(0, 0, &background);

		//putimage(240, 440, &botton1_1, SRCAND);
		//putimage(240, 440, &botton1, SRCPAINT);
		putimage(240, 400, &botton1);
		putimage(330, 400, &botton1);
		putimage(420, 400, &botton1);
		putimage(510, 400, &botton1);

		print_white(A);
		print_white(B);
		print_white(C);
		print_white(D);


		SetPos(30, 1);
		printf("����:%d", Score);
	}



	for (i = 0; i<12; i++)
	{

		A = Piece_move(A);
		B = Piece_move(B);
		C = Piece_move(C);
		D = Piece_move(D);

		putimage(0, 0, &background);

		//putimage(240, 440, &botton1_1, SRCAND);
		//putimage(240, 440, &botton1, SRCPAINT);
		putimage(240, 400, &botton1);
		putimage(330, 400, &botton1);
		putimage(420, 400, &botton1);
		putimage(510, 400, &botton1);

		print_white(A);
		print_white(B);
		print_white(C);
		print_white(D);
	}
	rewind(stdin);
	Sleep(2000);	
	closegraph();
	system("cls");
	if ((Score - Miss) < 0)
		return 0;
	else
		return Score-Miss;
}
