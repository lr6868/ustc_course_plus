#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
struct Node
{
	char name[50];
	Node* next;
};
void getline(char* s);
int main()
{
	Node *head,*ite,*tmp;
	FILE *file;
	file=fopen("data.dat","ab+"); 
	int opera,num;
	char name[50];
	int buf[50];
	head=new Node;
	strcpy(head->name,"");
	head->next=NULL;
	ite=head;
	while(!feof(file)&&fread(buf,sizeof(buf),1,file))
	{
		for(int i=0;i<50;i++) name[i]=buf[i];
		ite=new Node;
		strcpy(ite->name,name);
		ite->next=head->next;
		head->next=ite;
	}
	fclose(file);
	file=fopen("data.dat","wb");
	while(1)
	{
		system("cls");
		printf("please input your command.\n1:insert\n2:delete\n3:query\n4:quit\n");
		scanf("%d",&opera);
		if(opera==1) //���� 
		{
			printf("Please input the name:");
			getline(name);
			ite=new Node;
			strcpy(ite->name,name);
			ite->next=head->next;
			head->next=ite;
			printf("%s inserted!\n",name);
			getch();
		}
		else if(opera==2) //ɾ�� 
		{
			printf("Please input the name:");
			getline(name);
			for(ite=head;ite->next!=NULL;ite=ite->next)
			{
				if(strcmp(ite->next->name,name)==0)
				{
					tmp=ite->next;
					ite->next=ite->next->next;
					
					free(tmp);
					break;
				}
			}
			printf("%s deleted!\n",name);
			getch();
		}
		else if(opera==3)//���� 
		{
			printf("Please input the name:");
			getline(name);
			num=0;
			for(ite=head;ite!=NULL;ite=ite->next)
			{
				if(strcmp(ite->name,name)==0)
				{
					num++;
				}
			}
			if(num==0) 
			{
				Beep(1000,300);
				MessageBox(NULL,"NOT FOUND!","Not found",MB_OK);
				
			}
			else 
			{
				printf("%d book(s) found.\n",num);
				getch();
			}
		}
		else
		{
			for(ite=head->next;ite!=NULL;ite=ite->next)
			{
				for(int i=0;i<50;i++) buf[i]=ite->name[i];
				fwrite(buf,sizeof(buf),1,file);
			}
			fclose(file);
			break;
		}
	}
	return 0;
}
void getline(char* s)
{
	char ch;
	int cnt=0;
	ch=getchar();
	while((ch=getchar())!='\n')
	{
		s[cnt]=ch;
		cnt++;
	}
	s[cnt]=0;
}
