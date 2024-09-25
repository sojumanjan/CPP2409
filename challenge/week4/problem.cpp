#include<iostream>
#include<time.h>
using namespace std;

int main(){
    int i;
    int answer;
    cout << "산수 문제를 자동으로 출력합니다. " <<endl;

    while(true){
        srand(time(NULL));
        int firstNum = rand()%100;
        int secondNum = rand()%100;
        answer = firstNum + secondNum; //변수에 산수 정답 입력
        cout << firstNum << " + " << secondNum << " : ";
        cin >> i; //사용자 입력
        if (answer == i){ //정답이면 break를 통해 while문 탈출
            cout << "맞았습니다." << endl;
            break;
        }
        else
            cout << "틀렸습니다." << endl;
    }
}