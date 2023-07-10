#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100
#define LEFTROTATE(x, c) (((x) << (c)) | ((x) >> (32 - (c))))

void md5(unsigned char *initial_msg, size_t initial_len, unsigned char *digest) {
    // Initialize variables
    unsigned int h0, h1, h2, h3;
    h0 = 0x67452301;
    h1 = 0xEFCDAB89;
    h2 = 0x98BADCFE;
    h3 = 0x10325476;

    // Pre-processing
    unsigned char *msg = NULL;
    size_t new_len, offset;
    unsigned int w[16], a, b, c, d, i;
    new_len = (((initial_len + 8) / 64) + 1) * 64;
    msg = (unsigned char*)calloc(new_len, 1);
    memcpy(msg, initial_msg, initial_len);
    msg[initial_len] = 128;
    offset = initial_len + 1;
    while (offset < new_len - 8) {
        msg[offset++] = 0;
    }
    unsigned long long bit_len = 8 * initial_len;
    memcpy(msg + new_len - 8, &bit_len, 8);

    // Process message in 16-word blocks
    for (offset = 0; offset < new_len; offset += 64) {
        // Initialize hash value for this block
        a = h0;
        b = h1;
        c = h2;
        d = h3;

        // Copy block into w
        for (i = 0; i < 16; i++) {
            w[i] = (unsigned int)msg[offset + i * 4] |
                   ((unsigned int)msg[offset + i * 4 + 1] << 8) |
                   ((unsigned int)msg[offset + i * 4 + 2] << 16) |
                   ((unsigned int)msg[offset + i * 4 + 3] << 24);
        }

        // Main loop
        for (i = 0; i < 64; i++) {
            unsigned int f, g;
            if (i < 16) {
                f = (b & c) | ((~b) & d);
                g = i;
            } else if (i < 32) {
                f = (d & b) | ((~d) & c);
                g = (5 * i + 1) % 16;
            } else if (i < 48) {
                f = b ^ c ^ d;
                g = (3 * i + 5) % 16;
            } else {
                f = c ^ (b | (~d));
                g = (7 * i) % 16;
            }
            unsigned int temp = d;
            d = c;
            c = b;
            b = b + LEFTROTATE((a + f + w[g] + 0x5A827999), 5);
            a = temp;
        }

        // Add this block's hash to result so far
        h0 += a;
        h1 += b;
        h2 += c;
        h3 += d;
    }

    // Cleanup
    free(msg);

    // Output result
    digest[0] = (unsigned char)(h0);
    digest[1] = (unsigned char)(h0 >> 8);
    digest[2] = (unsigned char)(h0 >> 16);
    digest[3] = (unsigned char)(h0 >> 24);
    digest[4] = (unsigned char)(h1);
    digest[5] = (unsigned char)(h1 >> 8);
    digest[6] = (unsigned char)(h1 >> 16);
    digest[7] = (unsigned char)(h1 >> 24);
    digest[8] = (unsigned char)(h2);
    digest[9] = (unsigned char)(h2 >> 8);
    digest[10] = (unsigned char)(h2 >> 16);
    digest[11] = (unsigned char)(h2 >> 24);
    digest[12] = (unsigned char)(h3);
    digest[13] = (unsigned char)(h3 >> 8);
    digest[14] = (unsigned char)(h3 >> 16);
    digest[15] = (unsigned char)(h3 >> 24);
}

int main() {
    char message[MAX_SIZE];
    printf("\t\t\t -------------------- \n");
    printf("\t\t\t MD5 HASHING FUNCTION \n");
    printf("\t\t\t -------------------- \n");
    printf("\t\t\t\t  Hashing \n");
    printf("\t\t\t -------------------- \n");

    fflush(stdin);
    printf("Enter a message : ");
    gets(message);
    unsigned char digest[16];
    int i;

    md5((unsigned char*)&message, strlen(message), digest);

    printf("The HASHED Message is : ");
    for (i = 0; i < 16; i++) {
        printf("%02x", digest[i]);
    }
    printf("n");
    
    return 0;
}
