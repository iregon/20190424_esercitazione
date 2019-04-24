//
// Created by Alessandro on 24/04/2019.
//

#ifndef FATTORI_PRIMI_FACTORS_QUEUE_H
#define FATTORI_PRIMI_FACTORS_QUEUE_H

#endif //FATTORI_PRIMI_FACTORS_QUEUE_H

typedef struct n node;
struct n {
    int factor;
    int exp;
};

typedef struct q queue;
struct q {
    int size;
    int length;
    void** nodes;
};

queue* new_queue(int start_size);

int add_factor(queue* q, int factor);

int add_new_node(queue* q, int factor);

node* new_node();

void** alloc_new_nodes(queue *q, int num_additional_nodes);

int exist_factor(queue* q, int factor);

void increase_factors_exp(queue* q, int factor);