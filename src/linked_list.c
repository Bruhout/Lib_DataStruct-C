#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/linked_list.h"


NODE *CreateNode(void *data_element) {
    NODE *new_node = malloc(sizeof(NODE));
    if (new_node == NULL) {
        printf("Memory allocation error\n");
        return NULL;
    }
    new_node->data = data_element;
    new_node->next_node = NULL;
    return new_node;
}

NODE *CreateList(void *data_element) {
    NODE *new_list_head = CreateNode(NULL);
    if (new_list_head==NULL) {
        printf("Memory allocation error\n");
        return NULL;
    }
    new_list_head->next_node = NULL;
    new_list_head->data = data_element;
    return new_list_head;
}

int InsertAtBeginning(NODE **first_node_ptr, void *data_element) {
    if (*first_node_ptr == NULL) {
        printf("invalid linked list passed\n");
        return -2;
    }
    NODE *new_node = CreateNode(NULL);
    if (new_node==NULL) {
        printf("Memory allocation error\n");
        return -1;
    }
    new_node->data = data_element;
    new_node->next_node =*first_node_ptr; // The next_node points to the preivous first node.
    *first_node_ptr = new_node; // New node is set to the first node.
    return 0;
}

int InsertAtEnd(NODE *head_node, void *data_element) {
    if (head_node==NULL) {
        printf("Invalid linked_list passed\n");
        return -2;
    }
    NODE *buffer_node = head_node;
    while (buffer_node->next_node != NULL) {
        buffer_node = buffer_node->next_node;
    }
    NODE *new_node = malloc(sizeof(NODE));
    if (new_node == NULL) {
        printf("Error allocating memory\n");
        return -1;
    }
    buffer_node->next_node = new_node;
    new_node->data = data_element;
    new_node->next_node = NULL;
    return 0;
}

int ListLength(NODE *list_head) {
    if (list_head == NULL) {
        printf("Invalid linked list passed\n");
        return -2;
    }
    NODE *buffer = list_head;
    int count = 0;
    while (buffer != NULL) {
        buffer = buffer->next_node;
        count += 1;
    }
    return count;
}

int InsertAtIndex(NODE *list_head, void *data_element, int index) {
    if (list_head == NULL) {
        printf("Invalid linked list passed\n");
        return -2;
    }
    if (index < 0 || index > ListLength(list_head) + 1) {
        printf("Invalid index\n");
        return -3;
    }
    NODE *buffer1 = list_head;
    NODE *buffer2 = list_head;
    NODE *new_node = CreateNode(NULL);
    if (new_node==NULL) {
        printf("Memory allocation error\n");
        return -1;
    }
    new_node->data = data_element;
    for (int i = 0; i < index - 1; i++) {
        buffer1 = buffer1->next_node;
    }
    for (int i = 0; i < index; i++) {
        buffer2 = buffer2->next_node;
    }
    buffer1->next_node = new_node;
    new_node->next_node = buffer2;
    return 0;
}

int PrintList_char(NODE *head_node) {
    if (head_node==NULL) {
        printf("Inavlid linked list passed\n");
        return -2;
    }
    NODE *buffer = head_node;
    while (buffer != NULL) {
        printf("%s\n", (char *)buffer->data);
        buffer = buffer->next_node;
    }
    return 0;
}

int PrintList_int(NODE *head_node) {
    if (head_node==NULL) {
        printf("Invalid linked list passed\n");
        return -2;
    }
    NODE *buffer = head_node;
    while (buffer != NULL) {
        printf("%i\n", *(int *)(buffer->data));
        buffer = buffer->next_node;
    }
    return 0;
}
// Typecasting is only really required to be done when printing. the array
// itself can easily just store void*, a pointer. doesnt matter what to.

int CustomPrint(NODE* head_node, void (*print_f)(void*)) {
    if (head_node==NULL) {
        printf("Invalid linked list passed\n");
        return -2;
    }
    NODE* buffer=head_node;
    while(buffer!=NULL) {
        print_f(buffer->data);
        buffer=buffer->next_node;
    }
    return 0;
}


void* Indexing(NODE *first_node, int index) {
    if (first_node == NULL) {
        printf("Invalid linked list passed\n");
        return NULL;
    }
    NODE *buffer = first_node;
    for (int i = 0; i < index; i++) {
        if (buffer == NULL) {
        printf("Not enough nodes\n");
        return NULL;
        }
        buffer = buffer->next_node;
    }
    return buffer->data;
}


