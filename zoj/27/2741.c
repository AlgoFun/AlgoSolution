#include<stdio.h>
char *doit(char *p,double *res)
{
    double tmp;
    char *q;

    for(q=p;*q;q++)
        if(*q==',') *q=' ';
        else if(*q==')') *q=' ';
        else if(*q=='(') {q++;break;}
    sscanf(p,"%lf%lf",res,&tmp);
    return q;

}
int main()
{
    char line[1024],*p;
    double x0,xx,xa,xb,t;

    while(gets(line)){
        p=line+1;
        p=doit(p,&x0);
        p=doit(p,&xx);
        p=doit(p,&xa);
        p=doit(p,&xb);
        if(xa<xb){t=xa;xa=xb;xb=t;}
        while(*p){
            p=doit(p,&t);
            if(t>=xa){xb=xa;xa=t;}
            else if(t>xb) xb=t;
        }
        if(x0>0&&x0>xx&&x0>xb) printf("Offside\n");
        else printf("PlayOn\n");
    }
}
/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2595472 2007-09-04 01:58:54 Accepted 2741 C 00:00.00 392K �錄�� */
/* //2595471 2007-09-04 01:58:44 Accepted 2741 C++ 00:00.00 392K �錄�� */




/*
����̫ws�� ������ʵ�Ǹ����Ͷ���������

Խλ���жϾ��� �ڱ����볡��Խλ���������ڱ����볡�ڣ�

�ڶԷ��볡ʱֻҪ�ȵ����ڶ������ض�Ա�������߾���Խλ
*/

// 2012-09-07 01:37:24 | Accepted | 2741 | C | 0 | 160 | watashi | Source
