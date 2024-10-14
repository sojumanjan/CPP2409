#include<iostream>
#include<string>

using namespace std;

//문자열에서 대문자인 부분을 찾아 32만큼을 더하면 대문자 코드로 바뀜
string toLowerStr(string str){
    for (int i = 0; i < str.length(); i++){
        if (str[i] >= 'A' && str[i] <= 'Z'){
            str[i] += 32;
        }
    }
    return str;
}
//문자열에서 소문자인 부분을 찾아 32만큼을 빼면 소문자 코드로 바뀜
string toUpperStr(string str){
    for (int i = 0; i < str.length(); i++){
        if (str[i] >= 'a' && str[i] <= 'z'){
            str[i] -= 32;
        }
    }
    return str;
}

int calcHammingDist(string s1, string s2){
    //둘다 소문자로 바꿔서 비교
    s1 = toLowerStr(s1);
    s2 = toLowerStr(s2);
    int sum = 0;
    for (int i = 0; i < s1.length(); i++){
        if (s1[i] != s2[i])
            sum++;
    }
    return sum;
}

int main(){
    string s1, s2;
    int count = 0;

    do {
        cout << "DNA1 : ";
        cin >> s1;
        cout << "DNA2 : ";
        cin >> s2;
        if (s1.length() != s2.length())
            cout << "오류 : 길이가 다름" <<endl;
        else{
            cout << "해밍 거리는 " << calcHammingDist(s1, s2) << endl;
        }
    } while (s1.length() != s2.length());
    
    return 0;
}