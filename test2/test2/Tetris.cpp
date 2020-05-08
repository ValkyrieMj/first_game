#include <easyx.h>
#include <graphics.h>
#include <conio.h>
#include <time.h>
#include <math.h>



/////////////////////////////////////////////
// 定义常量、枚举量、结构体、全局变量
/////////////////////////////////////////////

#define	WIDTH	12		// 游戏区宽度
#define	HEIGHT	19		// 游戏区高度
#define	UNIT	20		// 每个游戏区单位的实际像素

// 定义操作类型
enum CMD
{
	CMD_ROTATE,						// 方块旋转
	CMD_LEFT, CMD_RIGHT, CMD_DOWN,	// 方块左、右、下移动
	CMD_SINK,						// 方块沉底
	CMD_QUIT						// 退出游戏
};

// 定义绘制方块的方法
enum DRAW
{
	SHOW,	// 显示方块
	CLEAR,	// 擦除方块
	FIX		// 固定方块
};

// 定义七种俄罗斯方块
struct BLOCK
{
	WORD dir[4];	// 方块的四个旋转状态
	COLORREF color;	// 方块的颜色
}	g_Blocks[7] = { { 0x0F00, 0x4444, 0x0F00, 0x4444, RED },		// I
{ 0x0660, 0x0660, 0x0660, 0x0660, BLUE },		// 口
{ 0x4460, 0x0740, 0x0622, 0x02E0, MAGENTA },	// L
{ 0x2260, 0x0470, 0x0644, 0x0E20, YELLOW },	// 反L
{ 0x0C60, 0x2640, 0x0C60, 0x2640, CYAN },		// Z
{ 0x0360, 0x4620, 0x0360, 0x4620, GREEN },	// 反Z
{ 0x4E00, 0x4640, 0x0E40, 0x4C40, BROWN } };	// T

												// 定义当前方块、下一个方块的信息
struct BLOCKINFO
{
	byte id;	// 方块 ID
	char x, y;	// 方块在游戏区中的坐标
	byte dir : 2;	// 方向
}	g_CurBlock, g_NextBlock;

// 定义游戏区
BYTE g_World[WIDTH][HEIGHT] = { 0 };
int SCORE[5] = { 0 };
int flag;   //mxj


/////////////////////////////////////////////
// 函数声明
/////////////////////////////////////////////

void Init();											// 初始化游戏
int Quit();											// 退出游戏
void NewGame();											// 开始新游戏
void GameOver();										// 结束游戏
void GameOk();										// 结束游戏
CMD  GetCmd();											// 获取控制命令
void DispatchCmd(CMD _cmd);								// 分发控制命令
void NewBlock();										// 生成新的方块
bool CheckBlock(BLOCKINFO _block);						// 检测指定方块是否可以放下
void DrawUnit(int x, int y, COLORREF c, DRAW _draw);	// 画单元方块
void DrawBlock(BLOCKINFO _block, DRAW _draw = SHOW);	// 画方块
void OnRotate();										// 旋转方块
void OnLeft();											// 左移方块
void OnRight();											// 右移方块
void OnDown();											// 下移方块
void OnSink();											// 沉底方块

void ToTheString(int x, char ch[4]);								//将数字转换成一个字符串

																	/////////////////////////////////////////////
																	// 函数定义
																	/////////////////////////////////////////////

																	// 主函数
int tetris()
{
	Init();

	CMD c;
	while (true)
	{
		c = GetCmd();
		DispatchCmd(c);

		// 按退出时，显示对话框咨询用户是否退出
		if (c == CMD_QUIT)
		{
			HWND wnd = GetHWnd();
			if (MessageBox(wnd, _T("您要退出游戏吗？"), _T("提醒"), MB_OKCANCEL | MB_ICONQUESTION) == IDOK)
				//Quit();
				return 2;
		}
		if (flag == 1)
			return 1;
		if (flag == 2)
			return 2;

	}
	return 1;
}


