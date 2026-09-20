#include <graphics.h>
#include <conio.h>

int main() {
	//初始化窗口
	initgraph(1000, 1100);

	//矩形,左上和右下角的xy坐标
	//主体
	rectangle(100, 200, 375, 430);
	//门
	rectangle(165, 325, 220, 430);
	//窗户
	rectangle(275, 235, 335, 295);
	//烟囱
	rectangle(330, 30, 380, 160);
	
	//圆形，圆心xy坐标，radius半径
	//门把手
	circle(207, 385, 9);

	//多边形，每个顶点的坐标和顶点数
	POINT arr[3] = {
		{240,20},
		{45,200},
		{435,200}
	};
	polygon(arr, 3);

	//线，初始端点和末端点的xy坐标
	//窗户的两条线
	line(305, 235, 305, 295);
	line(275, 265, 335, 265);
	//底线
	line(0, 430, 1000, 430);

	//卡住程序保持运行状态
	_getch();
	//关闭窗口
	closegraph();
	return 0;
}