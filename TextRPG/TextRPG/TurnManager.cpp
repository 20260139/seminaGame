#include "Base.h"

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