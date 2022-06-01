#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include<string.h>

/* Struktur Node */
struct klinik{
    char nama[100];
    char penyakit[100];
};

typedef struct pqueueNode_t {
   // int data;
//    char data[100];
    struct klinik data;
    struct pqueueNode_t *next;
} PQueueNode;

//struct klinik{
//    char nama[100];
//    char penyakit[100];
//};

/* Struktur ADT PriorityQueue menggunakan Linked List */

// Prioritas default: nilai minimum
typedef struct pqueue_t {
    PQueueNode *_top;
    unsigned _size;
} PriorityQueue;

/* Function prototype */

void pqueue_init(PriorityQueue *pqueue);
bool pqueue_isEmpty(PriorityQueue *pqueue);
void pqueue_push(PriorityQueue *pqueue, struct klinik value);
void pqueue_pop(PriorityQueue *pqueue);
int  pqueue_top(PriorityQueue *pqueue);

/* Function definition below */

void pqueue_init(PriorityQueue *pqueue)
{
    pqueue->_top = NULL;
    pqueue->_size = 0;
}

bool pqueue_isEmpty(PriorityQueue *pqueue) {
    return (pqueue->_top == NULL);
}

void pqueue_push(PriorityQueue *pqueue, struct klinik value)
{
    PQueueNode *temp = pqueue->_top;
    PQueueNode *newNode = \
        (PQueueNode*) malloc (sizeof(PQueueNode));
    newNode->data = value;
    newNode->next = NULL;

    if (pqueue_isEmpty(pqueue)) {
        pqueue->_top = newNode;
        return;
    }

//    if (value < pqueue->_top->data) {
    if (strcmp(value -> penyakit, pqueue->_top->data->penyakit)== -1){
        newNode->next = pqueue->_top;
        pqueue->_top = newNode;
    }
    else {
        while ( temp->next != NULL && strcmp(temp->next->data, value -> penyakit)== -1 )
        temp = temp->next;
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void pqueue_pop(PriorityQueue *pqueue)
{
    if (!pqueue_isEmpty(pqueue)) {
        PQueueNode *temp = pqueue->_top;
        pqueue->_top = pqueue->_top->next;
        free(temp);
    }
}

int pqueue_top(PriorityQueue *pqueue) {
    if (!pqueue_isEmpty(pqueue))
        return pqueue->_top->data;
    else return 0;
}

int main(int argc, char const *argv[])
{
    // Buat objek PriorityQueue
    PriorityQueue myPque;

    // PENTING! Jangan lupa diinisialisasi
    pqueue_init(&myPque);

    int n, q;
    klinik pas1, pas2, pas3;

    strcpy(pas1->nama,"Budi");
    strcpy(pas1->penyakit, "flu");

    pqueue_pushe(&myPque,pas1);

//    scanf("%d", &n);
//
//    scanf("%d", &q);
//
//    if
//        scanf("%s %s", nama, penyakit);
//        pqueue_push(&myPque) ;


    // Operasi pada priority queue
//    pqueue_push(&myPque, "aa");
//    pqueue_push(&myPque, "aaa");
//    pqueue_push(&myPque, "a");

    // cetak isi pque
    while (!pqueue_isEmpty(&myPque)) {
        printf("%s %s", pqueue_top(&myPque->nama),pqueue_top(&myPque->penyakit));
        pqueue_pop(&myPque);
    }
    puts("");
    return 0;
}
