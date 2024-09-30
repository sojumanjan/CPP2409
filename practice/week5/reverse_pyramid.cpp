#include<iostream>

using namespace std;

int main(){
    int floor;
    cout << "몇 층을 쌓겠습니까? (5~100):";
    cin >> floor;
    for (int i = 0; i < floor; i++){        //i = 0, 1, 2, 3, 4
        for (int j = i; j > 0; j--){ //j = 0, 1, 2, 3, 4
            cout << "S";
        }
        for (int k = 2 * (floor - i) - 1; k > 0; k--){ //k = 9, 7, 5, 3, 1
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}