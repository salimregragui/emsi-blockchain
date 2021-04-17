#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

#include "hblk_crypto.h"


EC_KEY *ec_load(char const *folder){
	
	EC_KEY *key;
	char pub_path[PATH_MAX];
	char pv_path[PATH_MAX];
	FILE *pubf;
	FILE *pvf;
	
	if(!opendir(folder))
	{
		fprintf(stderr,"%s","Unknown directory");	
	}
	snprintf(pub_path,PATH_MAX,"%s/%s",folder,PUB_FILENAME);
	snprintf(pv_path,PATH_MAX,"%s/%s",folder,PRI_FILENAME);

	pubf = fopen(pub_path,"w+");
	pvf = fopen(pv_path,"w+");

	if(PEM_read_EC_PUBKEY(pubf,&key,NULL,NULL)==0){
		fclose(pubf);
		fclose(pvf);
		return NULL;
	}
	if(PEM_read_ECPrivateKey(pvf,&key,NULL,NULL) == 0){
		fclose(pubf);
		fclose(pvf);
		return NULL;
	}
	fclose(pubf);
	fclose(pvf);
	return key;
}
