#include <iostream>
using namespace std;

class Shape
{
  public:
    Shape(double x, double y) : anchor_x(x), anchor_y(y) {}
    void print(void)
    {
        cout << "anchor: "
             << "(" << anchor_x << "," << anchor_y << ")";
    }

  private:
    double anchor_x, anchor_y;
};

int main(void){

    Shape box(5, 10);
    box.print();
    return 0;
}