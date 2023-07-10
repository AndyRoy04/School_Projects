#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#define ROTL(x, y) (((x) << (y)) | ((x) >> (32 - (y))))

void ripemd(const uint8_t *message, size_t message_len, uint8_t *digest, size_t digest_len) {
    uint32_t state[5] = {0x67452301, 0xEFCDAB89, 0x98BADCFE, 0x10325476, 0xC3D2E1F0};
    uint32_t buffer[16] = {0};
    size_t buffer_len = 0;
    size_t i, j;

    // Pad message
    uint64_t bit_len = message_len * 8;
    message_len += (message_len % 64 < 56) ? 64 - message_len % 64 : 128 - message_len % 64;
    uint8_t *padded_message = (uint8_t *)malloc(message_len);
    memcpy(padded_message, message, message_len - 8);
    padded_message[message_len - 8] = (bit_len >> 56) & 0xFF;
    padded_message[message_len - 7] = (bit_len >> 48) & 0xFF;
    padded_message[message_len - 6] = (bit_len >> 40) & 0xFF;
    padded_message[message_len - 5] = (bit_len >> 32) & 0xFF;
    padded_message[message_len - 4] = (bit_len >> 24) & 0xFF;
    padded_message[message_len - 3] = (bit_len >> 16) & 0xFF;
    padded_message[message_len - 2] = (bit_len >> 8) & 0xFF;
    padded_message[message_len - 1] = bit_len & 0xFF;

    // Process message in 512-bit blocks
    for (i = 0; i < message_len; i += 64) {
        for (j = 0; j < 16; j++) {
            buffer[j] = (padded_message[i + j * 4 + 3] << 24) |
                        (padded_message[i + j * 4 + 2] << 16) |
                        (padded_message[i + j * 4 + 1] << 8) |
                        (padded_message[i + j * 4]);
        }

        uint32_t a = state[0], b = state[1], c = state[2], d = state[3], e = state[4];
        uint32_t temp;

        // Round 1
        for (j = 0; j < 16; j++) {
            temp = a + ((b & c) | (~b & d)) + buffer[j];
            temp = ROTL(temp, 11);
            temp += e;
            e = d;
            d = c;
            c = ROTL(b, 10);
            b = a;
            a = temp;
        }

        // Round 2
        for (j = 0; j < 16; j++) {
            temp = a + ((b & (c | d)) | (c & d)) + buffer[(j * 5 + 1) % 16];
            temp = ROTL(temp, 14);
            temp += e;
            e = d;
            d = c;
            c = ROTL(b, 10);
            b = a;
            a = temp;
        }

        // Round 3
        for (j = 0; j < 16; j++) {
            temp = a + ((b | ~c) ^ d) + buffer[(j * 3 + 5) % 16];
            temp = ROTL(temp, 12);
            temp += e;
            e = d;
            d = c;
            c = ROTL(b, 10);
            b = a;
            a = temp;
        }

        // Round 4
        for (j = 0; j < 16; j++) {
            temp = a + ((b & d) | (c & ~d)) + buffer[(j * 7) % 16];
            temp = ROTL(temp, 9);
            temp += e;
            e = d;
            d = c;
            c = ROTL(b, 10);
            b = a;
            a = temp;
        }

        // Round 5
        for (j = 0; j < 16; j++) {
            temp = a + (b ^ (c | ~d)) + buffer[j];
            temp = ROTL(temp, 11);
            temp += e;
            e = d;
            d = c;
            c = ROTL(b, 10);
            b = a;
            a = temp;
        }

        state[0] += a;
        state[1] += b;
        state[2] += c;
        state[3] += d;
        state[4] += e;
    }

    // Convert state to digest
    for (i = 0; i < digest_len; i += 4) {
        digest[i] = (state[i / 4] >> 24) & 0xFF;
        digest[i + 1] = (state[i / 4] >> 16) & 0xFF;
        digest[i + 2] = (state[i / 4] >> 8) & 0xFF;
        digest[i + 3] = state[i / 4] & 0xFF;
    }

    free(padded_message);
}

int main() {
    uint8_t message[100];
    uint8_t digest[20] = {0};
    printf("\t\t\t ----------------------- \n");
    printf("\t\t\t RIPEMD HASHING FUNCTION \n");
    printf("\t\t\t ----------------------- \n");
    printf("\t\t\t\t  Hashing \n");
    printf("\t\t\t ----------------------- \n");

    fflush(stdin);
    printf("Enter a message : ");
    gets(message);
    ripemd(message, strlen((char *)message), digest, 20);

    printf(" The Digested message is : ");
    for (int i = 0; i < 20; i++) {
        printf("%02x", digest[i]);
    }
    printf("  -");

    return 0;
}