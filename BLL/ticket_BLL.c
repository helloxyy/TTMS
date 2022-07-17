void ticket_add(struct ticket* sk)
{
	struct ticket * t=(struct ticket *)malloc(sizeof(struct ticket));
	t->Room = sk->Room;
	strcpy(t->user_name,sk->user_name);
	strcpy(t->movie_name,sk->movie_name);
	t->n=sk->n;
	t->m=sk->m;
	t->mon = sk->mon;
	t->day = sk->day;
	t->hour = sk->hour;
	t->min = sk->min;
	t->sec = sk->sec;
	t->s = sk->s;
	t->next=ticket->next;
	ticket->next=t;
	ticket_printf();
	return ;
}

void ticket_delete_BLL(int n,int m)
{
	struct ticket * t,*p;
	t=ticket;
	while(t->next!=NULL)
	{
		if((n==t->n)&&(m==t->m))
		{
			t->s = 0;
			return;
		}
		t=t->next;
	}
	if(t->next==NULL)
	printf("无此项！Error");

}

void ticket_search_BLL(char* username)
{
	struct ticket*p;
	p=ticket;
	while(p->next!=NULL)
	{
		if((strcmp(username,p->user_name))==0)
		{
			printf("\n\t\t\t您好！此ID的电子票如下：");
			printf("\n\t\t\t ==============================================================\t\t") ;
			printf("\n\t\t\t\t\t\t-姐妹花影院电影票-\t\t");
			printf("\n\t\t\t|影厅号：ROOM %d\t\t\t影名:%10s\t\t\t|",p->Room,p->movie_name);
			printf("\n\t\t\t|用户名:%10s\t\t座位号：第%d行第%d列\t\t|",p->user_name,p->n,p->m);
			printf("\n\t\t\t|日期:%d/%d %d:%d:%d\t\t销售员:%s\t\t\t|",p->mon,p->day,p->hour,p->min,p->sec,nowuser.username);
			printf("\n\t\t\t|\t   请您文明观影，祝您观影愉快！\t\t\t\t|");
			printf("\n\t\t\t ===============================================================\t\t") ;
			return;
		}
		p=p->next;
	}
	if(p->next==NULL)
	 	printf("您还没有买票！！");

}
