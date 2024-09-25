#include<iostream>

using namespace std;

int main(){
    int vowel = 0;
    int consonant = 0;
    cout <<"영문자를 입력하고 멈추려면 ctrl + z를 치세요" <<endl;

    char ch;

    while (cin >> ch){ //ctrl + z 입력시 false 되면서 while문 종료
        if (ch >= 'a' && ch <= 'z'){ //입력한 문자가 소문자 알파벳일 때 실행
            switch(ch){ //자음은 a e i o u 5개이므로 자음이면 vowel에 1씩 추가 그 외의 문자는 모음이므로 default에서 consonant에 1씩 추가
                case 'a':
                case 'e':
                case 'i':
                case 'o':
                case 'u':
                    vowel ++;
                    break;
                default:
                    consonant ++;
                    break;
            }
        }
        else{ //입력한 문자가 소문자 알파벳이 아닐 때 실행
            cout << "영 소문자가 아닙니다. 다시 입력하세요 : ";
        }
    }
    cout << "모음 : " << vowel <<endl;
    cout <<"자음 : " << consonant << endl;
}