/*
[quote=Ice_Ax]
����Ϊa[1],a[2]��a[m]����С�������򣩣��ֱ���k[1],k[2]��k[m]������ô���ǿ���֤�����Ž���k[1],k[2]��k[m-1]�����ᳬ��a[m]:
����ĳ��k[i]>a[m],��ô���ǰ�k[i]��ȥa[m],k[m]����a[i],��k[i]*a[i]+k[m]*a[m] == (k[i]-a[m])*a[i]+(k[m]+a[i])*a[m]���������ĺͱ��ֲ��䣬��Ϊn,��������������k[i]+k[m]�����(k[i]-a[m])+ (k[m]+a[i])�������ˣ�������ţ������Ž�ì�ܡ�
����k[1],k[2]��k[m-1]��󲻻ᳬ��99�����ĺ���󲻻ᳬ����1+2+��+98��*99,�����500000�ɣ���ʵԶԶ�����������������ʱ���鷳�������㾫ȷ���ˣ���������1��500000��dp������Ž⣬Ȼ��ö����ǰm-1�����ĺͣ���Ϊi������dp[i]+(n-i)/a[m]����һ���⣬�����С�ľ����ˡ�
[/quote]
*/

#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXANS = 1111111111;
int dp[500000];

int main(void)
{
    int re, m, n;
    int a[101], s, ans;

    scanf("%d", &re);
    while(re--) {
        scanf("%d%d", &m, &n);
        for (int i = 0; i < m; i++)
            scanf("%d", &a[i]);
        sort(a, a + m);
        // TLE
        s = 0;
        for (int i = 1; i < m; i++)
            if(a[i] != a[s])
                a[++s] = a[i];
        m = s;
        //
        s = 0;
        for (int i = 0; i < m; i++) {
            s += (a[i + 1] - 1) * a[i];
            //if(a[i] == a[i + 1])
            //  char *p = new char[123456789];
        }
        dp[0] = 0;
        fill(dp + 1, dp + s + 1, MAXANS);
        for (int i = 0; i < m; i++)
            for (int j = a[i]; j <= s && j <= n; j++)
                dp[j] = min(dp[j], dp[j - a[i]] + 1);
        ans = MAXANS;
        for (int i = n % a[m]; i <= s && i <= n; i += a[m])
            ans = min(ans, dp[i] + (n - i) / a[m]);
        printf("%d\n", (ans == MAXANS) ? -1 : ans);
    }

    return 0;
}

//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2814895 2008-03-31 22:56:26 Accepted 2955 C++ 00:00.11 2392K �錄��

// 2012-09-07 01:49:58 | Accepted | 2955 | C++ | 30 | 2132 | watashi | Source
