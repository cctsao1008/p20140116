/*********************************************************************
 * Platform/modules/sll.h
 *
 *   Copyright (C) 2014  DRPM Development Team. All rights reserved.
 *   Author: TSAO, CHIA-CHENG <chiacheng.tsao@gmail.com>
 *
 *   GENERAL DESCRIPTION
 *      This module performs Singly-Linked Lists (SLL) functionality.
 *
 *********************************************************************/
#ifndef SLL_H_
#define SLL_H_
#include "platform.h"

/* Struct for linked list nodes. */
typedef struct _sll_node
{
    void* data;
    struct _sll_node* next;
}sll_node;

/* Struct for link-list data structure */
typedef struct _sll
{
    uint16_t size;
    
    /* The two nodes below define the two nodes
     * which must be known for a standard linked list */
    sll_node* head;
    sll_node* tail;
}sll;

typedef void (*sll_callback)(sll* list, sll_node *node);

/* list_initialize
 * Return type : void 
 * 
 * Description : Initializes the linked list of type linkedList.
 *  All linked lists must be initialized before any other operations
 *  can be ran on them. The destroy argument is put here as a way to
 *  free allocated data when list_destroy is used.*/
sll*
sll_create(void);

/* list_destroy
 * Return type : void
 * 
 * Description : Will destroy a list which is passed to it in the
 *  form of a pointer to a linkedList pointer. When a list has been
 *  destroyed, no more operations may be carried out unless the
 *  list_initialize function is called again. The list_destroy
 *  function removes all nodes from the list, and calls the
 *  function passed in as destroy during the list_initialize, once
 *  for every node during the destroy process. Destroy will not
 *  be performed if the destroy function was passed in as NULL.
 *
 * Runtime : O(n)
 */
void
sll_destroy(sll* list);

/* list_add_node
 * Return type : int - 1 = success,
 *                     0 = failure.
 * 
 * Description : Adds an node to the list (passed as "list")
 *  AFTER the node (passed as "node"). If "node" is NULL,
 *  then the new node will be added as the head of the list.
 *  The new node will contain a pointer to "data". This means the
 *  memory referenced by "data" needs to remain valid for the lifetime
 *  of the node in the list. It is the responsibility of the developer
 *  to manage this storage. 
 * 
 * Runtime : O(1),  O(1) means that the worst case run time is constant.
 */
uint16_t
sll_insert_node(sll* list, sll_node* node, const void* data);

/* list_del_node
 * Return type : int - 1 = success,
 *                     0 = failure.
 *
 * Description : Removes the node form the list (passed as "list")
 *  AFTER the node (passed as "node"). If "node is NULL, then
 *  the node which represents the head of the list will be removed.
 *  When this function returns, "data" will still point to the data which
 *  was stored in the node which has been removed. It is the responsibility
 *  of the programmer to manage this storage. 
 *
 * Runtime : O(1),  O(1) means that the worst case run time is constant.
 */
uint16_t
sll_delete_node(sll* list, sll_node* node, void** data);

void
sll_foreach(sll* list, sll_callback cbfun);

void
sll_test(void);

#endif /* SLL_H_ */
