#ifndef _NGX_RBTREE_H_INCLUDED_
#define _NGX_RBTREE_H_INCLUDED_

#include <stdint.h>

typedef struct swRbtree_node_s swRbtree_node;

struct swRbtree_node_s
{
	uint32_t key;
	void *value;
	swRbtree_node *left;
	swRbtree_node *right;
	swRbtree_node *parent;
	char color;
};

typedef struct swRbtree_s swRbtree;

struct swRbtree_s
{
	swRbtree_node *root;
	swRbtree_node *sentinel;
};

swRbtree* swRbtree_new();
void swRbtree_free(swRbtree*);
void swRbtree_insert(swRbtree *tree, uint32_t key, void *value);
void swRbtree_delete(swRbtree *tree, uint32_t key);
void *swRbtree_find(swRbtree *tree, uint32_t key);

#define swRbtree_red(node)               ((node)->color = 1)
#define swRbtree_black(node)             ((node)->color = 0)
#define swRbtree_is_red(node)            ((node)->color)
#define swRbtree_is_black(node)          (!swRbtree_is_red(node))
#define swRbtree_copy_color(n1, n2)      (n1->color = n2->color)

#define swRbtree_sentinel_init(node)      swRbtree_black(node)

static inline swRbtree_node *swRbtree_min(swRbtree_node *node, swRbtree_node *sentinel)
{
	while (node->left != sentinel)
	{
		node = node->left;
	}
	return node;
}

#endif
