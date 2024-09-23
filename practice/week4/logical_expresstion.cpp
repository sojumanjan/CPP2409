#include<iostream>

using namespace std;
int main(){
    bool b;
    b = 1 && 2; //둘다 true이므로 true
    cout << "1 && 2 = " << b << endl;
    
    b = 1 && 0; //둘다 1이 아니므로 false
    cout << "1 && 0 = " << b << endl;

    b = 0 || 0; //둘 중 하나도 true가 아니므로 false
    cout << "0 || 0 = " << b << endl;

    b = 0 || 1; //둘 중 하나가 true이므로 true;
    cout << "0 || 1 = " << b << endl;

    b = -1; //0을 제외한 숫자는 true로 인식함.
    cout << "b = " << b << endl;
    cout << "!b = " << !b << endl;

    return 0;
}