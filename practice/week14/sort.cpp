#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int main(){
    vector<int> data = {5, 2, 4, 1, 3, 20, 9, 9, 9, 9, 10};
    sort(data.begin()+2, data.end());
    for (int n : data){
        cout << n << ' ';
    }
    cout << '\n';
    return 0;
}
