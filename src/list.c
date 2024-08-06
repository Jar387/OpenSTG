#include <openstg.h>

list_head *bullet_list;
list_head *sched_list;
list_head *player_bullet_list;

void create_all_instances()
{
	bullet_list = create_list();
	sched_list = create_list();
	player_bullet_list = create_list();
}

list_head *create_list()
{
	list_head *head = (list_head *) malloc(sizeof(*head));
	memset(head, 0, sizeof(*head));
	return head;
}

void insert_tail(list_head * head, list_node * data)
{
	if (head == NULL || data == NULL) {
		NULLOBJ("list head");
		return;
	}
	data->prev = NULL;
	data->next = NULL;
	if (head->head == NULL) {
		head->head = data;
	} else {
		data->prev = head->tail;
		head->tail->next = data;
	}
	head->tail = data;
	data->id = head->next_id;
	head->next_id++;
}

void delete_object(list_head * head, list_node * obj)
{
	if (obj == NULL || obj->data == NULL) {
		NULLOBJ("list obj");
		return;
	}
	if (obj->prev != NULL) {
		obj->prev->next = obj->next;
	} else {
		head->head = obj->next;
	}

	if (obj->next != NULL) {
		obj->next->prev = obj->prev;
	} else {
		head->tail = obj->prev;
	}
	free(obj->data);
}

list_node *query_object(list_head * head, int id)
{
	if (head == NULL) {
		NULLOBJ("list head");
		return NULL;
	}
	list_node *index = head->head;
	if (index == NULL) {
		// empty list
		NULLOBJ("list head");
		return NULL;
	}
	while (index->id != id) {
		if (index->next == NULL) {
			OBJNOTFOUND("list node");
			return NULL;
		}
		index = index->next;
	}
	return index;
}

void delete_object_id(list_head * head, int id)
{
	list_node *obj = query_object(head, id);
	if (obj != NULL) {
		delete_object(head, obj);
	}
}

void list_foreach(list_head * head, void (*callback)(void *, int))
{
	if(head == NULL || head->head == NULL || callback == NULL) {
		NULLOBJ("list head");
		return;
	}
	list_node *index = head->head;
	while (index != NULL) {
		callback(index->data, index->id);
		index = index->next;
	}
}
