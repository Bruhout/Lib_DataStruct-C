#include "linked_list.h"

NODE** initialize_table(int length);
/*
    * Initialize a hash table with the given length.
    * Returns a pointer to the allocated table (NODE**) or NULL on error.
*/

int add_to_table(NODE** table, void* data_element, int (*custom_hash)(void*));
/*
    * Add a new data element to the hash table using the provided custom hash function.
    * Returns 0 on success, -1 on error.
*/

void print_table(NODE** table, int length, void (*hash_print)(void*));
/*
    * Print the contents of the hash table using the provided hash print function.
*/

int free_table(NODE** table , int length);
/*
    *Go through the table freeing any blocks that have been allocated.
    *Obviously, orphaned blocks will not be freed.
*/