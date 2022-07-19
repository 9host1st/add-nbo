#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

uint32_t ntohl(uint32_t x) {
	uint32_t t1 = (x & 0xff000000) >> 24;
	uint32_t t2 = (x & 0x00ff0000) >> 16;
	uint32_t t3 = (x & 0x0000ff00) >> 8;
	uint32_t t4 = (x & 0x000000ff);
	return t4 << 24 | t3 << 16 | t2 << 8 | t1;

}

int main(int argc, char **argv[]) {
	if(argc < 2) {
		printf("./add-nbo <file1> <file2>\n");
		exit(1);
	}
	FILE *fp1;
	FILE *fp2;
	fp1 = fopen(argv[1], "rb");
	fp2 = fopen(argv[2], "rb");
	if(fp1 == NULL || fp2 == NULL) {
		printf("FILE error!\n");
		exit(1);
	}
	uint32_t p;
	uint32_t q;
	fread(&p, 4, 1, fp1);
	fread(&q, 4, 1, fp2);
	p = ntohl(p);
	q = ntohl(q);
	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", p, p, q, q, p + q, p + q);
}
