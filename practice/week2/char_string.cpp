
#include<iostream>
#include<string>
using namespace std;

int main(){
    char c = 'C';
    //char d = "C"; 쌍따옴표는 안됨
    string s1 = "Good";
    string s2 = "Morning";
    string s3 = s1 + " " + s2 + "!"; 
    
    //문자열끼리의 합만 가능. 숫자 끼면 X
    //s1 + s2 + 10 + "개"; (X)
    cout<<s3<<endl;
    return 0;
}