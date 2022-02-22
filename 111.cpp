#include<iostream>
using namespace std;

class Base{
public:
    Base() {}
    ~Base() {}
    void print() {
        std::cout << "I'm Base" << endl;
    }

    virtual void i_am_virtual_foo() {
        std::cout << "I'm Base" << endl;

    }
};

class Sub: public Base{
public:
    Sub() {}
    ~Sub() {}
    void print() {
        std::cout << "I'm Sub" << endl;
    }

    virtual void i_am_virtual_foo() {
        std::cout << "I'm Sub" << endl;
    }
};
int main() {
    Base *base = new Base();
    Sub  *base2sub = dynamic_cast<Sub*>(base);
    if (base2sub != nullptr) {
        base2sub->print();
    }
    cout <<"<base->sub> base2sub val is: "<< base2sub << endl;

    delete base;
    return 0;
}
/* vs2017 输出为下
Sub->Base
I'm Sub
I'm Base
<sub->base> sub2base val is: 00B9E080   // 注:这个地址是系统分配的,每次不一定一样

Base->Sub
I'm Base
<base->sub> base2sub val is: 00000000   // VS2017的C++编译器,对此类错误的转换赋值为nullptr
*/