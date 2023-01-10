#include <stdio.h>

int main (void)
{
    FILE *fp = fopen("data", "rb");
    int num;

    fread(&num, sizeof(int), 1, fp);

    printf("result %d\n", num);     // if the weird number pops up, Congrats!
    
    return 0;
}