// C++ program to illustrate the use of unique_ptr 
#include<iostream> 
#include<memory> 
using namespace std;
  
class MyClass
{
public:
    void classMethod()
    {
        cout << "MyClass::classMethod" << endl;
    }
    void show()
    {
        cout << "MyClass::showMethod" << endl;
    }
};
  
int main()
{
    unique_ptr<MyClass> ptr_1 (new MyClass);
    ptr_1->show();
  
    // returns the memory address of ptr_1
    cout << ptr_1.get() << endl;
  
    // transfers ownership to ptr_2
    unique_ptr<MyClass> ptr_2 = move(ptr_1);
    ptr_2 -> show();
    cout << ptr_1.get() << endl;
    cout << ptr_2.get() << endl;
  
    // transfers ownership to ptr_3
    unique_ptr<MyClass> ptr_3 = move (ptr_2);
    ptr_3->show();
    cout << ptr_1.get() << endl;
    cout << ptr_2.get() << endl;
    cout << ptr_3.get() << endl;
  
    return 0;
}