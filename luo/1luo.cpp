/* 
1.����ͷ�ļ�
2.�����ռ�
3.������
4.���뱳��ͼƬ�����Լ�����
5.��������
6.��ͣ
7.�ر�ͼ�ļ�
8.����
*/
#include<iostream>//����������/���
#include<string>//�ַ�����
#include<conio.h>
#include<graphics.h>//�����ϵ�һϵ�в���
#include<Windows.h>//DOS�����
#include<MMSystem.h>//��������
#pragma comment(lib,_T("winmm.lib"))//���߱�����,����winmm.lib���ļ�

using namespace std;

void input_pwd(char pwd[], int max_len) {
	char c;
	int i = 0;
		
	while (1) {
		c = getch();
        // getch�������뻺�����ж�ȡ
		//��getch�У��ѻس��������룬ʶ��Ϊ�س���'\r'
        //��getchar�У��ѻس��������룬ʶ��Ϊ���з�'\n'
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

		std::cout << "�������˺ţ�";
		std::cin >> name;

		std::cout << "���������룺";
		//std::cin >> pwd;
		input_pwd(pwd, sizeof(pwd));

		if (name == "luo1376" && strcmp(pwd, "qq137676")==0) {
			//break;
			return;
		} else {
			cout << "�û������������!" << endl;
			system("pause");
		}
	}
}

int main(void){
   login();
    initgraph(1000,550);//��ʼ��ͼ��
	loadimage(0,("�ͷ��.jpg"));//����ͼƬ

	//�����ı�����
	settextstyle(40,0,_T("΢���ź�"));
	//����������ɫ
	settextcolor(RGB(255,255,0));

	//��һ�����ľ���,���Ͻ�����(800,40),���½�����(1132,100)
	rectangle(600,40,920,100);
	//�ھ����ڴ�ӡ�ı�
	outtextxy(615,50,_T("1-��վ404����"));

	rectangle(600,130,920,190);
	outtextxy(615,140,_T("2-��վ�۸Ĺ���"));

	rectangle(600,220,920,280);
	outtextxy(615,230,_T("3-��վ�����޸�"));

    rectangle(600,310,920,370);
	outtextxy(615,320,_T("4-�鿴������¼"));

    rectangle(600,400,920,460);
	outtextxy(615,410,_T("5-�˳�"));

    mciSendString("play ��õ�.mp3 repeat",0,0,0);
	
    system("pause");//��ͣ
	closegraph();//�ر�ͼ�ν���
    return 0;
}