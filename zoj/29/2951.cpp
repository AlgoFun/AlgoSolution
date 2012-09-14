/*
[quote="Ice_Ax"]
֤�������Ž���һ���������������û�бߡ�
��ÿ�������㶼�б���������ô���ǰ�����˳ʱ��ıߵĳ��ȼ�ȥ������ʱ��ıߵĳ��ȵõ�P��
��p>0����ÿ��˳ʱ��ıߵ�Ȩ��ȥ1����ʱ��ļ���1������ÿ�������յĻ��������䣬������cost�����p�����Ͻ���������裬cost�᲻�ϼ��٣�ֱ����һ���ߵ�Ȩ���0��Ҳ������ʧ�ˡ�������P<0Ҳһ����
[/quote]
*/

#include <cmath>
#include <cstdio>
double a[2002], d[2002];
int main(void)
{
    int re;
    int n;
    double s, t, ans;

    scanf("%d", &re);
    while(re--) {
        scanf("%d", &n);
        s = 0.0;
        for (int i = 0; i < n; i++) {
            scanf("%lf", &a[i]);
            s += a[i];
        }
        t = 0.0;
        for (int i = 0; i < n; i++) {
            scanf("%lf", &d[i]);
            t += d[i];
        }
        for (int i = 0; i < n; i++) {
            a[i] -= d[i] / t * s;
            scanf("%lf", &d[i]);
        }
        ans = -1;
        for (int i = 0; i < n; i++) {
            s = t = 0.0;
            for (int j = i; j < n; j++) {
                t = a[j] + t;
                s += d[j] * fabs(t);
            }
            for (int j = 0; j < i; j++) {
                t = a[j] + t;
                s += d[j] * fabs(t);
            }
            if(ans < 0 || s < ans)
                ans = s;
        }
        printf("%.2lf\n", ans);
    }

    return 0;
}

//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2813588 2008-03-31 15:31:07 Accepted 2951 C++ 00:00.61 424K �錄��

// 2012-09-07 01:49:31 | Accepted | 2951 | C++ | 180 | 212 | watashi | Source
