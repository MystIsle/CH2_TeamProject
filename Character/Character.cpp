#include "Character.h"

#include <iostream>
#include <random>

using namespace std;

ACharacter::ACharacter(const string& NewName, const FUnitStat& UnitStat)
{
	Name = NewName;
	Stat = UnitStat;
	
	Stat.Hp = Stat.MaxHp;
	Stat.Mp = Stat.MaxMp;

	cout << "[생성] " << Name << "가 전장에 나타났습니다! (HP: " << Stat.Hp << ")" << endl;
}

ACharacter::~ACharacter()
{
	cout << "ACharacter 소멸됨" << endl;
}

FDamageResult ACharacter::Attack(ACharacter* Target)
{
	int Damage = Stat.Atk;
	bool bCritical = GetRandomInt() < Stat.Critical;
	if (bCritical)
	{
		Damage = static_cast<int>(Damage * 1.5f);
	}
	
	// - 크리티컬 계산 - 
	int FinalDamage = Target->TakeDamage(Damage);
	FDamageResult result;
	result.Damage = FinalDamage;
	result.bCritical = bCritical;
	return result;
}

int ACharacter::TakeDamage(int DamageAmount)
{
	DamageAmount = DamageAmount - Stat.Def;
	DamageAmount = std::max(DamageAmount, 0);
	
	Stat.Hp = Stat.Hp - DamageAmount;
	Stat.Hp = std::max(Stat.Hp, 0);
	return DamageAmount; 
}

int ACharacter::GetRandomInt()
{
	static std::random_device rd;
	static std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dis(0, 100);
	return dis(gen);
}