// 初始化游戏
void Init()
{
	initgraph(640, 480);
	srand((unsigned)time(NULL));
	setbkmode(TRANSPARENT);			// 设置图案填充的背景色为透明
	loadimage(NULL, _T("C:\\Users\\lenovo\\source\\repos\\Project2\\pic2.jpg"), 640, 480);

	// 显示操作说明
	settextstyle(14, 0, _T("宋体"));
	outtextxy((WIDTH + 13) * UNIT - 1, 280, _T("操作说明"));
	outtextxy((WIDTH + 13) * UNIT - 1, 300, _T("上：旋转"));
	outtextxy((WIDTH + 13) * UNIT - 1, 320, _T("左：左移"));
	outtextxy((WIDTH + 13) * UNIT - 1, 340, _T("右：右移"));
	outtextxy((WIDTH + 13) * UNIT - 1, 360, _T("下：下移"));
	outtextxy((WIDTH + 13) * UNIT - 1, 380, _T("空格：沉底"));
	outtextxy((WIDTH + 13) * UNIT - 1, 400, _T("ESC：退出"));
	settextstyle(18, 0, _T("楷体"));
	outtextxy((WIDTH + 13) * UNIT - 1, 430, _T("俄罗斯方块"));
	outtextxy((WIDTH + 13) * UNIT - 1, 450, _T("By Cxk篮球组"));
	settextstyle(16, 0, _T("宋体"));
	outtextxy(20, 60, _T("积分说明："));
	outtextxy(20, 80, _T("分数大于999退出游戏"));
	outtextxy(20, 240, _T("总积分如下："));
	outtextxy(20, 260, _T("消去一行数："));
	outtextxy(20, 280, _T("消去二行数："));
	outtextxy(20, 300, _T("消去三行数："));
	outtextxy(20, 320, _T("消去四行数："));
	settextstyle(14, 0, _T("宋体"));
	outtextxy(20, 100, _T("一次消去一行加10分"));
	outtextxy(20, 120, _T("一次消去两行加30分"));
	outtextxy(20, 140, _T("一次消去三行加50分"));
	outtextxy(20, 160, _T("一次消去四行加100分"));
	char s[4] = { 0 };
	ToTheString(0, s);
	outtextxy(120, 240, _T(s));
	outtextxy(120, 260, _T(s));
	outtextxy(120, 280, _T(s));
	outtextxy(120, 300, _T(s));
	outtextxy(120, 320, _T(s));


	// 设置坐标原点
	setorigin(220, 50);

	// 绘制游戏区边界
	rectangle(-1, -1, WIDTH * UNIT, HEIGHT * UNIT);
	rectangle((WIDTH + 1) * UNIT - 1, -1, (WIDTH + 5) * UNIT, 4 * UNIT);

	SCORE[5] = { 0 };
	flag = 0;

	// 开始新游戏
	NewGame();
}


// 退出游戏
int Quit()
{
	closegraph();
	return 2;
}


// 开始新游戏
void NewGame()
{
	// 清空游戏区
	setfillcolor(BLACK);
	solidrectangle(0, 0, WIDTH * UNIT - 1, HEIGHT * UNIT - 1);
	ZeroMemory(g_World, WIDTH * HEIGHT);

	//分数清零
	char s[4] = { 0 };
	ToTheString(0, s);
	clearrectangle(-100, 190, -50, 210);
	clearrectangle(-100, 210, -50, 230);
	clearrectangle(-100, 230, -50, 250);
	clearrectangle(-100, 250, -50, 270);
	clearrectangle(-100, 270, -50, 290);
	outtextxy(-100, 190, _T(s));
	outtextxy(-100, 210, _T(s));
	outtextxy(-100, 230, _T(s));
	outtextxy(-100, 250, _T(s));
	outtextxy(-100, 270, _T(s));

	// 生成下一个方块
	g_NextBlock.id = rand() % 7;
	g_NextBlock.dir = rand() % 4;
	g_NextBlock.x = WIDTH + 1;
	g_NextBlock.y = HEIGHT - 1;

	// 获取新方块
	NewBlock();
}


// 结束游戏
void GameOver()
{
	HWND wnd = GetHWnd();
	if (MessageBox(wnd, _T("游戏失败。\n您想重新来一局吗？"), _T("游戏结束"), MB_YESNO | MB_ICONQUESTION) == IDYES)
		NewGame();
	else
	{
		flag = 2;
	}
		
}


// 结束游戏
void GameOk()
{
	HWND wnd = GetHWnd();
	if (MessageBox(wnd, _T("分数达到。\n您想继续下一游戏吗？"), _T("游戏结束"), MB_YESNO | MB_ICONQUESTION) == IDYES)
		flag = 1;
	else
		flag = 2;
}
// 获取控制命令
DWORD m_oldtime;
CMD GetCmd()
{
	// 获取控制值
	while (true)
	{
		// 如果超时，自动下落一格
		DWORD newtime = GetTickCount();
		if (newtime - m_oldtime >= 500 - SCORE[0] / 5)
		{
			m_oldtime = newtime;
			return CMD_DOWN;
		}

		// 如果有按键，返回按键对应的功能
		if (_kbhit())
		{
			switch (_getch())
			{
			case 27:	return CMD_QUIT;
			case ' ':	return CMD_SINK;
			case 0:
			case 0xE0:
				switch (_getch())
				{
				case 72:	return CMD_ROTATE;
				case 75:	return CMD_LEFT;
				case 77:	return CMD_RIGHT;
				case 80:	return CMD_DOWN;
				}
			}
		}

		// 延时 (降低 CPU 占用率)
		Sleep(20);
	}
}


