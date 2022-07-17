void manager_UI()
{
	fflush(stdin);
	printf("\t\t\t ----------------------\n");
	printf("\t\t\t|       经理系统       |\n");
	printf("\t\t\t|                      |\n"); 
	printf("\t\t\t|    1. 影片信息管理   |\n");
	printf("\t\t\t|                      |\n");	
	printf("\t\t\t|    2. 放映管理       |\n");
	printf("\t\t\t|                      |\n");	
	printf("\t\t\t|    3. 票房管理       |\n");
	printf("\t\t\t|                      |\n");
	printf("\t\t\t|    4. 售票情况       |\n");
	printf("\t\t\t|                      |\n");
	printf("\t\t\t|    5. 密码修改       |\n");
	printf("\t\t\t|                      |\n");
	printf("\t\t\t|    6.   退出         |\n");
	printf("\t\t\t|                      |\n");
	printf("\t\t\t ----------------------\n");
	printf("\t\t\t ")	;
while(1)
{
	char operation;
	operation=getch();
	switch(operation)
	{
		case '1': system("cls"); movie_manager_UI()   ; return;  
		case '2':  system("cls");movie_project_UI()   ; return;  
		case '3':  system("cls");money_manager_UI()  ; return;     
		case '4': system("cls"); sale_ticket_UI();  return;                     
		case '5': system("cls");password_UI(3)       ; return ;
		case '6':system("cls"); home(0) ; return ;
		default: printf("\n\t\t\t输入错误，请重新输入\n")	  ;  break;
	}
	 
}
	
	
	
	
	return;
}
void movie_manager_UI()
{
	fflush(stdin);
	printf("\t\t\t ----------------------\n");
	printf("\t\t\t|     影片管理系统     |\n");
	printf("\t\t\t|                      |\n"); 
	printf("\t\t\t|     1. 影片列表      |\n");
	printf("\t\t\t|                      |\n");	
	printf("\t\t\t|     2. 影片查询      |\n");
	printf("\t\t\t|                      |\n");	
	printf("\t\t\t|     3. 影片新增      |\n");
	printf("\t\t\t|                      |\n");
	printf("\t\t\t|     4. 影片删除      |\n");
	printf("\t\t\t|                      |\n");
	printf("\t\t\t|     5.   退出        |\n");
	printf("\t\t\t|                      |\n");
	printf("\t\t\t ----------------------\n")	;
	printf("\t\t\t ")	;
	while(1)
{
	char operation;
	operation=getch();
	system("cls");
	switch(operation)
	{
		case '1':  movie_list_UI(2)   ; return;  
		case '2':  movie_find_UI(2)    ; return;  
		case '3':  movie_add_UI()  ; return;                          
		case '4':  movie_delete_UI()       ; return ;
		case '5':  manager_UI() ; return ;
		default: printf("\n\t\t\t输入错误，请重新输入\n")	  ;  break;
	}
	
	
	
	
	
	
 } 
}
 void movie_add_UI()  
 {
 	struct movie_list t;
 	double money,wa;
 	char s[1000];
 	int i,flag=0;
 	fflush(stdin);
 	printf("\n\t\t\t请输入影片中文名：")	;
 	gets(t.movie_chinese_name) ;
	printf("\n\t\t\t请输入影片英文名：")	;
 	gets(t.movie_english_name) ;
 	printf("\n\t\t\t请输入票价："); 
	gets(s);
	for(i=1;i<strlen(s)-1;i++)
	{
		if(s[i]<'0'||s[i]>'9')
		{
			if(s[i]=='.')
			{
				flag++;
			}
			else
			{
				flag=10;
				break;
			}
		}
	}
	if(!(flag==0||flag==1)||s[0]<'0'||s[0]>'9'||s[strlen(s)-1]<'0'||s[strlen(s)-1]>'9')
	{
		printf("\t\t\t输入错误，按任意键返回");
		getch();
		system("cls");
		manager_UI();
		return ;
	}
	money=strtod(s,NULL);
 	money_add(t.movie_chinese_name,money)  ;
 	printf("\n\t\t\t请输入影片时长：")	;
 	gets(t.movie_time) ;
 		printf("\n\t\t\t请输入主演名单：")	;
 	gets(t.movie_performer) ;
 		printf("\n\t\t\t请输入导演名单：")	;
 	gets(t.movie_director) ;
 		printf("\n\t\t\t请输入制片人：")	;
 	gets(t.movie_producer) ;
 		printf("\n\t\t\t请输入拍摄地点：")	;
 	gets(t.movie_location) ;
 		printf("\n\t\t\t请输入发行公司：")	;
 	gets(t.movie_company) ;
 		printf("\n\t\t\t请输入编剧：")	;
 	gets(t.movie_screenwriter) ;
 		printf("\n\t\t\t请输入影片剧情简介：")	;
 	gets(t.movie_brief) ;

 	
	 movie_add(t);
 	
 	
 	printf("\t\t\t添加成功，继续添加（y/n）");
	char a = getch();
	system("cls");
	if(a!='y')
	manager_UI();
	else
	movie_add_UI()  ;
 	
 	return;
 	
	
 	
 	
 }
 void movie_delete_UI()       
 {
 	fflush(stdin);
	printf("\t\t\t 删除电影操作不可恢复!!!\n");
	printf("\t\t\t 请输入要删除的电影全名:");
	char movie[1000];
	gets(movie);
	int ch=movie_delete_BLL(movie);
 	if(ch==1)
	 {
	 	printf("\t\t\t删除成功,按任意键返回上一层");
	  } 
	else
	{
		system("cls");
		movie_0find(movie);
	 	printf("\t\t\t您输入的电影不存在,按任意键重新输入"); 
	 	getch();
	 	movie_delete_UI();
	 	return;
	}
	getch();
	 	system("cls");
		 manager_UI();
		 return;
 }
 
 void movie_project_UI() 
 {
 	fflush(stdin);
 	printf("\t\t\t ----------------------\n");
	printf("\t\t\t|     放映管理系统     |\n");
	printf("\t\t\t|                      |\n"); 
	printf("\t\t\t|    1. 安排放映       |\n");
	printf("\t\t\t|                      |\n");	
	printf("\t\t\t|    2. 修改放映       |\n");
	printf("\t\t\t|                      |\n");
	printf("\t\t\t|    3.   退出         |\n");
	printf("\t\t\t|                      |\n");
	printf("\t\t\t ----------------------\n")	;
	printf("\t\t\t ")	;
while(1)
{
	char operation;
	operation=getch();
	switch(operation)
	{
		case '1':  system("cls"); movie_start_UI()   ; return;  
		case '2':  system("cls"); movie_mode_UI()    ; return;  
		case '3':  system("cls"); manager_UI()       ; return;                          
		default: printf("\n\t\t\t输入错误，请重新输入")	  ;  break;
	}
	 
}
	
	return;
 	
 }
 void movie_start_UI()   
 {
 	fflush(stdin);
 	char s[100];
 	int id;
 	int a;
 	while(1)
 	{
 	printf("\n\t\t\t请输入场次：");
	scanf("%d",&a);
	printf("\n\t\t\t请输入放映厅号：");
	scanf("%d",&id);
	 if(id>4) 
	 {
	 	printf("\n\t\t\t放映厅不存在，请重新输入");
	 }
	 else break;
	 }
	 printf("\n\t\t\t请输入要放映的电影全名：");
	 scanf("%s",s);
	 struct movie_list * p=moviequery(s);
	 if(p==NULL)
	 {
	 	movie_0find(s);
	 	printf("\n\t\t\t您输入的电影不存在，重新输入（y/n）");
	 	char qq=getch();
	 	if(qq=='y')
	 	{
	 		system("cls");
	 		movie_start_UI() ;
			 return; 
		 }
	 	else
	 	{
	 		system("cls");
		 manager_UI();
		 return;
		 }
	 	
	  } 
	  printf("\n\t\t\t请输入日期：");
	  char date[100];
	  scanf("%s",date);
	  plan_add(a,id,s,date); 
	  printf("\n\t\t\t添加放映成功，按任意键返回");
	 	getch();
	 	system("cls");
		 manager_UI();
		 return;
	
 }
 void movie_mode_UI()
 {
 	fflush(stdin);
 	struct plan * t=plan ->next;
 	while(1)
 	{
 		printf("\n\t\t\t请输入场次序号：");
	 int id;
	 char ss[1000];
	 scanf("%s",ss);
	 double aa=strtod(ss,NULL);
	 id=(int)aa;
	 while(t!=NULL)
	 {
	 	if(t->num==id)
	 	{
	 		break;
		 }
	 	t=t->next;
	 }
	 if(t==NULL) 
	 {
	 	printf("\n\t\t\t放映厅不存在，请重新输入");
	 	t=plan ->next;
	 }
	 else break;
	 }
	 printf("\n\t\t\t正在放映：%s\n",t->plan_name);
	 printf("\n\t\t\t请输入要放映的电影全名：");
	 char s[100];
	 scanf("%s",s);
	 struct movie_list * p=moviequery(s);
	 if(p==NULL)
	 {
	 	movie_0find(s);
	 	printf("\n\t\t\t您输入的电影不存在，重新输入（y/n）");
	 	char qq=getch();
	 	if(qq=='y')
	 	{
	 		system("cls");
	 		movie_start_UI() ;
			 return ;
		 }
	 	else
	 	{
	 		system("cls");
		 manager_UI();
		 return;
		 }
	  } 
	  strcpy(t->plan_name,p->movie_chinese_name);
	  printf("\n\t\t\t请输入要修改的时间段：");
	  char date[100];
	  scanf("%s",date);
	  strcpy(t->plan_time,date); 
	  plan_printf();
	  printf("\n\t\t\t修改放映成功，按任意键返回");
 	  getch();
 	  system("cls");
	  manager_UI();
	  return;
 }
 void money_manager_UI()  
 {
 	fflush(stdin);
 	printf("\t\t\t ----------------------\n");
	printf("\t\t\t|     票房管理系统     |\n");
	printf("\t\t\t|                      |\n"); 
	printf("\t\t\t|    1. 电影票房       |\n");
	printf("\t\t\t|                      |\n");	
	printf("\t\t\t|    2. 员工销售额     |\n");
	printf("\t\t\t|                      |\n");
	printf("\t\t\t|    3.   退出         |\n");
	printf("\t\t\t|                      |\n");
	printf("\t\t\t ----------------------\n")	;
	printf("\t\t\t ")	;
while(1)
{
	char operation;
	operation=getch();
	switch(operation)
	{
		case '1':  system("cls"); movie_money_UI()   ; return;  
		case '2':  system("cls"); staff_money_UI()    ; return;  
		case '3':  system("cls"); manager_UI()       ; return;                          
		default: printf("\n\t\t\t输入错误，请重新输入");  break;
	}
	 
}
 	return;
 	

 }
 void movie_money_UI()
 {
 	fflush(stdin);
 	struct movie_list *t=movielist->next;
 	 printf("\n\t\t\t请输入排序方式序号（1.降序，2.升序）"); 
 	 char ch;
 	 while(1)
 	 {
 	 	ch=getch();
 	 	if(ch=='1'||ch=='2') break;
 	 	else printf("\n\t\t\t输入错误请重新输入");
	  }
 	 while(t!=NULL)
       {
       	  t->money=yj(t->movie_chinese_name,2);
       	  t=t->next;
	   }
 	 
     sort1(movielist->next,ch-'0');
     t=movielist->next;
     system("cls");
          printf("\n\t\t\t%-50s\t\t%-50s","电影","票房"); 
       while(t!=NULL)
       {
       	  printf("\n\t\t\t%-50s\t\t%-50lf",t->movie_chinese_name,t->money); 
       	  t=t->next;
	   }
	  
 	printf("\n\t\t\t按任意键返回");
 	getch();
 	system("cls");
 	money_manager_UI();
 	return;
 }
 void staff_money_UI()  
 {
 	fflush(stdin);
 	struct user_list * t=userlist;
 	printf("\n\t\t\t%-50s\t\t\t%-50s","员工id","业绩（元）"); 
       while(t!=NULL)
       {
	   	  if(t->jurisdiction==3)
       	  printf("\n\t\t\t%-50s\t\t%-50lf",t->user_name,yj(t->user_name,1)); 
       	  t=t->next;
	   }
	  
 	printf("\n\t\t\t\t按任意键返回");
 	getch();
 	system("cls");
 	money_manager_UI();
 	return;
 }  
 void sale_ticket_UI()
 {
 	struct data* t =datalist->next;
 	int i=0;
 	while(t!=NULL&&i<10)
 	{
 		i++;
 		printf("\n\t\t\tuser:%-10s\tmovie:%-10s\t%10s",t->user,t->movie,t->s);
 		t = t->next;
	
		if(i==9)
		{
			i = 0;
			getch();
			system("cls");
		}
	}
	printf("\n\t\t\t\t按任意键返回");
 	getch();
 	system("cls");
 	money_manager_UI();
 	return;
	
 }
