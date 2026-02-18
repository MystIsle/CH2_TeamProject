#include <Windows.h>
#include <iostream>

#include "BattleManager.h"
#include "Character/Character.h"
#include "Character/Monster.h"
#include "Character/Player.h"

using namespace std;

int main()
{
	ABattleManager* BattleManager = new ABattleManager();

	FUnitStat PlayerStat(200, 50, 30, 5, 10);
	FUnitStat MonsterStat(100, 30, 20, 3, 10);

	ACharacter* Player = new APlayer("용사", PlayerStat);
	ACharacter* Monster = new AMonster("몬스터", MonsterStat);

	cout << "===  데스매치 시작!  ===" << endl;

	BattleManager->WaitForPlayerInput();
	BattleManager->RunBattle(Player, Monster);
	BattleManager->WaitForPlayerInput();

	cout << "===  데스매치 종료!  ===" << endl;

	delete Player;
	delete Monster;
	delete BattleManager;

	return 0;
}
