#include<iostream>
#include<string>
#define MAXN 10000
using namespace std;
class formula //���ʽ�� 
{
	public:
		string expr=" "; //���ַ�����ʽ��ʾ���ʽ 
		char last_op='n'; //���һ��������������Ϊn��ʾ���ʽ��һ���� 
};
class stack //�ֶ�дջ 
{
	public:
		formula top();
		void push(formula s);
		void pop();
	private:
		formula data[MAXN]; //���������沨��ʽ��ֵ��ͬ���ǣ����ñ��ʽ�����ǽ����ջԪ�� 
		int len=0;
};
formula stack::top()
{
	return data[len-1];
}
void stack::push(formula s)
{
	data[len++]=s;
}
void stack::pop()
{
	data[--len].expr=" ";
	data[len].last_op='n';
}
int main()
{
	stack expression;
	char input;
	while((input=getchar())!='\n')
	{
		string tmp=" ";
		tmp[0]=input;
		formula top_now; //��Ҫѹ��ջ�����±��ʽ 
		if(tmp[0]>='0'&&tmp[0]<='9') //�������� 
		{
			top_now.expr=tmp;
			top_now.last_op='n';
			expression.push(top_now);
		}
		else //��������� 
		{
			formula top1,top2;
			top1=expression.top();
			expression.pop();
			top2=expression.top();
			expression.pop();
			if(input=='+'||input=='-')
			{
				if(top1.last_op=='+'||top1.last_op=='-') top1.expr="("+top1.expr+")"; //���Ǹ�top1���߼����ţ��������� 
				top_now.expr=top2.expr+tmp+top1.expr;
				top_now.last_op=input;
				expression.push(top_now);
			}
			else
			{
				if(top1.last_op!='n') top1.expr="("+top1.expr+")";
				if(top2.last_op=='+'||top2.last_op=='-') top2.expr="("+top2.expr+")";
				top_now.expr=top2.expr+tmp+top1.expr;
				top_now.last_op=input;
				expression.push(top_now);
			}
		}
	}
	cout<<expression.top().expr<<endl;
	return 0;
}
