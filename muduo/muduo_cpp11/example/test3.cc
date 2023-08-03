#include <iostream>

struct MyStruct {
    using MyType = int;
};

int main() {
    MyStruct::MyType variable = 10;
    std::cout << variable << std::endl;

    return 0;
}
