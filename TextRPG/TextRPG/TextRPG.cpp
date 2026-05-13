#include "Base.h";

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


int main()
{
    UI();
    Turn();
}
