#include "UMonsterAttackSkill.h"

#include "../Character/Character.h"

UMonsterAttackSkill::UMonsterAttackSkill(ACharacter* NewOwner)
    : USkill(NewOwner)
{
    
}

void UMonsterAttackSkill::Play(ACharacter* Target)
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
	
    string AttackMessage = "크아앙! 이빨로 물어뜯습니다!";
    if (result.bCritical)
    {
        AttackMessage = "크앙!!! 약점부위를 앙하고~! 아프게 이빨로 물어뜯습니다!";
    }
	
    result.PrintMessage(AttackMessage);
}
