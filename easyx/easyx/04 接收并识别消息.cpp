#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <Windows.h>
int main() {
	//初始化窗口
	initgraph(1000, 1100);
	//更改背景颜色设置为蓝色，并清空原来的填充重新绘制
	setbkcolor(0xe6d8ad);
	cleardevice();

	//定义全局变量0代白天和关门，1代表晚上和开门
	int flag1 = 0, flag2 = 0;

	while (1) {
		//定义消息类型并接收消息
		ExMessage msg;
		do {
			getmessage(&msg, EX_KEY | EX_MOUSE);
		} while (msg.message == WM_MOUSEMOVE);//键盘消息和鼠标消息
		
		//根据情况改变背景的颜色和门的开闭
		if (msg.message == WM_KEYDOWN&&msg.vkcode==32) {
			flag1 = (flag1 != 1);
		}
		else if (msg.message == WM_LBUTTONDOWN && msg.x > 0 && msg.x < 1000 && msg.y>0 && msg.y < 430) {
			flag2 = (flag2 != 1);
		}
		if(!flag1)setbkcolor(0xe6d8ad);
		else setbkcolor(0);
		cleardevice();

		//矩形,左上和右下角的xy坐标
		//主体
		setlinecolor(0);//线的颜色
		setlinestyle(PS_SOLID, 4);//线的样式
		setfillcolor(0xffffff);
		fillrectangle(100, 200, 375, 430);//有边框填充

		//门
		setlinecolor(0x577ab9);
		//关门背景填充为黑，否则为原色
		if (!flag2)setfillcolor(0xb0e4ef);//填充的颜色
		else setfillcolor(0);
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
		//开门不画，关门画
		if (!flag2) {
			setfillcolor(0x7f7f7f);
			solidcircle(207, 385, 9);//无边框填充
		}

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
		//白天为原色，晚上为白色
		if (!flag1)setfillcolor(0x00f2ff);
		else setfillcolor(0xffffff);
		solidcircle(625, 55, 50);

		//草地
		setfillcolor(0x4cbe22);
		solidrectangle(0, 430, 1000, 1100);

		//程序休眠1ms，其实没啥用，头文件为Windows.h
		Sleep(1);
	}

	//卡住程序保持运行状态，头文件为conio.h
	_getch();

	//关闭窗口
	closegraph();
	return 0;
}