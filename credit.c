#include <cs50.h>
#include <stdio.h>

int get_everyother(long numb);
int get_everythingelse(long numb);
int get_length(long numb);
int get_lasttwo(long numb);
int get_lastone(long numb);

int main(void)
{
    long numb = get_long("What is your Credit Card Number? ");
    int dig1 = get_everyother(numb);
    int dig2 = get_everythingelse(numb);
    int digt = dig1 + dig2;
    // find length
    int l = get_length(numb);
    // gets first and first 2 digits of number
    int lasttwo = get_lasttwo(numb);
    int lastone = get_lastone(numb);
    // create if statment that filters out invalid
    if (l != 16 && l != 15 && l != 13)
    {
        printf("INVALID\n");
    }
    else if ((digt % 10) != 0)
    {
        printf("INVALID\n");
    }
    else if (lasttwo == 34 || lasttwo == 37)
    {
        printf("AMEX\n");
    }
    else if (lasttwo == 51 || lasttwo == 52 || lasttwo == 53 || lasttwo == 54 || lasttwo == 55)
    {
        printf("MASTERCARD\n");
    }
    else if (lastone == 4)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}

int get_lastone(long numb)
{
    int l = get_length(numb);
    long lastone = numb;
    for (int i = 0; i < l - 1; i++)
    {
        lastone = lastone / 10;
    }
    return lastone;
}

int get_lasttwo(long numb)
{
    int l = get_length(numb);
    long lasttwo = numb;
    for (int i = 0; i < l - 2; i++)
    {
        lasttwo = lasttwo / 10;
    }
    return lasttwo;
}

int get_length(long numb)
{
    int l = 0;
    while (numb > 0)
    {
        numb = numb / 10;
        l++;
    }
    return l;
}

int get_everythingelse(long numb)
{
    int dig2 = 0;
    while (numb > 0)
    {
        dig2 = dig2 + (numb % 10);
        numb = numb / 100;
    }
    return dig2;
}

int get_everyother(long numb)
{

    int dig1 = 0;
    while (numb > 0)
    {
        numb = numb / 10;
        int digits = 2 * (numb % 10);
        int digitsum = 0;
        while (digits > 0)
        {
            digitsum = digitsum + (digits % 10);
            digits = digits / 10;
        }

        dig1 = dig1 + digitsum;
        numb = numb / 10;
    }
    return dig1;
}