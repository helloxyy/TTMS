void movie_list_UI(int ste)
{
	//fflush(stdin);
	struct movie_list *t;
	t=movielist;
	t=t->next;
	printf("\nӰƬ�б�չʾ��������˳�ҳ����ѡ��\"S\"���в�����������һҳ��A����һҳ��D��������") ;
	printf("\n%-10s\t%-60s%-20s\n","Ƭ��","����","Ƭ��");
	char ap;
	struct movie_list* a[100]={NULL};
	int i=1,j=1;
	for(i=1;t!=NULL;i++)
	{	
		if((i%NP) == 0)
		{
			a[j] = t;
			j++;
		}
		t=t->next;
	}
	int q = i;
	t=movielist;
	t=t->next;
	i=1;
	a[0]=movielist;
	while(t!=NULL)
	{
		printf("\n%-s\t%-60s%-20s\n",t->movie_chinese_name,t->movie_performer,t->movie_time);
		if(i==q/NP) 
		{
			printf("\n\t\t\t��һҳ��A��\n");
			printf("ִ�в�����");
			ap=getchar();
			getchar();
			if((ap=='A')||(ap=='a'))
			{
				i--;
				t->next = a[i-1]->next;
			}
			else if((ap=='d')||(ap=='D'))
			{
				t = a[i]->next; 
				i++;
				
			}
			else if((ap=='s')||(ap=='S'))
			{
				printf("�������������һ��");
				getch();
				system("cls");
				if(ste==0)
				tourist_UI();
				else if(ste==1)
				user_UI();
				else if(ste==2)
				movie_manager_UI();
				return;
			}
			system("cls");
			printf("\nӰƬ�б�չʾ��������˳�ҳ����ѡ��\"S\"���в�����������һҳ��A����һҳ��D��������") ;
			printf("\n%-10s\t%-60s%-20s\n","Ƭ��","����","Ƭ��");
		}
		t=t->next;
		if(a[i]->next==t)
		{
			if(i==1)
			{
				printf("\n\t\t\t��һҳ��D��\n");
				printf("ִ�в�����");
 
			}
			else if(a[i]->next!=NULL)
			{
				printf("\n\t\t\t��һҳ��A��|��һҳ��D��\n");
				printf("ִ�в�����");
			}
			ap=getchar();
			getchar();
			if((ap=='A')||(ap=='a'))
			{
				i--;
				t = a[i-1]->next;
			}
			else if((ap=='d')||(ap=='D'))
			{
				t = a[i]->next; 
				i++;
				
			}
			else if((ap=='s')||(ap=='S'))
			{
				printf("�������������һ��");
				getch();
				system("cls");
				if(ste==0)
				tourist_UI();
				else if(ste==1)
				user_UI();
				else if(ste==2)
				movie_manager_UI();
				return;
			}
			else
			{
				printf("\n����ʧ��!!!�����ϣ���");
				getch();
				system("cls");
				if(ste==0)
				tourist_UI();
				else if(ste==1)
				user_UI();
				else if(ste==2)
				movie_manager_UI();
			}
			system("cls");
			printf("\nӰƬ�б�չʾ��������˳�ҳ����ѡ��\"S\"���в�����������һҳ��A����һҳ��D��������") ;
			printf("\n%-10s\t%-60s%-20s\n","Ƭ��","����","Ƭ��");
		} 
		
	}
	printf("�������������һ��");
	getch();
	system("cls");
	if(ste==0)
	tourist_UI();
	else if(ste==1)
	user_UI();
	else if(ste==2)
	movie_manager_UI();
	return;

}

