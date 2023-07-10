#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define ROTL(x, y) (((x) << (y)) | ((x) >> (64 - (y))))
#define MAX 100

void sha3(const uint8_t *message, size_t message_len, uint8_t *digest, size_t digest_len)
{
    uint64_t state[25] = {0};
    uint8_t block[200] = {0};
    size_t block_len = 0;
    size_t i, j, k;

    // Initialize state
    state[1] = 1;

    // Absorb message
    for (i = 0; i < message_len; i++)
    {
        block[block_len++] = message[i];
        if (block_len == 200)
        {
            for (j = 0; j < 25; j++)
            {
                state[j] ^= ((uint64_t *)block)[j];
            }
            block_len = 0;

            // Permute state
            for (j = 0; j < 24; j++)
            {
                uint64_t t = state[0] ^ state[5] ^ state[10] ^ state[15] ^ state[20];
                for (k = 0; k < 25; k += 5)
                {
                    uint64_t a = state[k];
                    state[k] ^= ROTL(t, 1) ^ state[(k + 1) % 5 + j] ^ state[k + 1];
                    state[k + 1] ^= ROTL(state[k + 1] ^ state[(k + 2) % 5 + j], 1);
                    state[k + 2] ^= ROTL(state[k + 2] ^ state[(k + 3) % 5 + j], 1);
                    state[k + 3] ^= ROTL(state[k + 3] ^ state[(k + 4) % 5 + j], 1);
                    state[k + 4] ^= ROTL(state[k + 4] ^ a, 1);
                }
            }
        }
    }

    // Pad message
    block[block_len++] = 0x06;
    while (block_len < 200)
    {
        block[block_len++] = 0x00;
    }
    block[199] |= 0x80;

    // Absorb padded message
    for (j = 0; j < 25; j++)
    {
        state[j] ^= ((uint64_t *)block)[j];
    }

    // Permute state
    for (j = 0; j < 24; j++)
    {
        uint64_t t = state[0] ^ state[5] ^ state[10] ^ state[15] ^ state[20];
        for (k = 0; k < 25; k += 5)
        {
            uint64_t a = state[k];
            state[k] ^= ROTL(t, 1) ^ state[(k + 1) % 5 + j] ^ state[k + 1];
            state[k + 1] ^= ROTL(state[k + 1] ^ state[(k + 2) % 5 + j], 1);
            state[k + 2] ^= ROTL(state[k + 2] ^ state[(k + 3) % 5 + j], 1);
            state[k + 3] ^= ROTL(state[k + 3] ^ state[(k + 4) % 5 + j], 1);
            state[k + 4] ^= ROTL(state[k + 4] ^ a, 1);
        }
    }

    // Squeeze digest
    for (i = 0; i < digest_len; i++)
    {
        digest[i] = ((uint8_t *)state)[i];
    }
}

int main()
{
    uint8_t message[MAX];
    uint8_t digest[64] = {0};
    printf("\t\t\t ---------------------- \n");
    printf("\t\t\t SHA-3 HASHING FUNCTION \n");
    printf("\t\t\t ---------------------- \n");
    printf("\t\t\t\t  Hashing \n");
    printf("\t\t\t ---------------------- \n");

    fflush(stdin);
    printf("Enter a message : ");
    gets(message);
    sha3(message, strlen((char *)message), digest, 64);
    printf("The Encrypted Message is : ");
    for (int i = 0; i < 64; i++)
    {
        printf("%02x", digest[i]);
    }
    printf("-");
    return 0;
}
