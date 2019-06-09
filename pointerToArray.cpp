#include <iostream>

int main() {

    int *ptr;
    ptr = new int[5];
    for(int i = 0; i < 5; i++){
        int inputVar;
        std::cout<<"Input a number:"<<std::endl;
        std::cin>>inputVar;
        ptr[i] = inputVar;
    }
    for(int i = 0; i < 5; i++){
        //std::cout<<"Number "<<ptr[i] << " is stored on " << (ptr + i) << " address."<<std::endl;
        std::cout<<"Number "<<ptr[i] << " is stored on " << &ptr[i] << " address."<<std::endl;

    }

    delete[] ptr;
    return 0;
}