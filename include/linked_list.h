#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct NODE {
    void *data;
    struct NODE *next_node;
} NODE;

NODE *CreateNode(void *data_element);
/*
Returns pointer to the node created.
Returns NULL if memory allocation failed.
*/
//---------------------------------------------
// NODE *CreateList(void *data_element);
// Removed
/*
Returns pointer the first node of the list.
The next_node attribute is set to NULL.
Returns NULL if memory allocation error.
*/
//---------------------------------------------

NODE* CreateNodeBlank();
/*
Returns pointer to the node created.
Returns NULL is memory allocation failed.
The data pointer of the new node is set to NULL
*/
//---------------------------------------------

int InsertAtBeginning(NODE **first_node_ptr, void *data_element);
/*
list is passed as a NODE**, a pointer to the pointer to the first node.
This is because the NODE* needs to be passed by reference.
Memory allocation is handles by the function itself
Returns -2 if invalid link passed
Returns -1 if memory allocation error
Return 0 on successful insertion
*/
//---------------------------------------------

int InsertAtEnd(NODE *first_node, void *data_element);
/*
Insert data element at the end of the list.
Memory allocation is handles by the function itself
Returns -2 if invalid linked list passed
Returns -1 if memory allocation error
Return 0 on successful insertion
*/
//---------------------------------------------

int ListLength(NODE *list_head);
/*
Get the number of nodes in the list
Returns -2 if invalid linked list passed
Otherwise returns integer count of the nodes in the list
*/
//---------------------------------------------

int InsertAtIndex(NODE *list_head, void *data_element, int index);
/*
Insert a data_element at some location within the list
Memory allocation is handles by the function itself
Returns -1 in case of memory allocation error
Returns -2 if invalid linked list is passed
Returns -3 if invalid index is passed. (index<0 or index>=list_length(list))
Otherwise returns 0 on successful insersertion. 
*/
//---------------------------------------------

int PrintList_char(NODE *head_node);
int PrintList_int(NODE *first_node);
/*
print_list_type, The function must be defined for each type that you wish to support printing.
By default, the library only includes char* and int.
Returns -2 if invalid linked list is passed
Otherwise, returns 0 if successfully executed.
*/
//---------------------------------------------

int CustomPrint(NODE* head_node, void (*print_f)(void*));
/*
This lets you use a custom definition of how you would like the void* to be printed.
The user passes a self defined function.
This function specifies what type void* points to and how its to be printed.
custom_print, the calls this user defined function over all the nodes in the list.
P.S.: the user function can actually be doing anything, so maybe you can use this as a general functionality
to call any function over the entire list. IDK try it
*/
//---------------------------------------------

void *Indexing(NODE *first_node, int index);
/*
Since the list only stores void*, indexing will return a pointer to the data.
This pointer must be dereferenced to access the data.
This is done so that the same indexing function can be used for all data types.
Returns NULL if index is invalid. (index<0 or index>=list_length(list))
Returns NULL if invalid linked list is passed
*/
//---------------------------------------------

void Concatenate(NODE *first_list, NODE *second_list);
/*
No return value from this function.
The second_list is placed at the end of the first list.
The contatenated list is stored in the first_list pointer.
*/
//---------------------------------------------

NODE* DeleteNode(NODE *head_node, int index);
/*
list is passed as a NODE**, a pointer to the pointer to the first node.
This is because the NODE* needs to be passed by reference.
NVM this

Returns a pointer to the head node of the new linked list
*/
//---------------------------------------------

int FreeList(NODE* head_node);
/*
Goes through the list freeing node-by-node.
Dont try to access the list after freeing it.
I dont know what kinda errors u gonna get, but itll be Undefined Behaviour.
Returns 0 if list sucessfully freed.
Returns -2 if invalid linked list passed.
*/
//---------------------------------------------

NODE* LlFromArray_int(int* array_ptr, int length);
/*
Works only for integer arrays.
Returns a pointer to the head_node of the created linked_list.
Length controls the index till which the linked_list is created.
*/
//---------------------------------------------

int ArrayFromLl_int(NODE* head_node, int* array_ptr, int length);
/*
Memory must be allocated before calling the functions.
Length controls the index till which the array is populated.
returns -2 if invalid list passed.
*/
//---------------------------------------------

int SearchList(NODE* head_node, void* data_element, int(*compare)(void*, void*));
/*
Searches the list for a given data_element and returns its index.
The function to compare two data_elements must be defined by the user.
This is done to allow this function to work with any datatype.
Returns -1 if the data_element is not found within the given list.
returns -2 if invalid list passed.
*/
//---------------------------------------------

int SearchList_char(NODE* head_node, char* word);
/*
Implementation of search list for char* type.
Comparison is done using strcasecmp.
Returns -1 if element is not found.
returns -2 if invalid list passed.
*/
//---------------------------------------------

int SearchList_int(NODE* head_node, int integer);
/*
Implementation of search list for int type.
Comparision is done using the '==' operator.
Returns -1 if element not found.
Returns -2 if invalid list passed
*/
//---------------------------------------------

NODE* GetPointerToNode(NODE* head_node , int index);
/*
index through the linked list and get a pointer to the node at the desired index
returns NULL if invalid list passed
returns NULL if invalid index passed
*/
//---------------------------------------------

NODE* GetPointerToNodeCompare(NODE* head_node , void* comparision_element , int(*compare_function)(void* , void*));
/*
index through the linked list and get a pointer to the node which matches a given condition
The condition is implemented in the compare_function, which must be passed in by the user.
Returns NULL if invalid list passed.
*/

#endif
