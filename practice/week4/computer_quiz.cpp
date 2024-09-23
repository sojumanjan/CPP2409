#include<iostream>

using namespace std;

int main(){
    char secret_code = 'j';

    cout << "비밀 코드(소문자 알파벳 1개)를 맞춰보세요 : ";
    char code;
    cin >> code;
    if (code < secret_code)
        cout << code << "뒤에 있습니다"<< endl;
    else if (code > secret_code)
        cout << code << "앞에 있습니다."<< endl;
    else
        cout <<"맞췄습니다."<< endl;

    return 0;
}