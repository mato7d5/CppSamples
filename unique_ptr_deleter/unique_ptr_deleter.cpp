#include <memory>
#include <utility>
#include <iostream>

using namespace std;

void global_default_deleter(int* p) {
    cout << "global_default_deleter\n";
    delete p;
}

class DeleterFunctor {
private:
    int mNumber;

public:
    explicit DeleterFunctor(int num) : mNumber{num} { }

    void operator() (int* i) { cout << "DeleterFunctor with value: " << mNumber << '\n'; delete i; }
};

int main() {
    {
        unique_ptr<int, void(*)(int*)> p_i(new int, global_default_deleter);
        *p_i = 100;
    }

    {
        DeleterFunctor deleter(100);
        unique_ptr<int, DeleterFunctor> p_d(new int, deleter);
        *p_d = 200;
    }

    return 0;
}
