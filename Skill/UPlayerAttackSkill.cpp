#include "UPlayerAttackSkill.h"
#include "../Character/Character.h"
#include <string>

UPlayerAttackSkill::UPlayerAttackSkill(ACharacter* NewOwner)
    : USkill(NewOwner)
{
    
}

void UPlayerAttackSkill::Play(ACharacter* Target)
{
    int Damage = Owner->GetAtk();

    // - 크리티컬 계산 - 
    bool bCritical = Owner->GetRandomInt() < Owner->GetCritical();
    if (bCritical)
    {
        Damage = static_cast<int>(Damage * 1.5f);
    }

    int FinalDamage = Target->TakeDamage(Damage);
    FDamageResult result;
    result.Attacker = Owner;
    result.Target = Target;
    result.Damage = FinalDamage;
    result.bCritical = bCritical;
    
    std::string AttackMessage = "대검으로 공격합니다.";
    if (result.bCritical)
    {
        AttackMessage = "대검으로 뚝배기를 깻습니다~! 아 아프겟다.. ㅠㅠ";
    }
	
    result.PrintMessage(AttackMessage);
}
