#include<cstdio>
#include<windows.h>
int line[505][505],girl[505],k,m; //girl[i]�����i��Ů����npy
bool found(int x) //��x��Ů�� 
{
	if(x==m+1) return 1;
    for(int i=1; i<=m; i++)
    	if(line[x][i]&&!girl[i]) //���ݷ� 
		{
			girl[i]=x;
			if(found(x+1)) return 1;
			girl[i]=0;
		} 
    return 0;
}
int main()
{
    int x,y; 
	scanf("%d",&k); //���������� 
	scanf("%d",&m); //�������� 
    for(int i=0; i<k; i++)
    {
        scanf("%d %d",&x,&y); //ע�⣺����x y��ʾʵ����x��y������һ�� 
        line[x][y]=1;
    }
    system("cls");found(1); 
    for(int i=1; i<=m; i++) printf("%d��npy��%d\n",girl[i],i);system("pause");
    return 0;
}
