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