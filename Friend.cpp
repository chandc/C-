// demonstrate the use friend class
// 

#include<iostream>
#include<string>

using namespace std;

const float pi=3.1416;

class Rectangle;

class Square{
    friend class Rectangle;
    private:
        int side;
    public:
        Square(int s){
            side=s;}

//Square(int s) : side(s) {}

};

class Rectangle{ 
   private:
       int rec_width;
       int rec_height;
    public:
       int RecArea(){ return rec_width*rec_height;}
       void Convert(Square S){
           rec_width = S.side;
           rec_height = S.side;
       }
};

int main() {
    Rectangle r;
    Square s(4);
    r.Convert(s);
    std::cout << r.RecArea() << "\n";  
}