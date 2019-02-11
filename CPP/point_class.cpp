#include<iostream>
using namespace std;

class Point{
    private:
        int x,y;
    
    public:

        Point(double x = 0.0, double y = 0.0): x(x), y(y) {}

        double getx() { return this->x ; }
        double setx(double x ) {this->x  = x; }
        double gety() { return this->y ; }
        double sety(double x ) {this->x  = x; }

        // This overloading is for type temp++;
        void operator++ (int){

            this->x ++;
            this->y ++;
        }

        // for type ++temp
        Point operator++ (){

            this->x ++;
            this->y ++;

            Point temp(this->x, this->y);
            return temp;
        }

            Point operator+ (Point& p1){
            double a = p1.getx() + this->x;
            double b = p1.gety() + this->y;

            Point sum(a,b);

            return sum;
        }
    
};

ostream& operator<< (ostream& out, Point& p1){
    out<<"("<<p1.getx()<<", "<<p1.gety()<<") ";
}



int main(){

    Point p3();
    Point p5(7,9);
    
    p3++;

    
    Point p2 = p3 + p5;
    ++p3;
    
    cout<<p2<<endl;
    cout<<p5<<endl;
    cout<<p3<<endl;
}