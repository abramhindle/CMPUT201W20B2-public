
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

enum atype {
   INT,
   LONG,
   DOUBLE,
   FLOAT,
};
union anything {
int anInt;
long aLong;
double aDouble;
float aFloat;
};
struct linkedList;
struct linkedList { 
    enum atype type;
    union anything value;
    struct linkedList *next; 
};

struct linkedList * allocLinkedList( enum atype type, 
                                     union anything value, 
                                     struct linkedList * next) {
    struct linkedList * node = malloc(sizeof(*node));
    node->type  = type;
    node->value = value;
    node->next  = next;
    return node;
}

void freeLinkedList( struct linkedList * list) {
    if (list == NULL ){
       return;
    }
    freeLinkedList( list->next );
    free( list );
}

void freeLinkedListIterative( struct linkedList * list) {
    while( list != NULL ) {
        struct linkedList * freeMe = list;
        list = list->next;
        free(freeMe);
    }
}


int main() {
    union anything v = {.aDouble = 1.2 };
    struct linkedList * tail = allocLinkedList( DOUBLE, v, NULL);
    struct linkedList * head = tail;
    for (int i = 0 ; i < 10; i++) {
        v.anInt = i*2;
        head = allocLinkedList( INT, v, head );
    }
    struct linkedList * iter = head;
    while(iter!=NULL) {
        if (iter->type == INT) {
            printf("Print node value: %5d next: %p\n", iter->value.anInt, (void*)iter->next);
        } else {
            printf("Print node type:  %5d next: %p\n", iter->type, (void*)iter->next);
        }
        iter = iter->next;
        // iter->next ===> iter
    }    
    // freeLinkedList( head );
    // freeLinkedListIterative( head );
    return 0;
}
