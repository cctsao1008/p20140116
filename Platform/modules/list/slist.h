//
//  slist.h
//  SLinkList
//
//  Created by hailan on 8/14/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef SLINK_H_
#define SLINK_H_
#include "platform.h"

typedef int elem_type;


/* single link node structure */

typedef struct slink_node_t {
    void *data;
    struct slink_node_t *next;
} slink_node;

/* single link list structure */

typedef struct slink_list_t {
    slink_node *head;
    slink_node *tail;
    unsigned int length;
} slink_list;

typedef void (* slink_list_callback)(slink_node *node);

/* single link node operation */

slink_node* slink_node_make(void *data);
void slink_node_free(slink_node *node);
void slink_node_visit(slink_node *node);

/* single link list operation */

slink_list *slink_list_create(void);
void slink_list_destroy(slink_list *list);
void slink_list_append(slink_list *list, void *data);
void slink_list_delete(slink_list *list, unsigned int index);
void slink_list_foreach(slink_list *list, slink_list_callback callback);
void slink_list_traverse(slink_list *list);
void slink_list_reverse(slink_list *list);
slink_node *slink_list_intersection(slink_list *list1, slink_list *list2);

/* test single link list */
void slink_list_test_main(void);

#endif /* SLINK_H_ */
