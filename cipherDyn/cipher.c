#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "caesar.h"
#include "rot13.h"


#define CEASAR_SHIFT  3

int main(void)
{

	char in[100] = "the QUICK brown FOX jumps over THE lazy DOG";

	char encrypted[100];
	char decrypted[100];

	printf("Ceasar cipher (shift %d) :\n", CEASAR_SHIFT);

	void* handle;
	void* handle1;


	void (*encryptCeasar)(const char*, char*, int_fast16_t);
	void (*decryptCeasar)(const char*, char*, int_fast16_t);
	char error;
	handle = dlopen("libcaesar12.so",RTLD_NOW|RTLD_GLOBAL);
	if(handle == NULL)
	{
		fputs(dlerror(),stderr);
		exit(1);
	}

	encryptCeasar = dlsym(handle, "encryptCeasar");

	if((error = dlerror())!= NULL)
	{
		fputs(error, stderr);
		exit(1);
	}
	(*encryptCeasar)(in, encrypted, CEASAR_SHIFT);
	printf("Original: %s\nencrypted: %s\n", in, encrypted);
	//decryptCeasar(encrypted, decrypted, CEASAR_SHIFT);
	decryptCeasar = dlsym(handle, "decryptCeasar");
	(*decryptCeasar)(encrypted, decrypted, CEASAR_SHIFT);
	if((error = dlerror())!= NULL)
		{
			fputs(error, stderr);
			exit(1);
		}
	printf("decrypted: %s\n", decrypted);
	printf("\n");

	strcpy(encrypted,"");
	strcpy(decrypted,"");


	void (*encryptROT13)(const char*, char* );
	void (*decryptROT13)(const char*, char* );

	handle1 = dlopen("librot12.so",RTLD_NOW);

	if(handle1 == NULL)
		{
			fputs(dlerror(),stderr);
			exit(1);
		}

	encryptROT13 = dlsym(handle1, "encryptROT13");

		if((error = dlerror())!= NULL)
		{
			fputs(error, stderr);
			exit(1);
		}



	printf("ROT13:\n");
	(*encryptROT13)(in, encrypted);
	printf("Original: %s\nencrypted: %s\n", in, encrypted);

	decryptROT13 = dlsym(handle1, "decryptROT13");

			if((error = dlerror())!= NULL)
			{
				fputs(error, stderr);
				exit(1);
			}
	(*decryptROT13)(encrypted, decrypted);
	printf("decrypted: %s\n", decrypted);
	printf("\n");

	dlclose(handle);
	dlclose(handle1);

	return EXIT_SUCCESS;
}
