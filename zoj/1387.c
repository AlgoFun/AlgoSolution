/* //lalala Trie�� cpy��2443��code �����Ͼ���ʱ��sls˵�� */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const char* Morse[26]={
    ".-",
    "-...",
    "-.-.",
    "-..",
    ".",
    "..-.",
    "--.",
    "....",
    "..",
    ".---",
    "-.-",
    ".-..",
    "--",
    "-.",
    "---",
    ".--.",
    "--.-",
    ".-.",
    "...",
    "-",
    "..-",
    "...-",
    ".--",
    "-..-",
    "-.--",
    "--..",
};

struct Trie{
    int mark;
    struct Trie *p[2];
};
struct Trie root;
void init(struct Trie *p)
{
    p->mark=0;
    p->p[0]=p->p[1]=NULL;
}
void clear(struct Trie *p)
{
    if(p->p[0]){
        clear(p->p[0]);
        free(p->p[0]);
    }
    if(p->p[1]){
        clear(p->p[1]);
        free(p->p[1]);
    }
}
void insert(struct Trie *t,char *p)
{
    int next=(*p=='-');
    /*if(*p=='\0') t->mark=1;*//*WA::2684406 2007-11-24 16:55:15 Wrong Answer 1387 C 00:00.22 8392K �錄�� */
    if(*p=='\0') t->mark++;
    else{
        if(t->p[next]==NULL) init(t->p[next]=(struct Trie*)malloc(sizeof(struct Trie)));
        insert(t->p[next],p+1);
    }
}

char code[11111];
int len;
int dp[11111];

void doit(struct Trie *p,int t,int begin)
{
    if(p->mark) dp[t]+=dp[begin]*p->mark;
    switch(code[t]){
    case '.':if(p->p[0]) doit(p->p[0],t+1,begin);return;
    case '-':if(p->p[1]) doit(p->p[1],t+1,begin);return;
    default:return;
    }
}

int main()
{
    int re;
    int i,n;
    char cur[22],tmp[1024];

    scanf("%d",&re);
    while(re--){
        scanf("%s",code);
        len=strlen(code);
        scanf("%d",&n);
        init(&root);
        while(n--){
            scanf("%s",cur);
            strcpy(tmp,"");
            for(i=0;cur[i];i++)
                strcat(tmp,Morse[cur[i]-'A']);
            insert(&root,tmp);
        }
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        for(i=0;i<len;i++)
            if(dp[i]) doit(&root,i,i);
        clear(&root);
        printf("%d\n",dp[len]);
    }
}
/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2684411 2007-11-24 17:02:35 Accepted 1387 C 00:00.21 8388K �錄�� */

/* //��Tire�� */
/* //�������word���Ļ���Tire�죬ps�ռ�Ҳ��~����Hash�� */
/*
faint!

--  ���ߣ�kuuga
--  ����ʱ�䣺2006-5-19 21:45:55

--

¥�ϵ��㷨Ӧ����N^2���㷨

������10000*10000               ///10000*100

����ÿ�ζ�Ҫ�ж�һ�������Ƿ���Ӵ�ƥ��

����20������������ô��

��Ȼ������0.17S�ڹ�

ʵ�ڲ����ף�

--------------------------------------------------------------------------------

--  ���ߣ��׹�����
--  ����ʱ�䣺2007-1-28 20:58:35

--
2204291 2007-01-21 20:54:17 Accepted 1387 C++ 00:00.12 1620K Crux.D
�кܶ಻��Ҫƥ���

*/

// 2012-09-07 00:48:01 | Accepted | 1387 | C | 90 | 8132 | watashi | Source
