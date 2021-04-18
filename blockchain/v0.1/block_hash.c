#include "blockchain.h"

/**
 * block_hash - compute the hash of a block
 *
 * @block: pointer to the block to be hashed
 * @hash_buf: buffer in which to store the hash of @block
 *
 * Description: If @block is NULL or @hash_buf is NULL, do nothing.
 * Otherwise, compute the hash of the memory area pointed to by @block.
 *
 * Return: If @block is NULL, return NULL.
 * Otherwise, return @hash_buf.
 */
uint8_t *block_hash(
	block_t const *block, uint8_t hash_buf[SHA256_DIGEST_LENGTH])
{
	size_t len = 0;

	if (block && hash_buf)
	{
		len = sizeof(block->info) + block->data.len;
		return (sha256((int8_t const *)block, len, hash_buf));
	}
	return (NULL);
}
