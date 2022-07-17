void plan_add(int num,int id,char* plan_name,char* plan_time)
{
	struct plan * t=(struct plan *)malloc(sizeof(struct plan));
	t->num=num;
	t->plan_id =id;
	strcpy(t->plan_name,plan_name);
	strcpy(t->plan_time,plan_time);
	t->next=plan->next;
	plan->next=t;
	plan_printf();
	return ;
}
