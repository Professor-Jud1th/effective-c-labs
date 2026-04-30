/**
 * @file promotion_trap.c
 * @author Professor-Jud1th <Professor.Jud1th@protonmail.com>
 * @brief Demonstrate risks of implicit integer promotion.
 * @details Comparing signed and unsigned types can lead to insecure results.
 * @version 0.1
 * 2026-04-29
 *
 * @copyright Copyright (c) 2026
 *
 */

#include <stdio.h>

int main(void)
{
    int signed_val = -1;
    unsigned int unsigned_val = 1;

    printf("Comparing signed (%d) and unsigned (%u)...\n", signed_val, unsigned_val);

    /* * SECURITY FLAW: The compiler will promote signed_val to unsigned_int.
     * This means -1 becomes 4,294,967,295, making it GREATER than 1.
     */
    if (signed_val < unsigned_val)
    {
        printf("Result -1 is less than 1 (Logic works)\n");
    }
    else
    {
        printf("Result -1 is GREATER than 1 (SECURITY FLAW!)\n");
    }

    return 0;
}