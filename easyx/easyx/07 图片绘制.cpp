#include <graphics.h>
#include <conio.h>
void drawAlpha(int picture_x, int picture_y, IMAGE* picture) //x为载入图片的X坐标，y为Y坐标
{
	// 变量初始化
	DWORD * dst = GetImageBuffer(); // GetImageBuffer()函数，用于获取绘图设备的显存指针，EASYX自带
	DWORD* draw = GetImageBuffer();
	DWORD* src = GetImageBuffer(picture); //获取picture的显存指针
	int picture_width = picture->getwidth(); //获取picture的宽度，EASYX自带
	int picture_height = picture->getheight(); //获取picture的高度，EASYX自带
	int graphWidth = getwidth(); //获取绘图区的宽度，EASYX自带
	//3.2.纯色背景的绘制方式:
	//绘制时 在相同的坐标位置 先绘制掩码图 再绘制原图 并且传递对应的dwRop参数
	int graphHeight = getheight(); //获取绘图区的高度，EASYX自带
	int dstX = 0; //在显存里像素的角标
	// 实现透明贴图 公式： Cp=αp*FP+(1-αp)*BP ， 贝叶斯定理来进行点颜色的概率计算
	for (int iy = 0; iy < picture_height; iy++)
	{
	for (int ix = 0; ix < picture_width; ix++)
	{
	int srcX = ix + iy * picture_width; //在显存里像素的角标
	int sa = ((src[srcX] & 0xff000000) >> 24); //0xAArrggbb;AA是透明度
	int sr = ((src[srcX] & 0xff0000) >> 16); //获取RGB里的R
	int sg = ((src[srcX] & 0xff00) >> 8); //G
	int sb = src[srcX] & 0xff; //B
	if (ix >= 0 && ix <= graphWidth && iy >= 0 && iy <= graphHeight && dstX <=
	graphWidth * graphHeight)
	{
	dstX = (ix + picture_x) + (iy + picture_y) * graphWidth; //在显存里像素的角标
	int dr = ((dst[dstX] & 0xff0000) >> 16);
	int dg = ((dst[dstX] & 0xff00) >> 8);
	int db = dst[dstX] & 0xff;
	draw[dstX] = ((sr * sa / 255 + dr * (255 - sa) / 255) << 16); //公式：Cp = αp * FP + (1 - αp) * BP ； αp = sa / 255 , FP = sr , BP = dr| ((sg * sa / 255 + dg * (255 - sa) / 255) << 8) 
	//αp = sa / 255 , FP = sg , BP = dg| (sb * sa / 255 + db * (255 - sa) / 255); 
	//αp = sa / 255 , FP = sb , BP = db
				}
			}
		}
}
int main() {
	//初始化窗口
	initgraph(800, 600);
	
	//null为绘制在窗口，后面为相对路径（相对于当前程序文件07 图片绘制而言），绝对路径是从盘符开始到图像位置的,还有拉伸宽高
	loadimage(NULL, L"image/bg.jpg",800,600);

	//img保存图片,loadimage将图片加载到image中
	IMAGE img;
	loadimage(&img, L"image/a.png");
	//putimage用于将图片输出
	putimage(0, 0,&img);

	//透明贴图的实现,先绘制掩码，再绘制原图,掩码为白底黑图，原图为黑底
	IMAGE chim, chib;
	loadimage(&chib, L"image/b2.png");
	loadimage(&chim, L"image/b1.png");
	putimage(0, 200, &chib, SRCAND);
	putimage(0, 200, &chim, SRCPAINT);
	//同上，，适用于掩码为黑底白图，原图为白底
	IMAGE chicm, chicb;
	loadimage(&chicb, L"image/c2.png");
	loadimage(&chicm, L"image/c1.png");
	putimage(0, 400, &chicb, NOTSRCERASE);
	putimage(0, 400, &chicm, SRCINVERT);

	//透明贴图的实现，以像素为单位进行透明处理
	drawAlpha(200,0,&img);

	//卡住程序保持运行状态
	_getch();
	//关闭窗口
	closegraph();
	return 0;
}