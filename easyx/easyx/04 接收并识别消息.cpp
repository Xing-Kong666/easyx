#include <graphics.h>
#include <conio.h>
#include <Windows.h>
int main01() {
	//初始化窗口
	initgraph(1000, 1100);

	ExMessage msg;
	getmessage(&msg, EX_MOUSE | EX_KEY);
	//卡住程序保持运行状态
	_getch();
	//关闭窗口
	closegraph();
	return 0;
}