#include<iostream>
using namespace std;

int main(){
    int curMoney, candyPrice;
    cout<<"현재 가지고 있는 돈 : ";
    cin>> curMoney;
    cout<<"캔디의 가격 : ";
    cin>> candyPrice;
    cout<<"최대로 살 수 있는 캔디 : "<<curMoney/candyPrice<<endl;
    cout<<"캔디 구입 후 남은 돈 : "<<curMoney%candyPrice<<endl;
}