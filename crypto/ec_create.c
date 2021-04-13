#include "hblk_crypto.h"

/***
 * function that returns a pointer to an EC_KEY structure, 
 * containing both the public and private keys, or NULL upon failure
 * Both the private and the public keys are generated
 * use of the secp256k1 elliptic curve to create the new pair
 */

EC_KEY *ec_create(void)
{
    EC_KEY *newkey = EC_KEY_new_by_curve_name(EC_CURVE);

    if (!newkey)
        return (NULL);

    if (EC_KEY_generate_key(newkey) != 1)
    {
        EC_KEY_free(newkey);
        return (NULL);
    }

    return (newkey);
}
