#include <stdio.h>
int main()
{
    int a[1001],i,n,j,k,t;

    while(scanf("%d",&n),n){
        while(scanf("%d",&a[0]),t=a[0]){
            for(i=j=1;i<n;i++){
                scanf("%d",&a[j]);
                if(a[j]>t) {t=a[j];j++;}
                else t=a[j];
            }
            k=j;
            for(i=1;i<k;i++)
                if(a[i-1]>a[i]) break;
            if(i<k) printf("No\n");
            else printf("Yes\n");
        }
        printf("\n");
    }
}
/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2503256 2007-06-26 12:41:25 Accepted 1259 C 00:00.08 400K gl hf */

/*
������: SgHao ( [ focus ] ), ����: Algorithm
��  ��: Re: ����жϳ�ջ˳���Ƿ����
����վ: Ʈ��ˮ�Ƽ� (Sat Jan 19 13:20:49 2008), վ���ż�

ÿһ������ȷ���İ�
������һ��Ӧ�ó�ջ��Ԫ�أ��Լ���Ԫ�ص�ǰ�ڶ�ջ���滹��û�н����ջ��
����ȷ������Ҫ��ѹ��һ��Ԫ�ػ��ǵ���һ��Ԫ�أ����߿����ж������ܡ�
�� �� watashi (watashi) �Ĵ������ᵽ: ��
: O(n^3) 555
: how to simulate it?
: �� �� SgHao ( [ focus ] ) �Ĵ������ᵽ: ��
: : �������ʱ�临�Ӷȶ��٣�
: : ģ��һ��O(N)�͸㶨�ˡ�


--
5
9
101

�� ��Դ:��Ʈ��ˮ�Ƽ� freecity.cn��[FROM: SgHao]
*/

// 2012-09-07 00:43:21 | Accepted | 1259 | C | 20 | 160 | watashi | Source
