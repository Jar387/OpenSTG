#ifndef SCHED_H
#define SCHED_H

#include <openstg.h>

typedef struct task_t task;
typedef struct task_t {
	int id;
	int tick;		// frame count from task activation
	int abs_frame;
	int ferq;
	int die_countdown;

	void *data;		// data pointer for caller internal usage
	void (*callback)(int, void *);	// when it is a delay task, will pass the delay time
	// when it is a periodic task, will pass the loop times triggered+1
	list_node node;
} task;

void tick_sched();

void add_absolute_delay_task(int abs_frame, void (*callback)(int, void *),
			     void *data);
void add_delay_task(int frame, void (*callback)(int, void *), void *data);
void add_periodic_task(int freq_frame, void (*callback)(int, void *),
		       void *data);
void add_periodic_times_task(int freq_frame, int loop_time,
			     void (*callback)(int, void *), void *data);

#endif
