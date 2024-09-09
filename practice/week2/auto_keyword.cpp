#include<iostream>
using namespace std;

auto add(int x, int y){
    return x + y;
    //return x + y + 0.1;이면 실수형으로 변환되어 리턴
}
int main(){
    auto sum = add(5,6);
    cout<<sum;
    return 0;
}