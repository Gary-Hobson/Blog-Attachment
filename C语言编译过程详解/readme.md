# �ӱ��뵽����-�������������

## ǰ��
�����һ���ַ���ô���һ�������еĳ����أ���������ʹ����򵥵�һ��hello word ��������ʾ�����һ���������̡�  
����������ҵ�һЩ���õĵ��Է���������������debugʱ���ٽ�����⡣

�������ʱ���������̾�����
* **����** �� **Ԥ����** ��**����**�� **���**�� **����** 

![��������](../picture/�������.png)


**���л���**
> windows 10 + cygwin
>gcc �汾 7.4.0 

## һ�� ����
����C�����﷨���򣬽��ַ���ϳ�һ�����ض�������ı���  

main.c
```c
#include <stdio.h>

char hello[]={"hello word"};

int main(void)
{
    /*��ӡ�ַ����飬��ʾ�ַ���λ�úʹ�С*/
    printf("str:%s,ptr:%p,size:%d\n",hello,hello,sizeof(hello));

    return 0;
}
```

## ���� Ԥ����
Ԥ������Ҫ�ǽ�Դ�ļ��е�Ԥ����ָ��(```#define, #include ```)չ�����滻���߶���������ѡ�����ѡ��ɾ����  

����Ԥ����ָ�����ϸ˵������һƪ��������ϸ˵����  

��gcc����Ԥ�����йس��õĲ鿴ָ���У�
* **-E** ����Ҫѡ�gcc ʹ�øò�������Ԥ�����ļ���
* **-C** �������ַ����滻ʱ����ע��
* **-P** : �����#line ��Ϣ
* **-D**macro : �Բ������������ļ�ʹ�ú궨�� macro
* **-include** file : �ڲ������������ļ��ʼ����ͷ�ļ� file

�������������� ```gcc -E maic.c -o main.i``` ����Ԥ�������ļ���

<details>
<summary>չ���鿴main.i</summary>
<pre><code>

`#` 1 "main.c"
`#` 1 "<built-in>"
`#` 1 "<������>"
`#` 1 "main.c"
`#` 1 "/usr/include/stdio.h" 1 3 4
`#` 29 "/usr/include/stdio.h" 3 4
`#` 1 "/usr/include/_ansi.h" 1 3 4
... ʡ������ ...
`#` 41 "/usr/include/machine/_default_types.h" 3 4
typedef signed char __int8_t;

typedef unsigned char __uint8_t;
`#` 55 "/usr/include/machine/_default_types.h" 3 4
typedef short int __int16_t;

typedef short unsigned int __uint16_t;
`#` 77 "/usr/include/machine/_default_types.h" 3 4
typedef int __int32_t;
... ʡ������ ...

`#` 797 "/usr/include/stdio.h" 3 4
`#` 2 "main.c" 2
`#` 3 "main.c"
char hello[]={"hello gcc"};

int main(void)
{

    printf("str:%s,ptr:%p,size:%d\n",hello,hello,sizeof(hello));

    return 0;
} 
</code></pre>
</details>  
  
>
<font color=red >��main.i���������к��ͷ�ļ�ȫ��չ������ѡ���ڵ��Ժ��и�����ʮ�����á�</font>
    

��������ļ��г���������֪�ĺ��滻�⣬���кܶ���#��ͷ���У���Щ��ͷ�ļ��滻��λ����Ϣ��

>���﷨��ʽΪ��
>`#` �к� �ļ��� ���Ա�ʶ

|  ��ʶ  | ����  |
|  ----  | ----  |
| 1  | һ�����ļ��Ŀ�ʼ |
| 2  | ��ʾ��һ�����������ļ��з��� |
| 3  | ��ʾ�������������ϵͳ�ļ� |
| 4  | ��ʾ���������Ӧ��������һ����ʽ��```extern "C"```�� |

