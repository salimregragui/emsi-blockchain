#include "hblk_crypto.h"

/**
 * ec_load - loads an existing EC key pair on the disk
 *
 * @folder: path to the folder from which to load the keys
 *
 * Return: pointer to EC key pair, or NULL on failure
 */
EC_KEY *ec_load(char const *folder)
{
	EC_KEY *key = NULL;
	char buffer[BUFSIZ];
	FILE *fp;

	if (folder == NULL)
		return (NULL);

	sprintf(buffer, "%s/%s", folder, PUB_FILENAME);
	fp = fopen(buffer, "r");
	if (!fp)
		return (NULL);
	if (!PEM_read_EC_PUBKEY(fp, &key, NULL, NULL))
	{
		fclose(fp);
		return (key);
	}
	sprintf(buffer, "%s/%s", folder, PRI_FILENAME);
	fp = fopen(buffer, "r");
	if (fp == NULL)
		return (NULL);
	if (!PEM_read_ECPrivateKey(fp, &key, NULL, NULL))
	{
		fclose(fp);
		return (key);
	}

	fclose(fp);
	return (key);
}
