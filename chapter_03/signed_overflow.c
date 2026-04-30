/**
 * @file signed_overflow.c
 * @author Professor-Jud1th <Professor.Jud1th@protonmail.com>
 * @brief Demonstrating signed integer overflow and signed-bit flipping.
 * @details Showing Undefined Behavior by adding to a maxed-out signed int. Most hardware flips this from a negative to positive.
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
    // Start at max positive value
    int counter = INT_MAX;

    printf("Max signed int: %d\n", counter);

    // This is what triggers Undefined Behavior
    counter = counter + 1;

    printf("After +1 (Overflow): %d\n", counter);

    return 0;
}