// 分发控制命令
void DispatchCmd(CMD _cmd)
{
	switch (_cmd)
	{
	case CMD_ROTATE:	OnRotate();		break;
	case CMD_LEFT:		OnLeft();		break;
	case CMD_RIGHT:		OnRight();		break;
	case CMD_DOWN:		OnDown();		break;
	case CMD_SINK:		OnSink();		break;
	case CMD_QUIT:		break;
	}
}


// 生成新的方块
void NewBlock()
{
	g_CurBlock.id = g_NextBlock.id, g_NextBlock.id = rand() % 7;
	g_CurBlock.dir = g_NextBlock.dir, g_NextBlock.dir = rand() % 4;
	g_CurBlock.x = (WIDTH - 4) / 2;
	g_CurBlock.y = HEIGHT + 2;

	// 下移新方块直到有局部显示
	WORD c = g_Blocks[g_CurBlock.id].dir[g_CurBlock.dir];
	while ((c & 0xF) == 0)
	{
		g_CurBlock.y--;
		c >>= 4;
	}

	// 绘制新方块
	DrawBlock(g_CurBlock);

	// 绘制下一个方块
	setfillcolor(BLACK);
	solidrectangle((WIDTH + 1) * UNIT, 0, (WIDTH + 5) * UNIT - 1, 4 * UNIT - 1);
	DrawBlock(g_NextBlock);

	// 设置计时器，用于判断自动下落
	m_oldtime = GetTickCount();
}


// 画单元方块
void DrawUnit(int x, int y, COLORREF c, DRAW _draw)
{
	// 计算单元方块对应的屏幕坐标
	int left = x * UNIT;
	int top = (HEIGHT - y - 1) * UNIT;
	int right = (x + 1) * UNIT - 1;
	int bottom = (HEIGHT - y) * UNIT - 1;

	// 画单元方块
	switch (_draw)
	{
	case SHOW:
		// 画普通方块
		setlinecolor(0x006060);
		roundrect(left + 1, top + 1, right - 1, bottom - 1, 5, 5);
		setlinecolor(0x003030);
		roundrect(left, top, right, bottom, 8, 8);
		setfillcolor(c);
		setlinecolor(LIGHTGRAY);
		fillrectangle(left + 2, top + 2, right - 2, bottom - 2);
		break;

	case FIX:
		// 画固定的方块
		setfillcolor(RGB(GetRValue(c) * 2 / 3, GetGValue(c) * 2 / 3, GetBValue(c) * 2 / 3));
		setlinecolor(DARKGRAY);
		fillrectangle(left + 1, top + 1, right - 1, bottom - 1);
		break;

	case CLEAR:
		// 擦除方块
		setfillcolor(BLACK);
		solidrectangle(x * UNIT, (HEIGHT - y - 1) * UNIT, (x + 1) * UNIT - 1, (HEIGHT - y) * UNIT - 1);
		break;
	}
}


// 画方块
void DrawBlock(BLOCKINFO _block, DRAW _draw)
{
	WORD b = g_Blocks[_block.id].dir[_block.dir];
	int x, y;

	for (int i = 0; i < 16; i++, b <<= 1)
		if (b & 0x8000)
		{
			x = _block.x + i % 4;
			y = _block.y - i / 4;
			if (y < HEIGHT)
				DrawUnit(x, y, g_Blocks[_block.id].color, _draw);
		}
}


// 检测指定方块是否可以放下
bool CheckBlock(BLOCKINFO _block)
{
	WORD b = g_Blocks[_block.id].dir[_block.dir];
	int x, y;

	for (int i = 0; i < 16; i++, b <<= 1)
		if (b & 0x8000)
		{
			x = _block.x + i % 4;
			y = _block.y - i / 4;
			if ((x < 0) || (x >= WIDTH) || (y < 0))
				return false;

			if ((y < HEIGHT) && (g_World[x][y]))
				return false;
		}

	return true;
}


// 旋转方块
void OnRotate()
{
	// 获取可以旋转的 x 偏移量
	int dx;
	BLOCKINFO tmp = g_CurBlock;
	tmp.dir++;					if (CheckBlock(tmp)) { dx = 0;		goto rotate; }
	tmp.x = g_CurBlock.x - 1;	if (CheckBlock(tmp)) { dx = -1;	goto rotate; }
	tmp.x = g_CurBlock.x + 1;	if (CheckBlock(tmp)) { dx = 1;		goto rotate; }
	tmp.x = g_CurBlock.x - 2;	if (CheckBlock(tmp)) { dx = -2;	goto rotate; }
	tmp.x = g_CurBlock.x + 2;	if (CheckBlock(tmp)) { dx = 2;		goto rotate; }
	return;

rotate:
	// 旋转
	DrawBlock(g_CurBlock, CLEAR);
	g_CurBlock.dir++;
	g_CurBlock.x += dx;
	DrawBlock(g_CurBlock);
}


