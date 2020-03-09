/* 
1.建立头文件
2.命名空间
3.主函数
4.导入背景图片或者自己创造
5.导入音乐
6.暂停
7.关闭图文件
8.返回
*/
#include<iostream>//数据流输入/输出
#include<string>//字符串类
#include<conio.h>
#include<graphics.h>//画布上的一系列操作
#include<Windows.h>//DOS命令窗口
#include<MMSystem.h>//播放音乐
#pragma comment(lib,_T("winmm.lib"))//告诉编译器,加载winmm.lib库文件

using namespace std;

void input_pwd(char pwd[], int max_len) {
	char c;
	int i = 0;
		
	while (1) {
		c = getch();
        // getch不从输入缓冲区中读取
		//在getch中，把回车按键输入，识别为回车符'\r'
        //在getchar中，把回车按键输入，识别为换行符'\n'
		if (c == '\r' || i >= max_len) {  
			pwd[i] = 0;
			break;
		}
		pwd[i++] = c;
		printf("*", c);
	}
	printf("\n");
}
void login(void) {
	string name;
	//string pwd;
	char pwd[16];

	while (1) {
		system("cls");

		std::cout << "请输入账号：";
		std::cin >> name;

		std::cout << "请输入密码：";
		//std::cin >> pwd;
		input_pwd(pwd, sizeof(pwd));

		if (name == "luo1376" && strcmp(pwd, "qq137676")==0) {
			//break;
			return;
		} else {
			cout << "用户名或密码错误!" << endl;
			system("pause");
		}
	}
}

int main(void){
   login();
    initgraph(1000,550);//初始化图形
	loadimage(0,("最爱头像.jpg"));//加载图片

	//设置文本字体
	settextstyle(40,0,_T("微软雅黑"));
	//设置字体颜色
	settextcolor(RGB(255,255,0));

	//画一个空心矩形,左上角坐标(800,40),右下角坐标(1132,100)
	rectangle(600,40,920,100);
	//在矩形内打印文本
	outtextxy(615,50,_T("1-网站404攻击"));

	rectangle(600,130,920,190);
	outtextxy(615,140,_T("2-网站篡改攻击"));

	rectangle(600,220,920,280);
	outtextxy(615,230,_T("3-网站攻击修复"));

    rectangle(600,310,920,370);
	outtextxy(615,320,_T("4-查看攻击记录"));

    rectangle(600,400,920,460);
	outtextxy(615,410,_T("5-退出"));

    mciSendString("play 会好的.mp3 repeat",0,0,0);
	
    system("pause");//暂停
	closegraph();//关闭图形界面
    return 0;
}