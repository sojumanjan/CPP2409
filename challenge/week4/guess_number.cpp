#include<iostream>
#include<time.h>

using namespace std;

int main(){
    srand(time(NULL));

    int answer = rand()%100;
    int tries = 0;

    int guess;

    do{
        cout << "정답을 추측하세요 : ";
        cin >> guess;
        if(guess > answer){
            cout << "정답보다 추측한 수가 더 큽니다."<< endl;
            tries ++;
        }
        else if (guess < answer){
            cout << "정답보다 추측한 수가 더 작습니다." << endl;
            tries ++;
        }
    } while(guess != answer);
    cout << "축하합니다. 맞췄습니다. 시도 횟수 : " << tries <<endl;
}