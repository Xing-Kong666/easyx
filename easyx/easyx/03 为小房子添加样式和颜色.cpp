#include <graphics.h>
#include <conio.h>

int main03() {
	//初始化窗口
	initgraph(1000, 1100);
	//更改背景颜色设置为蓝色，并清空原来的填充重新绘制
	setbkcolor(0xe6d8ad);
	cleardevice();

	//矩形,左上和右下角的xy坐标
	//主体
	setlinecolor(0);//线的颜色
	setlinestyle(PS_SOLID, 4);//线的样式
	fillrectangle(100, 200, 375, 430);//有边框填充
	//门
	setlinecolor(0x577ab9);
	setfillcolor(0xb0e4ef);//填充的颜色
	fillrectangle(165, 325, 220, 430);
	//窗户
	setfillcolor(0x7f7f7f);
	fillrectangle(275, 235, 335, 295);
	setlinecolor(0);
	//烟囱
	setfillcolor(0x577ab9);
	fillrectangle(330, 30, 380, 160);

	//圆形，圆心xy坐标，radius半径
	//门把手
	setfillcolor(0x7f7f7f);
	solidcircle(207, 385, 9);//无边框填充

	//多边形，每个顶点的坐标和顶点数
	POINT arr[3] = {
		{240,20},
		{45,200},
		{435,200}
	};
	setfillcolor(0xe8a200);
	fillpolygon(arr, 3);

	//线，初始端点和末端点的xy坐标
	//窗户的两条线
	setlinecolor(0x577ab9);
	line(305, 235, 305, 295);
	line(275, 265, 335, 265);
	setlinecolor(0);
	//底线
	line(0, 430, 1000, 430);
	//太阳
	setfillcolor(0x00f2ff);
	solidcircle(625, 55, 50);
	//草地
	setfillcolor(0x4cbe22);
	solidrectangle(0, 430, 1000, 1100);
	//卡住程序保持运行状态
	_getch();
	//关闭窗口
	closegraph();
	return 0;
}