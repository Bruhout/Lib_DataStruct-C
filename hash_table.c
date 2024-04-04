#include <stdio.h>
#include <stdlib.h>
#include "lib/linked_list.h"

/*
A hash table is an array of NODE pointers. The table is given as a NODE** pointing to its first element
The hash table is allocated through malloc, on the heap
*/

NODE **initialize_table(int length)
{
    NODE **table = malloc(length * sizeof(NODE *));
    if (table == NULL)
    {
        printf("Memory allocation error\n");
        return NULL;
    }
    for (int i = 0; i < length; i++)
    {
        table[i] = NULL;
    }
    return table;
}

int add_to_table(NODE **table, void *data_element, int (*custom_hash)(void *))
{
    int hash_value = (*custom_hash)(data_element); // The custom_hash function must implemented by the user, for the desired datatype
    NODE *new_node = create_node(data_element);

    if (new_node == NULL)
    {
        printf("Failed to allocate new node\n");
        return -1;
    }

    if (table[hash_value] == NULL)
    {
        table[hash_value] = new_node;
        return 0;
    }
    NODE *buffer = table[hash_value];
    while (buffer->next_node != NULL)
    {
        buffer = buffer->next_node;
    }
    buffer->next_node = new_node;
    return 0;
}

void print_table(NODE **table, int length, void (*custom_print)(void *))
{
    NODE *buffer;
    for (int i = 0; i < length; i++)
    {
        if (table[i] != NULL)
        {
            buffer = table[i];
            while (buffer != NULL)
            {
                (*custom_print)(buffer->data); // custom_print must be implemented by the user for the desired datatype.
                buffer = buffer->next_node;
            }
        }
    }
}

int free_table(NODE **table, int length)
{
    if (table == NULL)
    {
        printf("Invalid table passed\n");
        return -1;
    }

    NODE *buffer;
    for (int i = 0; i < length; i++)
    {
        buffer = table[i];
        while (buffer != NULL)
        {
            free(buffer);
        }
    }
    return 0;
}