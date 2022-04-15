#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>


typedef struct node_t
{
    int value;
    struct node_t* next;
}  TNode;

//-----------------------------------------------------------------------------
TNode* Push(TNode** list, int value)
{

    assert(list);

    TNode* node = (TNode*)malloc(sizeof(TNode));
    node->value = value;
    node->next = *list;
    *list = node;

    return *list;
}
//-----------------------------------------------------------------------------
int Pop(TNode** list)
{

    assert(list);
    assert(*list);


    TNode* node = *list;
    *list = (*list)->next;
    int value = node->value;
    free(node);

    return value;
}
//-----------------------------------------------------------------------------
TNode** GetMax(TNode** list)
{
    assert(list);

    TNode** max = list;
    TNode* cur = *list;

    for (; cur->next; cur = cur->next)
    {
        if (cur->next->value > (*max)->value)
        {
            max = &cur->next;
        }
    }

    return max;
}
//-----------------------------------------------------------------------------
TNode* GetRandomList(int count)
{
    TNode* list = NULL;

    for (; count > 0; --count)
    {

        Push(&list, rand() % 90 + 10);
    }

    return list;
}
//-----------------------------------------------------------------------------
void Print(const TNode* list)
{
    for (; list; list = list->next)
    {
        printf("%d, ", list->value);
    }
    printf("\b\b \n");
}
//-----------------------------------------------------------------------------

int main()
{
    srand(time(NULL));

    TNode* list = GetRandomList(10);

    printf("source: ");
    Print(list);

    Pop(GetMax(&list));
    Pop(&list);
    Push(&list, 0);

    printf("result: ");
    Print(list);

    return 0;
}