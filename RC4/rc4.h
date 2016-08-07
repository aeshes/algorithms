#ifndef RC4_H
#define RC4_H

typedef struct {
	unsigned char sbox[256];
} RC4_KEY;

void rc4_init (RC4_KEY *rc4_key, unsigned char *key, int keylength);

unsigned char rc4_prga (RC4_KEY *rc4_key);

void rc4_crypt (RC4_KEY *rc4_key, unsigned char *data, int datalength, unsigned char *out);

#endif
