#include "Monster.h"

#include <iostream>


AMonster::AMonster(const string& NewName, const FUnitStat& NewStat)
	: ACharacter(NewName, NewStat)
{

}

FDamageResult AMonster::Attack(ACharacter* Target)
{
	FDamageResult result = ACharacter::Attack(Target);
	
	string AttackMessage = "크아앙! 이빨로 물어뜯습니다!";
	if (result.bCritical)
	{
		AttackMessage = "크앙!!! 약점부위를 앙하고~! 아프게 이빨로 물어뜯습니다!";
	}
	
	result.PrintMessage(AttackMessage);
	return result;
}

void AMonster::UseSkill(ACharacter* Target)
{
	FDamageResult result;
	result.Attacker = this;
	result.Target = Target;
	result.bCritical = false;

	int FinalDamage = Target->TakeDamage(Stat.Atk * 2);
	result.Damage = FinalDamage;
	
	result.PrintMessage("-필살기- 피를 빨아 회복합니다...!");
}
