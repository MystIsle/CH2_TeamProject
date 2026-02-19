#pragma once

class ACharacter;

class USkill
{
public:
	USkill(ACharacter* NewOwner);

protected:
	ACharacter* Owner = nullptr;

public:
	virtual void Play(ACharacter* Target) = 0;
};
