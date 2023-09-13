#include "hash_tables.h"

/**
 * hash_table_print - A function that prints the key:value from ht
 * @ht: pointer to the hash table
 *
 */
void hash_table_print(const hash_table_t *ht)

{
	unsigned long int n = 0;
	hash_node_t  *bucket;
	int not_fin = 0;

	if (!ht)
		return;

	printf("{");
	for (n = 0; n < ht->size; n++)
	{
		bucket = ht->array[n];
		while (bucket)
		{
			if (not_fin)
				printf(", ");
			printf("'%s': '%s'", bucket->key, bucket->value);
			not_fin = 1;
			bucket = bucket->next;
		}
	}
	printf("}\n");
}
