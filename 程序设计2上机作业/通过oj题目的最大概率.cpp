#include<iostream>
#include<stdlib.h>
using namespace std;
int lines[100];
int max_lens[100]={0};
int n_lines=0; //һ���м��� 
int getelem(char* s) //�õ����ո�split��Ľ�������separate token�ǿո񣬷���1�����򷵻�0 
{
	int i=0;
	char c;
	while((c=getchar())!=' '&&c!='\n'&&c!=EOF)
		s[i++]=c;
	s[i]=0;
	return c==' '?1:0;
}
int max_line(int index) //ʹ�ö�̬�滮��� 
{
	if(index==n_lines-2) max_lens[index]=max(lines[index],lines[index+1]);
	else if(index==n_lines-1) max_lens[index]=lines[index];
	else max_lens[index]=max(lines[index]+(max_lens[index+2]==0?max_line(index+2):max_lens[index+2]),max_lens[index+1]==0?max_line(index+1):max_lens[index+1]);
    return max_lens[index];
}
int main()
{
	char tmp[5];
	while(getelem(tmp))
		lines[n_lines++]=atoi(tmp);
	lines[n_lines++]=atoi(tmp);
	cout<<max_line(0)<<endl;
	return 0;
}
