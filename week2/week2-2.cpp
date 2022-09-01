#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Symbol_Table
{
    char lbl[100];
    int adr;
};

struct Symbol_Table st[10][50];
int ind[10] = {0};

int main(int argc, char **argv)
{

    int ch;

    do
    {
        printf("SYMBOL TABLE IMPLEMENTATION USING HASH TABLE\n");
        printf("1. INSERT\n");
        printf("2. SEARCH\n");
        printf("3. DISPLAY\n");
        printf("0. EXIT\n");

        printf("\n\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 0:
        {
            break;
        }
        case 1:
        {
            int n;
            printf("\nEnter the number of symbols you want to input: ");
            scanf("%d", &n);

            for (int i = 0; i < n; i++)
            {
                struct Symbol_Table symbol;
                printf("\nSymbol %d:", i + 1);
                printf("\nInput address: ");
                scanf("%d", &symbol.adr);
                printf("Input label: ");
                scanf("%s", symbol.lbl);

                int len = strlen(symbol.lbl);
                int hash = len % 10;

                st[hash][ind[hash]] = symbol;
                ind[hash]++;
            }
            break;
        }
        case 2:
        {
            char lbl[100];
            printf("\nEnter the label to search: ");
            scanf("%s", lbl);

            int len = strlen(lbl);
            int hash = len % 10;

            int found = 0;
            for (int i = 0; i < ind[hash]; i++)
            {
                if (strcmp(lbl, st[hash][i].lbl) == 0)
                {
                    printf("\nSymbol found!\n");
                    printf("\nAddress: %d", st[hash][i].adr);
                    printf("\nLabel: %s\n", st[hash][i].lbl);
                    found = 1;
                    break;
                }
            }

            if (!found)
            {
                printf("\nSymbol not found!\n");
            }
            break;
        }
        case 3:
        {
            for (int i = 0; i < 10; i++)
            {
                for (int j = 0; j < ind[i]; j++)
                {
                    printf("%d\t%s\n", st[i][j].adr, st[i][j].lbl);
                }
            }
            break;
        }
        default:
        {
            printf("\nInvalid Entry\n");
        }
        }

    } while (ch);

    return 0;
}
