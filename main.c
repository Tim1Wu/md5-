#include "lib_md5.h"
#include <stdio.h>
#include <stdlib.h>
void do_fp(FILE *f)
{
	MD5_CTX* md5 = (MD5_CTX*)malloc(sizeof(MD5_CTX));
	int fd, i;
	static unsigned char buf[16384];
	unsigned char digest[16] = { 0 };
	fd = fileno(f);
	MD5Init(md5);
	while (1)
	{
		i = read(fd, buf, 16384);
		if (i <= 0) break;
		MD5Update(md5, (unsigned char*)buf, (unsigned long)i);
	}
	MD5Final(md5,digest);
	for (i = 0; i < 16; i++)
		printf("%02x", digest[i]);
}
int main(int argc, char **argv)
{
	FILE *INf = fopen(argv[0], "rb");
	do_fp(INf);
	fclose(INf);
}
