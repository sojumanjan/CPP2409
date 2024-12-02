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
    virtual void DoAttack() = 0;
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
void User::DecreaseHP(int dec_hp){
    hp -= dec_hp;
};
void User::IncreaseHP(int inc_hp){
    hp += inc_hp;
};
int User::GetHP(){
    return hp;
};
void doAttack(){
    cout << "공격합니다." << endl;
}
User::User(){
    hp = 20;
    itemCnt = 0;
}
void User::DoAttack(){
    cout << "공격합니다." << endl;
}
void Warrior::DoAttack(){
    cout << "칼로 물리 공격을 합니다." << endl;
}
void Magician::DoAttack(){
    cout << "지팡이로 마법 공격을 합니다." << endl;
}