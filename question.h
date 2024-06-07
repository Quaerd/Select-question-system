#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include"classes.h"
using namespace std;
struct Question {
	string num;
	string qus;
	string req;
	string ddl;
	bool choiced;
	string onlynum;
	Question* next;
	friend bool operator==(const Question& a, const Question& b);
	friend bool operator!=(const Question& a, const Question& b);
	friend ostream& operator<<(ostream& o, const Question& b);
	Question(string n, string q, string r, string d,bool ch=false):num(n),qus(q),req(r),ddl(d),choiced(ch), next(0) {}
};
class Que_list {
protected:
	Question* first;
	Question* last;
	int Q_size;
	friend class Class;
public:
	Que_list(int d=0):first(0),last(0),Q_size(d){}
	void push_back(const Question& d);
	void add();
	bool mod();
	void FrToNext() { first = first->next; }
	void LaToNext() { last = last->next; }
	void ToNext(Question* d) { d = d->next; }
	int Que_size() { return Q_size; }
	bool find(string d);
	bool isexist(string);
	Question* findself(string d);
	void delconnection(string d);
	void choiced(string d);
	Question* front() { return first; }
	Question* end() { return last; }
	void desize() { Q_size--; }
	void read_file();
	bool isChoiced(string a);
	void print();
	void lastadd(Question* d) { last = d; }
	void printNot();
	void save_file();
	bool cmp(Question a, Question b) { return stoi(a.num) < stoi(b.num); }
};
