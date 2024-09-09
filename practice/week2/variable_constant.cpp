#include<iostream>
//심볼릭 상수 선언
#define PI 3.14159265359
using namespace std;
int main(){
    //정수형 변수 선언
    int income = 1000;
    //실수형 상수 선언
    const double TAX_RATE = 0.25;
    income = income - income * TAX_RATE;

    double x = 100;
    x = x * PI;

    cout <<x << endl;
    return 0;
}