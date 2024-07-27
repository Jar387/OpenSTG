#ifndef LIST_H
#define LIST_H

typedef struct list_node_t{
    int id;
    void* data;
    struct list_node_t* prev;
    struct list_node_t* next;
}list_node;

typedef struct list_head_t{
    list_node* head;
    list_node* tail;
    int next_id;
}list_head;

extern list_head* bullet_list;
extern list_head* sched_list;

void create_all_instances();

list_head* create_list();
void insert_tail(list_head* head, list_node* data);
void delete_object(list_head* head, list_node* obj);
void delete_object_id(list_head* head, int id);
list_node* query_object(list_head* head, int id);
void list_foreach(list_head* head, void(*callback)(void*, int));

#endif