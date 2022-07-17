struct plan{
	int num;
	int plan_id;
	char plan_name[100];
	char plan_time[100];
	struct plan* next;
};
struct plan* plan;
void plan_printf();
void plan_scanf();

