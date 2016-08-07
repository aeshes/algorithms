#include <stdio.h>
#include "rc4.h"

int main (int argc, char *argv[])
{
	int i;
	const int KEY_LENGTH  = 3;
	const int TEXT_LENGTH = 9;
	unsigned char key[6] = "xyz";
	unsigned char plaintext[256] = {0};
	unsigned char ciphertext[256] = {0};

	RC4_KEY rc4_key;
	rc4_init(&rc4_key, key, KEY_LENGTH);

	scanf("%s", plaintext);

	printf ("plaintext = %s\n", plaintext);

	rc4_crypt (&rc4_key, &plaintext[0], TEXT_LENGTH, &ciphertext[0]);

	printf ("ciphertext = %s\n", ciphertext);

	rc4_crypt (&rc4_key, &ciphertext[0], TEXT_LENGTH, &plaintext[0]);

	printf ("plaintext = %s\n", plaintext);

	rc4_init(&rc4_key, key, KEY_LENGTH);
	rc4_crypt (&rc4_key, &ciphertext[0], TEXT_LENGTH, &plaintext[0]);

	printf ("plaintext = %s\n", plaintext);

	scanf ("%d", &i);
	return 0;
}
