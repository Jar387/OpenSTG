#ifndef SCHED_H
#define SCHED_H

typedef struct task_t task;
typedef struct task_t{
    int id;
    int tick; // frame count from task activation
    int abs_frame;
    int ferq;
    int die_countdown;
    void (*callback)(int); // when it is a delay task, will pass the delay time
                           // when it is a periodic task, will pass the loop times triggered+1
    task* next;
}task;

void init_sched();
void tick_sched();

void add_absolute_delay_task(int abs_frame);
void add_delay_task(int frame);
void add_periodic_task(int freq_frame);
void add_periodic_times_task(int freq_frame, int loop_time);

#endif