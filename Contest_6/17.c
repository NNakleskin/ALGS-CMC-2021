#include "stdio.h"
#include "stdlib.h"

typedef struct mytreename
{
    struct mytreename* left, * right;//указатели на левое/правое поддерево и на родителя
    unsigned char height;//высота дерева
    int key, data;
} mytree;

unsigned char height(mytree* p)//функция узнает высоту дерева, которая установлена в узле
{
    return p ? p->height : 0;//если высота не 0, то возвращается высота, иначе 0
}

char bfactor(mytree* p)//вычисляет разницу между высотами правого и левого поддерева
{
    return (height(p->right) - height(p->left));
}

void fixheight(mytree* p)//восстанавливает корректное значение поля height
{
    unsigned char hl = height(p->left);//узнаем высоту левого поддерева
    unsigned char hr = height(p->right);//узнаем высоту правого поддерева
    p->height = (hl > hr ? hl : hr) + 1;//устанавливаем высоту больше и прибавляем к результату 1 (правое/левое поддерево также узел)
}

//Данное вращение используется тогда, когда высота p-left-поддерева = 2 и высота p-right-right-поддерева <= высота p-right-left-поддерева.
mytree* rotateright(mytree* p) // малый правый поворот вокруг p
{
    mytree* q = p->left;//берем левое поддерево
    p->left = q->right;//на место левого поддерева ставим p-left-right
    q->right = p;//на место правого сына взятого поддерева ставим корень
    fixheight(p);//корень опустился, поэтому меняем ему высоту
    fixheight(q);//новый корень, также устанавливаем ему высоту
    return q;//возвращаем указатель на вершину измененного дерева
}

//Данное вращение используется тогда, когда высота p-right-поддерева = 2 и высота p-right-left <= высота p-right-right
mytree* rotateleft(mytree* q) // левый поворот вокруг q
{
    mytree* p = q->right;//берем правое поддерево
    q->right = p->left;//на место правого поддерева ставим p-right-left
    p->left = q;//ставим на место левого сына взятого поддерева корень дерева
    fixheight(q);//устанавливаем корректные значения высот
    fixheight(p);
    return p;//возвращаем указатель на новый корень дерева
}

mytree* balance(mytree* p) //балансировка узла p
{
    fixheight(p);//устанавливаем корректное значение высоты, данная операция нужна, так как функция вызывается после действий, так что значения могут быть не правильные
    if (bfactor(p) == 2)//если нужно выполнить левый поворот
    {
        if (bfactor(p->right) < 0)//если нужно выполнить большое левое вращение
        {
            p->right = rotateright(p->right);//правый потомок делает малое правое вращение
        }
        return rotateleft(p);//делается левое малое вращение, так как теперь условие для выполнения малого левого вращения выполняется
    }
    if (bfactor(p) == -2)//если нужно выполнить правое вращение
    {
        if (bfactor(p->left) > 0)//если нужно выполнить правое большое вращение
        {
            p->left = rotateleft(p->left);//левый сын делает левое малое вращение
        }
        return rotateright(p);//делается правое малое вращение, так как теперь условие для выполнения малого правого вращения выполняется
    }
    return p; //балансировка не нужна
}

mytree* insert(mytree* p, int key, int data) // вставка ключа key и информации data в дерево с корнем p
{
    if (!p)//если прошли все дерево и находимся на месте листа или это первый элемент дерева
    {
        mytree* new = (mytree*)malloc(sizeof(mytree));//создаем структуру под дерево
        new->height = 1;//устанавливаем высоту листу
        new->right = NULL;
        new->left = NULL;
        new->data = data;
        new->key = key;
        return new;//возвращаем указатель на созданную структуру
    }
    if (key < p->key)//если ключ меньше корня дерева
    {
        p->left = insert(p->left, key, data);//тогда идем влево
    }
    else if (key > p->key)
    {
        p->right = insert(p->right, key, data);//идем вправо
    }
    else//key==p->key, соответственно надо заменить данные данного элемента структуры
    {
        p->data = data;
        return p;
    }
    return balance(p);
}

mytree* findmin(mytree* p) // поиск узла с минимальным ключом в дереве p
{
    return p->left ? findmin(p->left) : p;//идем до минимума, по свойству АВЛ-дерева он слева
}

mytree* removemin(mytree* p) // удаление узла с минимальным ключом из дерева p
{
    if (p->left == 0)//если левого поддерева нет, то минимум найден и возвращаем правое, чтобы поставить на его место
    {
        return p->right;
    }
    p->left = removemin(p->left);//в противном случае продолжаем идти до минимума в дереве
    return balance(p);//после удаления элемента производим балансировку
}

mytree* removee(mytree* p, int key)// удаление ключа key из дерева p
{
    if (!p)
    {
        return 0;//если не найден
    }
    if (key < p->key)//если меньше чем в корне
    {
        p->left = removee(p->left, key);//идем налево
    }
    else if (key > p->key)//если больше, то направо
    {
        p->right = removee(p->right, key);
    }
    else //  k == p->key
    {
        mytree* q = p->left;//запоминаем левое поддерево
        mytree* r = p->right;//запоминаем правое поддерево
        free(p);//удаляем найденный элемент
        if (!r)
        {
            return q;//если правого поддерева нет, то возвращаем указатель на левое поддерево
        }
        mytree* min = findmin(r);//если правое поддерево есть, то находим минимум в правом поддереве
        min->right = removemin(r);//ставим найденный элемент на место удаленного
        min->left = q;
        return balance(min);//производим балансировку
    }
    return balance(p);//производим балансировку каждой вершины
}

mytree* find(mytree* p, int key)//поиск по дереву p по ключу key, ищет первое вхождение в дереве
{
    if (!p)
    {
        return 0;//если не найден
    }
    if (key < p->key)//если меньше чем в корне
    {
        return find(p->left, key);//идем налево
    }
    else if (key > p->key)//если больше, то направо
    {
        return find(p->right, key);
    }
    else
    {
        return p;//если нашли
    }
    return 0;
}

void free_roots(mytree* root) // Удаление дерева
{
    if (!root) return;//если больше некуда идти, то заканчиваем рекурсию
    if (root->left)//если можно идти еще влево, то идем на максимум
    {
        free_roots(root->left);
    }
    if (root->right)//если уже нельзя идти влево, но можно идти вправо, то идем
    {
        free_roots(root->right);
    }//это листья, ни в право, ни влево идти же нельзя, удаляются листья, потом по цепочке все, что выше
    free(root);//удаляем структуру для поиска
}

int main(void)
{
    mytree* root = NULL;
    char op = 'A';
    while(op != 'F')
    {
        scanf("%c", &op);
        if(op == 'A')
        {
            int key, data;
            scanf("%d%d", &key, &data);
            root = insert(root, key, data);
        }
        if(op == 'D')
        {
            int key;
            scanf("%d", &key);
            root = removee(root, key);
        }
        if(op == 'S')
        {
            int key;
            scanf("%d", &key);
            if(!find(root, key))
            {
                continue;
            }
            printf("%d %d\n", key,  find(root, key)->data);
        }
        if(op == 'F')
        {
            free_roots(root);
        }
    }
    return 0;
}

