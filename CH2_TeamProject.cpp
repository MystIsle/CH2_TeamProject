#include <Windows.h>
#include <iostream>

#include "Character/Character.h"
#include "Character/Monster.h"
#include "Character/Player.h"

using namespace std;

void WaitForPlayerInput()
{
	system("pause");
	cout << endl;
}

bool BattleTurn(ACharacter* Attacker, ACharacter* Defender)
{
	cout << "[System] " << Attacker->GetName() << "의 턴입니다...!\n";
	Attacker->PlayTurn(Defender);
	Attacker->ShowStat();
	Defender->ShowStat();
	
	WaitForPlayerInput();
	if (Defender->IsDead())
	{
		cout << "[System] " << Defender->GetName() << " 사망... ㅠㅠ. 꿱"; 
	}

	return Defender->IsDead();
}

int main()
{
	ACharacter* Player = new APlayer("용사", FUnitStat(200, 50, 30, 5, 10));
	ACharacter* Monster = new AMonster("몬스터", FUnitStat(100, 30, 20, 3, 10));

	cout << "===  데스매치 시작!  ===" << endl;
	WaitForPlayerInput();

	while (!Player->IsDead() && !Monster->IsDead())
	{
		// 1. 플레이어의 턴 (게임 끝났으면 break)
		if (BattleTurn(Player, Monster) == true)
		{
			break;
		}

		// 2. 몬스터의 턴 (게임 끝났으면 break)
		if (BattleTurn(Monster, Player) == true)
		{
			break;
		}
	}

	delete Player;
	delete Monster;

	WaitForPlayerInput();
	return 0;
}
