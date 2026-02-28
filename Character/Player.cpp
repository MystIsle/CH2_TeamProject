#include "Player.h"

#include <iostream>

#include "../Skill/UPlayerAttackSkill.h"
#include "../Skill/UPlayerStrikeSkill.h"

APlayer::APlayer(const string& NewName, const FUnitStat& NewStat)
	: ACharacter(NewName, NewStat)
{
	Level = 1;
	Exp = 0;

	Skills.push_back(make_unique<UPlayerAttackSkill>(this));
	Skills.push_back(make_unique<UPlayerStrikeSkill>(this));
}

FDamageResult APlayer::Attack(ACharacter* Target)
{
	FDamageResult result = ACharacter::Attack(Target);
	string AttackMessage = "대검으로 공격합니다.";
	if (result.bCritical)
	{
		AttackMessage = "대검으로 뚝배기를 깻습니다~! 아 아프겟다.. ㅠㅠ";
	}
	
	result.PrintMessage(AttackMessage);
	return result;
}

void APlayer::UseSkill(ACharacter* Target)
{
	FDamageResult result;
	result.Attacker = this;
	result.Target = Target;
	result.bCritical = false;
	
	int FinalDamage = Target->TakeDamage(Stat.Atk * 2);
	result.Damage = FinalDamage;
	
	result.PrintMessage("-필살기- 회심의 일격...!");
}

void APlayer::LevelUp()
{
	
}

void APlayer::UseItem()
{
	
}
