// Example solution for operator overloading
// include iostream for printing
#include<iostream>
// Define Point class
class Point {    
    // Define public constructor
    // Define + operator overload
    // Define Print() function to print (x, y) of Point
    public:
        Point(int xc = 0, int yc = 0) : x(xc), y(yc) {}
        
        // The following will be automatically called when '+' is used with
        // between two Complex objects
        Point operator + (Point const &obj) 
        {
            Point res;
            res.x = Point::x + obj.x;
            res.y = Point::y + obj.y;
            return res;
        }
        // Print function
        void Print() 
        {
            std::cout << "Point: (" << Point::x << ", " << Point::y << ")"<< "\n";
        }
    
    // Declare private attributes x and y
    private:
        int x, y;
};

// Test in main()
int main() 
{
    Point p1(10, 5);
    Point p2(2, 4);
    Point p = p1 + p2; // An example call to "operator +"
    p1.Print();
    p2.Print();
    p.Print();
}