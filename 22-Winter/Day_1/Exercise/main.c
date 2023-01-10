#include <stdio.h>

int main (void)
{
    FILE *fp = fopen("data", "wb");
    int num = 825177405;

    fwrite(&num, sizeof(4), 1, fp);     // num : address of data, sizeof(4) : size of data
                                        // 1 : count of data, fp : file pointer

    return 0;
}