#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    // Prompt user for an amount of change
    float change;
    do
    {
        change = get_float("Change owed: ");
    }
    while (change < 0);
    
    // Convert dollars to cents
    int cents = round(change * 100);
    
    // Calculate the number of 25-cent coins
    int coinsq;
    coinsq = cents / 25;
    
    // Calculate the number of 10-cent coins
    int coinsd;
    coinsd = (cents % 25) / 10;
    
    // Calculate the number of 5-cent coins
    int coinsn;
    coinsn = ((cents % 25) % 10) / 5;
    
    // Print the total number of coins
    int coins;
    coins = coinsq + coinsd + coinsn + ((cents % 25) % 10) % 5;
    printf("%i\n", coins);
}