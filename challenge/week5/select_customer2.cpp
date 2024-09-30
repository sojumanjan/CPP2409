#include <iostream>
#include <string>
using namespace std;

int main() {
    const int maxPeople = 3;
    string names[maxPeople];
    int ages[maxPeople];
    bool isEnd = true;

    cout << maxPeople << "명의 회원 정보를 입력해주세요." << endl;

    for (int i = 0; i < maxPeople; i++) {
        cout << "사람 " << i+1 << "의 이름: ";
        cin >> names[i];
        cout << "사람 " << i+1 << "의 나이: ";
        cin >> ages[i];
    }
    int select;
    while(isEnd){
        cout << "1. 가장 나이가 많은 사람 출력" << endl;
        cout << "2. 가장 나이가 적은사람 출력" << endl;
        cout << "3. 종료" << endl;
        cin >> select;
        int index = 0;
        switch (select){
            case 1:{
                int maxAge = ages[0];
                for (int i = 0; i < maxPeople; i++){
                    if (ages[i] > maxAge){
                        maxAge = ages[i];
                        index = i;
                    }
                }
                cout << names[index] << " (" << ages[index] << "세)" << endl;
                
            } break;
            case 2:{
                int minAge = ages[0];
                for (int i = 0; i < maxPeople; i++){
                    if (ages[i] < minAge){
                        minAge = ages[i];
                    }
                }
                cout << names[index] << " (" << ages[index] << "세)" << endl;
                break;
            }
            case 3:
                isEnd = false;
                break;
        }
    }
    return 0;
}