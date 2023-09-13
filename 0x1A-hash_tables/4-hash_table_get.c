#include "hash_tables.h"

/**
 * hash_table_get - A function to retrieve value associeted with key
 * @ht: Pointer to the hash table
 * @key: Key to retrive value
 *
 * Return: value or NULL if key does not exit.
 */

char *hash_table_get(const hash_table_t *ht, const char *key)

{
	unsigned long int idx = 0;
	hash_node_t  *b;

	if (!ht || !key || !*key)
		return (NULL);

	idx = key_index((const unsigned char *)key, ht->size);
	b = ht->array[idx];

	while (b)
	{
		if (!strcmp(key, b->key))
			return (b->value);
		b = b->next;
	}
	return (NULL);
}
