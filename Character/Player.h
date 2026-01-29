#pragma once
#include "Character.h"

class APlayer : public ACharacter
{
public:
	APlayer(const string& NewName, const FUnitStat& NewStat);
	
protected:
	int Level;
	int Exp;
	
public:
	FDamageResult Attack(ACharacter* Target) override;
	
	void LevelUp();
	void UseItem();
};
