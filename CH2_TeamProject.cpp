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

int main()
{
    ACharacter* Player = new APlayer("용사", FUnitStat(200, 50, 30, 5, 10));
    ACharacter* Monster = new AMonster("몬스터", FUnitStat(100, 30, 20, 3, 10));

    cout << "===  데스매치 시작!  ===" << endl;
    WaitForPlayerInput();
    
    while (!Player->IsDead() && !Monster->IsDead()) 
    {
        // [ 플레이어 턴 ] 시작 ---
        
        // DoAction()의 기능?
        // 이번턴에 어떤행동을 할지 결정해서, 실행한다.
        
        
        //플레이어 공격 
        Player->UseSkill(Monster);
        
        //몬스터 죽었는지 체크: 죽으면 빠져나옴
        if (Monster->IsDead())
        {
            cout << "몬스터가 쓰러졌습니다! 승리!" << endl;
            break;
        }
        WaitForPlayerInput();
        // --- [ 플레이어 턴 ] 종료
        
        // [ 몬스터 턴 ] 시작 ---
        //몬스터 공격 
        Monster->UseSkill(Player);
        
        //플레이어 죽었는지 체크: 죽으면 빠져나옴
        if (Player->IsDead())
        {
            cout << "플레이어가 쓰러졌습니다... 패배..." << endl;
            break;
        }
        WaitForPlayerInput();
        // --- [ 몬스터 턴 ] 종료
    }

    delete Player;
    delete Monster;
    
    WaitForPlayerInput();
    return 0;
}