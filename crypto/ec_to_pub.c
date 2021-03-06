#include "hblk_crypto.h"

/**
 * ec_to_pub - extract the public key from an EC_KEY structure
 *
 * @key: pointer to the EC_KEY structure from which to extract the public key
 * @pub: address at which to store the extracted public key
 *
 * Description: If @key is NULL, nothing will be done.
 *
 * Return: If @key is NULL or an error occurs, return NULL.
 * Otherwise, return @pub.* function that extracts the public
 *key from an EC_KEY
 *opaque structure
 *@key: is a pointer to the EC_KEY structure to retrieve
 *the public key from. If it is NULL, your function must do nothing
 *and fail.
 *@pub is the address at which to store the extracted
 *public key (The key shall not be compressed)
 *Description : if @key is n
 */

uint8_t *ec_to_pub(EC_KEY const *key, uint8_t pub[EC_PUB_LEN])
{
const EC_GROUP *gp = NULL;
const EC_POINT *pt = NULL;

if (!key)
return (NULL);

gp = EC_KEY_get0_group(key);
pt = EC_KEY_get0_public_key(key);

if (!gp || !pt)
return (NULL);

if (!EC_POINT_point2oct(
gp, pt, EC_KEY_get_conv_form(key),
pub, EC_PUB_LEN, NULL))
return (NULL);

return (pub);
}
