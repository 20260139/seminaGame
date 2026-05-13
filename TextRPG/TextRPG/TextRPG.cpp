#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>

int hp;
int damage;
int defend;
int speed;
bool battling = false;

void UI()
{
    printf("체력: %d", hp);
    printf("        공격력: %d", damage);
    printf("        수비력: %d", defend);
    printf("        속도: %d\n\n", speed);
}

void EnemyStateView(int* EHp, int* EDamage, int* EDefend, int* ESpeed)
{
    //system("cls");
    UI();
    printf("적 스탯: ");
    printf("체력: %d", *EHp);
    printf("        공격력: %d", *EDamage);
    printf("        수비력: %d", *EDefend);
    printf("        속도: %d\n\n", *ESpeed);
}

void EnemyState(int hpDown = 0)
{
    int hp;
    int damage;
    int defend;
    int speed;

    if (!battling)
    {
        hp = rand() % 100;
        damage = rand() % 10;
        defend = rand() % 10;
        speed = rand() % 10;
    }

    battling = true;
    hp -= hpDown;

    EnemyStateView(&hp, &damage, &defend, &speed);
}

void HPDown(int damage)
{
    EnemyState(damage);
}

void EnemyMeet()
{
    Sleep(2000);
    //system("cls");
    UI();
    EnemyState();
}

void Turn()
{
    printf("턴 시작\n\n");
    Sleep(2000);
    srand(time(NULL));
    int value = rand() % 3;

    switch (value)
    {
    case 1:
        printf("적 조우\n");
        EnemyMeet();
        break;
    case 2:
        printf("휴식\n");

        break;
    case 3:
        printf("레벨업\n");

        break;
    }
}

int main()
{
    UI();
    Turn();
    Sleep(2000);
    HPDown(3);
}
