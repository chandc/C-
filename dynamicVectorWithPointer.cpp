#include <iostream>

int* createArr(int n) {
    int *ptr = new int[n];
    return ptr;
}

int* resizeArr(int* ptr,int _size, int exValue) {
    int *newPtr = new int[_size + exValue];

    for (int i = 0; i < _size; i++ ){
        newPtr[i] = ptr[i];
    }
    delete [] ptr;
    return newPtr;
}

int main () {

int _size;
std:: cout<< "Size of array: " << std::endl;
std::cin >>_size;
    int *ptr = createArr(_size);
    for(int i=0;i<_size;i++){

        ptr[i] = i*i;
    }
    std::cout << "Created array: "<<std::endl;
    for(int i=0;i<_size;i++){
        std::cout<< ptr[i] << std::endl;
    }
    std::cout<< "Expand value: ";
    int expandVal;
    std::cin >> expandVal;
    ptr = resizeArr(ptr, _size, expandVal);
    std::cout<< "Expanded array: " << std::endl;
    for(int i=0;i<(_size +expandVal);i++){
        std::cout<< ptr[i] << std::endl;
    }
    delete [] ptr;
    return 0;
}