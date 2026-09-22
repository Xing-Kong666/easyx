#include <graphics.h>
#include <conio.h>
int main05() {
	//初始化窗口
	initgraph(1000, 1100);

	//调整背景
	setbkcolor(0xffffff);
	cleardevice();

	//设置颜色数组,最大颜色数，最小颜色数，当前颜色之序
	int color[16] = { 0x000000,0xFFFFFF,0xFF0000,0x00FF00,0x0000FF,0xFFFF00,
		0x00FFFF,0xFF00FF,0xC0C0C0,0x808080,0x800000,0x808000,0x008000,0x800080,0x008080,0x000080 };
	int maxcolor = 16, mincolor = 1, nowcolor = 5;

	//设置画笔大小,最大最小和当前
	int maxbrush = 25, minbrush = 1, nowbrush = 5;

	//鼠标上一个点的坐标
	int prex = 0, prey = 0;

	//主循环
	while (1) {
		ExMessage msg;
		getmessage(&msg, EX_KEY | EX_MOUSE);

		//初始化颜色圆
		setfillcolor(color[nowcolor - 1]);
		solidcircle(50, 50, nowbrush);


		//q,w用于调节颜色，e用于清空画板
		switch (msg.message) {
		case WM_KEYDOWN:
			switch (msg.vkcode) {
				case 'Q':
					//q为往数组小端移动，越界判定
					nowcolor--;
					if (nowcolor < mincolor)nowcolor = maxcolor;
					setfillcolor(0xffffff);
					solidrectangle(0, 0, 100, 100);
					setfillcolor(color[nowcolor - 1]);
					solidcircle(50, 50, nowbrush);
					break;
				case 'W':
					//w为往数组大端移动，越界判定
					nowcolor++;
					if (nowcolor > maxcolor)nowcolor = mincolor;
					setfillcolor(0xffffff);
					solidrectangle(0, 0, 100, 100);
					setfillcolor(color[nowcolor - 1]);
					solidcircle(50, 50, nowbrush);
					break;
				case 'E':
					//e为清空画板
					cleardevice();
					setfillcolor(color[nowcolor - 1]);
					solidcircle(50, 50, nowbrush);
					break;
			}
			break;
		case WM_MOUSEWHEEL:
			nowbrush += msg.wheel / 120;
			if (nowbrush > maxbrush)nowbrush = minbrush;
			setfillcolor(0xffffff);
			solidrectangle(0, 0, 100, 100);
			setfillcolor(color[nowcolor - 1]);
			solidcircle(50, 50, nowbrush);
			break;
		case WM_LBUTTONDOWN:
			prex = msg.x;
			prey = msg.y;
			setfillcolor(color[nowcolor - 1]);
			solidcircle(prex, prey, nowbrush);
			break;
		case WM_MOUSEMOVE:
			if (!msg.lbutton)break;
			setlinecolor(color[nowcolor - 1]);
			setlinestyle(PS_SOLID, nowbrush);
			line(prex, prey, msg.x,msg.y);
			prex = msg.x;
			prey = msg.y;
			break;
		}
	}


	//卡住程序保持运行状态
	_getch();
	//关闭窗口
	closegraph();
	return 0;
}