#include <stdio.h>

char hello[]={"hello gcc"};

int main(void)
{
    /*��ӡ�ַ����飬��ʾ�ַ���λ�úʹ�С*/
    printf("str:%s,ptr:%p,size:%d\n",hello,hello,sizeof(hello));

    return 0;
}