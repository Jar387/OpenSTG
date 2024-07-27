#include <openstg.h>

static void sched_one(void* data, int id){
    task* t = (task*)data;
    if(t->abs_frame!=-1){
        if(t->abs_frame<=tick){
            t->callback(t->tick);
            delete_object(sched_list, &t->node);
            return;
        }
        return;
    }
    if(t->tick%t->ferq==0){
        t->callback(t->tick/t->ferq);
        if(t->die_countdown!=-1){
            // have loop time limit
            t->die_countdown--;
            if(t->die_countdown==0){
                delete_object(sched_list, &t->node);
                return;
            }
        }
        t->tick++;
        return;
    }
    t->tick++;
}

void tick_sched(){
    if(sched_list->head==NULL){
        return;
    }
    list_foreach(sched_list, &sched_one);
}

void add_absolute_delay_task(int abs_frame, void (*callback)(int)){
    task* t = (task*)malloc(sizeof(*t));
    memset(t, 0, sizeof(*t));
    t->abs_frame = abs_frame;
    t->callback = callback;
    t->node.data = t;
    insert_tail(sched_list, &t->node);
}

void add_delay_task(int frame, void (*callback)(int)){
    add_absolute_delay_task(frame+tick, callback);
}

void add_periodic_task(int freq_frame, void (*callback)(int)){
    task* t = (task*)malloc(sizeof(*t));
    memset(t, 0, sizeof(*t));
    t->ferq = freq_frame;
    t->die_countdown = -1;
    t->abs_frame = -1;
    t->callback = callback;
    t->node.data = t;
    insert_tail(sched_list, &t->node);
}

void add_periodic_times_task(int freq_frame, int loop_time, void (*callback)(int)){
    task* t = (task*)malloc(sizeof(*t));
    memset(t, 0, sizeof(*t));
    t->ferq = freq_frame;
    t->die_countdown = loop_time;
    t->abs_frame = -1;
    t->callback = callback;
    t->node.data = t;
    insert_tail(sched_list, &t->node);
}