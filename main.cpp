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
		cout << "\n\n\ ********------欢迎使用面向对象选题设计选题管理系统------******** \n\n";
		cout << "|----------------- 1.自动匹配题目功能                 --------------|\n";
		cout << "|----------------- 2.手动匹配题目功能                 --------------|\n";
		cout << "|----------------- 3.学生信息增加功能                 --------------|\n";
		cout << "|----------------- 4.学生信息修改功能                 --------------|\n";
		cout << "|----------------- 5.学生信息删除功能                 --------------|\n";
		cout << "|----------------- 6.题目信息增加功能                 --------------|\n";
		cout << "|----------------- 7.题目信息修改功能                 --------------|\n";
		cout << "|----------------- 8.题目信息删除功能                 --------------|\n";
		cout << "|----------------- 9.题目信息打印功能                 --------------|\n";
		cout << "|----------------- 10.打印匹配结果功能                --------------|\n";
		cout << "|----------------- 0.退出选题系统功能                 --------------|\n";
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
	cout << "退出成功" << endl;
	}
