#include <string.h>
#include "ras.h"
// ras = remove all sep
char *myras(char *src, char *sep)
{
    char *pstr;
    char *tmp = src;
    do
    {
        src = strpbrk(src, sep); // find separator
        if (src)
        {
            pstr = src + strspn(src, sep); // skip separator
            strcpy(src, pstr);
        }
    } while (src && *src);
    return tmp;
}
