// Example solution for function overloading
// include iostream for printing
#include<iostream>
// Define Point class
class Point {    
    // Declare private attributes x and y
    private:
        int x, y;
    // Define public constructor
    // Define Print() function to print (x, y) of Point
    public:
        Point(int xc = 0, int yc = 0) : x(xc), y(yc) {};

    // Define operator overload
        Point operator + (Point const &obj) {
            Point res;
            res.x = Point::x + obj.x;
            res.y = Point::y + obj.y;
            return res;
        }
        
        // overload function p.print depending on the number of input parameters
        void Print() {
            std::cout << "no input parameter" << "\n";
            std::cout << "Point: (" << Point::x << ", " << Point::y << ")"<< "\n";
        }
        void Print(int x) {
            std::cout << "one input parameter: " << x << "\n";
            std::cout << "Point: (" << x << ", " << Point::y << ")"<< "\n";
        }

        void Print(int x, int y) {
            std::cout << "2 input parameters: " << x << "," << y << "\n";
            std::cout << "Point: (" << x << ", " << y << ")"<< "\n";
        }        
};

// Test in main()
int main() 
{
    Point p1(10, 5), p2(1,7);

    Point p3 = p1 + p2;

    p1.Print();
    p1.Print(3);

    p3.Print();
    p3.Print(2);
    p3.Print(2, 3);
}