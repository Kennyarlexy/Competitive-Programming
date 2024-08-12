#pragma GCC optimize("O0")
#include <bits/stdc++.h>
#define ll long long
using namespace std;

class MyException : public exception {
public:
    int depth;
    MyException(int i) : depth(i) {}
    int getDepth() const noexcept {
        return depth;
    }
};

void f2(int i, int k = 100) {
    if (i == k) {
        throw exception();
    }
    try {
        f2(i+1);
    }
    catch (const MyException& e) {
        throw e;
    }
    catch (...) {
        throw MyException(i);
    }
}

int main() {
    try {
        f2(1);
    }  
    catch (const MyException& e) {
        cerr << e.getDepth() << "\n";
    }
    catch (...) {
        cerr << "Caught unknown exception\n";
    }
    
    
    return 0;
}