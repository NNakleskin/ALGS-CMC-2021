#include "stdio.h"
#include "string.h"
#include "stdlib.h"

#define NOT_FOUND 0

//структура дерева
struct bin_tree
{
    char name[101];
    unsigned int adress;
    struct bin_tree* left;//левый потомок
    struct bin_tree* right;//правый потомок
};

//вставка в дерево
struct bin_tree* insert(struct bin_tree* root, char* x, unsigned int adress)
{
    if (!root)//если дерева нет, то формируем корень
    {
        root = (struct bin_tree*)malloc(sizeof(struct bin_tree));
        root->left = 0;
        root->right = 0;
        strcpy(root->name, x);
        root->adress = adress;
    }
    else  if (strcmp(x, root->name) < 0)//условие добавление левого потомка
    {
        root->left = insert(root->left, x, adress);
    }
    else//условие добавление правого потомка
    {
        root->right = insert(root->right, x, adress);
    }
    //возвращаем узел, который рассматривали
    return root;//если это был лист, то мы создали там элемент и закончили рекурсию
}

//функция удаления всего дерева
void reemove(struct bin_tree* root)
{
    if (root != 0)
    {
        reemove(root->left);
        reemove(root->right);
        free(root);
    }
}

//функция для поиска минимального элемента в дереве
struct bin_tree* findmin(struct bin_tree* p) // поиск узла с минимальным ключом в дереве p
{
    return p->left ? findmin(p->left) : p;//идем до минимума
}

//функция для удаления минимального элемента
struct bin_tree* removemin(struct bin_tree* p) // удаление узла с минимальным ключом из дерева p
{
    if (p->left == 0)//если левого поддерева нет, то минимум найден и возвращаем правое, чтобы поставить на его место
    {
        return p->right;
    }
    p->left = removemin(p->left);//в противном случае продолжаем идти до минимума в дереве
    return p;
}

struct bin_tree* find(struct bin_tree* p, char* kk)
{
    if (!p) return NOT_FOUND;//если не найден
    if (strcmp(kk, p->name) < 0)
    {
        return find(p->left, kk);
    }
    else if (strcmp(kk, p->name) > 0)
    {
        return find(p->right, kk);
    }
    else return p;//возвращаем указатель на адрес
    return 0;
}

int main(void)
{
    FILE* input = fopen("input.txt", "r");
    FILE* output = fopen("output.txt", "a");
    int n;
    fscanf(input, "%d", &n);
    struct bin_tree* a = NULL;
    unsigned int adress;
    char name[101];
    for (int i = 0; i < n; i++)
    {
        fscanf(input, "%s", name);
        fscanf(input, "%u", &adress);
        a = insert(a, name, adress);
    }
    int m;
    fscanf(input, "%d", &m);
    struct bin_tree* x = NULL;
    for (int i = 0; i < m; i++)
    {
        char res[101];
        fscanf(input, "%s", res);
        x = find(a, res);
        if (x)
        {
            fprintf(output, "%u\n", x->adress);
        }
        else
        {
            fprintf(output, "-1\n");
        }
    }
    reemove(a);
    fclose(input);
    fclose(output);
    return 0;
}
