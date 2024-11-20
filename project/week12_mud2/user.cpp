#include "user.h"
#include<iostream>
#include<string>

void User::DecreaseHP(int dec_hp){
    hp -= dec_hp;
};
void User::IncreaseHP(int inc_hp){
    hp += inc_hp;
};
int User::GetHP(){
    return hp;
};
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