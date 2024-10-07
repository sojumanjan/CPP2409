#include<iostream>

using namespace std;

int main(){
    const int numCell = 3;
    char board[numCell][numCell]{};
    int x, y;
    char winner = ' '; //승리한 유저 변수s
    //보드 초기화
    for (x = 0; x < numCell; x++){
        for (y = 0; y < numCell; y++){
            board[x][y] = ' ';
        }
    }

    int k = 0;
    char currentUser = 'X';
     //유저 차례 출력
    while(winner == ' '){ //승자가 생길 때 while문 탈출
        switch(k % 2){ //몇 라운드인지에 따라 차례 바꾸기 
            case 0:{   //한 차례마다 k가 1씩 증가 -> 나머지가 0, 1 반복됨
                cout << "첫 번째 유저(X)의 차례입니다. -> ";
                currentUser = 'X';
                break;
            }
            case 1:{
                cout << "두 번째 유저(O)의 차례입니다. -> ";
                currentUser = 'O';
                break;
            }
        }
        //좌표 입력
        cout << "(x, y) 좌표를 입력하세요 : ";
        cin >> x >> y;
        //좌표 유효성 검사
        if (x >= numCell || y >= numCell){
            cout << x << ", " << y << ": ";
            cout << "x와 y 둘 중 하나가 칸을 벗어났습니다." << endl;
            continue;
        }
        if (board[x][y] != ' '){
            cout << "(" << x << ", " << y << ")에 이미 돌이 차있습니다." << endl;
            continue;
        }
        board[x][y] = currentUser;

        //현재 보드 판 출력
        for (int i = 0; i < numCell ; i++){ //몇 행 출력하는지 (3번 반복)
            cout << "---|---|---" << endl;
            for (int j = 0; j < numCell; j++){ //몇 열 출력하는지 (3번 반복)
                cout << " ";
                cout << board[i][j];
                if (j == numCell - 1){ //마지막 열이라면 오른쪽 벽 출력 X
                    break;
                }
                cout << " |";
            }
            cout << endl;
        }
        cout << "---|---|---" << endl;
        k++;
        //빙고 검사
        if (k >= (2 * numCell) - 1){ //한 유저가 돌 3개 이상을 놓았을 시 빙고 검사
            //행,열 승리 검사
            for (int i = 0; i < numCell; i++){
                int rCountO = 0; //한 행에 같은 모양 개수 검사
                int rCountX = 0;
                int cCountO = 0; //한 열에 같은 모양 개수 검사
                int cCountX = 0;
                for (int j = 0; j < numCell; j++){
                    if (board[i][j] == 'X') //행 카운트를 위한 if문
                        rCountX++;
                    else if (board[i][j] == 'O')
                        rCountO++;
                    if (board[j][i] == 'X') //열 카운트를 위한 if문
                        cCountX++;
                    else if (board[j][i] == 'O')
                        cCountO++;
                }
                //한 행과 열에 O,X가 3개일 경우 검사
                if (rCountO == numCell){ //한 행에 O가 3개일 경우
                    winner = 'O';
                    cout << "가로로 3개가 놓였습니다. " << winner <<"의 승리입니다."<< endl;
                    break;
                }
                else if (rCountX == numCell){//한 행에 X가 3개일 경우
                    winner = 'X';
                    cout << "가로로 3개가 놓였습니다. " << winner <<"의 승리입니다."<< endl;
                    break;
                }
                else if (cCountO == numCell){//한 열에 O가 3개일 경우
                    winner = 'O';
                    cout << "세로로 3개가 놓였습니다. " << winner <<"의 승리입니다."<< endl;
                    break;
                }
                else if (cCountX == numCell){//한 열에 X가 3개일 경우
                    winner = 'X';
                    cout << "세로로 3개가 놓였습니다. " << winner <<"의 승리입니다."<< endl;
                    break;
                }
                else { //둘 다 아니면 count변수 초기화 후 다음 행, 열로 이동
                    rCountO = 0;
                    rCountX = 0;
                    cCountO = 0;
                    cCountX = 0;
                }
            }
            //대각 승리 검사
            int countX = 0; //대각 X카운트
            int countO = 0; //대각 O카운트
            //왼 -> 오 대각 빙고 검사
            for (int i = 0; i < numCell; i++){
                if (board[i][i] == 'X')
                    countX++;
                else if (board[i][i] == 'O')
                    countO++;
            }
            
            if (countX == numCell || countO == numCell){
                if (countX == numCell) //대각에 X가 3개면 X승리
                winner = 'X';
                else if (countO == 3) //대각에 O가 3개면 Y승리
                winner = 'O';
                cout << "왼쪽에서 오른쪽 아래 대각선으로 " << winner <<"돌이 놓였습니다. " << winner <<"유저의 승리입니다." << endl;
            }
                
            //오 -> 왼 대각 빙고 검사
            countX = 0;
            countO = 0;
            for (int i = 0; i < numCell; i++){
                if (board[i][numCell - i - 1] == 'X')
                    countX++;
                else if (board[i][numCell - i - 1] == 'O')
                    countO++;
            }
            
            if (countX == numCell || countO == numCell){
                if (countX == numCell) //대각에 X가 3개면 X승리
                    winner = 'X';
                else if (countO == numCell) //대각에 O가 3개면 Y승리
                    winner = 'Y';
                cout << "오른쪽에서 왼쪽 아래 대각선으로 " << winner <<"돌이 놓였습니다. " << winner <<"유저의 승리입니다." << endl;
            }
                
        }
        if (k == numCell * numCell){
            cout << "판이 꽉 찼으나 승자가 없습니다. 무승부입니다." << endl;
            winner = 'A';
        }
    }
    return 0;
}