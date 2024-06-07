#include<iostream>
#include<string>
#include"question.h"
#include"classes.h"
#include"systerm.h"
bool systerm::IsSelected(const string d){
    Student* p = cla.front();
        for(; p; p = p->next) {
            if (stoi(p->que_number) == stoi(d)) return true;       
        }
        return false;
}
void systerm::unassign(const string d) {
    Student* p = cla.front();
    for (; p; p=p->next) {
        if (stoi(p->que_number) == stoi(d)) {
            p->que_number = "0";
            Que.delconnection(d);
        }
    }
}
void systerm::pop_front() {
    if (Que.front()) {
        Question* p = Que.front();
        if ((*p).choiced != 0) {
            unassign((*p).num);
        }
        Que.FrToNext();
        Que.desize();
    }
}
bool  systerm::delQuestion() {
    string nu, q, re, ddl;
    cout << "please enter the question number " << endl;
    cin >> nu;
    if (!Que.isexist(nu)) {
        cout << "the question doesn't exist" << endl;
        return false;
    }
    Question* d = Que.findself(nu);
    if (!Que.front()) return false;
    Question* p = Que.front();
    if ((d) == Que.front()) {pop_front(); return true; }
    if (IsSelected(nu)) {
        unassign(nu);
    }
    Question* p0 = p;
    p = p->next;
    for (; p; p = p->next) {
        if (*p == *d) {
            p0->next = p->next;
            if (p == Que.end()) Que.lastadd(p0);          
            return true;
        }
        p0 = p;
    }
    Que.desize();
};
void  systerm::ManualSelect() {
    string a;
    while(1){
        system("cls");
        cout << "----------The students who did't choiced question------------" << endl;
        cla.printnot();
        cout << "continue or not    (y/n)" << endl;      
        cin >> a;
        if (a != "y") { break; }
        system("cls");
        cout << "please input your information" << endl;
        string na, nu, cl,q,b;
        cout << "number" << endl;
        cin >> nu;
        cout << "name" << endl;
        cin >> na;
        cout << "class" << endl;
        cin >> cl;
        int Qnum = Que.Que_size();
        int random_number=rand() % Qnum+1;
        string num = to_string(random_number);
        while(Que.isChoiced(num)) {
            random_number = rand() % Qnum+1;
            num = to_string(random_number);
        }
        Student is(nu, na, cl);
        if (cla.isexist(&is)) {
        Student* p = cla.find(is); 
            if (p->que_number != "0") {
                Que.delconnection(p->que_number);
        }
                Que.choiced(num);
                p->que_number = num;
        cout << "finish" << endl;}
        else {
            cout << "the student doesn't exist" << endl;           
        }
        save_file();
        cout << "continue or not   (y/n)" << endl;
        cin >> a;
        if (a != "y") break;
    }
};
void systerm::AutoSelect() {
    system("cls");
    srand(static_cast<unsigned int>(time(0))); 
    while (1) {
        int cnt = 0;
        Student* p = cla.front();
        while (p->que_number != "0") {
            if (p != cla._last()) {
                p = p->next;
                cnt++;
            }
            else break;
        }
        if (p->que_number != "0") cnt++;
        if (cnt ==cla.class_size()) {
            cout << "everyone has choiced a question." << endl;
            cout << "return to the menu    (y/n)" << endl;
            string a;
            cin >> a;
            if (a == "y") break;
        }
        int len = (p->num).length();
        int Qnum = Que.Que_size();
        int random_number = rand() % Qnum+1;
        string num = to_string(random_number);
        while (Que.isChoiced(num)) {
            random_number = rand() % Qnum+1;
            num = to_string(random_number);
        }
        if (Que.find(num)) {
            p->que_number =num ;
            Que.choiced(num);
        }
        if (p==cla._last()&&p->que_number != "0") cnt++;
        if (cnt == cla.class_size()) {
            cout << "everyone has a question." << endl;
            cout << "return to the menu    (y/n)" << endl;
            string a;
            cin >> a;
            if (a == "y") break;
        }
        p = p->next;      
    }
};
void systerm::changeStu() {
    while (1) {
        system("cls");
        if (cla.mod()) cout << "finish" << endl;
        else cout << "please input the correct information" << endl;
        cout << "continue or not  (y/n)" << endl;
        string a;
        cin >> a;
        if (a != "y") break;
    }
}
void systerm::changeQue(){
    while (1) {
        system("cls");
        if (Que.mod()) cout << "finish" << endl;
        else cout << "please input the correct information" << endl;
        cout << "continue or not  (y/n)" << endl;
        string a;
        cin >> a;
        if (a != "y") break;
    }
}
void systerm::delStu() {
    while (1) {
        system("cls");
        if (cla.del()) cout << "finish" << endl;
        else cout << "please input the correct information" << endl;
        cout << "continue or not  (y/n)" << endl;
        string a;
        cin >> a;
        if (a != "y") break;
    }
}
void systerm::delQue() {
    while (1) {
        system("cls");
        if ((*this).delQuestion()) cout << "finish" << endl;
        else cout << "please input the correct information" << endl;
        cout << "continue or not  (y/n)" << endl;
        string a;
        cin >> a;
        if (a != "y") break;
    }
}
void systerm::addStu() {
    while (1) {
        system("cls");
        cla.add();
        cout << "finish" << endl;
        cout << "continue or not  (y/n)" << endl;
        string a;
        cin >> a;
        if (a != "y") break;
    }
}
void systerm::addQue() {
    while (1) {
        system("cls");
        Que.add();
        cout << "finish" << endl;
        cout << "continue or not  (y/n)" << endl;
        string a;
        cin >> a;
        if (a != "y") break;
    }
}
void systerm::printStu(){
    system("cls");
    while (1) {
        cla.print();
        string a;
        cout << "finish or not   (y/n)" << endl;
        cin >> a;
        if (a == "y") break;
    }
}
void systerm::printQue() {
    system("cls");
    while (1) {
        Que.print();
        string a;
        cout << "finish or not   (y/n)" << endl;
        cin >> a;
        if (a == "y") break;
    }
}
void systerm::read_file() {
    cla.read_file();
    Que.read_file();
}
void systerm::save_file() {
    cla.save_file();
    Que.save_file();
}

