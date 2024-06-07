#include"question.h"
#include<iostream>
#include<string>
#include<locale>
using namespace std;
bool operator==(const Question& a, const Question& b) {
    return (b.num == a.num && b.qus == a.qus && b.ddl == a.ddl&&a.req==b.req);
}
bool operator!=(const Question& a, const Question& b) {
    return (b.num != a.num || b.qus != a.qus || b.ddl != a.ddl|| a.req != b.req);
}
ostream& operator<<(ostream& o, const Question& b) {
    o << "number " << b.num << "\t"
        << "question " << b.qus << endl
    << "requirement " << b.req << endl;
    o << "dead line "  << b.ddl ;
    if (b.choiced) o << "  choiced";
    else o << "  not choiced";
    return o;
}
bool Que_list::find(string d) {
    Question *p= first;
    for (; p; p = p->next) {
        if (stoi(p->num )==stoi( d)) return true;
    }
    return false;
}
Question* Que_list::findself(string d) {
    Question* p = first;
    for (; p; p = p->next) {
        if (stoi(p->num) == stoi(d)) return p;
    }
}
void Que_list::delconnection(string d){
    Question* p = findself(d);
    p->choiced = false;
}
void Que_list::choiced(string d) {
    Question* p = (*this).findself(d);
    p->choiced = true;
}
bool Que_list::isChoiced(string a) {
    Question* p = findself(a);
    if (p->choiced) return true;
    else return false;
}
void Que_list::add() {
    string nu, q, re,d;
    cout << "please enter information of the question" << endl;
    cout << "number " << endl;
    cin >> nu;
    cout << "question name " << endl;
    cin >> q;
    cout << "requirement " << endl;
    cin >> re;
    cout << "dead line " << endl;
    cin >> d;
    Question* a = new Question(nu,q, re,d);
    if (!first) {
        first = last = a;
        return;
    }
    Question* p = first;
    Question* p0 = p;
    for (; p; p = p->next) {
        if (stoi(a->num) < stoi(p->num)) {
            if (p == first) {
                a->next = p;
                first = a;
                break;
            }
            else {
                a->next = p0->next;
                p0->next = a;
                break;
            }
        }
        else if (stoi(a->num) >= stoi(p->num)) {
            p0 = p;
            if (p == last) {
                p->next = a;
                last = a;
                break;
            }
        }
    }
    Q_size++;
}
void Que_list::push_back(const Question& d) {
    Question* a = new Question(d);
    if (!first) {
        first = last = a;
        Q_size++;
        return;
    }
    Question* p = first;
    Question* p0 = p;
    for (; p; p = p->next) {
        if (stoi(a->num) < stoi(p->num)) {
            if (p == first) {
                a->next = p;
                first = a;
                break;
            }
            else {
                a->next = p0->next;
                p0->next = a;
                break;
            }
        }
        else if (stoi(a->num) >= stoi(p->num)) {
            p0 = p;
            if (p == last) {
                p->next = a;
                last = a;
                break;
            }
        }
    }
    Q_size++;
}
bool Que_list::mod() {
    string nu, q, re, d;
    cout << "please enter  information of the question" << endl;
    cout << "number " << endl;
    cin >> nu;
    if (!isexist(nu)) {
        cout << "the question doesn't exist" << endl;
        return false;
    }
    Question* a = findself(nu);
    cout << "please enter the final information " << endl;
    cout << "question name " << endl;
    cin >> q;
    cout << "requirement " << endl;
    cin >> re;
    cout << "dead line " << endl;
    cin >> d;
    Question* p = first;
    for (; p; p = p->next) {
        if (*p == (*a) ){
            p->num = nu;
            p->qus = q;
            p->req = re;
            p->ddl = d;
            return true;
        }
    }
    return false;
}
void Que_list::read_file() {
    fstream fin("question.txt", ios::in);
    if (!fin) {
        cout << "read error" << endl;
        return;
    }
    string num; string qus; string req; string ddl;
    bool ch;
    while(fin >> num >> qus >> req >> ddl >> ch) {
        Question* p = new Question(num,qus,req,ddl,ch);
        (*this).push_back(*p);
    }
    fin.close();
}
void Que_list::print() {
    Question* p = first;
    for (; p; p = p->next) {
        if (p == first) cout << "------------------------" << endl;
        cout << *p << endl;
        cout << "------------------------" << endl;
    }
}
void Que_list::printNot() {
    Question* p = first;
    for (; p; p = p->next) {
        if (!p->choiced) cout << *p << endl;
    }
}
void Que_list::save_file() {
    fstream fout("question.txt", ios::out);
    if (!fout) cout << "save error" << endl;
    Question* p = first;
    for (; p; p = p->next) {
        fout << p->num << ' ' << p->qus << ' ' << p->req << ' ' << p->ddl << ' ' << p->choiced << endl;
    }
    fout.close();
}
bool Que_list::isexist(string a) {
    Question* p = first;
    for (; p; p = p->next) {
        if (stoi(p->num )== stoi(a)) return true;
    }
    return false;
}