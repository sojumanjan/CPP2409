#include<iostream>

using namespace std;

int main(){
    int a, b, c, largest;

    cout << "3개의 정수를 입력하시오 : ";
    cin >> a >> b >> c;
    if (a > b && a > c) //a가 b, c보다 크면 가장큰수는 a, b와 c도 마찬가지
        cout << "가장 큰 수는 " << a << "입니다."<< endl;
    else if (b > a && b > c)
        cout << "가장 큰 수는 " << b << "입니다." << endl;
    else if (c > a && c > b)
        cout << "가장 큰 수는 " << c << "입니다." << endl;
    else{
        if (a == b) //위 if문이 모두 실행되지 않으면 가장 큰 수가 두개 이상이라는 뜻이므로 큰 수 출력
            cout << "가장 큰 수가 2개 이상이며 그 수는 " << a <<"입니다." << endl;
        else if (b == c)
            cout << "가장 큰 수가 2개 이상이며 그 수는" << b <<"입니다." <<endl;
        else
            cout << "가장 큰 수가 2개 이상이며 그 수는" << c <<"입니다." <<endl;
    }
        
}