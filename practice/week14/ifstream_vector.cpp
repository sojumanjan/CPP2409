#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

class TempData{
public:
int hour;
double temperature;
};

int main(){
    ifstream is{"temp.txt"};
    if (!is){
        cerr << "파일 오픈에 실패했습니다." << endl;
        exit(1);
    }

    vector<TempData> temps;
    int hour;
    double temperature;

    while (is >> hour >> temperature){
        temps.push_back(TempData{hour, temperature});
    }
    for (TempData k : temps){
        cout << k.hour << "시 : 온도 " << k.temperature << endl;
    }
    return 0;
}