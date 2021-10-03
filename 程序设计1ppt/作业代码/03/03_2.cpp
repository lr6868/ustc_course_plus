#include<iostream>
#include<windows.h>
int days(int month);
using namespace std;
int main()
{
	int year,month,ans,days,cen;
	cin>>year>>month;
	if(year<1600) //�ж������Ƿ�Ϸ�������û�涨������2100����ǰ�� 
	{
		MessageBox(NULL,"The year must be greater than 1600!","Error",MB_OK);
		return 0;
	}
	if(month<1||month>12)
	{
		MessageBox(NULL,"Invalid month!","Error",MB_OK);
		return 0;
	} 
	if(month==2&&(year%4==0&&year%100!=0||year%400==0)) days=29; //�ж�2���Ƿ���29�� 
	else //�жϸ����м��� 
	{
		switch(month)
		{
			case 1:days=31;break;
			case 2:days=29;break;
			case 3:days=31;break;
			case 4:days=30;break;
			case 5:days=31;break;
			case 6:days=30;break;
			case 7:days=31;break;
			case 8:days=31;break;
			case 9:days=30;break;
			case 10:days=31;break;
			case 11:days=30;break;
			case 12:days=31;break;
			default:break;
		}
		
	}
	if(month==1||month==2) //Ϊ���ò��չ�ʽ 
	{
		month+=12;
		year--;
	}
	cen=year/100;
	year%=100;
	ans=(year+year/4+cen/4-2*cen+26*(month+1)/10)%7; //���ò��չ�ʽ�������һ�������ڼ� 
	cout<<"Sun\tMon\tTur\tWed\tThu\tFri\tSat\t"<<endl; //��ӡ��ʽ������ 
	for(int i=1;i<=ans;i++) cout<<"\t";
	for(int i=1;i<=days;i++)
	{
		cout<<i<<"\t";
		if((i+ans)%7==0) cout<<endl;
	}
	system("pause");
	return 0;
}
