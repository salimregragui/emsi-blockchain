#include "hblk_crypto.h"

/**
 * ec_sign - sign a message using an EC private key
 *
 * @key: pointer to the EC key pair containing the private key to be used
 * @msg: message to be signed
 * @msglen: length of @message
 * @sig: address at which to store the signature
 *
 * Return: If key, msg, or sig is NULL, or if an error occurs, return NULL.
 * Otherwise, return a pointer to the buffer containing the signature.
 */
uint8_t *ec_sign(
	EC_KEY const *key, uint8_t const *msg, size_t msglen, sig_t *sig)
{
	unsigned int len = 0;

	if (key && msg && msglen)
	{
		memset(sig->sig, 0, sizeof(sig->sig) / sizeof(*sig->sig));
		if (ECDSA_sign(0, msg, msglen, sig->sig, &len, (EC_KEY *)key))
		{
			sig->len = len;
			return (sig->sig);
		}
		sig->len = 0;
	}
	return (NULL);
}
