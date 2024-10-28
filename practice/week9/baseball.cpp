#include <iostream>
#include <string>
using namespace std;

//입력된 숫자에 같은 수가 있는지 확인
bool checkNumber(int f1, int f2, int f3){
	if (f1 == f2 || f2 == f3 || f1 == f3){
		cout << "겹치는 숫자가 있습니다. " << endl;
		return false;
	}
	return true;
}

int main() {
	int randomNum; // 맞춰야 하는 3자리수의 숫자 저장 변수
	int firstNum; // 정답의 첫번째 자리수
	int secondNum; // 정답의 두번째 자리수
	int thirdNum; // 정답의 세번째 자리수

	while (1) {		
		randomNum = rand() % 900 + 100; // 랜덤한 3자리수 생성

		bool same = false; // 모든 수가 다를 경우 true를 갖는 변수

		// TODO 1: 3자리 숫자의 자릿수를 추출하고, 모든 수가 다른지 체크하는 코드블록 작성
		thirdNum = randomNum % 10;
		randomNum /= 10;
		secondNum = randomNum % 10;
		firstNum = randomNum / 10;
		same = checkNumber(firstNum, secondNum, thirdNum);

		if (same == true) {
			break;
		}
	}
	cout << firstNum << endl << secondNum << endl << thirdNum << endl;
	int turn = 0;
	while (1) {
		cout << turn + 1 << "번째 시도입니다. " << endl;

		int userNumber; // 사용자가 입력한 세자리수 저장 변수
		int guessFirst; // 추측한 숫자의 첫번째 자리수
		int guessSecond; // 추측한 숫자의 두번째 자리수
		int guessThird; // 추측한 숫자의 세번째 자리수


		// 사용자에게 세자리 수를 입력받는 코드 블록
		while (1) {
			cout << "세자리 수를 입력해주세요: ";
			cin >> userNumber;

			bool same = false; // 모든 수가 다를 경우 true를 갖는 변수
			// TODO 1: 3자리 숫자의 자릿수를 추출하고, 모든 수가 다른지 체크하는 코드블록 작성
			int number = userNumber;
			guessThird = number % 10;
			number /= 10;
			guessSecond = number % 10;
			guessFirst = number / 10;
			//자리수 확인 후 같은 숫자가 있으면 다시 반복
			same = checkNumber(guessFirst, guessSecond, guessThird);

			if (to_string(userNumber).length() != 3) {
				cout << "입력된 숫자가 3자리 수가 아닙니다. 다시 입력하세요." << endl;
				continue;
			}

			if (same == true) {
				break;
			}
		}


		int strike = 0; // 스트라이크 갯수를 저장하는 변수
		int ball = 0; // 볼 갯수를 저장하는 변수

		// TODO 2: 정답과 추측한 숫자의 자릿수와 숫자를 비교하며 힌트를 주기 위한 코드블록 작성
		//각 자리수가 추측한 수와 일치하면 strike 1증가
		if (firstNum == guessFirst)
			strike++;
		if (secondNum == guessSecond)
			strike++;
		if (thirdNum == guessThird)
			strike++;
		//각 자리수가 다른 두 자리수의 수와 일치하면 ball 1증가
		if (firstNum == guessSecond || firstNum == guessThird)
			ball++;
		if (secondNum == guessFirst || secondNum == guessThird)
			ball++;
		if(thirdNum == guessFirst || thirdNum == guessSecond)
			ball++;

		cout << userNumber << "의 결과 : " << strike << " 스트라이크, " << ball << "볼 입니다." << endl;
		
		if (strike == 3) {
			cout << "정답을 맞췄습니다. 축하합니다.";
			break;
		}

		turn += 1;
	}

	return 0;
}
