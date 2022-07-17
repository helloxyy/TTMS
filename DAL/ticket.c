void ticket_scanf()
{
	FILE * fp;
	fp=fopen("./DAL/ticket.ini","r");
	if(fp==NULL)
	{
		printf("\t\t\t票件信息文件打开失败！！");
		getch();
		exit(0);
	}
	int room;
	char user_name[20];
	char movie_name[20];
	char number[20];
	int n,m;
	int mon,day,hour,min,sec;
	int s;
	struct ticket *head,*p,*q;
	head=(struct ticket *)malloc(sizeof(struct ticket));
	head->next=NULL;
	while(fscanf(fp,"%d %s %s %d %d %d %d %d %d %d",&room,movie_name,user_name,&n,&m,&mon,&day,&hour,&min,&sec)!=EOF) 
	{
		p=(struct ticket *)malloc(sizeof(struct ticket));
		p->Room = room;
		strcpy(p->movie_name,movie_name);
		strcpy(p->user_name,user_name);
		p->m = m;
		p->n = n;
		p->mon = mon;
		p->day = day;
		p->hour = hour;
		p->min = min;
		p->sec = sec;
		p->s = s;
		
		if(head->next==NULL)
		{
			head->next=p;
			q=p;
		}
		else
		{
			q->next=p;
			q=p;
		}	
	}
	fclose(fp);
	ticket=head;
	return;
}
void ticket_printf()
{
	FILE *fp;
	fp=fopen("./DAL/ticket.ini","w+");
	if(fp==NULL)
	{
		printf("\t\t\t票件信息文件打开失败！！");
		getch();
		exit(0);
	}
	struct ticket * t;
	t=ticket->next;
	int i,j;
	while(t!=NULL)
	{
		fprintf(fp,"%d %s %s %d %d %d %d %d %d %d\n",t->Room,t->movie_name,t->user_name,t->n,t->m,t->mon,t->day,t->hour,t->min,t->sec);
		t=t->next;
	}
	fclose(fp);
	return ;	
}
