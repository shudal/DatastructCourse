#include <iostream>
#include <string>
#include "LinkList.cpp"

using namespace std;

struct Student {
    int id;
    string name;
    Student() {
        id = 0;
        name = "none";
    }
    Student(int _id, string _name): id(_id), name(_name) {};
    bool operator== (const Student b) const {
        if (this->id == b.id && this->name == b.name) {
            return true;
        }
        return false;
    }

};
const int maxsize = 10;

void visit(const Student &s) {
    cout<<"id="<<s.id<<", name="<<s.name<<endl;
}
int main() {
    int stuSize = 2;
    Student students[maxsize] = {Student(1, "junhao"), Student(2, "hyy")};
    LinkList<Student> l(students, stuSize);
    l.traverse(visit);
    cout<<"length="<<l.getLength()<<endl;
    cout<<"locate 1:"<<l.locate(Student(1, "junhao"))<<endl;
    cout<<"locate 2:"<<l.locate(Student(2, "hyy"))<<endl;

    cout<<"---"<<endl;
    cout<<"get()"<<endl;;
    Student s1, s2;
    cout<<l.get(0, s1);
    cout<<l.get(1, s2);
    visit(s1);
    visit(s2);
    cout<<"---"<<endl;
    cout<<"set()"<<endl;
    l.set(0, Student(3, "MJH"));
    l.set(1, Student(5, "HYY"));
    l.traverse(visit);
    cout<<"---"<<endl;
    cout<<"insert(0)"<<endl;
    l.insert(0, Student(2, "mjh"));
    l.traverse(visit);
    cout<<"insert(2)"<<endl;
    l.insert(2, Student(4, "hyy"));
    l.traverse(visit);
    cout<<"del(0)"<<endl;
    Student s3;
    cout<<l.del(0, s3)<<endl;;
    visit(s3);
    l.traverse(visit);
    cout<<"del(1)"<<endl;
    cout<<l.del(1, s3)<<endl;
    visit(s3);
    l.traverse(visit);
    cout<<"insert()"<<endl;
    cout<<l.insert(Student(6, "hyy"));
    l.traverse(visit);

    cout<<"----"<<endl;
    LinkList<Student> l2(l);
    cout<<"l2.traverse():"<<endl;
    l2.traverse(visit);
    cout<<"l.traverse():"<<endl;
    l.traverse(visit);

    cout<<"----"<<endl;
    LinkList<Student> l3;
    l3 = l2;
    l3.traverse(visit);
    return 0;
}
