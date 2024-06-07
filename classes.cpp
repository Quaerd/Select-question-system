#include<iostream>
#include<string>
#include"classes.h"
using namespace std;
bool operator==(const Student& a, const Student& b) {
    return (b.cla == a.cla && b.name == a.name && b.num == a.num);
}
bool operator!=(const Student& a, const Student& b) {
    return (b.cla != a.cla || b.name != a.name || b.num != a.num);
}
void Class::pop_front() {  
    if (first) { 
        Student* p = first;
        first = first->next;
    }
    else {
        first = last = 0;
    }
    size--;
}
void Class::add() {
    string na, nu, cl;
    cout << "please enter the student's information " << endl;
    cout << "number " << endl;
    cin >> nu;
    cout << "name " << endl;
    cin >> na;
    cout << "class " << endl;
    cin >> cl;
    Student* p = new Student(nu, na, cl);
    if (!first){
        first = last = p;
        size++;
        return;}
    last->next = p;
    last=p;
    size++;
}
void Class::push_back(const Student& d) {
    Student* p = new Student(d);
    if (!first) {
        first = last = p;
        size++;
        return;
    }
    last->next = p;
    last = p;
    size++;
}
bool Class::del() {
    string na, nu, cl;
    cout << "please enter the student's information " << endl;
    cout << "number" << endl;
    cin >> nu;
    cout << "name" << endl;
    cin >> na;
    cout << "class" << endl;
    cin >> cl;
    Student* d = new Student(nu, na, cl);
    if (!isexist(d)) {
        cout << "the student doesn't exist" << endl;
        return false;
    }
    if (!first) return false;
    Student* p = first;
    if ((*d) == *first) { pop_front();  return true; }  
    Student* p0 = p;
    p = p->next;
    for (; p; p = p->next) {
        if (*p == (*d)) {
            p0->next = p->next;
            if (p == last) last = p0;          
            size--;
            return true;
        }
        p0 = p;
    }  
}
bool Class::mod( ) {
    string na, nu, cl;
    cout << "please enter the student's information " << endl;
    cout << "number " << endl;
    cin >> nu;
    cout << "name " << endl;
    cin >> na;
    cout << "class " << endl;
    cin >> cl;
    Student* a = new Student(nu, na, cl);
    if (!isexist(a)) {cout << "the student doesn't exist" << endl;
    return false;
    }  
    cout << "please enter the final information" << endl;
    cout << "number " << endl;
    cin >> nu;
    cout << "name " << endl;
    cin >> na;
    cout << "class " << endl;
    cin >> cl;
    Student* b = new Student(nu, na, cl,a->que_number);
    Student* p = first;
    for (; p; p = p->next) {
        if (*p == (*a)) {
            p->cla = (*b).cla;
            p->name = (*b).name;
            p->num = (*b).num;       
            delete b;
            delete a;
            return true;
        }
    }
    if (p = _last())
    {      
        delete b;
        delete a;
        return false;
    }
}
bool Class::isexist(Student*a) {
    Student* p = first;
    for (; p; p = p->next) {
        if (*p == *a) return true;
    }
    return false;
}
void Class::read_file() {
    fstream fin("class.txt", ios::in);
    if (!fin) { cout << "error at reading file" << endl; }
    string num, name, cla, que;
     while (fin >> num>> name>>cla>>que) {
        Student* p = new Student(num, name, cla,que);
        (*this).push_back(*p);    
    }
     fin.close();
}
void Class::save_file() {
    fstream fout("class.txt", ios::out);
    if (!fout) { cout << "error at saving file" << endl; }
    Student* p = first;
    for (; p; p = p->next) {   
        fout << p->num << ' ' << p->name << ' ' << p->cla << ' ' << p->que_number << endl;  
    }
    fout.close();
}
Student* Class::find(const Student& d) {
    Student* p = first;
    for (; p; p = p->next) {
        if (*p == d) return p;
    }
    return 0;
}
void Class::print() {
    Student* p = first;
    for (; p != nullptr; p = p->next) {
        if (first == 0) cout << "error " << endl;
    cout << "number: " << p->num << "\t"
        << "name: " << p->name << "\t" 
        << "class: " << p->cla << "\t" 
        <<"question number: "<<p->que_number<<endl;
    }
}
void Class::printnot() {
    Student* p = first;
    int cnt = 0;
    for (; p != nullptr; p = p->next) {
        if (first == 0) cout << "error " << endl;
        if (p->que_number == "0") {
            cnt++;
            cout << "number: " << p->num << "\t"
                << "name: " << p->name << "\t"
                << "class: " << p->cla << "\t"
                << "question number: " << p->que_number << endl;
        }
    }
    if (cnt == 0) {
        cout << "all the student has choiced the question."
            << endl << "do you want to modify your question randomly "
            << endl;
    }
}