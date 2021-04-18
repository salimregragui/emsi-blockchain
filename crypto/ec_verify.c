
#include "hblk_crypto.h"

/**
 * ec_verify - verify a signature using an EC public key
 *
 * @key: pointer to the EC key pair containing the public key to be used
 * @msg: message to be signed
 * @msglen: length of @message
 * @sig: address at which to store the signature
 *
 * Return: If key, msg, or sig is NULL, or if verification fails, return 0.
 * Otherwise, return 1.
 */
int ec_verify(
	EC_KEY const *key, uint8_t const *msg, size_t msglen, sig_t const *sig)
{
	if (key && msg && sig)
	{
		return (ECDSA_verify(
			0, msg, msglen, sig->sig, sig->len, (EC_KEY *)key) == 1);
	}
	return (0);
}
