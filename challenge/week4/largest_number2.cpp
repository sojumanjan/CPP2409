#include<iostream>

using namespace std;

int main(){
    int a, b, c, largest;

    cout << "3개의 정수를 입력하시오 : ";
    cin >> a >> b >> c;
    largest = a;
    if (b > largest){
        if (c > b)
            largest = c;
        else
            largest = b;
    }
    if (c > largest){
        if (b > c)
            largest = b;
        else
            largest = c;
    }

    cout << "가장 큰 정수는 " << largest <<"입니다."<< endl;
}