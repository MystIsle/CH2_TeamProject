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
	void PlayTurn(ACharacter* Target) override;
	
	void LevelUp();
	void UseItem();
};
