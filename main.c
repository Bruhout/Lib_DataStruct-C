#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NODE {
  void *data;
  struct NODE *next_node;
} NODE;

NODE *create_node(void *data_element) {
  NODE *new_node = malloc(sizeof(NODE));
  if (new_node == NULL) {
    printf("Memory allocation error\n");
    return NULL;
  }
  new_node->data = data_element;
  new_node->next_node = NULL;
  return new_node;
}

NODE *create_list(void *data_element) {
  NODE *new_list_head = create_node(NULL);
  if (new_list_head==NULL) {
    printf("Memory allocation error\n");
    return NULL;
  }
  new_list_head->next_node = NULL;
  new_list_head->data = data_element;
  return new_list_head;
}

int insert_at_beginning(NODE **first_node_ptr, void *data_element) {
  if (*first_node_ptr == NULL) {
    printf("invalid linked list passed\n");
    return -2;
  }
  NODE *new_node = create_node(NULL);
  if (new_node==NULL) {
    printf("Memory allocation error\n");
    return -1;
  }
  new_node->data = data_element;
  new_node->next_node =
      *first_node_ptr; // The next_node points to the preivous first node.
  *first_node_ptr = new_node; // New node is set to the first node.
  return 0;
}

int insert_at_end(NODE *first_node, void *data_element) {
  if (first_node==NULL) {
    printf("Invalid linked_list passed\n");
    return -2;
  }
  NODE *buffer = first_node;
  while (buffer->next_node != NULL) {
    buffer = buffer->next_node;
  }
  NODE *new_node = malloc(sizeof(NODE));
  if (new_node == NULL) {
    printf("Error allocating memory\n");
    return -1;
  }
  buffer->next_node = new_node;
  new_node->data = data_element;
  new_node->next_node = NULL;
  return 0;
}

int list_length(NODE *list_head) {
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

int insert_at_index(NODE *list_head, void *data_element, int index) {
  if (list_head == NULL) {
    printf("Invalid linked list passed\n");
    return -2;
  }
  if (index < 0 || index > list_length(list_head) + 1) {
    printf("Invalid index\n");
    return -3;
  }
  NODE *buffer1 = list_head;
  NODE *buffer2 = list_head;
  NODE *new_node = create_node(NULL);
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

int print_list_char(NODE *head_node) {
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

int print_list_int(NODE *first_node) {
  if (first_node==NULL) {
    printf("Invalid linked list passed\n");
    return -2;
  }
  NODE *buffer = first_node;
  while (buffer != NULL) {
    printf("%i\n", *(int *)(buffer->data));
    buffer = buffer->next_node;
  }
  return 0;
}
// Typecasting is only really required to be done when printing. the array
// itself can easily just store void*, a pointer. doesnt matter what to.
void *indexing(NODE *first_node, int index) {
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

void concatenate(NODE *first_list, NODE *second_list) {
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

void delete_node(NODE **list, int index) {
  if (list == NULL) {
    printf("Invalid linked list passed\n");
    return;
  }
  if (index < 0 || index >= list_length(*list)) {
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
