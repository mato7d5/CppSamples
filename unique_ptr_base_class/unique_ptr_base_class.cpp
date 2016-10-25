#include <memory>
#include <utility>
#include <iostream>
#include <functional>

using namespace std;

class DeleterFunctor {
private:
    int mNumber;

public:
    explicit DeleterFunctor(int num) : mNumber{num} { }
    DeleterFunctor(const DeleterFunctor& d) : mNumber{d.mNumber} { cout << "Copy ctor of DeleterFunctor\n";}

    void operator() (int* i) { cout << "DeleterFunctor with value: " << mNumber << '\n'; delete i; }
};

class MyUniquePtr : public unique_ptr<int, DeleterFunctor > { 
private:
	int mNumber;

public:
	explicit MyUniquePtr (int num) : unique_ptr<int, DeleterFunctor> (new int, DeleterFunctor(num)), mNumber{num} { };
	MyUniquePtr(MyUniquePtr&& ptr) = default;
	MyUniquePtr& operator=(MyUniquePtr&& ptr) = default;
};

int main() {
	MyUniquePtr u(100);
	MyUniquePtr u2(std::move(u));

	return 0;
}
 
