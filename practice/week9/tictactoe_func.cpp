#include <iostream>
using namespace std;

const int numCell = 3;

bool isValid (char board[numCell][numCell], int x, int y){
	if (x >= numCell || y >= numCell) {// 좌표 범위를 벗어날때
			cout << x << "," << y << ": x와 y둘중 하나가 칸을 벗어납니다. " << endl;
			return false;
		}
		if (board[x][y] != ' ') {// 좌표범위의 입력값이 중복될때
			cout << x << "," << y << ": 이미 돌이 차있습니다. " << endl;
			return false;
		}
	return true;
}

//보드의 행, 열 검사 함수
bool checkBoardLine(char board[numCell][numCell], char currentUser){
	for (int i = 0; i < numCell; i++){
		int checkCount = 0;
		for (int j = 0; j < numCell; j++){
			if (board[i][j] == currentUser)
				checkCount++;
		}
		if (checkCount == numCell){
			cout << "가로에 모두 돌이 놓였습니다.";
			return true;
		}
	}
	for (int i = 0; i < numCell; i++){
		int checkCount = 0;
		for (int j = 0; j < numCell; j++){
			if (board[j][i] == currentUser)
				checkCount++;
		}
		if (checkCount == numCell){
			cout << "세로에 모두 돌이 놓였습니다.";
			return true;
		}
	}
	return false;
}
//보드의 대각 검사 함수
bool checkBoardDeagak(char board[numCell][numCell], char currentUser){
	int checkCount = 0;
	char cellChar = board[0][0];
	if (cellChar != ' '){
		for (int i = 0; i < numCell; i++){
			if (board[i][i] == cellChar){
				checkCount++;
			}
		}
		//대각이 찼으므로 isWin변경
		if (checkCount == numCell ){
			cout << "왼쪽에서 오른쪽 대각선으로 " << currentUser <<" 돌이 모두 놓였습니다."<< endl;
			return true;
		}
		checkCount = 0;
		cellChar = board[0][numCell-1];
		//위 왼->오 대각선 검사와 동일
		if (cellChar != ' '){
			for (int i = 0; i < numCell; i++){
				if (board[i][numCell-1-i] == cellChar){
					checkCount++;
				}
			}
			if (checkCount == numCell){
				cout << "오른쪽에서 왼쪽 대각선으로 " << currentUser <<" 돌이 모두 놓였습니다."<< endl;
				return true;
			}
		}
	}
	return false;
}
//승리 조건 검사 함수
bool checkWin(char board[numCell][numCell], char currentUser){
	//행, 열 검사 후 승자가 없다면 대각 검사 리턴. 승자가 있다면 바로 true 리턴
	if (checkBoardLine(board, currentUser) == false)
		return checkBoardDeagak(board, currentUser);
	else 
		return true;
		
}
//보드판 출력 함수화
void visualizeBoard(char board[numCell][numCell]){
	for (int i = 0; i < numCell; i++){
		for (int j = 0; j < numCell; j++){
			if (j == numCell - 1)
				cout << "---" << endl;
			else
				cout << "---|";
		}
		for (int j = 0; j < numCell - 1; j++){
			if (board[i][j] == ' ')
				cout << "   |";
			else
				cout << " " << board[i][j] << " |";
		}
		cout << " " << board[i][numCell - 1] << endl;
	}
	for (int j = 0; j < numCell; j++){
		if (j == numCell - 1)
			cout << "---" << endl;
		else
			cout << "---|";
	}
}

int main() {
	// 게임을 진행하는 데 필요한 변수 선언
	int k = 0; // 누구 차례인지 체크하기 위한 변수
	char currentUser = 'X'; // 현재 유저의 돌을 저장하기 위한 변수
	char board[numCell][numCell]{}; // 보드판을 나타내는 2차원 배열
	int x, y = 0; // 사용자에게 xy좌표값을 입력받기 위한 변수

	// 보드판 초기화
	for (int i = 0; i < numCell; i++) {
		for (int j = 0; j < numCell; j++) {
			board[i][j] = ' ';
		}
	}

	// 게임을 무한 반복
	while (true) {
		// 1. 누구 차례인지 출력
		// TODO 1.1: 3인용 게임으로 변경
		switch (k % 3) {
		case 0:
			currentUser = 'X';
			break;
		case 1:			
			currentUser = 'O';
			break;
		case 2:
			currentUser = 'H';
		}
		cout << k % 3 + 1 << "번 유저("<< currentUser <<")의 차례입니다. -> ";

		// 2. 좌표 입력 받기
		cout << "(x, y) 좌표를 입력하세요: ";
		int x, y;
		cin >> x >> y;

		// 3. 입력받은 좌표의 유효성 체크
		// TODO FUNC 1: isValid 함수 생성 후 호출
		if (isValid(board, x, y) == false){
			continue;
		}

		// 4. 입력받은 좌표에 현재 유저의 돌 놓기
		board[x][y] = currentUser;

		// 5. 현재 보드 판 출력
		// TODO 1.2: numCell 숫자에 맞춘 보드판 출력
		visualizeBoard(board);

		bool isWin = false; // 승리 여부
		// TODO FUNC2: 6.1부터 6.2까지 checkWin 함수 생성 후 호출
		// 6.1. 가로/세로 돌 체크하기 + 대각선 돌 체크하기
		isWin = checkWin(board, currentUser);

		// 승리자가 결정되었으면 해당 플레이어를 출력하고 게임을 종료한다.
		if (isWin == true) {
			cout << k % 3 + 1<< "번 유저(" << currentUser << ")의 승리입니다!" << endl;
			break;
		}

		// 7. 모든 칸 다 찼는지 체크하기
		int checked = 0;
		for (int i = 0; i < numCell; i++) {
			for (int j = 0; j < numCell; j++) {
				if (board[i][j] == ' ') {
					checked++;
				}
			}
		}
		if (checked == 0) {
			cout << "모든 칸이 다 찼습니다.  종료합니다. " << endl;
			break;
		}
		k++;
	}

	return 0;
}