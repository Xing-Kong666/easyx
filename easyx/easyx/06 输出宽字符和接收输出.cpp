#include <graphics.h>
#include <conio.h>
#include <stdio.h>
int main() {
	//初始化窗口
	initgraph(1000, 1100);

	//输出宽字符
	wchar_t ch = L'宽';
	outtextxy(50, 50, ch);

	//接收并输出宽字符
	while (1) {
		ExMessage msg;
		getmessage(&msg, EX_CHAR);
		outtextxy(100, 100, msg.ch);
	}
	
	//设置颜色，字体，大小(高，宽，宽的0代表自适应)
	settextcolor(0xe6d8ad);
	settextstyle(50, 0, L"正楷");
	setfillcolor(0xffffff);
	solidcircle(200, 200, 200);
	setbkmode(TRANSPARENT);
	outtextxy(200, 200, L"输出设置好的宽字符");
	
	wchar_t chs[] = L"这是宽字符数组\0";
	//统计宽字符数组长度
	int len = wcslen(chs);

	wchar_t arr[100] = L"";
	//进行宽字符串拼接
	wsprintf(arr, L"宽字符串拼接");
	outtextxy(50, 50, arr);
	//卡住程序保持运行状态

	char mul[100] = "hello world!";
	wchar_t wmul[100]=L"";
	MultiByteToWideChar(0,0,mul,8,wmul,100);
	outtextxy(300, 300, wmul);
	WideCharToMultiByte(0, 0, L"你好世界", 4, mul, 100, 0, 0);
	outtextxy(400, 400, wmul);
	_getch();
	//关闭窗口
	closegraph();
	return 0;
}