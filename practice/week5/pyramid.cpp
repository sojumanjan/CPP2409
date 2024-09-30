#include<iostream>

using namespace std;

int main(){
    int floor;
    cout << "몇 층을 쌓겠습니까? (5~100):";
    cin >> floor;                                   
    for (int i = floor; i > 0 ; i--){                //i = 5, 4, 3, 2, 1
        for (int j = floor - i; j < floor - 1; j++){    //j = 4, 3, 2, 1, 0
            cout << "S";                                
        }
        for (int k = (floor - i + 1) * 2 - 1; k > 0; k--){        //k = 1, 3, 5, 7, 9 
            cout << "*";
        } 
        cout << endl;
    }
    return 0;
}