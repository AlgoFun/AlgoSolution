/*
�����⻹��һ�����ķ��������ǵ������е�����ڵ������key������󣬵õ�������Ϊcartesian tree�����������

1. �������Ǵ����ң�һ��˳��������飬һ�߽���cartesian tree��
2. ���������Ѿ�����������ĵ�i��Ԫ�أ�����Ӧ��������i���ڵ���ɵ�cartesian tree����ô��i+1���ڵ�ض�����i+1���ڵ���ɵ�cartesian tree������·�������Ҷ˵㡣
3. ����ԭi�����cartesian tree������·�������Ҷ˵�������ϲ��ҵ�һ��priority��i+1�ڵ��Ľڵ㣬����ҵ��ˣ��Ͱ�i+1�ڵ����������Ϊ�Ǹ��ڵ�������������Ǹ��ڵ����������Ϊi+1�ڵ㡣����Ҳ��������i+1�ڵ����������Ϊԭ���ĸ�������i+1�ڵ���Ϊ�¸���
4. ��Ҫ������ǣ�������µ�����������·���������Ǵ��ϵ��¡���Ϊ���ϵ��»����O(n!)�ĸ��Ӷȣ������µ��ϵĹ����У�û��������౻�߹�һ�Σ���Ϊ���߹��Ľڵ�ر���Ϊĳ����������������ٿ��ܳ���������·���У�������O(n)�ĸ��Ӷȡ�

Rank Submit time Run time Run memory Language User
1 2006-07-10 13:00:21 00:00.36 3780K C++ SHiVa
2 2006-07-10 12:59:55 00:00.37 3776K C++ ???
3 2007-06-09 10:40:22 00:00.38 4148K C++ Fire!
4 2008-04-13 15:57:50 00:00.41 3160K C++ leokan
*/





#include <cstdio>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int n;
int a[16][65536][2];

void reset()
{
    for (int l = 1; (1 << l) <= n; l++) {
        int d = (1 << (l - 1)), dd = (1 << l);
        for (int i = 0; i + dd <= n; i++) {
            if (a[l - 1][i][0] >= a[l - 1][i + d][0]) {
                a[l][i][0] = a[l - 1][i][0];
                a[l][i][1] = a[l - 1][i][1];
            }
            else {
                a[l][i][0] = a[l - 1][i + d][0];
                a[l][i][1] = a[l - 1][i + d][1];
            }
        }
    }
}

int lg(int x)
{
    int ret = 0;

    while ((1 << ret) <= x) {
        ++ret;
    }

    return ret - 1;
}

//[l, r)
int query_index(int l, int r)
{
    int d = lg(r - l);

    if (a[d][l][0] >= a[d][r - (1 << d)][0]) {
        return a[d][l][1];
    }
    else {
        return a[d][r - (1 << d)][1];
    }
}

/******************************************************************/

vector<pair<string, int> > v;

void gao(int l, int r)
{
    if (l == r) {
        return;
    }
    int m = query_index(l, r);
    putchar('(');
    gao(l, m);
    printf("%s/%d", v[m].first.c_str(), v[m].second);
    gao(m + 1, r);
    putchar(')');
}

int main(void)
{
    int p;
    static char buf[256];

    for (int i = 0; i < 65536; i++) {
        a[0][i][1] = i;
    }
    while (scanf("%d", &n) != EOF && n > 0) {
        v.clear();
        for (int i = 0; i < n; i++) {
            scanf(" %[a-z]/%d", buf, &p);
            v.push_back(make_pair((string)buf, p));
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < n; i++) {
            a[0][i][0] = v[i].second;
        }
        reset();
        gao(0, n);
        putchar('\n');
    }

    return 0;
}

//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//3018568 2008-08-02 19:40:26 Accepted 2243 C++ 00:01.21 13080K Re:ReJudge

// 2012-09-07 01:16:56 | Accepted | 2243 | C++ | 380 | 10004 | watashi | Source
