#include "Character.h"
#include "../Skill/Skill.h"

#include <iostream>
#include <random>

using namespace std;

void FDamageResult::PrintMessage(const string& AttackMessage)
{
	cout << "-------------------------------------------------" << endl;
	Attacker->PrintName();
	cout << AttackMessage << '\n';
	
	Target->PrintName();
	cout << "'받은 데미지': " << Damage << "-> '남은 HP': " << Target->GetHp() << "/" << Target->GetMaxHp() << endl;
	cout << "-------------------------------------------------" << endl;
}

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

	// - 크리티컬 계산 - 
	bool bCritical = GetRandomInt() < Stat.Critical;
	if (bCritical)
	{
		Damage = static_cast<int>(Damage * 1.5f);
	}

	int FinalDamage = Target->TakeDamage(Damage);
	FDamageResult result;
	result.Attacker = this;
	result.Target = Target;
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

void ACharacter::Heal(int amount)
{
	int PrevHp = Stat.Hp;
	Stat.Hp += amount;
	Stat.Hp = std::min(Stat.MaxHp, Stat.Hp);

	int ActualHeal = Stat.Hp - PrevHp;

	PrintName();
	cout << ActualHeal << " HP를 회복했습니다...!" << endl;
}

int ACharacter::GetRandomInt()
{
	static std::random_device rd;
	static std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dis(0, 100);
	return dis(gen);
}

void ACharacter::PrintName()
{
	cout << "[" << Name << "] ";
}

void ACharacter::ShowStat()
{
	cout << "[System] ";
	PrintName();
	
	cout << " HP: " << Stat.Hp << " / " << Stat.MaxMp <<  " MP: " << Stat.Mp << " / " << Stat.MaxMp << endl;
}

void ACharacter::PlayTurn(ACharacter* Target)
{
	if (GetRandomInt() < 50)
	{
		Attack(Target);
	}
	else
	{
		UseSkill(Target);
	}
}
