#include<iostream>
#include<string>

using namespace std;

class Animal{
protected:
    string color;
    string name;
    int age;

public:
    std::string getColor(){return color;}
    std::string getName(){return name;}
    int getAge(){return age;}
    
    void setColor(string c){ color = c;}
    void setName(string c){name = c;}
    void setAge(int a){age = a;}
};

class Snake: public Animal{
     private:
        int length;
    public:
        int getLength(){return length;}
        void setLength(int l){length=l;}

};

class Cat: public Animal{
     private:
        int height;
    public:
        int getHeight(){return height;}
        void setHeight(int h){height=h;}

};
    
    
// Test in main()
int main() {
    Cat c;
    Snake s;

    c.setAge(10);
    c.setHeight(2);
    s.setName("Python");
    cout << "Age= " << c.getAge() << "\n";
    cout << "Height= " << c.getHeight() << "\n";
    cout << "Name= " << s.getName() << "\n";

}