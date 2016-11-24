#include "list.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

void LLcatenate(list_t * L1, list_t * L2) {
    if (L2->head == NULL) {
        assert(L2->tail == NULL);
    } else if (L1->head == NULL) {
        assert(L1->tail == NULL);
        //L1->head = L2->head;
        //L1->tail = L2->tail;
        *L1 = *L2;
    } else {
        L1->tail->next = L2->head;
        L1->tail= L2->tail;
    }
    free(L2);
}

void list_sort(list_t* intlist){
    if( intlist-> head == intlist -> tail){
        return;
    }
    int pivotNumber = intlist->head->val;
    element_t* pivot  = intlist->head;
    intlist->head = intlist->head->next;
    element_t* current = intlist->head;
    element_t* next;

    list_t* first = list_create();
    list_t* second =list_create();

    while(current != NULL){
        next = current->next;
        current->next = NULL;
        if( current->val <= pivotNumber){
            list_append(first, current->val);
        }
        else if(current->val > pivotNumber){
            list_append(second, current->val);
        }
        current = next;
    }

    intlist->head = NULL;
    intlist->tail = NULL;

    list_sort(first);
    list_sort(second);

    LLcatenate(intlist, first);
    list_append(intlist, pivot->val);
    LLcatenate(intlist, second);


}
