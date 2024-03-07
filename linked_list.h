typedef struct NODE {
    void* data;
    struct NODE* next_node;
}NODE;


NODE* create_node(void* data_element);
NODE* create_list(void* data_element);
int insert_at_beginning(NODE** first_node_ptr, void* data_element);
int insert_at_end(NODE* first_node, void* data_element);
int list_length(NODE* first_node);
int insert_at_index(NODE* first_node, void* input_data, int index);
int print_list_char(NODE* first_node);
int print_list_int(NODE* first_node);
void* indexing(NODE* first_node, int index);
void concatenate(NODE* first_list, NODE* second_list);
void delete_node(NODE** list, int index);