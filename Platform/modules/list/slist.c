//
//  slist.c
//  SLinkList
//
//  Created by hailan on 8/14/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//
#include "slist.h"


/* single link node operation */

slink_node *
slink_node_make(void *data) {
    slink_node *node = (slink_node *)malloc(sizeof(slink_node));
    //assert(node != NULL);
    node->data = data;
    node->next = NULL;
    return node;
}

void
slink_node_free(slink_node *node) {
    free(node);
    node = NULL;
}

void
slink_node_visit(slink_node *node) {
    //assert(node != NULL);
    printf("[0x%04X | %d]\n", node, *((uint16_t*)(node->data)));
}

/* single link list operation */

slink_list *
slink_list_create(void) {
    slink_list *list = (slink_list *)malloc(sizeof(slink_list));
    //assert(list != NULL);
    list->head = NULL;
    list->tail = NULL;
    list->length = 0;
    return list;
}

void
slink_list_destroy(slink_list *list) {
    slink_node *current = list->head->next;

    while (current != list->tail) {
        slink_node *next = current->next;
        slink_node_free(current);
        current = next;
    }
    slink_node_free(list->head);
    slink_node_free(list->tail);
    free(list);
    list = NULL;
}

void
slink_list_append(slink_list *list, void *data) {
    slink_node *node = slink_node_make(data);

    if(NULL == list->head)
    {
        //node->next = node;
        list->head = node;
        list->tail = node;
    }
    else
    {
        node->next = list->head;
        list->head = node;
    }

    list->length += 1;
}

void
slink_list_delete(slink_list *list, unsigned int index) {
    //assert(index >=0 && index < list->length);
    slink_node *current = list->head->next;
    slink_node *pre = list->head;
    unsigned int i = 0;
    while (current->next == NULL) {
        if (i == index) {
            break;
        }
        pre = current;
        current = current->next;
        i++;
    }
    pre->next = current->next;
    slink_node_free(current);
    list->length -= 1;
}

void
slink_list_foreach(slink_list *list, slink_list_callback callback) {
    uint16_t i = 0;
    slink_node *current = list->head;

    for( i = 0; i < list->length ; i++) {
        callback(current);
        current = current->next;
    }
}

#if 0
void
slink_list_traverse(slink_list *list) {
    printf("The fields of list \n0x%04X\n", list);
    slink_list_foreach(list, slink_node_visit);
}

void
slink_list_reverse(slink_list *list) {
    slink_node *node = list->head;
    slink_node *pre = NULL;
    slink_node *current = list->head;
    slink_node *next = current->next;
    while (current != NULL) {
        current->next = pre;
        pre = current;
        current = next;
        next = (next==NULL ? NULL : next->next);
    }

    list->head = list->tail;
    list->tail = node;
}

slink_node *
slink_list_intersection(slink_list *list1, slink_list *list2) {
    slink_node *current1 = list1->head->next;
    while (current1 != list1->tail) {
        
        slink_node *current2 = list2->head->next;
        while (current2 != list2->tail) {
            if (current2 == current1) {
                return current1;
            }
            current2 = current2->next;
        }
        
        current1 = current1->next;
    }
    return NULL;
}

/* single link list test */

void
slink_list_print(slink_list *list) {
    slink_node *current = list->head->next;
    printf("single link list \n0x%04X\n", list);
    printf("length %d\n", list->length);
    printf("head [%x|%d]->\n", list->head, list->head->data);
    while (current != list->tail) {
        printf("[%x|%d]->\n", current, current->data);
        current = current->next;
    }
    printf("tail [%x|%d]\n", list->tail, list->tail->data);
}

void
slink_list_test_main(void) {
    slink_list *list = slink_list_create();
    slink_list_print(list);
    
    slink_list_append(list, 12);
    slink_list_append(list, 13);
    slink_list_append(list, 14);
    slink_list_print(list);
    
    slink_list_delete(list, 2);
    slink_list_print(list);
    
    slink_list_traverse(list);
    
    slink_list_reverse(list);
    slink_list_print(list);
    
    slink_list_destroy(list);
}
#endif

