#include<iostream>
#include"classes.h"
#include"systerm.h"
#include<fstream>
using namespace std;
int main() {
	while (1)
	{
		system("cls");
		int fun;
		cout << "\n\n\ ********------��ӭʹ���������ѡ�����ѡ�����ϵͳ------******** \n\n";
		cout << "|----------------- 1.�Զ�ƥ����Ŀ����                 --------------|\n";
		cout << "|----------------- 2.�ֶ�ƥ����Ŀ����                 --------------|\n";
		cout << "|----------------- 3.ѧ����Ϣ���ӹ���                 --------------|\n";
		cout << "|----------------- 4.ѧ����Ϣ�޸Ĺ���                 --------------|\n";
		cout << "|----------------- 5.ѧ����Ϣɾ������                 --------------|\n";
		cout << "|----------------- 6.��Ŀ��Ϣ���ӹ���                 --------------|\n";
		cout << "|----------------- 7.��Ŀ��Ϣ�޸Ĺ���                 --------------|\n";
		cout << "|----------------- 8.��Ŀ��Ϣɾ������                 --------------|\n";
		cout << "|----------------- 9.��Ŀ��Ϣ��ӡ����                 --------------|\n";
		cout << "|----------------- 10.��ӡƥ��������                --------------|\n";
		cout << "|----------------- 0.�˳�ѡ��ϵͳ����                 --------------|\n";
		cout << endl;
		cout << "please input the move" << endl;
		systerm a;
		a.read_file();
		cin >> fun;
		if (fun == 1) {
		a.AutoSelect();
			a.save_file();
		}
		else if (fun == 2) {
			a.ManualSelect();			
		}
		else if (fun == 3) {
			a.addStu();
			a.save_file();
		}
		else if (fun == 4) {
			a.changeStu();
			a.save_file();
		}
		else if (fun == 5) {
			a.delStu();
			a.save_file();
		}
		else if (fun == 6) {
			a.addQue();
			a.save_file();
		}
		else if (fun == 7) {
			a.changeQue();
			a.save_file();
		}
		else if (fun == 8) {
			a.delQue();
			a.save_file();
		}
		else if (fun == 9) {
			a.printQue();
		}
		else if (fun == 10) {
			a.printStu();
		}
		else if (fun == 0) {
			break;
		}
	}
	cout << "--------------------" << endl;
	cout << "�˳��ɹ�" << endl;
	}
