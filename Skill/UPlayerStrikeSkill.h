#pragma once
#include "Skill.h"

class UPlayerStrikeSkill : public USkill
{
public:
    UPlayerStrikeSkill(ACharacter* NewOwner);

    void OnPlay(ACharacter* Target) override;
};
