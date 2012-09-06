#include <stdio.h>
#define isempty() (size==0)
#define clear() (size=0)
#define top() (stack[size-1])
#define topIndex() (index[size-1])
#define pop() (--size)
#define push(i,value) (index[size]=i,stack[size]=value,++size)
char str[100001];
char stack[100001];
int index[100001];
int size;
int main()
{
    int i,start,f,begin,end,len;

    while(gets(str)!=NULL){
        begin=end=-1;/*bs myself*/
        start=-1;
        len=0;
        clear();
        for(i=0;str[i];++i){
            switch(str[i]){
            case '(':case '[':
                push(i,str[i]);break;
            case ')':case ']':
                if(!isempty()&&(str[i]==')'&&top()=='('||str[i]==']'&&top()=='[')){
                    pop();
                    if(!isempty()) f=topIndex();
                    else f=start;
                    if(i-f>len){
                        len=i-f;
                        begin=f;
                        end=i;
                    }
                }
                else{
                    start=i;
                    clear();
                }
                break;
            }
        }
        str[end+1]='\0';
        puts(str+begin+1);
        getchar();
        putchar('\n');
    }
}
/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2681782 2007-11-21 14:24:47 Accepted 2704 C 00:00.04 976K �錄�� */
/*
Rank Submit time Run time Run memory Language User
1 2007-05-16 10:00:33 00:00.04 580K C++ 9911
2 2006-11-06 14:39:53 00:00.04 884K C++ xprogrammer
3 2007-11-21 14:24:47 00:00.04 976K C �錄��
4 2007-03-01 20:19:00 00:00.05 884K C++ ��.Woody
5 2007-03-01 20:45:29 00:00.05 884K C++ LoadingTime
6 2006-05-08 12:34:33 00:00.05 976K C++ ���ݽ���
7 2006-04-26 16:17:35 00:00.05 1264K C++ tmpf
8 2006-04-26 16:27:18 00:00.05 1276K C++ foolman
9 2007-04-28 22:44:59 00:00.05 1372K C++ forever
10 2006-03-26 21:08:39 00:00.05 1468K C++ -_-
11 2006-05-21 12:57:09 00:00.06 876K C++ һ��С��^o^ @ZJOU
*/


/*
��Ŀ����
��һ������[]()�����ַ���ɵ��ַ���,��һ����öԵ���Ӵ�
�����")[])([])(]"�õ�"([])"

ע�⵽������ʵ����Ҫ:
����λ��i���ַ�'[',������֮ƥ���λ��j��']'�����Ӵ�"[A]",���A���ǿմ�,��ô��һ������ʼ��i+1��ֹ��j-1�����Դ�
(Aһ������Դ�,��A]B�϶�������Դ�,�������B)
����,λ��i�����Դ�=[A]+λ��j+1�����Դ�

����,���ǿ���DP
f[n]��ʾ��ʼ��λ��n�����Դ�.
���s[n]='['��'(',��ôֻ��Ҫ���n+1+f[n+1]���ַ��Ƿ���֮ƥ��.��ƥ��,�ټ���f[n+2+f[n+1]]
����
���
03-26-2006
*/

/*
��ʵ������ô�鷳����һ��ջɨ��һ�ξ͸㶨�ˡ�

ȷʵ,��ջ�Ǹ��򵥵İ취

���ĳ���ַ���������,��ôջ�������ַ�һ�������䴮
*/

// 2012-09-07 01:35:40 | Accepted | 2704 | C | 20 | 744 | watashi | Source
