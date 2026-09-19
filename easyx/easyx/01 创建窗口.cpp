#include <graphics.h>
#include <conio.h>
int main() {
	//初始化窗口
	initgraph(1000, 1100);
	//卡住程序保持运行状态
	_getch();
	//关闭窗口
	closegraph();
	return 0;
}