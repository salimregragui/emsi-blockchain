#include "hblk_crypto.h"

#define MAX(a, b) ((a) > (b) ? (a) : (b))

/**
 * _ec_save - save public and private keys in PEM format (subroutine)
 *
 * @key: pointer to the EC key pair to be saved
 * @folder: path of the directory in which to save the keys
 * @ofile_len: maximum output file path length
 *
 * Return: Upon failure, return 0. Otherwise, return 1.
 */
static int _ec_save(EC_KEY *key, char const *folder, size_t ofile_len)
{
	FILE *ostream = NULL;
	char *ofile = calloc(ofile_len + 1, sizeof(*ofile));

	if (!ofile)
	{
		return (0);
	}
	sprintf(ofile, "%s/" PRI_FILENAME "%c", folder, '\0');
	ostream = fopen(ofile, "w");
	if (!ostream)
	{
		free(ofile);
		return (0);
	}
	if (!PEM_write_ECPrivateKey(ostream, key, NULL, NULL, 0, NULL, NULL))
	{
		fclose(ostream);
		free(ofile);
		return (0);
	}
	fclose(ostream);
	sprintf(ofile, "%s/" PUB_FILENAME "%c", folder, '\0');
	ostream = fopen(ofile, "w");
	if (!ostream)
	{
		free(ofile);
		return (0);
	}
	if (!PEM_write_EC_PUBKEY(ostream, key))
	{
		fclose(ostream);
		free(ofile);
		return (0);
	}
	fclose(ostream);
	free(ofile);
	return (1);
}

/**
 * ec_save - save public and private keys in PEM format
 *
 * @key: pointer to the EC key pair to be saved
 * @folder: path of the directory in which to save the keys
 *
 * Description: If the directory @folder does not exist, it will be created.
 * The public and private keys will be saved to the filenames defined by the
 * macros PUB_FILENAME and PRI_FILENAME, respectively, which default to
 * 'key_pub.pem' and 'key.pem'.
 *
 * Return: Upon failure, return 0. Otherwise, return 1.
 */
int ec_save(EC_KEY *key, char const *folder)
{
	size_t folder_len = 0;
	size_t pri_file_len = 0;
	size_t pub_file_len = 0;

	if (!key || !folder)
	{
		return (0);
	}
	mkdir(folder, S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH);
	folder_len = strlen(folder);
	pri_file_len = folder_len + strlen("/" PRI_FILENAME);
	pub_file_len = folder_len + strlen("/" PUB_FILENAME);
	return (_ec_save(key, folder, MAX(pri_file_len, pub_file_len)));
}
