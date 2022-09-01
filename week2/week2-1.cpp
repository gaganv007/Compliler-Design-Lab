#include <bits/stdc++.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
int size = 0;

struct Symbol_Table
{
    char lbl[10];
    int address;
    struct Symbol_Table *nxt;
} * first, *last;

int search(char lab[])
{
    int i, flag = 0;
    struct Symbol_Table *temp;
    temp = first;
    for (i = 0; i < size; i++)
    {
        if (strcmp(temp->lbl, lab) == 0)
        {
            flag = 1;
            break;
        }
        temp = temp->nxt;
    }
    return flag;
}

void insert()
{
    int n;
    char l[10];
    printf("Enter the label: ");
    scanf("%s", l);
    n = search(l);
    if (n == 1)
        printf("The label is already in the symbol table. Duplicate cant be inserted\n");
    else
    {
        struct Symbol_Table *p;
        p = (Symbol_Table*)(malloc(sizeof(*p)));
        strcpy(p->lbl, l);
        printf("Enter the address: ");
        scanf("%d", &p->address);
        p->nxt = NULL;
        if (size == 0)
        {
            first = p;
            last = p;
        }
        else
        {
            last->nxt = p;
            last = p;
        }
        size++;
    }
}

void display()
{
    int i;
    struct Symbol_Table *p;
    p = first;
    printf("\nLABEL\tADDRESS\n");
    for (i = 0; i < size; i++)
    {
        printf("%s\t%d\n", p->lbl, p->address);
        p = p->nxt;
    }
}

int main()
{
    int ch;
    int y;
    char la[10];
    do
    {
        printf("\nSYMBOL TABLE IMPLEMENTATION USING LINKED LIST\n");
        printf("\n1.INSERT\n");
        printf("\n2.DISPLAY\n");
        printf("\n3.SEARCH\n");
        printf("\n4.EXIT\n");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insert();
            printf("\nInserted Succesfully\n");
            break;
        case 2:
            display();
            break;
        case 3:
            printf("Input the label to be searched: ");
            scanf("%s", la);
            y = search(la);
            if (y == 1)
                printf("Label is present in the symbol table\n");
            else
                printf("Label is not present in the symbol table\n");
            break;
        case 4:
            exit(0);
        }
    } while (ch < 6);
    return 0;
}
