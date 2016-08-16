#include "rc4.h"

// Safe XOR SWAP macro
#define swap(a, b) ((&(a) == &(b)) ? (a) : ((a)^=(b),(b)^=(a),(a)^=(b)))


// Key Scheduling Algorithm
void rc4_init (RC4_KEY *rc4_key, unsigned char *key, int keylength)
{
	int i, j;

	// Initialize s-box
	for (i = 0; i < 256; i++)
		rc4_key->sbox[i] = i;

	// Scrambling
	for (i = 0, j = 0; i < 256; i++)
	{
		// Randomize s-box using the supplied key
		j = (j + rc4_key->sbox[i] + key[i % keylength]) % 256;
		swap (rc4_key->sbox[i], rc4_key->sbox[j]);
	}
}

// Encrypt/decrypt data with the RC4 algorithm
void rc4_crypt (RC4_KEY *rc4_key, unsigned char *data, int datalength, unsigned char *out)
{
	int i = 0, j = 0, n = 0;
	int byte_iterator = 0;

	// Process input data
	for (byte_iterator = 0; byte_iterator < datalength; ++byte_iterator)
	{
		i = (i + 1) % 256;
		j = (j + rc4_key->sbox[i]) % 256;

		swap (rc4_key->sbox[i], rc4_key->sbox[j]);

		n = rc4_key->sbox[(rc4_key->sbox[i] + rc4_key->sbox[j]) % 256];

		// Encryption/decryption
		out[byte_iterator] = data[byte_iterator] ^ n;
	}
}

// Pseudo Random Generator Algorithm
unsigned char rc4_prga (RC4_KEY *rc4_key)
{
	int i = 0, j = 0;

	i = (i + 1) % 256;
	j = (j + rc4_key->sbox[i]) % 256;

	swap (rc4_key->sbox[i], rc4_key->sbox[j]);

	return rc4_key->sbox[(rc4_key->sbox[i] + rc4_key->sbox[j]) % 256];
}
