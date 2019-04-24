#include <stdio.h>
#include "factors_queue.h"

void factorize(queue* q, int num);

int get_prime_divider(int num);

void print_queue(queue* q);

int main() {
    int num;

    do {
        queue *q = new_queue(1);

        if (q == NULL) {
            printf("ERROR: impossibile allocare la lista");
            return 1;
        }

        printf("> Inserisci il numero da scomporre: ");
        scanf("%d", &num);

        if (num <= 0 || num == 1) break;

        printf("\nI fattori che compongono il numero %d sono: ", num);
        factorize(q, num);
        print_queue(q);
        printf("\n\n");

    } while(1);

    return 0;
}

void factorize(queue* q, int num) {
    int b;
    while (num != 1) {
        b = get_prime_divider(num);
        num /= b;
        add_factor(q, b);
    }
}

int get_prime_divider(int num) {
    int b = 2;
    while (num % b != 0) b++;
    return b;
}

void print_queue(queue* q) {
    for (int i = 0; i < q->length; ++i) {
        printf("%d^%d   ", (*(node*)q->nodes[i]).factor, (*(node*)q->nodes[i]).exp);
    }
}