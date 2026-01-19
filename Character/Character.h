// 파일명: Character.h
#pragma once
#include <iostream>
#include <string>

using namespace std;

class ACharacter
{
public:
    ACharacter();
    ACharacter(string NewName, int NewHp, int NewAtk);
    ~ACharacter();
    
protected:
    string Name;
    int Hp;
    int Atk;

public:
    int GetHp() { return Hp; }
    bool IsDead() { return Hp <= 0; }
    
    void Attack(ACharacter* Target);
    void TakeDamage(int DamageAmount);
};