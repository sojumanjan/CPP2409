#include <iostream>

using namespace std;

class Rectangle {
public:
    int width, height;
    int CalcArea() {
        return width * height;
    }
};
int main() {
    Rectangle obj;
    Rectangle obj2;
    obj.width = 3;
    obj.height = 4;
    obj2.width = 10;
    obj2.height = 5;
    int area = obj.CalcArea();
    int area2 = obj2.CalcArea();
    cout << "사각형1의 넒이: " << area << endl;
    cout << "사각형2의 넓이: " << area2 << endl;
    return 0;
}
