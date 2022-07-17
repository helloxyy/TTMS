struct ticket
{
	char user_name[20];
	int Room;
	char movie_name[20];
	int n,m;
	int mon;
	int day,hour,min,sec;
	int s;
	struct ticket *next;
};
struct ticket * ticket;
void ticket_scanf();
void ticket_printf();

