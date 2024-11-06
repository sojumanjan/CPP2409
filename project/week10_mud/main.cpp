#include <iostream>
#include <string>
#include<vector>
#include "user.h"

using namespace std;

const int mapX = 5;
const int mapY = 5;
int playerHp = 20;
// 사용자 정의 함수
bool checkXY(int user_x, int mapX, int user_y, int mapY, string ch);
void displayMap(vector<vector<int>> map, int user_x, int user_y);
bool checkGoal(vector<vector<int>> map, int user_x, int user_y);
//명령어 확인 후 움직였다면 true반환
bool checkMove(string ch){
	return (ch == "up" || ch == "down" || ch == "left" || ch == "right");
}

// 메인  함수
int main() {
    User user;
	// 0은 빈 공간, 1은 아이템, 2는 적, 3은 포션, 4는 목적지
	vector<vector<int>> map = { {0, 1, 2, 0, 4},
					{1, 0, 0, 2, 0},
					{0, 0, 0, 0, 0},
					{0, 2, 3, 0, 0},
					{3, 0, 0, 0, 2} };

	// 유저의 위치를 저장할 변수
	int user_x = 0; // 가로 번호
	int user_y = 0; // 세로 번호
	displayMap(map, user_x, user_y);
	cout << "HP : " << user.GetHP() << endl;
	// 게임 시작 
	while (1) { // 사용자에게 계속 입력받기 위해 무한 루프
		// 사용자의 입력을 저장할 변수
		string user_input = "";
		//한글 입력시 이상하게 인식해서 영어로 바꿈.
		cout << "명령어를 입력하세요 (up,down,left,right,map,exit): ";
		cin >> user_input;
		//움직였는지 확인
		if (checkMove(user_input) == true){
			//만약 이동 명령어라면 XY를 체크, 매개변수로 명령어를 전달해서 XY 확인
			if (checkXY(user_x, mapX, user_y, mapY, user_input) == false){
				cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
				continue;
			}
			//움직였는데 XY가 유효하다면 실행
			else{
				user.DecreaseHP(1);
				if (user_input == "up") {
					cout << "위로 한 칸 올라갑니다." << endl;
					user_y --;
				}
				else if (user_input == "down") {
					cout << "아래로 한 칸 내려갑니다." << endl;
					user_y ++;
				}
				else if (user_input == "left") {
					cout << "왼쪽으로 이동합니다." << endl;
					user_x --;
				}
				else if (user_input == "right") {
					cout << "오른쪽으로 이동합니다." << endl;
					user_x ++;
				}
				//움직인 칸에 있는 상호체 확인
				if (map[user_y][user_x] == 1){
					cout << "아이템을 먹었습니다. " << endl;
				}
				if (map[user_y][user_x] == 2){
					user.DecreaseHP(2);
					cout << "적을 만났습니다. HP가 추가로 2 감소합니다." << endl;
				}
				if (map[user_y][user_x] == 3){
					user.IncreaseHP(2);
					cout << "포션을 먹었습니다. HP를 2 회복합니다. " << endl;
				}
				displayMap(map, user_x, user_y);
				cout << "HP : " << user.GetHP() << endl;
				if (playerHp <= 0){
					cout << "HP가 0이하가 되었습니다. 게임을 종료합니다." << endl;
					break;
				}
			}
		}
		//움직이지 않았다면 실행
		else if (user_input == "map") {
			// TODO: 지도 보여주기 함수 호출
			displayMap(map, user_x, user_y);
		}
		else if (user_input == "exit") {
			cout << "종료합니다.";
			break;
		}
		else{
			cout << "잘못된 입력입니다. : " << user_input << endl;
			continue;
		}	

		// 목적지에 도달했는지 체크
		bool finish = checkGoal(map, user_x, user_y);
		if (finish == true) {
			cout << "목적지에 도착했습니다! 축하합니다!" << endl;
			cout << "게임을 종료합니다." << endl;
			break;
		}

	}
	return 0;
}


// 지도와 사용자 위치 출력하는 함수
void displayMap(vector<vector<int>> map, int user_x, int user_y) {
	for (int i = 0; i < mapY; i++) {
		for (int j = 0; j < mapX; j++) {
			if (i == user_y && j == user_x) {
				cout << " USER |"; // 양 옆 1칸 공백
			}
			else {
				int posState = map[i][j];
				switch (posState) {
				case 0:
					cout << "      |"; // 6칸 공백
					break;
				case 1:
					cout << "아이템|";
					break;
				case 2:
					cout << "  적  |"; // 양 옆 2칸 공백
					break;
				case 3:
					cout << " 포션 |"; // 양 옆 1칸 공백
					break;
				case 4:
					cout << "목적지|";
					break;
				}
			}
		}
		cout << endl;
		cout << " -------------------------------- " << endl;
	}
}

// 이동하려는 곳이 유효한 좌표인지 체크하는 함수 (매개변수 추가 - 유저 명령어)
bool checkXY(int user_x, int mapX, int user_y, int mapY, string user_input) {
	bool checkFlag = false;
	if (user_input == "up")
		user_y--;
	else if (user_input == "down")
		user_y++;
	else if (user_input == "left")
		user_x--;
	else if (user_input == "right")
		user_x++;
	if (user_x >= 0 && user_x < mapX && user_y >= 0 && user_y < mapY) {
		checkFlag = true;
	}
	return checkFlag;
}

// 유저의 위치가 목적지인지 체크하는 함수
bool checkGoal(vector<vector<int>> map, int user_x, int user_y) {
	// 목적지 도착하면
	if (map[user_y][user_x] == 4) {
		return true;
	}
	return false;
}