// 左移方块
void OnLeft()
{
	BLOCKINFO tmp = g_CurBlock;
	tmp.x--;
	if (CheckBlock(tmp))
	{
		DrawBlock(g_CurBlock, CLEAR);
		g_CurBlock.x--;
		DrawBlock(g_CurBlock);
	}
}


// 右移方块
void OnRight()
{
	BLOCKINFO tmp = g_CurBlock;
	tmp.x++;
	if (CheckBlock(tmp))
	{
		DrawBlock(g_CurBlock, CLEAR);
		g_CurBlock.x++;
		DrawBlock(g_CurBlock);
	}
}


// 下移方块
void OnDown()
{
	BLOCKINFO tmp = g_CurBlock;
	tmp.y--;
	if (CheckBlock(tmp))
	{
		DrawBlock(g_CurBlock, CLEAR);
		g_CurBlock.y--;
		DrawBlock(g_CurBlock);
	}
	else
		OnSink();	// 不可下移时，执行“沉底方块”操作
}


// 沉底方块
void OnSink()
{
	int i, x, y, j, t;

	int score[4] = { 10,30,50,100 };

	// 连续下移方块
	DrawBlock(g_CurBlock, CLEAR);
	BLOCKINFO tmp = g_CurBlock;
	tmp.y--;
	while (CheckBlock(tmp))
	{
		g_CurBlock.y--;
		tmp.y--;
	}
	DrawBlock(g_CurBlock, FIX);

	// 固定方块在游戏区
	WORD b = g_Blocks[g_CurBlock.id].dir[g_CurBlock.dir];
	for (i = 0; i < 16; i++, b <<= 1)
		if (b & 0x8000)
		{
			if (g_CurBlock.y - i / 4 >= HEIGHT)
			{	// 如果方块的固定位置超出高度，结束游戏
				GameOver();
				return;
			}
			else
				g_World[g_CurBlock.x + i % 4][g_CurBlock.y - i / 4] = 1;
		}

	// 检查是否需要消掉行，并标记
	BYTE remove = 0;	// 低 4 位用来标记方块涉及的 4 行是否有消除行为
	for (y = g_CurBlock.y; y >= max(g_CurBlock.y - 3, 0); y--)
	{
		i = 0;
		for (x = 0; x < WIDTH; x++)
			if (g_World[x][y] == 1)
				i++;

		if (i == WIDTH)
		{
			remove |= (1 << (g_CurBlock.y - y));
			setfillcolor(LIGHTGREEN);
			setlinecolor(LIGHTGREEN);
			setfillstyle(BS_HATCHED, HS_DIAGCROSS);
			fillrectangle(0, (HEIGHT - y - 1) * UNIT + UNIT / 2 - 5, WIDTH * UNIT - 1, (HEIGHT - y - 1) * UNIT + UNIT / 2 + 5);
			setfillstyle(BS_SOLID);
		}
	}

	if (remove) //如果产生消行，记录分数
	{
		j = 0;
		t = remove;
		if (t & 1) {
			j += 1;
		}
		if (t & 2) {
			j += 1;
		}
		if (t & 4) {
			j += 1;
		}
		if (t & 8) {
			j += 1;
		}
		SCORE[0] += score[j - 1];
		SCORE[j] += 1;

		if (SCORE[0] > 50)   //修改过关神器
		{
			GameOk();
		}

		char s[4] = { 0 };
		ToTheString(SCORE[0], s);
		clearrectangle(-100, 190, -50, 210);
		outtextxy(-100, 190, _T(s));

		clearrectangle(-100, 190 + 20 * j, -50, 210 + 20 * j);
		ToTheString(SCORE[j], s);
		outtextxy(-100, 190 + 20 * j, _T(s));
	}

	if (remove)	// 如果产生整行消除
	{
		// 延时 300 毫秒
		Sleep(300);

		// 擦掉刚才标记的行
		IMAGE img;
		for (i = 0; i < 4; i++, remove >>= 1)
		{
			if (remove & 1)
			{
				for (y = g_CurBlock.y - i + 1; y < HEIGHT; y++)
					for (x = 0; x < WIDTH; x++)
					{
						g_World[x][y - 1] = g_World[x][y];
						g_World[x][y] = 0;
					}

				getimage(&img, 0, 0, WIDTH * UNIT, (HEIGHT - (g_CurBlock.y - i + 1)) * UNIT);
				putimage(0, UNIT, &img);
			}
		}
	}

	// 产生新方块
	NewBlock();
}


void ToTheString(int x, char ch[4])
{
	//数字范围0-999
	int a;
	a = x / 100;
	ch[0] = a + '0';
	x %= 100;
	a = x / 10;
	ch[1] = a + '0';
	x %= 10;
	ch[2] = x + '0';
}