#include "Monster.h"

#include <iostream>
#include <vector>

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
	vector<USkill*> UsableSkills;
	for (auto& skill : Skills)
	{
		if (skill->CanUse())
		{
			UsableSkills.push_back(skill.get());
		}
	}

	if (UsableSkills.empty())
	{
		cout << Name << "은(는) 아무 행동도 할 수 없습니다!" << endl;
		return;
	}

	int index = GetRandomInt(static_cast<int>(UsableSkills.size()));
	UsableSkills[index]->Play(Target);
}
