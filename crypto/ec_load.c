#include "hblk_crypto.h"

#define MAX(a, b) ((a) > (b) ? (a) : (b))

/**
 * _ec_load - load public and private keys in PEM format (subroutine)
 *
 * @folder: path of the directory from which to load the keys
 * @ifile_len: maximum input file path length
 * @key: address of an EC key pair pointer
 *
 * Description: The public and private keys will be loaded from the filenames
 * defined by the macros PUB_FILENAME and PRI_FILENAME, respectively, which
 * default to 'key_pub.pem' and 'key.pem'.
 *
 * Return: Upon failure, return NULL. Otherwise, return a pointer to the loaded
 * EC key pair.
 */
static EC_KEY *_ec_load(char const *folder, size_t ifile_len, EC_KEY **key)
{
	FILE *istream = NULL;
	char *ifile = calloc(ifile_len + 1, sizeof(*ifile));

	if (!ifile)
	{
		return (NULL);
	}
	sprintf(ifile, "%s/" PUB_FILENAME "%c", folder, '\0');
	istream = fopen(ifile, "r");
	if (!istream)
	{
		free(ifile);
		return (NULL);
	}
	if (!PEM_read_EC_PUBKEY(istream, key, NULL, NULL))
	{
		fclose(istream);
		EC_KEY_free(*key);
		free(ifile);
		return (NULL);
	}
	fclose(istream);
	sprintf(ifile, "%s/" PRI_FILENAME "%c", folder, '\0');
	istream = fopen(ifile, "r");
	if (!istream)
	{
		EC_KEY_free(*key);
		free(ifile);
		return (NULL);
	}
	if (!PEM_read_ECPrivateKey(istream, key, NULL, NULL))
	{
		fclose(istream);
		EC_KEY_free(*key);
		free(ifile);
		return (NULL);
	}
	fclose(istream);
	free(ifile);
	return (*key);
}

/**
 * ec_load - load public and private keys in PEM format
 *
 * @folder: path of the directory from which to load the keys
 *
 * Description: The public and private keys will be loaded from the filenames
 * defined by the macros PUB_FILENAME and PRI_FILENAME, respectively, which
 * default to 'key_pub.pem' and 'key.pem'.
 *
 * Return: Upon failure, return NULL. Otherwise, return a pointer to the loaded
 * EC key pair.
 */
EC_KEY *ec_load(char const *folder)
{
	size_t folder_len = 0;
	size_t pri_file_len = 0;
	size_t pub_file_len = 0;
	EC_KEY *key = NULL;

	if (!folder)
	{
		return (NULL);
	}
	folder_len = strlen(folder);
	pri_file_len = folder_len + strlen("/" PRI_FILENAME);
	pub_file_len = folder_len + strlen("/" PUB_FILENAME);
	return (_ec_load(folder, MAX(pri_file_len, pub_file_len), &key));
}
