/**
 * @file chapter2_alignment.c
 * @brief Memory alignment, structure padding.
 * - Compiler: Clang/LLVM.
 * - Integer size: 4 bytes (Standard for modern 64-bit systems).
 * - Pointer size: 8 bytes.
 * - Alignment: Ensuring the compliler follows the natural alignment of types.
 *
 * @version 0.1
 * @date 2026-04-28
 * @author Professor-Jud1th <Professor.Jud1th@protonmail.com>
 * @copyright Copyright (c) 2026 Professor-Jud1th
 */

#include <stdio.h>
#include <stdalign.h>
#include <assert.h>

/* --- Compile-Time Security Checks --- */
/* Ensure the program only compiles if assumptions are true */
static_assert(sizeof(int) == 4, "Error: This program assumes a 4-byte integer size.");
static_assert(sizeof(double) == 8, "Error: This program assumes an 8-byte double size.");
static_assert(sizeof(void*) == 8, "Error: This program requires a 64-bit architecture.");

/**
 * @struct MemoryLab
 * @brief Structure designed to trigger compiler padding.
 * @note I added this to test Assumptions. The compiler should  pad to the largest member's alignment (8 bytes).
 */
struct MemoryLab {
    double precision_val; /**< 8-byte float */
    int user_id;          /**< 4-byte integer */
    char status_flag;     /**< 1-byte char */
};

/**
 * @brief Entry point for alignment investigation.
 * @return Should return int 0 on success.
 */
int main(void) {
    printf("--- M2 ARM64 Alignment & Padding Lab ---\n\n");

    /* 1. Fundamental Type Analysis */
    printf("Type Analysis:\n");
    printf("  char:   Size %zu | Align %zu\n", sizeof(char), alignof(char));
    printf("  int:    Size %zu | Align %zu\n", sizeof(int), alignof(int));
    printf("  double: Size %zu | Align %zu\n\n", sizeof(double), alignof(double));

    /* 2. Structure Padding Analysis */
    struct MemoryLab lab;
    
    printf("Structure Analysis (MemoryLab):\n");
    printf("  Total Size: %zu bytes\n", sizeof(lab));
    
    // Calculate expected vs actual to highlight examples of  padding
    size_t raw_size = sizeof(double) + sizeof(int) + sizeof(char);
    size_t padding = sizeof(struct MemoryLab) - raw_size;
    
    printf("  Raw Data:   %zu bytes\n", raw_size);
    printf("  Padding:    %zu bytes\n", padding);

    return 0;
}