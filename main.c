#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NODE {
    void* data;
    struct NODE* next_node;
}NODE;

NODE* create_node(void* data_element) {
    NODE* new_node=malloc(sizeof(NODE));
    if (new_node==NULL) {
        printf("Memory allocation error");
        return NULL;
    }
    new_node->data=data_element;
    new_node->next_node=NULL;
    return new_node;
}

NODE* create_list(void* data_element) {
    NODE* first_node=create_node(NULL);
    first_node->next_node=NULL;
    first_node->data=data_element;
    return first_node;
}

int insert_at_beginning(NODE** first_node_ptr, void* data_element) {
    NODE* new_node=create_node(NULL);
    if (*first_node_ptr==NULL) {
        printf("invalid linked list passed");
        return -2;
    }
    new_node->data=data_element;
    new_node->next_node=*first_node_ptr; //The next_node points to the preivous first node.
    *first_node_ptr=new_node; //New node is set to the first node.
    return 0;
}


int insert_at_end(NODE* first_node, void* data_element) {
    NODE* buffer=first_node;
    while (buffer->next_node!=NULL) {
        buffer=buffer->next_node;
    }
    NODE* new_node=malloc(sizeof(NODE));
    if (new_node==NULL) {
        printf("Error allocating memory");
        return -1;
    }
    buffer->next_node=new_node;
    new_node->data=data_element;
    new_node->next_node=NULL;
    return 0;
}

int list_length(NODE* first_node) {
    if (first_node==NULL) {
        printf("Invalid Node");
        return -1;
    }
    NODE* buffer=first_node;
    int count=0;
    while (buffer!=NULL) {
        buffer=buffer->next_node;
        count+=1;
    }
    return count;
}

int insert_at_index(NODE* first_node, void* data_element, int index) {
    if (first_node==NULL) {
        printf("Invalid list");
        return -1;
    }
    if (index<0 || index>list_length(first_node)+1) {
        printf("Invalid index");
        return -2;
    }
    NODE* buffer1=first_node;
    NODE* buffer2=first_node;
    NODE* new_node=create_node(NULL);
    new_node->data=data_element;
    for (int i=0; i<index-1; i++) {
        buffer1=buffer1->next_node;
    }
    for (int i=0; i<index; i++) {
        buffer2=buffer2->next_node;
    }
    buffer1->next_node=new_node;
    new_node->next_node=buffer2;
    return 0;
}

int print_list_char(NODE* first_node) {
    NODE* buffer=first_node;
    while (buffer!=NULL) {
        printf("%s\n", (char*)buffer->data);
        buffer=buffer->next_node;
    }
    return 0;
}

int print_list_int(NODE* first_node) {
    NODE* buffer=first_node;
    while (buffer!=NULL) {
        printf("%i\n", *(int*)(buffer->data));
        buffer=buffer->next_node;
    }
    return 0;
}
//Typecasting is only really required to be done when printing. the array itself can easily just store void*, a pointer.
//doesnt matter what to.
void* indexing(NODE* first_node, int index) {
    if (first_node==NULL) {
        printf("Invalid Node");
        return NULL;
    }
    NODE* buffer=first_node;
    for (int i=0; i<index; i++) {
        if (buffer==NULL) {
            printf("not enough nodes");
            return NULL;
        }
        buffer=buffer->next_node;
    }
    return buffer->data;
}

void concatenate(NODE* first_list, NODE* second_list) {
    if (first_list==NULL) {
        printf("Invalid first_list");
        return;
    }
    if (second_list==NULL) {
        printf("Invalid second_list");
        return;
    }
    NODE* buffer1=first_list;
    while (buffer1->next_node!=NULL) {//this loop with set the first buffer to the end of the first array.
        buffer1=buffer1->next_node;
    }
    NODE* buffer2=second_list;
    while (buffer2!=NULL) {
        buffer1->next_node=buffer2;
        buffer1=buffer2;
        buffer2=buffer2->next_node;
    }
}

void delete_node(NODE** list, int index) {
    if (list==NULL) {
        printf("Invalid list\n");
        return;
    }
    if (index < 0 || index >= list_length(*list)) {
        printf("Invalid index\n");
        return;
    }
    NODE* buffer=*list;
    if (index==0) {
        *list=buffer->next_node;
        return;
    }
    for (int i=0; i<index-1; i++) {
        buffer=buffer->next_node;
    }
    buffer->next_node=buffer->next_node->next_node;
}