#include "Monster.h"

#include <iostream>

#include "../Skill/UMonsterAttackSkill.h"
#include "../Skill/UMonsterDrainSkill.h"


AMonster::AMonster(const string& NewName, const FUnitStat& NewStat)
	: ACharacter(NewName, NewStat)
{
	Skills.push_back(make_unique<UMonsterAttackSkill>(this));
	Skills.push_back(make_unique<UMonsterDrainSkill>(this));
}

void AMonster::PlayTurn(ACharacter* Target)
{
	int index = GetRandomInt(static_cast<int>(Skills.size()));
	Skills[index]->Play(Target);
}
