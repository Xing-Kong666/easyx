#include <graphics.h>
#include <conio.h>
int main08() {
	//初始化窗口
	initgraph(1000, 1100);

	//初始化原图和掩码图数组
	IMAGE arrm[4];
	IMAGE arrb[4];

	//将图画加载到数组中
	for (int i = 0; i < 4; i++) {
		wchar_t goal[100] = L"";
		wsprintf(goal, L"image/k%d_b.png", i + 1);
		loadimage(&arrb[i], goal);
		wsprintf(goal, L"image/k%d_m.png", i + 1);
		loadimage(&arrm[i], goal);
	}

	////开始批量绘制，能够防止闪退
	//BeginBatchDraw();
	//while(1)for (int i = 0; i < 4; i++) {
	//	loadimage(NULL, L"image/bg.jpg");
	//	putimage(50, 100, &arrb[i], SRCAND);
	//	putimage(50, 100, &arrm[i], SRCPAINT);
	//	//进行绘制
	//	FlushBatchDraw();
	//	//等待100ms，1s=1000ms,相当于每秒10帧
	//	Sleep(100);
	//}
	//EndBatchDraw();

	//精灵图的绘制
	IMAGE ik_b[4];
	IMAGE ik_m[4];

	//将图画加载到数组中
	IMAGE fb, fm;
	loadimage(&fb, L"image/ik_b.png");
	loadimage(&fm, L"image/ik_m.png");

	BeginBatchDraw();
	for (int i = 0; i < 4; i++) {
		loadimage(NULL, L"image/bg.jpg");
		putimage(200, 100, 220, 292, &fb, 220 * i, 0, SRCAND);
		putimage(200, 100, 220, 292, &fm, 220 * i, 0, SRCPAINT);
		FlushBatchDraw();
		Sleep(100);
	}
	//结束绘制
	EndBatchDraw();

	////二重结合
	//BeginBatchDraw();
	//while (1)for (int i = 0; i < 4; i++) {
	//	loadimage(NULL, L"image/bg.jpg");
	//	putimage(50, 100, &arrb[i], SRCAND);
	//	putimage(50, 100, &arrm[i], SRCPAINT);
	//	putimage(100, 100, 220, 292, &fb, 220 * i, 0, SRCAND);
	//	putimage(100, 100, 220, 292, &fm, 220 * i, 0, SRCPAINT);			
	//	//进行绘制
	//	FlushBatchDraw();
	//	//等待100ms，1s=1000ms,相当于每秒10帧
	//	Sleep(200);
	//}
	//EndBatchDraw();

	//图片旋转
	//setbkcolor(0xffffff);
	//cleardevice();

	//IMAGE fm1,bm;
	//IMAGE fe,be;
	//loadimage(&fe, L"image/b2.png");
	//loadimage(&fm1, L"image/b1.png");
	//BeginBatchDraw();
	//for (int i = 0; i < 1000; i++) {
	//	loadimage(NULL, L"image/bg.jpg");
	//	rotateimage(&bm, &fm1, 6.28 / 100 * i);
	//	rotateimage(&be, &fe, 6.28 / 100 * i);
	//	putimage(0, 0, &be, SRCAND);
	//	putimage(0, 0, &bm, SRCPAINT);
	//	FlushBatchDraw();
	//	Sleep(100);
	//}

	//保存指定区域图像
	IMAGE get;
	//将图像赋给get
	getimage(&get, 0, 0, 1000, 1100);
	//新建一个文件，将get中的图像保存在这个文件中，如果已存在则不进行操作或覆盖
	saveimage(L"image/pict.png", &get);
	EndBatchDraw();
	//卡住程序保持运行状态
	_getch();
	//关闭窗口
	closegraph();
	return 0;
}