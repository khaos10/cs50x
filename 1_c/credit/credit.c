#include<cs50.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void)
{
    // Prompt user for card number
    long card_number;
    do
    {
        card_number = get_long("Number: ");
    }
    while (card_number < 0);

    // Count length
    int length = 0;
    long y = card_number;
    do
    {
        y = y / 10;
        length++;
    }
    while (y > 0);

    // Calculate checksum
    long x = card_number;
    int sum1 = 0;
    int sum2 = 0;
    int digit1;
    int digit2;
    int d21;
    int d22;
    do
    {
        // Add last digit to sum1
        digit1 = x % 10;
        x = x / 10;
        sum1 = sum1 + digit1;

        // Multiply second last digit and add to sum2
        digit2 = (x % 10) * 2;
        d21 = digit2 % 10;
        d22 = digit2 / 10;
        x = x / 10;
        sum2 = sum2 + d21 + d22;
    }
    while (x > 0);

    int total = sum1 + sum2;

    // Check for card length and starting digits
    long start = card_number;
    do
    {
        // Get starting digits
        start = start / 10;
    }
    while (start > 100);

    if ((total % 10 == 0) && length == 15 && ((start / 10 == 3) && (start % 10 == 4 || start % 10 == 7)))
    {
        printf("AMEX\n");
    }
    else if ((total % 10 == 0) && length == 16 && (start > 50 && start < 56))
    {
        printf("MASTERCARD\n");
    }
    else if ((total % 10 == 0) && (length == 13 || length == 16) && (start / 10 == 4))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}




