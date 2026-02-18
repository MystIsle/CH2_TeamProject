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
	ACharacter* Player = new APlayer("용사", FUnitStat(200, 50, 30, 5, 10));
	ACharacter* Monster = new AMonster("몬스터", FUnitStat(100, 30, 20, 3, 10));

	cout << "===  데스매치 시작!  ===" << endl;
	
	BattleManager->WaitForPlayerInput();
	BattleManager->RunBattle(Player, Monster);
	BattleManager-> WaitForPlayerInput();
	
	delete Player;
	delete Monster;
	delete BattleManager;
	
	return 0;
}
