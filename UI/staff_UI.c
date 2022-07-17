char user[20];
void staff_UI()
{
	fflush(stdin);
	printf("\t\t\t ----------------------\n");
	printf("\t\t\t|       员工系统       |\n");
	printf("\t\t\t|                      |\n"); 
	printf("\t\t\t|      1. 影票出售     |\n");
	printf("\t\t\t|                      |\n");
	printf("\t\t\t|      2. 顾客退票     |\n");
	printf("\t\t\t|                      |\n");	
	printf("\t\t\t|      3. 坏座添加     |\n");
	printf("\t\t\t|                      |\n");	
	printf("\t\t\t|      4. 今日销售额   |\n");
	printf("\t\t\t|                      |\n");
	printf("\t\t\t|      5. 密码修改     |\n");//员工密码修改 
	printf("\t\t\t|                      |\n");
	printf("\t\t\t|      6. 查询演出票   |\n");
	printf("\t\t\t|                      |\n");
	printf("\t\t\t|      7. 更换场次     |\n");
	printf("\t\t\t|                      |\n");
	printf("\t\t\t|      8. 演出计划查询 |\n");
	printf("\t\t\t|                      |\n");
	printf("\t\t\t|      9.   退出       |\n");
	printf("\t\t\t|                      |\n");
	printf("\t\t\t ----------------------\n");
	printf("\t\t\t ");
while(1)
{
	char operation;
	operation=getch();
	switch(operation)
	{
		case '1': system("cls"); movie_sale()   ; return; 
		case '2': system("cls"); movie_return()   ; return;   
		case '3':  system("cls");seat_brokenadd()    ; return;  
		case '4':  system("cls");
		printf("\n\t\t\t%s今日销售额为：%.2lf",nowuser.username,yj(nowuser.username,1));
		printf("\n\t\t\t按任意键返回");
		getch();
		system("cls");
		staff_UI();     return;                          
		case '5': system("cls");password_UI(3); return;
		case '6': system("cls");search_print();	return;	
		case '7': system("cls");reset_count();  return;
		case '8': system("cls");search_plan();  return;
		case '9': system("cls"); home(0) ; return ;
		default: printf("\n\t\t\t输入错误，请重新输入:\n");  break;
	}
	 
}
return ;
}
void movie_sale()
{
	fflush(stdin);
	struct seat *t=seatlist->next;
	printf("\n\t\t\t放映列表\n")	  ;
	while(t!=NULL)
	{
		printf("\n\t\t\t\t%d号厅\t\t正在放映：%s\n",t->ID,t->movie_name)	  ;
		t=t->next;
	}
	printf("\n\t\t\t请输入影厅序号：") ;
	int a=0; 
	char operation;
while(1)
{
	
	operation=getch();
	switch(operation)
	{
		case '1':  a=1;break;
		case '2':  a=2;break;
		case '3':  a=3;break;  
		case '4':  a=4;break;   
		default: printf("\n\t\t\t输入错误，请重新输入:\n")	  ;  break;
	}
	
	 if(a!=0) break;
}
t=seat_find(a);
system("cls");
seat_print(t);
printf("\n");
printf("\n\t\t\t\t请输入N:");
int i,n,m;
char ss[1000];
double pp;
scanf("%s",ss);
for(i=0;i<strlen(ss);i++)
{
	if(ss[i]<'0'||ss[i]>'9')
	{
		printf("\n\t\t\t输入错误，按任意键返回");
			getch();
			system("cls");
			staff_UI();
		return; 
	}
}
pp=strtod(ss,NULL);
n=(int)pp;

printf("\n\t\t\t\t请输入M:")	  ;
scanf("%s",ss);
for(i=0;i<strlen(ss);i++)
{
	if(ss[i]<'0'||ss[i]>'9')
	{
		printf("\n\t\t\t输入错误，按任意键返回");
			getch();
			system("cls");
			staff_UI();
		return; 
	}
}
pp=strtod(ss,NULL);
m=(int)pp;
printf("\t\t\t\t请输入用户名：");
scanf("%s",user);

if(n<t->n&&n<t->m&&n>=0&&m>=0&&t->seat[n][m]==1)
{
	struct ticket* p=(struct ticket *)malloc(sizeof(struct ticket));
	struct time tml = time_print_BLL();
	p->Room = a;
	strcpy(p->movie_name,t->movie_name);
	strcpy(p->user_name,user);
	p->n = n;
	p->m = m;
	p->mon = tml.mon;
	p->day = tml.day;
	p->hour = tml.hour;
	p->min = tml.min;
	p->sec = tml.sec;
	p->s = 1;
	ticket_add(p);
	t->seat[n][m]=2;
	seat_printf();
	data_add(nowuser.username,t->movie_name,1);	
	printf("\n\t\t\t出售成功，票面如下：");
	printf("\n\t\t\t ==============================================================\t\t") ;
	printf("\n\t\t\t\t\t\t-姐妹花影院电影票-\t\t");
	printf("\n\t\t\t|影厅号：ROOM %d\t\t\t影名:%10s\t\t\t|",p->Room,p->movie_name);
	printf("\n\t\t\t|用户名:%10s\t\t座位号：第%d行第%d列\t\t|",p->user_name,p->n,p->m);
	printf("\n\t\t\t|日期:%d/%d %d:%d:%d\t\t销售员:%s\t\t\t|",p->mon,p->day,p->hour,p->min,p->sec,nowuser.username);
	printf("\n\t\t\t|\t   请您文明观影，祝您观影愉快！\t\t\t\t|");
	printf("\n\t\t\t ===============================================================\t\t") ;
	printf("按任意键返回..."); 
	getch();
	system("cls");
	staff_UI();
}
else
{
	printf("\nt\t\t\t此座位无法出售，按任意键返回");
	getch();
	system("cls");
	staff_UI();
}
	
	return ;
}

