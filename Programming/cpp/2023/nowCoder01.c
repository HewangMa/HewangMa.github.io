#include <stdio.h>
int main()
{
    char *s = "1314520";
    int v1 = 0, v2 = 0, v3 = 0, v4 = 0;
    for (int i = 0; s[i]; i++)
    {
        switch (s[i])
        {
        default:
            v4++;
        case '1':
            v1++;
        case '2':
            v2++;
        case '3':
            v3++;
        }
    }
    printf("%d, %d, %d, %d", v4, v1, v2, v3)
}
