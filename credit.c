#include <stdio.h>
#include <cs50.h>

// This program verifies if a credit card number is valid using Luhn's algorhythm. Developed by Guilherme Wanderley in 2017 for CS50.

long long prompt(void);
int first_sum(long long n);
int second_sum(long long n);
int verify(long long n);
int check_company(long long n);

// Main function, prints results according to the company_id returned by check_company
int main(void)
{
    long long cc_number = prompt();
    int valid = verify (cc_number);
    if (valid == 1)
    {
        int company_id = check_company(cc_number);
        switch (company_id)
        {
            case 0:
                printf("UNSPECIFIED\n");
                break;
            case 1:
                printf("AMEX\n");
                break;
            case 2:
                printf("MASTERCARD\n");
                break;
            case 3:
                printf("VISA\n");
                break;
        }
    }
    else
    {
        printf("INVALID\n");
    }
}

// Prompts the user to input a credit card number
long long prompt(void)
{
    printf("Number: ");
    long long cc_number = get_long_long();
    return cc_number;
}

// Adds every other digit from second-to-last multiplied by two
int first_sum (long long n)
{
    int sum = 0;
    while (n)
    {
        int x = ((n / 10) % 10) * 2;

        // This conditional adds the digits of the result separately, if it is greater than 10
        if (x > 9)
        {
            int sup = 0;
            while (x)
            {
                int s = x % 10;
                sup += s;
                x /= 10;
            }
            x = sup;
        }
        sum += x;
        n /= 100;
    }
    return sum;
}

// Adds every other digit starting from last
int second_sum (long long n)
{
    int sum = 0;
    while (n)
    {
        int x = n % 10;
        sum += x;
        n /= 100;
    }
    return sum;
}

// Does the checksum and verifies if the number is valid, returns true or false
int verify (long long n)
{
    int isvalid = 0;
    int sum1 = first_sum(n);
    int sum2 = second_sum(n);
    int result = sum1 + sum2;
    if (result % 10 == 0)
    {
        isvalid = 1;
    }
    return isvalid;
}

// Finds out the company based on how many digits and the starting number.
int check_company(long long n)
{
    int company_id = 0;
    if ( n >= 340000000000000 && n <= 379999999999999 )
    {
        company_id = 1;
    }
    else if ( n >= 5100000000000000 && n <= 5599999999999999 )
    {
        company_id = 2;
    }
    else if ( n >= 4000000000000 && n <= 4999999999999 )
    {
        company_id = 3;
    }
    else if ( n >= 4000000000000000 && n <= 4999999999999999 )
    {
        company_id = 3;
    }
    return company_id;
}