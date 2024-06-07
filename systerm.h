#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include"question.h"
#include"classes.h"
using namespace std;
class systerm {
	Class cla;
	Que_list Que;
public:
	systerm(){}
	friend bool operator==(const Student& a, const Student& b);
	friend bool operator!=(const Student& a, const Student& b);
	friend bool operator==(const Question& a, const Question& b);
	friend bool operator!=(const Question& a, const Question& b);
	void ManualSelect() ;
	void AutoSelect();
	bool IsSelected(const string d);
	void unassign(const string d);
	bool delQuestion();
	void changeStu();
	void delStu();
	void delQue();
	void addStu();
	void addQue();
	void changeQue();
	void pop_front();
	void read_file();
	void save_file();
	void printStu();
	void printQue();
};