void Concatenate(NODE *first_list, NODE *second_list) {
    if (first_list == NULL) {
        printf("Invalid first_list\n");
        return;
    }
    if (second_list == NULL) {
        printf("Invalid second_list\n");
        return;
    }
    NODE *buffer1 = first_list;
    while (buffer1->next_node != NULL) { 
        // this loop with set the first buffer to the end of the first array.
        buffer1 = buffer1->next_node;
    }
    NODE *buffer2 = second_list;
    while (buffer2 != NULL) {
        buffer1->next_node = buffer2;
        buffer1 = buffer2;
        buffer2 = buffer2->next_node;
    }
}

void DeleteNode(NODE **list, int index) {
    if (list == NULL) {
        printf("Invalid linked list passed\n");
        return;
    }
    if (index < 0 || index >= ListLength(*list)) {
        printf("Invalid index\n");
        return;
    }
    NODE *buffer = *list;
    if (index == 0) {
        *list = buffer->next_node;
        return;
    }
    for (int i = 0; i < index - 1; i++) {
        buffer = buffer->next_node;
    }
    buffer->next_node = buffer->next_node->next_node;
}

int FreeList(NODE* head_node)  
{
    if (head_node==NULL) {
        printf("Invalid linked list passed\n");
        return -2;
    }
    NODE* buffer=head_node;
    while (buffer!=NULL) {
        free(buffer);
        buffer=buffer->next_node;
    }
    return 0;
}

NODE* LlFromArray_int(int* array_ptr,int length) 
{
    int* int_memory=malloc(sizeof(int));
    *int_memory=array_ptr[0];
    NODE* new_list=CreateList(int_memory);
    for (int i=1; i<length; i++) {
        int_memory=malloc(sizeof(int));
        *int_memory=array_ptr[i];
        InsertAtEnd(new_list, int_memory);
    }
    return new_list;
}
//WORKING
int ArrayFromLl_int(NODE* head_node, int* array_ptr, int length) 
{
    if (head_node==NULL)
    {
        printf("Invalid list passes\n");
        return -2;
    }

    NODE* buffer=head_node;
    int count=0;
    for (int i=0; i<length; i++) {
        *(array_ptr+i)=*(int*)(buffer->data);
        buffer=buffer->next_node;
        count++;
    }
    return count;
}
//WORKING LESSGOO

int SearchList(NODE* head_node, void* data_element, int(*compare)(void*, void*)) 
{
    if (head_node==NULL)
    {
        printf("Invalid list passes\n");
        return -2;
    }

    NODE* buffer_node=head_node;
    int counter=0;
    while(buffer_node!=NULL) {
        if (compare(data_element, buffer_node->data)==0) {
            return counter;
        }
        buffer_node=buffer_node->next_node;
        counter++;
    }
    return -1;
}
//compare returns 0 for true, anything else for false.
//search_list returns the index for true, -1 for false

int SearchList_char(NODE* head_node , char* word) 
{
    if (head_node==NULL)
    {
        printf("Invalid list passes\n");
        return -2;
    }

    NODE* buffer_node=head_node;
    int counter=0;
    while (buffer_node!=NULL) {
        if (strcasecmp(word, (void*)buffer_node->data)==0) {
            return counter;
        }
        buffer_node=buffer_node->next_node;
        counter++;
    }
    return -1;
}

int SearchList_int(NODE* head_node, int integer) 
{
    if (head_node==NULL)
    {
        printf("Invalid list passes\n");
        return -2;
    }

    NODE* buffer_node=head_node;
    int counter=0;
    while (buffer_node!=NULL) {
        if (integer==*(int*)buffer_node->data) {
            return counter;
        }
        buffer_node=buffer_node->next_node;
        counter++;
    }
    return -1;
}

NODE* GetPointerToNode(NODE* head_node , int index)
{
    if (head_node==NULL)
    {
        printf("Invalid list passes\n");
        return NULL;
    }

    NODE* buffer_node=head_node;

    for (int i=0 ; i<index ; i++)
    {
        if (buffer_node==NULL)
        {
            printf("Index passed is too large\n");
            return NULL;
        }
        buffer_node=buffer_node->next_node;
    }
    
    return buffer_node;
}

NODE* GetPointerToNodeCompare(NODE* head_node , void* comparision_element , int(*compare_function)(void* , void*))
{
    if (head_node==NULL)
    {
        printf("Invalid list passes\n");
        return NULL;
    }
    
    NODE* buffer_node=head_node;
    //compare function returns 0 when found
    while (compare_function(buffer_node->data , comparision_element)!=0)
    {
        buffer_node=buffer_node->next_node;
    }

    return buffer_node;
}
