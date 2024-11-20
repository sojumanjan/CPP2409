#include <iostream>
#include <string>
#include <vector>
#include "user.h"

using namespace std;

const int map_X = 5;
const int map_Y = 5;
// 사용자 정의 함수
bool CheckXY(int user_x, int map_X, int user_y, int map_Y, string ch);
void DisplayMap(vector<vector<int>> map, int w_x, int w_y, int m_x, int m_y);
bool CheckGoal(vector<vector<int>> map, int user_x, int user_y);
//명령어 확인 후 움직였다면 true반환
bool CheckMove(string ch){
	return (ch == "up" || ch == "down" || ch == "left" || ch == "right");
}

// 메인  함수
int main() {
    User *user;
	Magician magician;
	Warrior warrior;
	//유저 턴을 바꾸기 위한 변수
	int k = 0;
	string cur_user_name;
	// 0은 빈 공간, 1은 아이템, 2는 적, 3은 포션, 4는 목적지
	vector<vector<int>> map = { {0, 1, 2, 0, 4},
					{1, 0, 0, 2, 0},
					{0, 0, 0, 0, 0},
					{0, 2, 3, 0, 0},
					{3, 0, 0, 0, 2} };

	user = &warrior;
	DisplayMap(map, warrior.user_x, warrior.user_y, magician.user_x, magician.user_y);
	cout << "HP : " << user->GetHP() << endl;
	// 게임 시작 
	while (1) { // 사용자에게 계속 입력받기 위해 무한 루프
		k++;
		if (k % 2 == 0){
			user = &warrior;
			cur_user_name = "Warrior";
		}
		else {
			user = &magician;
			cur_user_name = "Magician";
		}
		cout << "현재 차례 : "<< cur_user_name << endl;
		// 사용자의 입력을 저장할 변수
		string user_input = "";
		//한글 입력시 이상하게 인식해서 영어로 바꿈.
		cout << "명령어를 입력하세요 (up,down,left,right,map,exit,attack): ";
		cin >> user_input;
		//움직였는지 확인
		if (CheckMove(user_input) == true){
			//만약 이동 명령어라면 XY를 체크, 매개변수로 명령어를 전달해서 XY 확인
			if (CheckXY(user->user_x, map_X, user->user_y, map_Y, user_input) == false){
				cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
				continue;
			}
			//움직였는데 XY가 유효하다면 실행
			else{
				user->DecreaseHP(1);
				if (user_input == "up") {
					cout << "위로 한 칸 올라갑니다." << endl;
					user->user_y --;
				}
				else if (user_input == "down") {
					cout << "아래로 한 칸 내려갑니다." << endl;
					user->user_y ++;
				}
				else if (user_input == "left") {
					cout << "왼쪽으로 이동합니다." << endl;
					user->user_x --;
				}
				else if (user_input == "right") {
					cout << "오른쪽으로 이동합니다." << endl;
					user->user_x ++;
				}
				//움직인 칸에 있는 상호체 확인
				if (map[user->user_y][user->user_x] == 1){
					cout << "아이템을 먹었습니다. " << endl;
					user->itemCnt++;
				}
				if (map[user->user_y][user->user_x] == 2){
					user->DecreaseHP(2);
					cout << "적을 만났습니다. HP가 추가로 2 감소합니다." << endl;
				}
				if (map[user->user_y][user->user_x] == 3){
					user->IncreaseHP(2);
					cout << "포션을 먹었습니다. HP를 2 회복합니다. " << endl;
				}
				DisplayMap(map, warrior.user_x, warrior.user_y, magician.user_x, magician.user_y);
				cout << "현재 HP는 " << user->GetHP() << " 이고, 먹은 아이템은 총 " << user->itemCnt << "개 입니다." <<endl;
				if (user->GetHP() <= 0){
					cout << "HP가 0이하가 되었습니다. 게임을 종료합니다." << endl;
					break;
				}
			}
		}
		//움직이지 않았다면 실행
		else if (user_input == "map") {
			// TODO: 지도 보여주기 함수 호출
			DisplayMap(map, warrior.user_x, warrior.user_y, magician.user_x, magician.user_y);
		}
		else if (user_input == "exit") {
			cout << "종료합니다.";
			break;
		}
		else if (user_input == "attack"){
			user->DoAttack();
		}
		else{
			cout << "잘못된 입력입니다. : " << user_input << endl;
			continue;
		}	

		// 목적지에 도달했는지 체크
		bool finish = CheckGoal(map, user->user_x, user->user_y);
		if (finish == true) {
			cout << "목적지에 도착했습니다! 축하합니다!" << endl;
			cout << "게임을 종료합니다." << endl;
			break;
		}

	}
	return 0;
}

// 지도와 사용자 위치 출력하는 함수
void DisplayMap(vector<vector<int>> map, int w_x, int w_y, int m_x, int m_y) {
	for (int i = 0; i < map_Y; i++) {
		for (int j = 0; j < map_X; j++) {
			if (i == w_x && j == w_y && j == m_x && i==m_y) {
				cout << " Both |"; // 양 옆 1칸 공백
			}
			else if (i == w_x && j == w_y){
				cout << " Warr |";
			}
			else if (i == m_x && j == m_y){
				cout << " Magi |";
			}
			else {
				int pos_state = map[i][j];
				switch (pos_state) {
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
bool CheckXY(int user_x, int mapX, int user_y, int mapY, string user_input) {
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
bool CheckGoal(vector<vector<int>> map, int user_x, int user_y) {
	// 목적지 도착하면
	if (map[user_y][user_x] == 4) {
		return true;
	}
	return false;
}