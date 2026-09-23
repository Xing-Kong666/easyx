#include <graphics.h>
#include <conio.h>
//音频播放三件套，两头一库
#include <windows.h>
#include <mmsystem.h>
#pragma comment (lib,"winmm.lib")
int main() {
	//初始化窗口
	initgraph(1000, 1100);
	/*
	open 路径 alias 别名 type mpegvideo
	    音乐路径  以后可以用别名   设置为mpegvideo代表音乐为循环播放类型
	*/
	mciSendString(L"open music/bgm.wav alias bgm type mpegvideo", 0, 0, 0);
	/*
	play 路径or别名 repeat from 2000
	播放        设置为mpeg可以利用repeat循环播放音乐了，from是后的数字是从音乐的第2秒开始播放
	*/
	mciSendString(L"play bgm repeat", 0, 0, 0);
	/*
	pause 别名
	从当前位置停止播放，下次播放从当前位置播放
	*/
	mciSendString(L"pause bgm", 0, 0, 0);
	Sleep(9000);
	/*
	setaudio 别名 volume to 200
	设置音量               音量范围为0-1000
	*/
	mciSendString(L"setaudio bgm volume to 200", 0, 0, 0);
	mciSendString(L"play bgm repeat", 0, 0, 0);
	/*
	close 别名
	结束播放，别名失效
	*/
	mciSendString(L"close bgm", 0, 0, 0);
	//卡住程序保持运行状态
	_getch();
	//关闭窗口
	closegraph();
	return 0;
}