>```# 1 "/usr/include/_ansi.h" 1 3 4```  
>
>����һ�б�ʾ���������������```/usr/include/_ansi.h```�ļ�����������һ��ϵͳ�ļ���ͷ��
> ��Ԥ����ʱ���-P�������ɲ���ʾ#line���ݡ�

��keil ������Ԥ�����ļ�ѡ�����£�
![keil����Ԥ�����ļ�](../picture/keil����Ԥ�����ļ�.jpg)

## ����
�ڶ�Դ�ļ�����Ԥ������ɺ�Ҫ��Ԥ�����ļ����б��룬��Դ�ļ����дʷ�������ת��Ϊ������ԡ�

������������������```gcc main.i -S -o main.S``` ���ɻ���ļ�

<details>
<summary>չ���鿴main.i</summary>
<pre><code>

	.file	"main.c"
	.text
	.globl	hello
	.data
	.align 8
hello:
	.ascii "hello gcc\0"
	.def	__main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
.LC0:
	.ascii "str:%s,ptr:%p,size:%d\12\0"
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	call	__main
	movl	$10, %r9d
	leaq	hello(%rip), %r8
	leaq	hello(%rip), %rdx
	leaq	.LC0(%rip), %rcx
	call	printf
	movl	$0, %eax
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.ident	"GCC: (GNU) 7.4.0"
	.def	printf;	.scl	2;	.type	32;	.endef

</code></pre>
</details>  

**ʹ�ñ������Դ�ļ�����Ϊ����ļ��󣬿ɱȽϻ��Ľ�������ĳЩ��������Ż�**

## ���
ʹ��-c����������������ֻ���л���.o�ļ��������ɿ�ִ���ļ�
������������������ ```gcc main.S -c -o main.o```���ɡ�
��Ŀ���ļ�(*.o)�ļ��У������˸�Դ�ļ��ĺ�����������Ϣ��  
��ͨ��objdump���߲鿴���и������ݶε�˵���ͷ��ű�����ʹ��IDA�ȷ�����������ɻ�����C�ļ���������ʹ��IDA ��main.o������Ľ���������ṹ��Cԭ�ļ�����һ�¡�
![�������](../picture/main.o�������Ϣ.jpg)

## ����
ʹ��GCC�в�ʹ������������ֻ����-oĬ�Ͻ������Ӳ����������ӹ����лὫ����Ŀ���ļ�����̬�⡢��̬��һ����ָ������(���ӽű�)�������������ɿ�ִ���ļ���  

��������������```gcc main.o -Wl,-Map=main.map -o main.exe``` ���ɿ�ִ���ļ���������map�ļ���  

�����ڸó�����ֻʹ����ϵͳ�⣬��û��ʹ���ⲿ�⣬����û��ָ����̬/��̬����������·����

**-l**��ָ�������ӵĿ�����
**-L**��ָ�����ӿ�Ĳ���·����
**-Wl,-Map=file.map**������map�ļ������а����˷��ű�͵�ַӳ�����Ϣ��

## ����
��������������```./main.exe```���г������������£�
``` sh
$ ./main.exe
str:hello gcc,ptr:0x100402010,size:10
```

��main.map���ɿ���hello�ַ����ı�����ַ�ͱ�����С�����ӡ��ֵһ�¡�
``` 
.data          0x0000000100402000       0x10 /usr/lib/gcc/x86_64-pc-cygwin/7.4.0/crtbegin.o
                0x0000000100402000                __dso_handle
 .data          0x0000000100402010       0x10 main.o
                0x0000000100402010                hello
 .data          0x0000000100402020        0x0 /usr/lib/gcc/x86_64-pc-cygwin/7.4.0/../../../../lib/libcygwin.a(cygwin_crt0.o)
 .data          0x0000000100402020        0x0 /usr/lib/gcc/x86_64-pc-cygwin/7.4.0/../../../../lib/libcygwin.a(premain0.o)
```
