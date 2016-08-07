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
		// Randomize the permutations using the supplied key
		j = (j + rc4_key->sbox[i] + key[i % keylength]) % 256;
		swap (rc4_key->sbox[i], rc4_key->sbox[j]);
	}
}

// Encrypt/decrypt data with the RC4 algorithm
void rc4_crypt (RC4_KEY *rc4_key, unsigned char *data, int datalength, unsigned char *out)
{
	int i = 0, j = 0, n;

	// Process input data
	for (i = 0; i < datalength; i++)
	{
		i = (i + 1) % 256;
		j = (j + rc4_key->sbox[i]) % 256;

		swap (rc4_key->sbox[i], rc4_key->sbox[j]);

		n = rc4_key->sbox[(rc4_key->sbox[i] + rc4_key->sbox[j]) % 256];

		// Encryption/decryption
		out[i] = data[i] ^ n;
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
