/*Codia����������ȡ���ߣ������ڲ�̫��Ĳ������ݣ�������Ҫ������python�ű�ģ���ύ����
ʹ�÷�������ʹ��check_spaces��ȡÿһ�е����ݸ�����Ȼ�����ÿһ��������check�������ֲ��ҡ�������ַ������ߴ���������Ҫ����Ӧ�޸ġ�
���������ݴ����趨��Χʱ����Ӧ�����н�����ΪRuntime Error���������н��һ��ΪWrong Answer�� 
*/ 
#include<stdlib.h>
#include<stdio.h> 
void re()
{
    printf("%d",0/0);
}
void check(int index,float a,float b)
{
    float f;
    for(int i=0;i<index-1;i++)
    {
        scanf("%f",&f);
    }
    scanf("%f",&f);
    if(f>=a&&f<=b) re();
}
int spaces(int enters)
{
    int i=0,enter=0;
    char c;
    chec:;
    if((c=getchar())==' ') i++;
    else if(c=='\n') enter++;
    if(enter==enters) return i;
    goto chec;
}
void check_spaces(int spacel,int spacer,int enters)
{
    int s=spaces(enters);
    if(s>=spacel&&s<=spacer) re();
}
