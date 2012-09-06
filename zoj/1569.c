/*
from cc98
 1
  2    �� n,m;
  3    ���� sum[10000]��  //sum[i]��ʾ��ȡ��0~i�����ĺͣ��ڶ�mȡ����������
  4    sum[0]=0��
  5    �� ��=0��    //�����ж��ٸ���������
  6    �� i �� 1 �� n
  7    {
  8        ��ȡ x��        //������һ���������˲��ֺ����飬ԭ��������Ͳ��ñ�����
  9        sum[i]=sum[i-1]+x��
 10        sum[i]%=m��            //������Ӧ�ú�����ɡ���
 11        �� j �� 0 �� i - 1
 12        {
 13            ��� sum[j]==sum[i]   //��ôsum[i]-sum[j]���� �� j �� i �ĺͣ���m����
 14             ��+=1��
 15        }
 16    }
 17    ����𰸣�
 18
 19

������O(max(n, m))�İɣ�����һ�飬count[i]��ʾsum[j] % m = i�ĸ�����Ȼ���0��m����count[i]��total+=(count[i]*(count[i]-1))/2

1
  2    �� n,m;
  3    ���� sum[10000]��  //sum[i]��ʾ��ȡ��0~i�����ĺͣ��ڶ�mȡ����������
  4    ���� count[5000]��  //count[i]��ĿǰΪֹ����Ϊi��sum����
  5
  6    ��� count Ϊ�㣻
  7    sum[0]=0��
  8
  9    �� ��=0��    //�����ж��ٸ���������
 10
 11    �� i �� 1 �� n
 12    {
 13        ��ȡ x��        //������һ���������˲��ֺ����飬ԭ��������Ͳ��ñ�����
 14        sum[i]=sum[i-1]+x��
 15        sum[i]%=m��            //������Ӧ�ú�����ɡ���
 16        count[sum[i]]+=1��
 17        ��+=count[sum[i]]��
 18    }
 19    ����𰸣�
 20
 21

*/
#include <stdio.h>
int main()
{
    int i,n,m,x,sum[10002],mod[5001];
    long count;

    while(scanf("%d%d",&n,&m)!=EOF){
        for(i=0;i<m;i++)
            mod[i]=0;
        sum[0]=0;
        mod[0]=1;
        for(i=1;i<=n;i++){
            scanf("%d",&x);
            sum[i]=(sum[i-1]+x)%m;
            mod[sum[i]]++;
        }
        count=0;
        for(i=0;i<m;i++)
            if(mod[i]>1) count+=mod[i]*(mod[i]-1)/2;
        printf("%ld\n",count);
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2501930 2007-06-24 16:08:31 Accepted 1569 C 00:00.03 448K �錄�� */

// 2012-09-07 03:02:26 | Accepted | 1569 | C | 20 | 160 | watashi | Source
