#pragma once

#include <string>
#include <vector>
#include <memory>

class ACharacter;
class USkill;
using namespace std;

struct FUnitStat
{
	int MaxHp;
	int MaxMp;
	int Atk;
	int Def;
	int Critical;
	
	int Hp = 0;
	int Mp = 0;
	
	FUnitStat()
	{
	}
	
	FUnitStat(int MaxHp, int MaxMp, int Atk, int Def, int Critical)
	{
		this->MaxHp = MaxHp;
		this->MaxMp = MaxMp;
		
		this->Atk = Atk;
		this->Def = Def;
		this->Critical = Critical;
	}
};

//데이터 덩어리 - 묶음
// 최종 데미지, 크리티컬 여부 묶어서 전달할거야~ 
struct FDamageResult
{
	int Damage;
	bool bCritical;
	
	ACharacter* Attacker;
	ACharacter* Target;
	
	void PrintMessage(const string& AttackMessage);
};

class ACharacter
{
public:
	ACharacter(const string& NewName, const FUnitStat& UnitStat);
	virtual ~ACharacter();

protected:
	string Name;
	FUnitStat Stat;
	vector<unique_ptr<USkill>> Skills;

public:
	const string& GetName() { return Name; }
	int GetHp() const { return Stat.Hp; }
	int GetMaxHp() const { return Stat.MaxHp; }
	int GetAtk() const { return Stat.Atk; }
	int GetCritical() const { return Stat.Critical; }
	bool IsDead() const { return Stat.Hp <= 0; }
	
	virtual FDamageResult Attack(ACharacter* Target);
	virtual void UseSkill(ACharacter* Target) = 0;
	
	int TakeDamage(int DamageAmount);
	void Heal(int amount);
	void PrintName();
	void ShowStat();
	void PlayTurn(ACharacter* Target);
	int GetRandomInt();
};
