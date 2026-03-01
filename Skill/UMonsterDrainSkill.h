#pragma once
#include "Skill.h"

class UMonsterDrainSkill : public USkill
{
public:
    UMonsterDrainSkill(ACharacter* NewOwner);
    
    void OnPlay(ACharacter* Target) override;
};
