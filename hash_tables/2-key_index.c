#include "hash_tables.h"
/**
 * key_index - gives you the index of a key
 * @key: the key
 * @size: the size of the array of the hash table
 *
 * Return: the index at which the key/value pair should be stored in the
 *         array of the hash table
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	/**
	 * Hash the key using hash_djb2()
	 * Use modulo (% size) to map the huge hash number into array range
	 * Return that index
	 */
	return (hash_djb2(key) % size);
}
