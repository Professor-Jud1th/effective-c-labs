/**
 * @file unsigned_wrap.c
 * @author Professor-Jud1th <Professor.Jud1th@protonmail.com>
 * @brief Example program showing unsigned integer wrap-around behavior.
 * @details Program shows when subtracting from unsigned zero, results in max value for the type, which results in logic bug.
 * @version 0.1
 * 2026-04-29
 *
 * @copyright Copyright (c) 2026 
 *
 */

#include <stdio.h>
#include <limits.h>

int main(void)
{
    // Start at absolute floor
    unsigned int balance = 0;

    printf("Starting balance: %u\n", balance);

    /* * SECURITY ISSUE: Subtracting from unsigned zero
     *  results in the value wrapping to UNIT_MAX (4.2 billion approx.)
     */
    balance = balance - 1;

    printf("Balance after -1: %u\n", balance);

    if (balance > 1000)
    {
        printf("Security Alert: Balance is now massive!) \n");
    }

    return 0;
}
