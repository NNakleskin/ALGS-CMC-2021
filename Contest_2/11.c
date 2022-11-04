#include "stdio.h"

int main(void)
{
    // a - 1
    // b - 2
    // c - 3
    // d - 4
    // e - 5
    // f - 6
    // g - 7
    // h - 8
    char a[8] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'}; // Массив для перевода буквенных координат в числовые
    int chess_desk[8][8], count = 0; // Обозначаем матрицу-поле и счетчик клеток
    for(int i = 0; i < 8; i++) // Заполняем матрицу единицами
    {
        for(int j = 0; j < 8; j++)
            chess_desk[i][j] = 1;
    }
    char x1, x2;
    int y1, y2;
    scanf("%c %d %c %d", &x1, &y1, &x2, &y2);
    y1--; y2--;
    for(int i = 0; i < 8; i++) // Переводим буквенные координаты в числовые
        if(x1 == a[i]){
            x1 = i;
        }
    for(int i = 0; i < 8; i++)
        if(x2 == a[i]){
            x2 = i;
        }
    for(int i = -1; i <= 1; i++) // Обнуляем все смежные координаты
    {
        for(int j = -1; j <= 1; j++){
            if(((x1 + i) >= 0) && ((x1 + i) < 8) && ((y1 + j) >= 0) && ((y1 + j) < 8))
                chess_desk[x1 + i][y1 + j] = 0;
        }
    }
    for(int i = -1; i <= 1; i++)
    {
        for(int j = -1; j <= 1; j++){
            if(((x2 + i) >= 0) && ((x2 + i) < 8) && ((y2 + j) >= 0) && ((y2 + j) < 8))
                chess_desk[x2 + i][y2 + j] = 0;
        }
    }
    for(int i = 0; i < 8; i++) // Считаем количество ненулевых клеток
    {
        for(int j = 0; j < 8; j++)
            count += chess_desk[i][j];
    }
    for(int i = 0; i < 8; i++) // Вывод массива
    {
        for(int j = 0; j < 8; j++)
            printf("%d ",chess_desk[i][j]);
        printf("\n");
    }
    printf("%d\n", count);
}
