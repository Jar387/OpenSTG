#include <openstg.h>

array_head *create_array(int max_size, int object_size)
{
	if (object_size <= 0 || object_size > PG_SIZE) {
		ILLEGALPARAM("object size bigger than machine page size");
	}
	array_head *head = (array_head *) malloc(sizeof(*head));
	head->data = malloc(PG_SIZE);
	head->max = max_size;
	head->obj_sz = object_size;
	head->size = PG_SIZE;
	head->used = 0;
	return head;
}

void destroy_array(array_head * array)
{
	free(array->data);
	free(array);
}

void put_obj(array_head * array, void *data, int index)
{
	char *data_addr = array->data + array->obj_sz * index;
	memcpy(data_addr, data, array->obj_sz);
	array->used += array->size;
	if (array->used + array->obj_sz >= array->size) {
		// need expand array
		array->size += PG_SIZE;
		if (array->max != -1) {
			// have limit
			if (array->size > array->max) {
				ILLEGALSTATE("array size reached limit");
				return;
			}
		}
		array->data = realloc(array->data, array->size);
	}
}

void *get_obj(array_head * array, int index)
{
	return array->data + index * array->obj_sz;
}
