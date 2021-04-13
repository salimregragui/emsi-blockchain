#include "hblk_crypto.h"

/**
 * ec_from_pub - create an EC_KEY structure given a public key
 *
 * @pub: address from which to read the public key
 *
 * Description: The private key of the created EC_KEY may be uninitialized.
 *
 * Return: If an error occurs, return NULL.
 * Otherwise, return a pointer to the created EC_KEY structure.
 */

EC_KEY *ec_from_pub(uint8_t const pub[EC_PUB_LEN])
{
const EC_GROUP *gp = NULL;
EC_POINT *pt = NULL;
EC_KEY *key = NULL;

if (!pub)
return (NULL);

key = EC_KEY_new_by_curve_name(EC_CURVE);

if (!key)
return (NULL);

gp = EC_KEY_get0_group(key);

if (!gp)
{
EC_KEY_free(key);
return (NULL);
}
pt = EC_POINT_new(gp);

if (!pt)
{
EC_KEY_free(key);
return (NULL);
}

if (!EC_POINT_oct2point(
gp, pt, pub, EC_PUB_LEN, NULL) || !EC_KEY_set_public_key(key, pt))
{
EC_KEY_free(key);
EC_POINT_free(pt);
return (NULL);
}
EC_POINT_free(pt);

return (key);
}
