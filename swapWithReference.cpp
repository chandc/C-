#include <iostream>

template <typename Type>
void swap(Type& var1, Type& var2) {

    var1 += var2;
    var2 = var1 - var2;
    var1 -= var2;
}

int main() {

    float var1 = 23.2;
    float var2 = 14.83;

    std::cout << "Values before swap: " << var1 << " " << var2 << std::endl;
    swap(var1, var2);
    std::cout << "Values after swap: " << var1 <<  " " << var2 << std::endl;

    return 0;
}