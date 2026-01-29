#pragma once

#include <string>

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
};

class ACharacter
{
public:
	ACharacter(const string& NewName, const FUnitStat& UnitStat);
	virtual ~ACharacter();

protected:
	string Name;
	FUnitStat Stat;

public:
	const string& GetName() { return Name; }
	int GetHp() const { return Stat.Hp; }
	bool IsDead() const { return Stat.Hp <= 0; }
	
	virtual FDamageResult Attack(ACharacter* Target);
	int TakeDamage(int DamageAmount);
	
private:
	int GetRandomInt();
};
