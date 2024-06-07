#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include"question.h"
#include<fstream>
using namespace std;
struct Student {
	string num;
	string name;
	string cla;
	string que_number;
	Student* next;
	Student(string n=" ", string na=" ", string c=" ",string que="0") :num(n), name(na), cla(c), next(0), que_number(que) {}
    friend bool operator==( const Student& a, const Student& b);
	friend bool operator!=(const Student& a, const Student& b);
};
class Class{
protected :
	Student* first;
	Student* last;
	int size;
public:
	Class():first(0),last(0),size(0){}
	void pop_front();
	Student* _first() { return first; }
	Student* _last() { return last; }
	void add();
	void push_back(const Student& d);
	bool del();
	bool mod();
	bool isexist(Student*a);
	int class_size() { return size; }
	Student* front() { return first; }
	void read_file();
	void save_file();
	Student*find(const Student& d);
	void print();
	void printnot();
};