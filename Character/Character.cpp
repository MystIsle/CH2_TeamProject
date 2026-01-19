// 파일명: Character.cpp
#include "Character.h"

// ---------------------------------------------------------
// [Mission 4] 생성자에서 기본값 설정하기
// ---------------------------------------------------------
ACharacter::ACharacter()
{
    Name = "Unknown";
    Hp = 100;
    Atk = 10;

    cout << "ACharacter 생성됨: " << Name << " (HP: " << Hp << ")" << endl;
}

ACharacter::ACharacter(string NewName, int NewHp, int NewAtk)
{
    Name = NewName;
    Hp = NewHp;
    Atk = NewAtk;
    
    cout << "[생성] " << Name << "가 전장에 나타났습니다! (HP: " << Hp << ")" << endl;
}

ACharacter::~ACharacter()
{
    cout << "ACharacter 소멸됨" << endl;
}

void ACharacter::Attack()
{
    cout << Name << "가 공격합니다!" << Atk << endl;
}

void ACharacter::TakeDamage(int DamageAmount)
{
    Hp -= DamageAmount;

    cout << Name << "가 " << DamageAmount << "의 피해를 입었습니다." << endl;
}