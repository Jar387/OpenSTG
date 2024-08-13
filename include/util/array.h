#ifndef ARRAY_H
#define ARRAY_H

// alloc aligned to page avoid realloc mem copy
#define PG_SIZE 2<<10		// 4KiB small page

typedef struct {
	char *data;		// data head
	int size;
	int used;
	int max;
	int obj_sz;
} array_head;

array_head *create_array(int max_size, int object_size);
void destroy_array(array_head * array);

void put_obj(array_head * array, void *data, int index);
void *get_obj(array_head * array, int index);

#endif
