#include <stdio.h>
#include <string.h>

/* 功  能：将str字符串中的oldstr字符串替换为newstr字符串
 * 参  数：str：操作目标 oldstr：被替换者 newstr：替换者
 * 返回值：返回替换之后的字符串
 * 版  本： V0.2
 */
char *strrpl(char *str, char *oldstr, char *newstr)
{
    if (str == NULL || oldstr == NULL || newstr == NULL)
    {
        return NULL;
    }

    int size = strlen(str);
    char bstr[size]; //转换缓冲区
    memset(bstr, 0, sizeof(bstr));

    for (int i = 0; i < size; i++)
    {
        if (!strncmp(str + i, oldstr, strlen(oldstr)))
        { //查找目标字符串
            strcat(bstr, newstr);
            i += strlen(oldstr) - 1;
        }
        else
        {
            strncat(bstr, str + i, 1); //保存一字节进缓冲区
        }
    }

    strcpy(str, bstr);
    return str;
}
#ifdef _DEBUG
int main(int argc, char const *argv[])
{
    char str[] = "YY-MM-DD hh:mm:ss\n";
    strrpl(str, "YYYY", "2020");
    strrpl(str, "YY", "20");
    printf("%s", str);
    strrpl(str, "MM", "01");
    printf("%s", str);
    strrpl(str, "DD", "01");
    printf("%s", str);
    strrpl(str, "hh", "03");
    printf("%s", str);
    return 0;
}
#endif