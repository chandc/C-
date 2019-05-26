// demonstrate the use of inheritance with protected attributes

#include<iostream>
#include<string>

using namespace std;

const float pi=3.1416;

class Line{
protected:
    int length;
};

class Circle: public Line{
 
    public:
        void setRadius(int l){
            Circle::length=l;}
        float getArea(){ 
            return Circle::length*Circle::length*pi;}

};


int main() {
    Circle c;
    c.setRadius(1);
    cout << "Area of a Circle= "<< c.getArea() << "\n";
}