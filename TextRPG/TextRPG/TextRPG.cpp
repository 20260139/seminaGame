#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>

int maxHp;
int hp;
int maxDefend;
int damage;
int defend;
float speed;
float maxSpeed;
int level = 1;
float exp;
bool battling = false;
bool bossBattle = false;
bool playerTurn = false;
bool boss2page = false;


int Ehp;
int Edamage;
int Edefend;
int Espeed;

void UI();
void EnemyStateView();
void EnemyState(int hpDown = 0);
void HpDown(int damage);
void EHPDown(int damage);
void EnemyMeet();
void Turn();
void SpeedCheck();
void PlayerTurnStart();
void PlayerAttack();
void PlayerDefend();
void Run();
void EnemyTurn();
void EndCheck();
void LevelUp();
void EventCheck();
void Rest();
void Boss();

int main()
{
    srand(time(NULL));
    hp = rand() % 100 + 1;
    damage = rand() % 10;
    defend = rand() % 10;
    speed = rand() % 10 + 1;
    maxHp = hp;
    maxDefend = defend;
    maxSpeed = speed;
    UI();
    Turn();
}

void Boss()
{
    bossBattle = true;
    battling = true;
    Ehp = 100;
    Edamage = 55;
    Edefend = 30;
    Espeed = 40;

    EnemyStateView();
    SpeedCheck();
}

void Rest()
{
    hp += maxHp * 0.3;

    if (hp >= maxHp)
    {
        hp = maxHp;
    }

    Sleep(1000);
    system("cls");
    UI();
    EventCheck();
}

void EventCheck()
{
    if (bossBattle)
    {
        system("cls");
        printf("Game Clear\n\n");
        exit(0);
    }

    if (exp >= 5)
    {
        LevelUp();
    }
    else
    {
        if (level >= 10)
        {
            printf("보스전에 진입합니다\n\n");
            Sleep(1000);
            Boss();
            return;
        }

        Turn();
    }
}

void LevelUp()
{
    level++;
    damage += 5;
    defend += 5;
    maxDefend = defend;
    speed += 3;
    maxSpeed = speed;
    exp = 0;
    Sleep(1000);
    system("cls");
    UI();
    EventCheck();
}

void EndCheck()
{
    defend = maxDefend;
    speed += 0.5;
    system("cls");
    EnemyStateView();

    if (hp <= 0)
    {
        system("cls");
        printf("Game Over\n");
        exit(0);
    }
    else if (Ehp <= 0)
    {
        system("cls");
        printf("Clear\n");
        battling = false;
        exp++;
        speed = maxSpeed;
        EventCheck();
    }

    if (playerTurn)
    {
        PlayerTurnStart();
    }
    else
    {
        EnemyTurn();
    }
}

void Run()
{
    if (speed >= Espeed)
    {
        system("cls");
        UI();
        printf("도주하는데 성공하였습니다\n");
        speed = maxSpeed;
        battling = false;
        EventCheck();
    }
    else
    {
        printf("도주에 실패하였습니다\n");
        Sleep(1000);
        EnemyTurn();
    }
}

void PlayerDefend()
{
    printf("방어력이 증가합니다");
    defend *= 2;
    Sleep(1000);
    system("cls");
    EnemyStateView();
    EnemyTurn();
}

void PlayerAttack()
{
    EHPDown(damage);
    EndCheck();
}

void PlayerTurnStart()
{
    playerTurn = false;
    printf("1. 공격 ");
    printf("        2. 수비");
    printf("        3. 도망\n");
    int value = 0;

    scanf_s("%d", &value);

    switch (value)
    {
    case 1:
        PlayerAttack();
        break;
    case 2:
        PlayerDefend();
        break;
    case 3:
        Run();
        break;
    default:
        printf("잘못된 입력입니다\n");
        PlayerTurnStart();
    }

    EndCheck();
}

void EnemyTurn()
{
    Sleep(1000);
    printf("적 공격\n");
    Sleep(1000);
    HpDown(Edamage);
    playerTurn = true;
    EndCheck();
}

void UI()
{
    printf("레벨: %d", level);
    printf("        체력: %d", hp);
    printf("        공격력: %d", damage);
    printf("        수비력: %d", defend);
    printf("        속도: %.1f\n\n", speed);
}

void SpeedCheck()
{
    Sleep(1000);
    if (speed >= Espeed)
    {
        playerTurn = true;
        printf("플레이어 턴 시작\n");
        Sleep(2000);
        PlayerTurnStart();
    }
    else
    {
        playerTurn = false;
        printf("적 턴 시작\n");
        Sleep(2000);
        EnemyTurn();
    }
}

void EnemyStateView()
{
    system("cls");
    UI();
    printf("적 스탯: ");
    printf("체력: %d", Ehp);
    printf("        공격력: %d", Edamage);
    printf("        수비력: %d", Edefend);
    printf("        속도: %d\n\n", Espeed);
}

void EnemyState(int hpDown)
{
    if (!battling)
    {
        Ehp = rand() % 100 + 1;
        Edamage = rand() % 10 + (level * 3);
        Edefend = rand() % 10 + (level * 3);
        Espeed = rand() % 10 + (level * 3);
    }

    int value = hpDown - Edefend;
    if (value <= 0)
    {
        value = 1;
    }

    battling = true;
    Ehp -= value;

    EnemyStateView();
}

void EHPDown(int damage)
{
    EnemyState(damage);
}

void HpDown(int damage)
{
    int value = damage - defend;
    if (value <= 0)
    {
        value = 0;
    }
    hp -= value;

    if (bossBattle && Ehp <= Ehp / 2 && !boss2page)
    {
        printf("보스가 분노합니다\n\n");
        Edamage *= 1.5;
        Edefend *= 1.5;
        boss2page = true;
        Sleep(1000);
    }
    system("cls");
    EnemyStateView();
}

void EnemyMeet()
{
    Sleep(2000);
    system("cls");
    EnemyState();
    Sleep(2000);
    SpeedCheck();
}

void Turn()
{
    printf("턴 시작\n\n");
    Sleep(2000);
    srand(time(NULL));
    int value = rand() % 3 + 1;

    switch (value)
    {
    case 1:
        printf("적 조우\n\n");
        EnemyMeet();
        break;
    case 2:
        printf("휴식\n\n");
        Rest();
        break;
    case 3:
        printf("레벨업\n\n");
        LevelUp();
        break;
    }
}

