/*struct plan{
	int num;
	int plan_id;
	char plan_name[100];
	char plan_time[100];
	struct plan* next;
};*/
void plan_scanf()
{
	FILE * fp;
	fp=fopen("./DAL/plan.ini","r");
	if(fp==NULL)
	{
		printf("\t\t\t票件信息文件打开失败！！");
		getch();
		exit(0);
	}
	int num;
	int id;
	char plan_name[100];
	char plan_time[100]; 
	struct plan *head,*p,*q;
	head=(struct plan *)malloc(sizeof(struct plan));
	head->next=NULL;
	while(fscanf(fp,"%d %d %s %s",&num,&id,plan_name,plan_time)!=EOF) 
	{
		p=(struct plan *)malloc(sizeof(struct plan));
		p->num = num;
		p->plan_id = id;
		strcpy(p->plan_name,plan_name);
		strcpy(p->plan_time,plan_time);

		
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
	plan=head;
	return;
}
void plan_printf()
{
	FILE *fp;
	fp=fopen("./DAL/plan.ini","w+");
	if(fp==NULL)
	{
		printf("\t\t\t计划信息文件打开失败！！");
		getch();
		exit(0);
	}
	struct plan * t;
	t=plan->next;
	int i,j;
	while(t!=NULL)
	{
		fprintf(fp,"%d %d %s %s\n",t->num,t->plan_id,t->plan_name,t->plan_time);
		t=t->next;
	}
	fclose(fp);
	return ;	
}
