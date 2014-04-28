/*********************************************************************
 * Platform/modules/sll.c
 *
 *   Copyright (C) 2014  DRPM Development Team. All rights reserved.
 *   Author: TSAO, CHIA-CHENG <chiacheng.tsao@gmail.com>
 *
 *   GENERAL DESCRIPTION
 *      This module performs Singly-Linked Lists (SLL) functionality.
 *
 *********************************************************************/
#include "sll.h"

sll*
sll_create(void)
{
    sll *list = (sll*)malloc(sizeof(sll));

    if(NULL == list)
    {
        list = NULL;
        goto done;
    }

    list->size = 0;
    list->head = NULL;
    list->tail = NULL;

done :
    return list;
}

void 
sll_destroy(sll* list)
{
    if(NULL == list)
        return;

    /* Loop to remove each node from the list */
    while (list->size > 0)
    {
        sll_delete_node(list, NULL, NULL);
    }

    /* No more operations can be performed on this list now. As a
     * precaution, the structure should be cleared anyway. */
    memset(list, 0, sizeof(sll));
}

uint16_t 
sll_insert_node(sll* list, sll_node* node, const void* data)
{
    sll_node *new_node;

    if(NULL == list)
        return false;
    
    /* Attempt to allocate the memory for the new node */    
    if ((new_node = (sll_node *)malloc(sizeof(sll_node))) == NULL)
    {
        //printf("sll_add_node : failed to create new node\n");
        return false;
    }
    
    new_node->data = (void*)data;
    
    if (node == NULL)
    {
        /* Add the new node at the HEAD of the list */
        if (list->size == 0)
        {
            list->tail = new_node;
        }
        
        new_node->next = list->head;
        list->head=new_node;
    }    
    else
    {
        if (node->next == NULL)
        {
            list->tail = new_node;
        }
    
        new_node->next = node->next;
        node->next = new_node;
    }
    
    list->size++;
    return true;
}

uint16_t
sll_delete_node(sll* list, sll_node* node, void** data)
{
    sll_node* old_node;

    if(NULL == list)
        return false;

    /* Can't remove from an empty list */
    if ( list->size == 0 )
    {
        //printf("sll_del_node : cannot remove node from empty list.\n");
        return false;
    }

    /* Continue to remove node from list */
    if ( node == NULL )
    {
        /* Remove node at head of list */
        if(NULL != data)
            *data = list->head->data;

        old_node = list->head;
        list->head = list->head->next;

        if ( list->size == 1 )
        {
            list->tail = NULL;
        }
    }
    else
    {
        /* Remove node from anywhere else in the list */
        if ( node->next == NULL )
        {
            /*If there is no node after the current one, fail */
            //printf("sll_del_node : no node after tail\n");
            return false;
        }

        if(NULL != data)
            *data = node->data;

        old_node = node->next;
        node->next = node->next->next;

        if ( node->next == NULL )
        {
            /* Setting new tail of list */
            list->tail = node;
        }
    }
    
    /* Free the storage which was allocated in the list for old node. */
    free(old_node);
    
    list->size--;

    return true;
}

void
sll_print_data(sll* list, sll_node* node)
{

    printf("0x%04X %s\n", node, ((char*)(node->data)));
}

void
sll_foreach(sll* list, sll_callback callback)
{
    uint16_t i = 0;
    sll_node *node = list->head;

    if(NULL == list)
        return;

    for( i = 0; i < (list->size) ; i++) {
        callback(list, node);
        node = node->next;
    }
}

#if 0
void
sll_test(void)
{
    sll* list = NULL;

    list = sll_create();

    if(NULL == list)
    {
        printf("no more heap!\n");
        return;
    }

    printf("insert a node.\n");
    sll_insert_node(list, NULL, "node 1");
    sll_foreach(list, sll_print_data);

    printf("insert a node.\n");
    sll_insert_node(list, NULL, "node 2");
    sll_foreach(list, sll_print_data);

    printf("insert a node.\n");
    sll_insert_node(list, NULL, "node 3");
    sll_foreach(list, sll_print_data);

    while(0 != (list->size))
    {
    	printf("delete a node.\n");
        sll_delete_node(list, NULL, NULL);
        sll_foreach(list, sll_print_data);
    }
    
    printf("no more node!\n");
    
    free(list);
}
#endif

