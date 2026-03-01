#pragma once

#include "Skill.h"

//1. 부모 클래스 상속 받았음.
//2. 생성자 만들고, 부모클래스 초기화(생성자호출) 하기
//3. 순수 가상함수 상속 : Play() 오버라이드

//자식 클래스 : 플레이어 일반공격
class UPlayerAttackSkill : public USkill
{
public:
    UPlayerAttackSkill(ACharacter* NewOwner);
    
    void OnPlay(ACharacter* Target) override;
};
