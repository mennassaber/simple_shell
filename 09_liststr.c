#include "shell.h"

/**
 * add_new_node - adds a new node to the beginning of the list
 * @head: address of pointer to head node
 * @str: string to be stored in the node
 * @num: index used by history
 *
 * Return: address of the newly added node
 */
list_t *add_new_node(list_t **head, const char *str, int num)
{
	list_t *new_node;

	if (!head)
		return (NULL);

	new_node = malloc(sizeof(list_t));
	if (!new_node)
		return (NULL);

	_memset((void *)new_node, 0, sizeof(list_t));
	new_node->num = num;

	if (str)
	{
		new_node->str = _strdup(str);
		if (!new_node->str)
		{
			free(new_node);
			return (NULL);
		}
	}

	new_node->next = *head;
	*head = new_node;

	return (new_node);
}

/**
 * add_new_node_end - adds a new node to the end of the list
 * @head: address of pointer to head node
 * @str: string to be stored in the node
 * @num: index used by history
 *
 * Return: address of the newly added node
 */
list_t *add_new_node_end(list_t **head, const char *str, int num)
{
	list_t *new_node, *temp;

	if (!head)
		return (NULL);

	new_node = malloc(sizeof(list_t));
	if (!new_node)
		return (NULL);

	_memset((void *)new_node, 0, sizeof(list_t));
	new_node->num = num;

	if (str)
	{
		new_node->str = _strdup(str);
		if (!new_node->str)
		{
			free(new_node);
			return (NULL);
		}
	}

	if (*head)
	{
		temp = *head;
		while (temp->next)
			temp = temp->next;
		temp->next = new_node;
	}
	else
		*head = new_node;

	return (new_node);
}

/**
 * print_list_strings - prints only the strings in the list
 * @h: pointer to the first node
 *
 * Return: number of nodes in the list
 */
size_t print_list_strings(const list_t *h)
{
	size_t count = 0;

	while (h)
	{
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		count++;
	}

	return (count);
}

/**
 * delete_node_at_index - deletes a node at a given index
 * @head: address of pointer to the first node
 * @index: index of the node to be deleted
 *
 * Return: 1 on success, 0 on failure
 */
int delete_node_at_index(list_t **head, unsigned int index)
{
	list_t *current, *prev = NULL;
	unsigned int i = 0;

	if (!head || !*head)
		return (0);

	current = *head;

	if (index == 0)
	{
		*head = current->next;
		free(current->str);
		free(current);
		return (1);
	}

	while (current && i < index)
	{
#include "shell.h"

/**
 * add_new_node - adds a new node to the beginning of the list
 * @head: address of pointer to head node
 * @str: string to be stored in the node
 * @num: index used by history
 *
 * Return: address of the newly added node
 */
list_t *add_new_node(list_t **head, const char *str, int num)
{
	list_t *new_node;

	if (!head)
		return (NULL);

	new_node = malloc(sizeof(list_t));
	if (!new_node)
		return (NULL);

	_memset((void *)new_node, 0, sizeof(list_t));
	new_node->num = num;

	if (str)
	{
		new_node->str = _strdup(str);
		if (!new_node->str)
		{
			free(new_node);
			return (NULL);
		}
	}

	new_node->next = *head;
	*head = new_node;

	return (new_node);
}

/**
 * add_new_node_end - adds a new node to the end of the list
 * @head: address of pointer to head node
 * @str: string to be stored in the node
 * @num: index used by history
 *
 * Return: address of the newly added node
 */
list_t *add_new_node_end(list_t **head, const char *str, int num)
{
	list_t *new_node, *temp;

	if (!head)
OBOBOB		return (NULL);

	new_node = malloc(sizeof(list_t));
	if (!new_node)
OBOBOB		return (NULL);

	_memset((void *)new_node, 0, sizeof(list_t));
	new_node->num = num;
OBOBOB
	if (str)
	{
		new_node->str = _strdup(str);
		if (!new_node->str)
		{
			free(new_node);
			return (NULL);
		}
	}

	if (*head)
	{
		temp = *head;
		while (temp->next)
			temp = temp->next;
		temp->next = new_node;
	}
	else
		*head = new_node;

	return (new_node);
}

/**
 * print_list_strings - prints only the strings in the list
 * @h: pointer to the first node
 *
 * Return: number of nodes in the list
 */
size_t print_list_strings(const list_t *h)
{
	size_t count = 0;

	while (h)
	{
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		count++;
	}

	return (count);
}

/**
 * delete_node_at_index - deletes a node at a given index
 * @head: address of pointer to the first node
 * @index: index of the node to be deleted
 *
 * Return: 1 on success, 0 on failure
 */
int delete_node_at_index(list_t **head, unsigned int index)
{
	list_t *current, *prev = NULL;
	unsigned int i = 0;

	if (!head || !*head)
OAOAOA		return (0);

	current = *head;
OAOAOA
	if (index == 0)
	{
		*head = current->next;
		free(current->str);
		free(current);
		return (1);
	}

	while (current && i < index)
	{
		prev = current;
		current = current->next;
		i++;
	}

	if (i == index && current)
	{
		prev->next = current->next;
		free(current->str);
		free(current);
		return (1);
	}

	return (0);
}

/**
 * free_list - frees all nodes in the list
 * @head_ptr: address of pointer to the first node
 *
 * Return: void
 */
void free_list(list_t **head_ptr)
{
	list_t *current, *temp;

	if (!head_ptr || !*head_ptr)
		return;

	current = *head_ptr;

	while (current)
	{
		temp = current->next;
		free(current->str);
		free(current);
		current = temp;
	}

	*head_ptr = NULL;
}

