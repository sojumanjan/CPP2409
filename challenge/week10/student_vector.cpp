#include<vector>
#include<iostream>

using namespace std;

int main(){
    vector<int> grade;
    int studentGrade = 0;
    int sum = 0;
    int studentsCount = 0;
    while (1){
        cout << "성적을 입력하시오(종료는 -1) : ";
        cin >> studentGrade;
        if (studentGrade == -1)
            break;
        sum += studentGrade;
        studentsCount++;
    }
    cout << "성적 평균 = " << float(sum / studentsCount) << endl;
}