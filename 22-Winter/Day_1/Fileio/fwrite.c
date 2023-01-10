#include <stdio.h>

int main (void)
{
    FILE *fp;
    char buffer[] = {'x', 'y', 'z'};    // arrayname = &arry[0], arrayname[] = *arrayname

    fp = fopen("myfile.bin", "wb");
    fwrite(buffer, sizeof(char), sizeof(buffer), fp);
    fclose(fp);

    return 0;
}