#include "Monster.h"

#include <iostream>


AMonster::AMonster(const string& NewName, const FUnitStat& NewStat)
	: ACharacter(NewName, NewStat)
{

}

FDamageResult AMonster::Attack(ACharacter* Target)
{
	FDamageResult result = ACharacter::Attack(Target);
	string AttackMessage = "이(가) 이빨로 물어뜯습니다!";
	if (result.bCritical)
	{
		AttackMessage = "이(가) 약점부위를 앙하고~! 아프게 이빨로 물어뜯습니다!";
	}

	cout << "크아앙! " << Name << AttackMessage << "데미지: " << result.Damage << endl;
	cout << Target->GetName() << " HP: " << Target->GetHp() << endl;
	return result;
}
