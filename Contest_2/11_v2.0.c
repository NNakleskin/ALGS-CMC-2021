#include "stdio.h"
#include "stdlib.h"

int convert(char x) // Переводим буквенные координаты в числовые
{
    char a[8] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
    for(int i = 0; i < 8; i++)
    {
        if(x == a[i]){
            return i;
        }
    }
    return 0;
}

int len(char a[]) // Определение длины массива
{
    int count = 0;
    for (int i = 0; a[i] != '\0'; i++)
        count++;
    return count;
}

int main(void)
{
    char coordinates[128];
    int x, y;
    scanf("%s", coordinates);
    int chess_desk[8][8], count = 0; // Обозначаем матрицу-поле и счетчик клеток
    for(int i = 0; i < 8; i++) // Заполняем матрицу единицами
    {
        for(int j = 0; j < 8; j++)
            chess_desk[i][j] = 1;
    }
    for(int i1 = 0; i1 <= (len(coordinates) - 2); i1 += 2)
    {
        x = convert(coordinates[i1]);
        y = atoi(&coordinates[i1 + 1]) - 1;
        for(int i = -1; i <= 1; i++) // Обнуляем все смежные координаты
        {
            for(int j = -1; j <= 1; j++)
            {
                if(((x + i) >= 0) && ((x + i) < 8) && ((y + j) >= 0) && ((y + j) < 8))
                    chess_desk[x + i][y + j] = 0;
            }
        }
    }
    for(int i = 0; i < 8; i++) // Считаем количество ненулевых клеток
    {
        for(int j = 0; j < 8; j++)
            count += chess_desk[i][j];
    }
    printf("%d", count);
    return 0;
}
