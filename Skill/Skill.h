#pragma once

#include <string>

class ACharacter;

//부모 클래스
class USkill
{
public:
	USkill(ACharacter* NewOwner, const std::string& NewName);
	virtual ~USkill() = default;

protected:
	ACharacter* Owner = nullptr;
	std::string Name;

public:
	const std::string& GetName() const { return Name; }
	virtual void Play(ACharacter* Target) = 0;
};
