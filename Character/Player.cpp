#include "Player.h"

#include <iostream>

APlayer::APlayer(const string& NewName, const FUnitStat& NewStat)
	: ACharacter(NewName, NewStat)
{
	Level = 1;
	Exp = 0;
}

FDamageResult APlayer::Attack(ACharacter* Target)
{
	FDamageResult result = ACharacter::Attack(Target);
	string AttackMessage = "이(가) 대검으로 공격합니다.";
	if (result.bCritical)
	{
		AttackMessage = "이(가) 대검으로 뚝배기를 깻습니다~! 아 아프겟다.. ㅠㅠ";
	}
	cout << Name << AttackMessage << "데미지: " << result.Damage << endl;
	cout << Target->GetName() << " HP: " << Target->GetHp() << endl;
	return result;
}

void APlayer::LevelUp()
{

}

void APlayer::UseItem()
{

}
