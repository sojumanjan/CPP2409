#include<iostream>
#include<string>

using namespace std;

class User{
private:
    int hp;
public:
    int itemCnt;
    void DecreaseHP(int dec_hp);
    void IncreaseHP(int inc_hp);
    int GetHP();
	// 유저의 위치를 저장할 변수
	int user_x = 0; // 가로 번호
	int user_y = 0; // 세로 번호
    virtual void DoAttack();
    User();
};

class Warrior : public User{
public:
    void DoAttack();
};
class Magician : public User{
public:
    void DoAttack();
};