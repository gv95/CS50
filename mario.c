#include <stdio.h>
#include <cs50.h>

int prompt(void);
void build(int h);

int main(void)
{
    int h = prompt();
    build(h);

}

int prompt(void)
{
    int n;
    do
    {
        printf("Height: ");
        n = get_int();
    }
    while (n < 0 || n > 23);
    return n;
}

void build(int h)
{
    for(int i = 1; i < h + 1; i++)
    {
        for(int s = 0; s < h - i ; s++)
        {
            printf(" ");
        }

        for(int t = 0; t < i; t++)
        {
            printf("#");
        }

        printf("  ");

        for(int t = 0; t < i; t++)
        {
            printf("#");
        }
        printf("\n");
    }
}