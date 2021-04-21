#include <stdlib.h>
#include <stdio.h>

#include "hblk_crypto.h"

/**
 * ec_load - load an EC key pair from the disk
 * @folder: path to folder from which to load the keys
 *
 * Return: pointer to created EC key pair, NULL on error
 */
EC_KEY *ec_load(char const *folder)
{
FILE *fp;
EC_KEY *key;
char path[BUFSIZ];
if (!folder)
return (NULL);
sprintf(path, "%s/%s", folder, PUB_FILENAME);
fp = fopen(path, "r");
if (!PEM_read_EC_PUBKEY(fp, &key, NULL, NULL))
return (NULL);
fclose(fp);
sprintf(path, "%s/%s", folder, PRI_FILENAME);
fp = fopen(path, "r");
if (!PEM_read_ECPrivateKey(fp, &key, NULL, NULL))
return (NULL);
fclose(fp);
return (key);
}
