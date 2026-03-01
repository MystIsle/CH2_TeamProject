#include "Skill.h"
#include "../Character/Character.h"

USkill::USkill(ACharacter* NewOwner, const std::string& NewName, int NewMpCost)
{
	Owner = NewOwner;
	Name = NewName;
	MpCost = NewMpCost;
}

bool USkill::CanUse() const
{
	return Owner->HasEnoughMp(MpCost);
}

void USkill::Play(ACharacter* Target)
{
	Owner->ConsumeMp(MpCost);
	OnPlay(Target);
}
