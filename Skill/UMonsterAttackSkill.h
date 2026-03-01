#pragma once

#include "Skill.h"

class UMonsterAttackSkill : public USkill
{
public:
    UMonsterAttackSkill(ACharacter* NewOwner);
    
    void OnPlay(ACharacter* Target) override;
};
