// Pembukaan

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

/* Struktur Node */

typedef struct snode_t {
    int data;
    struct snode_t *next;
} SListNode;

/* Struktur ADT SinglyList */

typedef struct slist_t {
    unsigned _size;
    SListNode *_head;
} SinglyList;

/* Function definition below */

void slist_init(SinglyList *list)
{
    list->_head = NULL;
    list->_size = 0;
}

bool slist_isEmpty(SinglyList *list) {
    return (list->_head == NULL);
}

void slist_pushFront(SinglyList *list, int value)
{
    SListNode *newNode = (SListNode*) malloc(sizeof(SListNode));
    if (newNode) {
        list->_size++;
        newNode->data = value;

        if (slist_isEmpty(list)) newNode->next = NULL;
        else newNode->next = list->_head;
        list->_head = newNode;
    }
}

void slist_popFront(SinglyList *list)
{
    if (!slist_isEmpty(list)) {
        SListNode *temp = list->_head;
        list->_head = list->_head->next;
        free(temp);
        list->_size--;
    }
}

void slist_pushBack(SinglyList *list, int value)
{
    SListNode *newNode = (SListNode*) malloc(sizeof(SListNode));
    if (newNode) {
        list->_size++;
        newNode->data = value;
        newNode->next = NULL;

        if (slist_isEmpty(list))
            list->_head = newNode;
        else {
            SListNode *temp = list->_head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
    }
}

void slist_popBack(SinglyList *list)
{
    if (!slist_isEmpty(list)) {
        SListNode *nextNode = list->_head->next;
        SListNode *currNode = list->_head;

        if (currNode->next == NULL) {
            free(currNode);
            list->_head = NULL;
            return;
        }

        while (nextNode->next != NULL) {
            currNode = nextNode;
            nextNode = nextNode->next;
        }
        currNode->next = NULL;
        free(nextNode);
        list->_size--;
    }
}

void slist_insertAt(SinglyList *list, int index, int value)
{
    /* Kasus apabila posisinya melebihi batas */
    if (slist_isEmpty(list) || index >= list->_size) {
        slist_pushBack(list, value);
        return;
    }
    else if (index == 0 || index < 0) {
        slist_pushFront(list, value);
        return;
    }

    SListNode *newNode = (SListNode*) malloc(sizeof(SListNode));
    if (newNode) {
        SListNode *temp = list->_head;
        int _i = 0;
        while (temp->next != NULL && _i < index-1) {
            temp = temp->next;
            _i++;
        }
        newNode->data = value;
        newNode->next = temp->next;
        temp->next = newNode;
        list->_size++;
    }
}

void slist_removeAt(SinglyList *list, int index)
{
    if (!slist_isEmpty(list)) {

        /* Kasus apabila posisinya melebihi batas */
        if (index >= list->_size) {
            slist_popBack(list);
            return;
        }
        else if (index == 0 || index < 0) {
            slist_popFront(list);
            return;
        }

        SListNode *temp = list->_head;
        int _i = 0;
        while (temp->next != NULL && _i < index-1) {
            temp = temp->next;
            _i++;
        }
        SListNode *nextTo = temp->next->next;
        free(temp->next);
        temp->next = nextTo;
        list->_size--;
    }
}

void slist_remove(SinglyList *list, int value)
{
    if (!slist_isEmpty(list)) {
        SListNode *temp, *prev;
        temp = list->_head;

        if (temp->data == value) {
            slist_popFront(list);
            return;
        }
        while (temp != NULL && temp->data != value) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL) return;
        prev->next = temp->next;
        free(temp);
        list->_size--;
    }
}

int slist_front(SinglyList *list)
{
    if (!slist_isEmpty(list)) {
        return list->_head->data;
    }
    return 0;
}

int slist_back(SinglyList *list)
{
    if (!slist_isEmpty(list)) {
        SListNode *temp = list->_head;
        while (temp->next != NULL)
            temp = temp->next;
        return temp->data;
    }
    return 0;
}

int slist_getAt(SinglyList *list, int index)
{
    if (!slist_isEmpty(list)) {
        SListNode *temp = list->_head;
        int _i = 0;
        while (temp->next != NULL && _i < index) {
            temp = temp->next;
            _i++;
        }
        return temp->data;
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    // Buat objek SinglyList
    SinglyList Cetak;
    SinglyList TTD;
    SinglyList Sampul;

    // PENTING! Jangan lupa diinisialisasi
    slist_init(&Cetak);
    slist_init(&TTD);
    slist_init(&Sampul);

    int i = 0, Query, index, value = 1,x = 0;
    char perintah[10];

    scanf("%d", &Query);
    while(i < Query)
    {
    scanf("%s %d", &perintah, &index);

    if(toupper(perintah[0] == 'C')){
        while(x<index){
            slist_pushFront(&Cetak, value);
            value++;
            x++;
        }
            x = 0;
        }else if(toupper(perintah[0] == 'T')){
            while(x<index){
                slist_pushFront(&TTD, slist_front(&Cetak));
                slist_popFront(&Cetak);
                x++;
        }
            x = 0;
        }else if(toupper(perintah[0] == 'S')){
            while(x<index){
                slist_pushFront(&Sampul, slist_front(&TTD));
                slist_popFront(&TTD);
                x++;
        }
            x = 0;
    }
        i++;
}
    printf("tumpukan 1: ");
        while (!slist_isEmpty(&Cetak)) {
        printf("%d ", slist_back(&Cetak));
        slist_popBack(&Cetak);
    }
    printf("\ntumpukan 2: ");
        while (!slist_isEmpty(&TTD)) {
        printf("%d ", slist_back(&TTD));
        slist_popBack(&TTD);
    }
    printf("\ntumpukan 3: ");
        while (!slist_isEmpty(&Sampul)) {
        printf("%d ", slist_back(&Sampul));
        slist_popBack(&Sampul);
    }
    return 0;
}
