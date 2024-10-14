#include<iostream>
#include<string>

using namespace std;

int main(){
    //문자열 객체 생성
    string s = "Hello, World!";
    
    //특정 인덱스의 문자 접근 (읽기 전용)
    char ch = s[7];
    cout << "인덱스 7의 문자: " << ch << endl;

    if (!s.empty()){
        cout << "이 문자열은 비어있지 않습니다." << endl;
    }
    else{
        cout << "이 문자열은 비어있습니다." << endl;
    }

    //문자열에 문자열 삽입
    s.insert(5, " C++");
    cout << "index 5에 c++ 문자열 삽입: " << s << endl;

    return 0;
}