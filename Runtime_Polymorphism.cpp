// Example solution for function overloading
// include iostream for printing
#include<iostream>
// Define Point class
class Base {    
    // Define public constructor
    public:
        Base(){};
        virtual void Print(){
            std::cout << "print from Base class" << "\n";
        }  
        void calc(int v1, int v2){
            std::cout << "print from Base class" << "\n";
            std::cout << "calc function output:" << v1+v2 << "\n";
        }      
};

class Derived: public Base {    
    // Define public constructor
    public:
        Derived(){};
        void Print(){
            std::cout << "print from dervied class" << "\n";
        }  
        void calc(int v1, int v2){
            std::cout << "print from Derived class" << "\n";
            std::cout << "calc function output:" << v1-v2 << "\n";
        }     
};

// Test in main()
int main() 
{
    Base *base_ptr;
    Derived derived;
    base_ptr = &derived;

    //virtual function, binded at runtime (Runtime polymorphism)
    base_ptr->Print();

    // Non-virtual function, binded at compile time
    base_ptr->calc(3,4);

    derived.Print();

    derived.calc(3,3);
}