void seat_brokenadd()  
{
	fflush(stdin);
	printf("\n\t\t\t请输入影厅序号：") ;
	int a=0; 
	char operation;
while(1)
{
	
	operation=getch();
	switch(operation)
	{
		case '1':   a=1;break;
		case '2':  	a=2;break;
		case '3':   a=3;break;  
		case '4': 	a=4;break;   
		default: printf("\t\t\t输入错误，请重新输入:\n")	  ;  break;
	}
	
	 if(a!=0) break;
}


	struct seat *t=seat_find(a);
	seat_print(t);
	
printf("\n");
printf("\n\t\t\t请输入N:")	  ;
int i,n,m;
char ss[1000];
double pp;
scanf("%s",ss);
for(i=0;i<strlen(ss);i++)
{
	if(ss[i]<'0'||ss[i]>'9')
	{
		printf("\n\t\t\t输入错误，按任意键返回");
			getch();
			system("cls");
			staff_UI();
		return; 
	}
}
pp=strtod(ss,NULL);
n=(int)pp;

printf("\n\t\t\t请输入M:")	  ;
scanf("%s",ss);
for(i=0;i<strlen(ss);i++)
{
	if(ss[i]<'0'||ss[i]>'9')
	{
		printf("\n\t\t\t输入错误，按任意键返回");
			getch();
			system("cls");
			staff_UI();
		return; 
	}
}
pp=strtod(ss,NULL);
m=(int)pp;
if(n<t->n&&n<t->m&&n>=0&&m>=0)
{
	t->seat[n][m]=3;
	seat_printf();	
	printf("\n\t\t\t添加成功，按任意键返回");
	getch();
	system("cls");
	staff_UI();
}
else
{
		printf("\n\t\t\t座位输入错误，按任意键返回");
	getch();
	system("cls");
	staff_UI();
}
  }  
  
