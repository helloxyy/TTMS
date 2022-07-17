struct time time_print_BLL()
{
	time_t l;
	struct tm* k;
	time(&l);
	k = localtime(&l);
	struct time t;
	t.mon=k->tm_mon+1;
	t.day=k->tm_mday;
	t.hour=k->tm_hour;
	t.min=k->tm_min;
	t.sec=k->tm_sec;
	return t;
}
