#include <bits/stdc++.h>

using namespace std;

class A {
    int i;

public:
    A(int i) : i(i) { cout << "copy constructor" << endl; }
    A(const A &a) : i(a.i) { cout << "copy constructor" << endl; }
    A(const A &&a) : i(a.i) { cout << "move constructor" << endl; }
    A &operator=(const A &a) {
        i = a.i;
        cout << "operator=" << endl;
    }
    A &operator++() {
        i++;
        return *this;
    }
};

int main() {
    A a1(1);
    A a2 = ++a1;
    return 0;
}