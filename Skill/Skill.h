#pragma once

#include <string>

class ACharacter;

//부모 클래스
class USkill
{
public:
	USkill(ACharacter* NewOwner, const std::string& NewName, int NewMpCost);
	virtual ~USkill() = default;

protected:
	ACharacter* Owner = nullptr;
	std::string Name;
	int MpCost;

public:
	const std::string& GetName() const { return Name; }
	int GetMpCost() const { return MpCost; }
	virtual void Play(ACharacter* Target) = 0;
};
