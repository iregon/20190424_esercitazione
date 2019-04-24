//
// Created by Alessandro on 24/04/2019.
//

#include <stdlib.h>
#include "factors_queue.h"

queue* new_queue(int start_size) {
    queue* q = (queue*)malloc(sizeof(queue));

    q->nodes = (void**)malloc(sizeof(node) * start_size);
    q->size = start_size;
    q->length = 0;

    return q;
}

int add_factor(queue* q, int factor) {

    if(exist_factor(q, factor)) increase_factors_exp(q, factor);
    else {
        int res = add_new_node(q, factor);
        if(res != 1) return res;
    }

    return 1;
}

int  add_new_node(queue* q, int factor) {
    node *n = new_node();

    if (n == NULL) return 0;

    n->factor = factor;

    if (q->length >= q->size) {
        q->nodes = alloc_new_nodes(q, 10);
        if (q->nodes == NULL) return 0;
    }

    q->nodes[q->length++] = n;

    return 1;
}

node* new_node() {
    node* n = (node*)malloc(sizeof(node));

    if(n == NULL) return NULL;

    n->factor = 0;
    n->exp = 1;

    return n;
}

void** alloc_new_nodes(queue *q, int num_additional_nodes) {
    void** nodes = (void**)realloc(q->nodes, q->size + num_additional_nodes);
    return nodes;
}

int exist_factor(queue* q, int factor) {
    for (int i = 0; i < q->length; ++i) {
        if((*(node*)q->nodes[i]).factor == factor) return 1;
    }

    return 0;
}

void increase_factors_exp(queue* q, int factor) {
    for (int i = 0; i < q->length; ++i) {
        if((*(node*)q->nodes[i]).factor == factor) {
            (*(node*)q->nodes[i]).exp++;
            break;
        };
    }
}