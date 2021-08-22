#include <iostream>

using namespace std;

class Grandparent {
public:
    Grandparent() { cout << "Grandparent constructor" << endl; }
    virtual ~Grandparent() { cout << "Grandparent destructor" << endl; }
};

class Parent1 : public Grandparent {
public:
    Parent1() { cout << "Parent1 constructor" << endl; }
    ~Parent1() { cout << "Parent1 destructor" << endl; }
};

class Parent2 : public Grandparent {
public:
    Parent2() { cout << "Parent2 constructor" << endl; }
    ~Parent2() { cout << "Parent2 destructor" << endl; }
};

class Son : public Parent2, public Parent1 {
public:
    Son() { cout << "Son constructor" << endl; }
    ~Son() { cout << "Son destructor" << endl; }
};

int main() {
    // Grandparent *gp = new Grandparent();
    // Parent1 *p1 = new Parent1();
    // Parent2 *p2 = new Parent2();
    // delete p2;
    // delete p1;
    // delete gs;
    return 0;
}