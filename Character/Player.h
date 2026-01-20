#pragma once
#include "Character.h"

class APlayer : public ACharacter
{
public:
	APlayer();
	
protected:
	int Level;
	int Exp;
	
public:
	void SetName(string Name);
	void LevelUp();
	void UseItem();
	void WinBattle();
};
