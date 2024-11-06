#include<vector>
#include<iostream>
#include<string>
using namespace std;

int main(){
    vector<vector<string>> movie;
    movie.push_back({"titinic", "9.9"});
    movie.push_back({"gone with the wind", "9.6"});
    movie.push_back({"terminator", "9.7"});
    for (int i = 0; i < 3; i++){
        cout << movie[i][0] << ": " << movie[i][1] << endl;
    }
    
}