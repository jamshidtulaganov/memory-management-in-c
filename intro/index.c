#include <stdio.h>

int main(void)
{
    //#declaring th 
    // int n = 500;
    // int *p = &n;

    // printf("%p\n", p);
    // printf("%i\n", *p);

    // declaring the string
    char *s = "ja"; // 'j', 'a', 'null'

    printf("%p\n", &s);
    printf("%p\n", &s[0]);
    printf("%c\n", s[1]);
    printf("%c\n", s[2]);
}