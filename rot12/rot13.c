#include "rot13.h"
#include "caesar.h"

void encryptROT13(const char* in, char* out)
{
	encryptCeasar(in, out, ROT13);
}

void decryptROT13(const char* in, char* out)
{
	encryptCeasar(in, out, ROT13);
}
