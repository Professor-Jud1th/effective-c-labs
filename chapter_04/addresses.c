/**
 * @file addresses.c
 * @author Professor-Jud1th <Professor.Jud1th@protonmail.com>
 * @brief Program demonstrating memory reconaissance for viewing stack allocation
 * @details Program maps out stack allocation of integer array. Also features contiguous memory demo and pointer math
 * @version 0.1
 * %2026-05-01
 *
 * @copyright Copyright (c) 2026
 *
 */

#include <stdio.h>

int main()
{
    int suite[5] = {10, 20, 30, 40, 50};
    int *ptr = suite; // Pointer to start of array

    printf("Base Address of array: %p\n\n", (void *)suite);

    for (int i = 0; i < 5; i++)
    {
        printf("Index [%d] value = %d | address = %p\n", i, suite[i], (void *)&suite[i]);
    }

    printf("\n Pointer math check:\n");
    printf("Address at ptr +1: %p (Jump of 4-bytes occurs)\n", (void *)(ptr + 1));

    return 0;
}