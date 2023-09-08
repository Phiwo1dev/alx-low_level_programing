#include "hash_tables.h"

/**
 * hash_table_create - A function that creates a hash table.
 * @size: size of the array.
 *
 * Return: NULL for error
 *         Otherwise - pointer to the new hash table.
 */
hash_table_t *hash_table_create(unsigned long int size)

{
	hash_table_t *ht;
	unsigned long int h;

	ht = malloc(sizeof(hash_table_t));
	if (ht == NULL)
		return (NULL);

	ht->size = size;
	ht->array = malloc(sizeof(hash_node_t *) * size);
	if (ht->array == NULL)
		return (NULL);
	for (h = 0; h < size; h++)
		ht->array[h] = NULL;

	return (ht);
}
