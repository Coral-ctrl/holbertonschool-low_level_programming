#include "hash_tables.h"
#include <string.h>
#include <stdlib.h>

/**
 * create_node - creates a new hash table node
 * @key: the key to add (must be non-empty)
 * @value: the value associated with the key
 *
 * Return: pointer to the new node, or NULL on failure
 */
hash_node_t *create_node(const char *key, const char *value)
{
	/* Allocate memory for the node structure */
	hash_node_t *node = malloc(sizeof(hash_node_t));

	if (node == NULL)
		return (NULL);

	/* Duplicate the key so the hash table owns its own copy */
	node->key = strdup(key);
	if (node->key == NULL)
	{
		free(node);
		return (NULL);
	}

	/* Duplicate the value separately */
	node->value = strdup(value);
	if (node->value == NULL)
	{
		free(node->key);
		free(node);
		return (NULL);
	}

	/* New nodes always start with next = NULL */
	node->next = NULL;
	return (node);
}

/**
 * find_node - searches for a key in a linked list
 * @head: pointer to the head of the list
 * @key: the key to search for
 *
 * Return: pointer to the matching node, or NULL if not found
 */
hash_node_t *find_node(hash_node_t *head, const char *key)
{
	/* Traverse the linked list */
	while (head != NULL)
	{
		/*
		 * strcmp returns 0 when two strings match exactly.
		 * If keys match, we have found the correct node.
		 */
		if (strcmp(head->key, key) == 0)
			return (head);
		/* Move to next node */
		head = head->next;
	}
	return (NULL);
}

/**
 * update_node - updates the value of an existing hash node
 * @node: the node whose value is to be updated
 * @value: the new value to assign (will be duplicated)
 *
 * Return: 1 on success, 0 on failure
 */
int update_node(hash_node_t *node, const char *value)
{
	/*
	 * Duplicate the new value first.
	 * We do this BEFORE freeing the old one to avoid losing data
	 * if strdup fails.
	 */
	char *new_value = strdup(value);

	if (new_value == NULL)
		return (0);

	/* Free old value and replace it with the new copy */
	free(node->value);
	node->value = new_value;
	return (1);
}

/**
 * hash_table_set - adds an element to the hash table
 * @ht: the hash table you want to add or update the key/value to
 * @key: the key (non-empty string)
 * @value: the value associated with the key (must be duplicated)
 *
 * Return: 1 on success, 0 otherwise
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	hash_node_t *node, *new;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	/* Compute array index using hash_djb2 % size */
	index = key_index((const unsigned char *)key, ht->size);

	/* Check if key already exists in this bucket */
	node = find_node(ht->array[index], key);

	if (node != NULL)
	{
		/* Key found -> update its value */
		return (update_node(node, value));
	}

	/* Key not found -> create a new node */
	new = create_node(key, value);
	if (new == NULL)
		return (0);

	/* Insert new node at beginning (collision handling) */
	new->next = ht->array[index];
	ht->array[index] = new;

	return (1);
}
