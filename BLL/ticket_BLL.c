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
	printf("�޴��Error");

}

void ticket_search_BLL(char* username)
{
	struct ticket*p;
	p=ticket;
	while(p->next!=NULL)
	{
		if((strcmp(username,p->user_name))==0)
		{
			printf("\n\t\t\t���ã���ID�ĵ���Ʊ���£�");
			printf("\n\t\t\t ==============================================================\t\t") ;
			printf("\n\t\t\t\t\t\t-���û�ӰԺ��ӰƱ-\t\t");
			printf("\n\t\t\t|Ӱ���ţ�ROOM %d\t\t\tӰ��:%10s\t\t\t|",p->Room,p->movie_name);
			printf("\n\t\t\t|�û���:%10s\t\t��λ�ţ���%d�е�%d��\t\t|",p->user_name,p->n,p->m);
			printf("\n\t\t\t|����:%d/%d %d:%d:%d\t\t����Ա:%s\t\t\t|",p->mon,p->day,p->hour,p->min,p->sec,nowuser.username);
			printf("\n\t\t\t|\t   ����������Ӱ��ף����Ӱ��죡\t\t\t\t|");
			printf("\n\t\t\t ===============================================================\t\t") ;
			return;
		}
		p=p->next;
	}
	if(p->next==NULL)
	 	printf("����û����Ʊ����");

}
