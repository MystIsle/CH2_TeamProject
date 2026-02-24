#pragma once

class ACharacter;

//부모 클래스
class USkill
{
public:
	USkill(ACharacter* NewOwner);

protected:
	ACharacter* Owner = nullptr;

public:
	virtual void Play(ACharacter* Target) = 0;
};
