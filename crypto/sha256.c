#include "hblk_crypto.h"
#include <openssl/sha.h>

/*
a function that computes the hash of a sequence of bytes

- s is the sequence of bytes to be hashed
- len is the number of bytes to hash in s
- The resulting hash is stored in digest
- function returns a pointer to digest
- If digest happens to be NULL, the function must do nothing and return NULL
*/
uint8_t *sha256(int8_t const *s, size_t len, uint8_t digest[SHA256_DIGEST_LENGTH])
{
  if (!s)
    return NULL;

  SHA256_CTX ctx;
  SHA256_Init(&ctx);
  SHA256_Update(&ctx, s, len);
  SHA256_Final(&digest, &context);

  if(!digest)
    return NULL;

  return &digest;
}  
