#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>

int hp;
int damage;
int defend;
int speed;

void UI()
{
    printf("체력: %d", hp);
    printf("        공격력: %d", damage);
    printf("        수비력: %d", defend);
    printf("        속도: %d\n\n", speed);
}

void EnemyState()
{
    int hp = rand() % 100;
    int damage = rand() % 10;
    int defend = rand() % 10;
    int speed = rand() % 10;

    printf("적 스탯: ");
    printf("체력: %d", hp);
    printf("        공격력: %d", damage);
    printf("        수비력: %d", defend);
    printf("        속도: %d\n\n", speed);
}

void EnemyMeet()
{
    Sleep(2000);
    system("cls");
    UI();
    EnemyState();
}

void Turn()
{
    printf("턴 시작\n\n");
    Sleep(2000);
    srand(time(NULL));
    int value = rand() % 4;

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
}
