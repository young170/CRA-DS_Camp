#include <stdio.h>
#include <stdlib.h>

int main (void)
{
    FILE *fp;
    long lSzie;
    char *buffer;
    size_t result;

    fp = fopen("myfile.bin", "rb");

    if (fp == NULL) {
        fputs("FILE error", stderr);    // stderr : standard error console.
        exit(1);                        // equivalent to return 1. returning 0 means successful termination.
    }

    fseek(fp, 0, SEEK_END);     // move file pointer (cursor) to the end of the file.
    lSzie = ftell(fp);          // then get the size from beginning to end.
    rewind(fp);                 // rewind the pointer back to the beginning.

    buffer = (char *) malloc(sizeof(char) * lSzie);     // buffer is the size of the file.
    if (buffer == NULL) {
        fputs("READ error", stderr);
        exit(2);
    }

    result = fread(buffer, 1, lSzie, fp);       // data read and filled to buffer.
    if (result != lSzie) {                      // result contains the position.
        fputs("READING error", stderr);
        exit(3);
    }

	for (int i = 0; i < lSzie; i++) {
		fputc(buffer[i], stdout);
	}

    fclose(fp);
    free(buffer);

    return 0;
}