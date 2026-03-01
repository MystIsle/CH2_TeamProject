#include "Skill.h"

USkill::USkill(ACharacter* NewOwner, const std::string& NewName, int NewMpCost)
{
	Owner = NewOwner;
	Name = NewName;
	MpCost = NewMpCost;
}
