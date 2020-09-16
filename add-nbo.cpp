#include <stdio.h>
#include <stdint.h>
#include <netinet/in.h>

uint32_t filetohl(FILE *fp) {
    uint32_t temp, res;
    fread(&temp, sizeof(uint32_t), 1, fp);
    res = ntohl(temp);
    return res;
}

int main(int argc, char *argv[]) {
    uint32_t a, b, c;
    FILE *fp = fopen(argv[1], "r");
    FILE *fp2 = fopen(argv[2], "r");

    a = filetohl(fp);
    b = filetohl(fp2);
    c = a + b;
    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", a, a, b, b, c, c);

    return 0;
}
