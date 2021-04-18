#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "hblk_crypto.h"

/**
 * ec_verify - verifies the signature of a given set of bytes,
 * using a given EC_KEY public key
 * @key: points to the EC_KEY structure containing the public key
 * to be used to verify the signature
 * @msg: points to the characters to be signed
 * @msglen: length of msg
 * @sig: points to the signature to be checked
 * Return: 1 if the signature is valid, and 0 otherwise
 */
int ec_verify(EC_KEY const *key, uint8_t const *msg,
	      size_t msglen, sig_t const *sig)
{
if (key == NULL)
return (0);
if (!EC_KEY_check_key(key))
return (0);
if (msg == NULL)
return (0);
if (sig == NULL)
return (0);
if (ECDSA_verify(0, msg, msglen,
		 sig->sig, sig->len, (EC_KEY *)key) != 1)
return (0);
return (1);
}
