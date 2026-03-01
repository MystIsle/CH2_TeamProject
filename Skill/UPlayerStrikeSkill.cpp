#include "UPlayerStrikeSkill.h"
#include "../Character/Character.h"

UPlayerStrikeSkill::UPlayerStrikeSkill(ACharacter* NewOwner)
    : USkill(NewOwner, "회심의 일격", 20)
{
}

void UPlayerStrikeSkill::Play(ACharacter* Target)
{
    FDamageResult result;
    result.Attacker = Owner;
    result.Target = Target;
    result.bCritical = false;
	
    int FinalDamage = Target->TakeDamage(Owner->GetAtk() * 2);
    result.Damage = FinalDamage;
	
    result.PrintMessage("-필살기- 회심의 일격...!");
}
