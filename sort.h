#ifndef SORTING
#define SORTING

/* Built-in libraries */
#include <stdio.h>
#include <stdlib.h>

/* Structs */
/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/* Prototypes */
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);

/* Custom functions */
int part(int *array, int left, int right, size_t size);
void myquicksort(int *array, int left, int right, size_t size);
void myswap(int *array, int firts, int second, int size);
void quick_sort_hoare(int *array, size_t size);
void myswapy(int *array, int i, int j);
#endif