void movie_return()
{
	fflush(stdin);
	struct seat *t;
	printf("\n\t\t\t请输入影厅序号：") ;
	int a=0; 
	char operation;
while(1)
{
	
	operation=getch();
	switch(operation)
	{
		case '1':   a=1;break;
		case '2':  	a=2;break;
		case '3':   a=3;break;  
		case '4': 	a=4;break;   
		default: printf("\n\t\t\t输入错误，请重新输入:\n")	  ;  break;
	}
	
	 if(a!=0) break;
}
t=seat_find(a);
printf("\n");
printf("\n\t\t\t请输入行号:")	  ;
int i,n,m;
char ss[1000];
double pp;
scanf("%s",ss);
for(i=0;i<strlen(ss);i++)
{
	if(ss[i]<'0'||ss[i]>'9')
	{
		printf("\n\t\t\t输入错误，按任意键返回");
			getch();
			system("cls");
			staff_UI();
		return; 
	}
}
pp=strtod(ss,NULL);
n=(int)pp;

printf("\n\t\t\t请输入列号:")	  ;
scanf("%s",ss);
for(i=0;i<strlen(ss);i++)
{
	if(ss[i]<'0'||ss[i]>'9')
	{
		printf("\n\t\t\t输入错误，按任意键返回");
			getch();
			system("cls");
			staff_UI();
		return; 
	}
}
pp=strtod(ss,NULL);
m=(int)pp;

if(n<t->n&&n<t->m&&n>=0&&m>=0&&t->seat[n][m]==2)
{
	t->seat[n][m]=1;
	seat_printf();
	ticket_delete_BLL(n,m); 
	///////////////////////
	data_add(nowuser.username,t->movie_name,2);
	printf("\n\t\t\t退票成功，按任意键返回");
	getch();
	system("cls");
	staff_UI();
}
else
{
	printf("\n\t\t\t查无此票，按任意键返回");
	getch();
	system("cls");
	staff_UI();
}
	
	return ;
}   




void search_print()
{
	printf("\n\t\t\t\t请输入查询顾客的姓名ID：");
	char name[20];
	gets(name);
	ticket_search_BLL(name);
	printf("\n\t\t\t按任意键返回");
	getch();
	system("cls");
	staff_UI();
} 


void reset_count()
{
	printf("\n\t\t\t请选择场次：");
	int n;
	scanf("%d",&n);
	struct plan* k = plan->next;
	struct seat* t = seatlist->next;
	int i,j;
	while(k!=NULL)
	{

		if(k->num==n)
			{
				strcpy(t->movie_name,k->plan_name);	
				for(i=0;i<10;i++)
				{
					for(j=0;j<10;j++)
					{
						if(t->seat[i][j]==2)
						{
							t->seat[i][j]=1;
						}
					}
				}
				seat_printf(); 
				
				t=t->next;
			}	
		
		 
		k=k->next;
	}
	printf("\n\t\t\t场次修改成功！！！,按任意键返回");
	getch();
	system("cls");
	staff_UI();	
}


void search_plan()
{
	struct plan* t = plan->next;
	printf("\n\t\t\t请选择要查询的方式"); 
	printf("\n\t\t\t1.\t全部计划");
	printf("\n\t\t\t2.\t按场次查找\n\t\t\t");
	int a; 
	
	scanf("%d",&a);
	if(a==1)
	{
		system("cls");
		int i=0; 
		while(t!=NULL&&i<5)
		{
			printf("\n\t\t\t%d\troom%d\t%-10s\t%-10s\n",t->num,t->plan_id,t->plan_name,t->plan_time);
			t=t->next;
			i++;
			if(i==4)
			{
				i=0;
				getch();
				system("cls");
			}
		}
		printf("\n\t\t\t按任意键返回");
		getch();
		system("cls");
		staff_UI();	
		 
	}
	else if(a==2)
	{
		system("cls");
		printf("\n\t\t\t请输入查询场次：");
		int s,op=1;
		scanf("%d",&s); 
		
		while(t!=NULL)
		{
			if(t->num==s)
			{
			printf("\n\t\t\t%d\troom%d\t%s\t%s\n",t->num,t->plan_id,t->plan_name,t->plan_time);
			op=0;
			}
			t=t->next;
		}
		if(op==0)
		{
		printf("\n\t\t\t按任意键返回");
		getch();
		system("cls");
		staff_UI();	
		}
		else
		{
			printf("\n\t\t\t您输入的场次不正确！！"); 
			printf("\n\t\t\t按任意键返回");
			getch();
			system("cls");
			staff_UI();	
		}
	}
	else
	{
		printf("\n\t\t\t您的操作不正确！！"); 
		printf("\n\t\t\t按任意键返回");
			getch();
			system("cls");
			staff_UI();		
	}
}










































