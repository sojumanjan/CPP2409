#include<iostream>
using namespace std;

int main(){
    int temperature;
    cout<<"화씨온도 : ";
    cin>> temperature;
    cout<<"섭씨온도 : "<<(5.0 / 9.0) * (temperature - 32);
}