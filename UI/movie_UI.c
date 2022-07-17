void movie_list_UI(int ste)
{
	//fflush(stdin);
	struct movie_list *t;
	t=movielist;
	t=t->next;
	printf("\n影片列表展示：如果想退出页面请选择\"S\"进行操作！！！上一页（A）下一页（D）！！！") ;
	printf("\n%-10s\t%-60s%-20s\n","片名","主演","片长");
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
			printf("\n\t\t\t上一页（A）\n");
			printf("执行操作：");
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
				printf("按任意键返回上一层");
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
			printf("\n影片列表展示：如果想退出页面请选择\"S\"进行操作！！！上一页（A）下一页（D）！！！") ;
			printf("\n%-10s\t%-60s%-20s\n","片名","主演","片长");
		}
		t=t->next;
		if(a[i]->next==t)
		{
			if(i==1)
			{
				printf("\n\t\t\t下一页（D）\n");
				printf("执行操作：");
 
			}
			else if(a[i]->next!=NULL)
			{
				printf("\n\t\t\t上一页（A）|下一页（D）\n");
				printf("执行操作：");
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
				printf("按任意键返回上一层");
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
				printf("\n操作失误!!!不符合！！");
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
			printf("\n影片列表展示：如果想退出页面请选择\"S\"进行操作！！！上一页（A）下一页（D）！！！") ;
			printf("\n%-10s\t%-60s%-20s\n","片名","主演","片长");
		} 
		
	}
	printf("按任意键返回上一层");
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
	printf("\t\t\t|        影片查找      |\n");
	printf("\t\t\t|                      |\n"); 
	printf("\t\t\t|     1. 按片名查找    |\n");
	printf("\t\t\t|                      |\n"); 	
	printf("\t\t\t|     2. 按主演查找    |\n");
	printf("\t\t\t|                      |\n"); 	
	printf("\t\t\t|     3.   退出        |\n");
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
		default:   printf("\n\t\t\t 输入错误，请重新输入")	; 
	}

	}
}
void movie_find1_UI(int ste)
{
	fflush(stdin);
	struct movie_list *t;
	t=movielist;
	t=t->next;
	printf("\t\t\t 输入影片名称：");
	char s[100];
	scanf("%s",s); 
	while(t!=NULL)
	{
		if(strcmp(s,t->movie_chinese_name)==0)
		{
			movie_print_UI(t);
			printf("\t\t\t按任意键返回");
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
	if(x==1) printf("\t\t\t没找到呀，你要找的是不是：\n");
	else
	{
		printf("\t\t\t未找到影片，按任意键返回：\n");
		getch();
		movie_find_UI(ste);
		return ;
	}
	printf("\n%-10s\t%-60s%-20s\n","片名","主演","片长");
	while(t!=NULL)
	{
		if(strstr(t->movie_chinese_name,s)!=NULL)
		{
			printf("\n%-s\t%-60s%-20s\n",t->movie_chinese_name,t->movie_performer,t->movie_time);
		}
		t=t->next;
	}
	printf("\t\t\t按任意键返回：");
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
	printf("\t\t\t 输入主演姓名：");
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
		printf("\t\t\t未找到主演信息，按任意键返回：\n");
		getch();
		movie_find_UI(ste);
		return ;
	}
	printf("\n%-10s\t%-60s%-20s\n","片名","主演","片长");
	while(t!=NULL)
	{
		if(strstr(t->movie_performer,s)!=NULL)
		{
			printf("\n%-s\t%-60s%-20s\n",t->movie_chinese_name,t->movie_performer,t->movie_time);
		}
		t=t->next;
	}
	printf("\t\t\t按任意键返回：");
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
	printf("\n 影片名 ：%-30s 英文名：%-60s\n",t->movie_chinese_name,t->movie_english_name);
	printf("  导演  ：%-30s 演员 ：%-60s\n",t->movie_director,t->movie_performer);
	printf("出品公司：%-30s 制片人：%-60s\n",t->movie_company,t->movie_producer);
	printf(" 拍摄地 ：%-30s 编剧 ：%-60s\n",t->movie_location,t->movie_screenwriter);
	printf("剧情简介：\n");
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
		printf("\n\t\t\t没找到呀，你要找的是不是：\n");
		printf("\n%-10s\t%-60s%-20s\n","片名","主演","片长");
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
