#include "UMonsterDrainSkill.h"

#include "../Character/Character.h"

UMonsterDrainSkill::UMonsterDrainSkill(ACharacter* NewOwner)
    :USkill(NewOwner)
{
}

void UMonsterDrainSkill::Play(ACharacter* Target)
{
    FDamageResult result;
    result.Attacker = Owner;
    result.Target = Target;
    result.bCritical = false;

    int FinalDamage = Target->TakeDamage(Owner->GetAtk());
    result.Damage = FinalDamage;
	
    result.PrintMessage("-필살기- 피를 빨아 회복합니다...!");
}
