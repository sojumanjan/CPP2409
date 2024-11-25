#include<iostream>

using namespace std;

class RemoteControl {
public:
    virtual void TurnOn() = 0;
    virtual void TurnOff() = 0;
};

class Television : public RemoteControl {
    void TurnOn() override {
        cout << "텔레비전을 킵니다." << endl;
    }
    void TurnOff() override {
        cout << "텔레비전을 끕니다." << endl;
    }
};

class Refrigerator : public RemoteControl {
    void TurnOn() override {
        cout << "냉장고를 킵니다." << endl;
    }
    void TurnOff() override {
        cout << "냉장고를 끕니다." << endl;
    }
};

int main(){
    // Tv를 켜고 끄는 동작을 인터페이스를 통해 수행
    RemoteControl *remoteTV = new Television();
    remoteTV->TurnOff();
    remoteTV->TurnOn();

    RemoteControl *remoteRefrigerator = new Refrigerator();
    remoteRefrigerator -> TurnOff();
    remoteRefrigerator -> TurnOn();
    delete remoteRefrigerator, remoteTV;
}