void movie_find_UI(int ste)
{
	fflush(stdin);
	system("cls");
	printf("\t\t\t ----------------------\n");
	printf("\t\t\t|        ӰƬ����      |\n");
	printf("\t\t\t|                      |\n"); 
	printf("\t\t\t|     1. ��Ƭ������    |\n");
	printf("\t\t\t|                      |\n"); 	
	printf("\t\t\t|     2. �����ݲ���    |\n");
	printf("\t\t\t|                      |\n"); 	
	printf("\t\t\t|     3.   �˳�        |\n");
	printf("\t\t\t ----------------------\n")	;
	printf("\t\t\t ")	;
	char operation;
	while(1)
	{
	operation=getch();
	switch(operation)
	{
		case '1':  system("cls")  ;movie_find1_UI(ste);  return;  
		case '2':  system("cls")  ;movie_find2_UI(ste);  return;  
		case '3':  
		{							system("cls")  ;	
			 	   				  	if(ste==0)
			 	   				  	tourist_UI();
	 								else if(ste==1)
									user_UI();
									else if(ste==2)
									movie_manager_UI(); 
									return;
		}
		default:   printf("\n\t\t\t �����������������")	; 
	}

	}
}
void movie_find1_UI(int ste)
{
	fflush(stdin);
	struct movie_list *t;
	t=movielist;
	t=t->next;
	printf("\t\t\t ����ӰƬ���ƣ�");
	char s[100];
	scanf("%s",s); 
	while(t!=NULL)
	{
		if(strcmp(s,t->movie_chinese_name)==0)
		{
			movie_print_UI(t);
			printf("\t\t\t�����������");
			getch();
			movie_find_UI(ste);
			return ;
		}
		t=t->next;
	}
	t=movielist;
	t=t->next;
	int x=0;
	while(t!=NULL)
	{
		if(strstr(t->movie_chinese_name,s)!=NULL)
		{
			x=1;
			break;
		}
		t=t->next;
	}
	t=movielist;
	t=t->next;
	if(x==1) printf("\t\t\tû�ҵ�ѽ����Ҫ�ҵ��ǲ��ǣ�\n");
	else
	{
		printf("\t\t\tδ�ҵ�ӰƬ������������أ�\n");
		getch();
		movie_find_UI(ste);
		return ;
	}
	printf("\n%-10s\t%-60s%-20s\n","Ƭ��","����","Ƭ��");
	while(t!=NULL)
	{
		if(strstr(t->movie_chinese_name,s)!=NULL)
		{
			printf("\n%-s\t%-60s%-20s\n",t->movie_chinese_name,t->movie_performer,t->movie_time);
		}
		t=t->next;
	}
	printf("\t\t\t����������أ�");
	getch();
	movie_find_UI(ste);
	return ;
	
}
void movie_find2_UI(int ste)
{
	fflush(stdin);
	struct movie_list *t;
	t=movielist;
	t=t->next;
	printf("\t\t\t ��������������");
	char s[100];
	scanf("%s",s); 
	t=movielist;
	t=t->next;
	int x=0;
	while(t!=NULL)
	{
		if(strstr(t->movie_performer,s)!=NULL)
		{
			x=1;
			break;
		}
		t=t->next;
	}
	t=movielist;
	t=t->next;
	if(x!=1) 
	{
		printf("\t\t\tδ�ҵ�������Ϣ������������أ�\n");
		getch();
		movie_find_UI(ste);
		return ;
	}
	printf("\n%-10s\t%-60s%-20s\n","Ƭ��","����","Ƭ��");
	while(t!=NULL)
	{
		if(strstr(t->movie_performer,s)!=NULL)
		{
			printf("\n%-s\t%-60s%-20s\n",t->movie_chinese_name,t->movie_performer,t->movie_time);
		}
		t=t->next;
	}
	printf("\t\t\t����������أ�");
	getch();
	movie_find_UI(ste);
	return ;
}
void movie_print_UI(struct movie_list *t)
{
	fflush(stdin);
	system("cls");
	int i;
	for(i=0;i<189;i++)
	printf("=") ;
	printf("\n ӰƬ�� ��%-30s Ӣ������%-60s\n",t->movie_chinese_name,t->movie_english_name);
	printf("  ����  ��%-30s ��Ա ��%-60s\n",t->movie_director,t->movie_performer);
	printf("��Ʒ��˾��%-30s ��Ƭ�ˣ�%-60s\n",t->movie_company,t->movie_producer);
	printf(" ����� ��%-30s ��� ��%-60s\n",t->movie_location,t->movie_screenwriter);
	printf("�����飺\n");
	printf("%s\n\n",t->movie_brief);
		for(i=0;i<189;i++)
	printf("=") ;
	
	
	
	
	return ;
 } 
 
 
 
 
void movie_0find(char *s)
{
	fflush(stdin);
	struct movie_list *t;
	t=movielist;
	t=t->next;
	int x=0;
	while(t!=NULL)
	{
		if(strstr(t->movie_chinese_name,s)!=NULL)
		{
			x=1;
			break;
		}
		t=t->next;
	}
	t=movielist;
	t=t->next;
	if(x==1)
	{
		printf("\n\t\t\tû�ҵ�ѽ����Ҫ�ҵ��ǲ��ǣ�\n");
		printf("\n%-10s\t%-60s%-20s\n","Ƭ��","����","Ƭ��");
	}
	while(t!=NULL)
	{
		if(strstr(t->movie_chinese_name,s)!=NULL)
		{
			printf("\n%-s\t%-60s%-20s\n",t->movie_chinese_name,t->movie_performer,t->movie_time);
		}
		t=t->next;
	}
	return ;	
}
