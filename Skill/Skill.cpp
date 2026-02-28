#include "Skill.h"

USkill::USkill(ACharacter* NewOwner, const std::string& NewName)
{
	Owner = NewOwner;
	Name = NewName;
}
