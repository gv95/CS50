#include <cs50.h>
#include <stdio.h>
#include <math.h>

float prompt(void);
int convert(float n);
int calculate(int x);

int main(void)
{
    float input = prompt();
    int rounded = convert(input);
    int result = calculate(rounded);
    printf("%i\n", result);

}

float prompt(void)
{
    float n;
    do
    {
    printf("How much change is owed?\n");
    n = get_float();
    }
    while (n < 0);
    return n;
}

int convert(float n)
{
    int x;
    float t;
    t = n * 100;
    x = round (t);
    return x;
}

int calculate(int x)
{
    int quarters, dimes, nickels, pennies;
    quarters = x / 25;
    dimes = (x % 25) / 10;
    nickels = ((x % 25) % 10) / 5;
    pennies = ((x % 25) % 10) % 5;
    int result = quarters + dimes + nickels + pennies;
    return result;
}
