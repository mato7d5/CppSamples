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
    DeleterFunctor(const DeleterFunctor& d) : mNumber{d.mNumber} { cout << "Copy ctor of DeleterFunctor\n";}

    void operator() (int* i) { cout << "DeleterFunctor with value: " << mNumber << '\n'; delete i; }
};

int main() {
    {
        unique_ptr<int, void(*)(int*)> p_i(new int, global_default_deleter);
        *p_i = 100;
    }

    {
        DeleterFunctor deleter(100);
        unique_ptr<int, DeleterFunctor> p_d(new int, deleter); // copy of deleter
        *p_d = 200;
    }

    {
        DeleterFunctor deleter(200);
        unique_ptr<int, DeleterFunctor&> p_d(new int, deleter); // deleter as reference
        *p_d = 300;
    }

    {
        auto lambda_deleter = [] (int* p) -> void { cout << "lambda_deleter\n"; delete p; };
        unique_ptr<int, decltype(lambda_deleter)> p_l(new int, lambda_deleter);
        *p_l = 400;
    }

    return 0;
}
