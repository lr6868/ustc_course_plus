#include<stdio.h>
int visited[10]={0},factor[10]={1,1,2,6,24,120,720,5040,40320,362880},n; //visited��ʾÿ�������Ƿ��Ѿ������factor�洢0��9�Ľ׳� 
void output(int k,int round) //round��ʾ���Ҫ����ڼ������� 
{
	if(round>n) return;
	int th=(k-1)/factor[n-round],over=0,i; //th��ʾ��������ǰ��һλҪƫ�ƶ��٣�over��ʾ�Ѿ�ƫ���˶��� 
	for(i=1;i<=n;i++)
	{
		if(visited[i]==0&&over==th) break;
		if(visited[i]==0) over++;
	}
	visited[i]=1;
	printf("%d",i);
	output(k-th*factor[n-round],round+1);
}
int main()
{
	int k;
	scanf("%d %d",&n,&k);
	output(k,1);
	return 0;
}
