#include<iostream>

using namespace std;

int main(){
    cout << "구구단 출력" << endl;

    for (int i = 2; i <= 9; i++){ //단 구분을 위한 큰 for문
        cout << i << "단" << endl;
        for (int j = 1; j <= 9; j++){ //단에서 1 ~ 9까지 곱셈을 나타내는 for문
            cout << i << " * " << j << " = " << i * j << endl;
        }
        cout << endl;
    }
}