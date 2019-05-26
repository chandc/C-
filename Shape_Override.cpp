// C++ program for function overriding
#include<iostream>
using namespace std;

const float pi=3.1416;

class Shape {
    public:
        Shape() { }
        virtual double Area() const = 0;
        virtual double PerimeterLength() const = 0;
};

class Rectangle : public Shape {
    private:
       int width;
       int height;
  
  public:
       Rectangle(int wid, int ht) { width=wid; height=ht; }
       virtual double Area() const override{
             std::cout << "Rectangle:" << "\n";
             return width*height; 
        }
        virtual double PerimeterLength() const override{
            std::cout << "Rectangle:" << "\n";
            return 2*(width + height);
        }
};
class Circle : public Shape {
    private:
       int radius;
  
  public:
       Circle(int r) { radius=r; }
         virtual double Area() const override {
            std::cout << "Circle:" << "\n";
            return Circle::radius*Circle::radius*pi;
        }
        virtual double PerimeterLength() const override{
            std::cout << "Circle:" << "\n";
            return 2 * radius*pi;
    }
};


int main() {
    // Generic containter of Shapes (array) :
    Shape** shapes = new Shape*[2];
    shapes[0] = new Circle(12);
    shapes[1] = new Rectangle(10, 6);
    for (int i = 0;i < 2;i++) {
        std::cout << "Area: " << shapes[i]->Area()<< "\n";
        std::cout << "Perimeter: " << shapes[i]->PerimeterLength() << "\n";

    }
}
