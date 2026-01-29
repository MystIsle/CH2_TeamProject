#include <Windows.h>
#include <iostream>

#include "Character/Character.h"
#include "Character/Monster.h"
#include "Character/Player.h"

using namespace std;

int main()
{
    ACharacter* Player = new APlayer("용사", FUnitStat(200, 50, 30, 5, 10));
    ACharacter* Monster = new AMonster("몬스터", FUnitStat(100, 30, 20, 3, 10));

    cout << "===  데스매치 시작!  ===" << endl;
    Sleep(1000);
    
    while (!Player->IsDead() && !Monster->IsDead()) 
    {
        Player->Attack(Monster);
        
        if (Monster->IsDead())
        {
            cout << "몬스터가 쓰러졌습니다! 승리!" << endl;
            break;
        }
        
        Sleep(500);
        Monster->Attack(Player);
        if (Player->IsDead())
        {
            cout << "플레이어가 쓰러졌습니다... 패배..." << endl;
            break;
        }

        Sleep(1000);
    }

    delete Player;
    delete Monster;
    
    return 0;
}