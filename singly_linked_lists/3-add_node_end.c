#include "lists.h"
#include <stdlib.h>
#include <string.h>

/**
 * add_node_end - adds a new node at the end of a list_t list
 * @head: pointer to pointer to the first node
 * @str: string to add
 *
 * Return: address of the new node, or NULL if it failed
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new, *last;
	unsigned int len = 0;

	if (str == NULL)
		return (NULL);

	new = malloc(sizeof(list_t));
	if (new == NULL)
		return (NULL);

	new->str = strdup(str);
	if (new->str == NULL)
	{
		free(new);
		return (NULL);
	}

	while (str[len] != '\0')
		len++;

	new->len = len;
	new->next = NULL;

	/* if the list is empty, new node becomes the head */
	if (*head == NULL)
	{
		*head = new;
		return (new);
	}

	/* traverse to the last node */
	last = *head;
	while (last->next != NULL)
		last = last->next;

	/* append the new node at the end */
	last->next = new;

	return (new);
}
