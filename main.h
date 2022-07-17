                            //包含头文件
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<windows.h>
#include<conio.h>
#include<time.h>
                             //函数定义头
#include".\BLL\time_BLL.h"  		//获取系统时间                         
#include".\UI\init_UI.h"			//初始开机界面 
#include".\DAL\data.h"				//数据存储 ：座位情况 售出和退票记录的存在 
#include".\DAL\money.h"				//票价 
#include".\UI\home_UI.h"			//主菜单 
#include".\BLL\init_BLL.h"			//包括开机函数以及文件的打开操作 
#include".\DAL\seat_operation.h"	//座位的文件操作 
#include".\DAL\plan.h"
#include".\BLL\plan_BLL.h"
#include".\BLL\user_BLL.h"			//用户管理的逻辑层 
#include".\DAL\movie_operation.h"	//影片的文件操作 
#include".\DAL\user_operation.h"	//用户的文件操作 
#include".\UI\manager_UI.h"			//经理系统的界面层 
#include".\DAL\ticket.h" 			//电子票存档 
#include".\BLL\ticket_BLL.h"		//电子票生成 
#include".\UI\staff_UI.h"			//员工的界面层 
#include".\UI\tourist_UI.h"			//游客的界面层 
#include".\UI\user_UI.h"			//普通用户的界面层 
#include".\UI\movie_UI.h"			//影片的界面层 
#include".\BLL\movie_BLL.h"			//影片存储的逻辑层 
#include".\UI\seat_UI.h"			//座位管理的界面层 
#include".\BLL\seat_BLL.h"			//座位管理的各项操作 
#include".\UI\admin_UI.h"			//管理人员的界面层 
#include".\BLL\money_BLL.h"			//票价操作层 
#include".\BLL\sort_BLL.h"			//排序：统归电影票房 



                                 //c文件
#include".\BLL\time_BLL.c"
#include".\DAL\data.c"
#include".\UI\init_UI.c"
#include".\DAL\money.c"
#include".\BLL\init_BLL.c"
#include".\UI\seat_UI.c"
#include".\BLL\seat_BLL.c"
#include".\DAL\plan.c"
#include".\BLL\plan_BLL.c"
#include".\BLL\movie_BLL.c"
#include".\DAL\seat_operation.c"
#include".\BLL\user_BLL.c"
#include".\DAL\movie_operation.c"
#include".\DAL\user_operation.c"
#include".\UI\home_UI.c"
#include".\UI\manager_UI.c"
#include".\DAL\ticket.c"
#include".\BLL\ticket_BLL.c"
#include".\UI\staff_UI.c"
#include".\UI\tourist_UI.c"
#include".\UI\user_UI.c"
#include".\UI\movie_UI.c"
#include".\UI\admin_UI.c"
#include".\BLL\money_BLL.c"
#include".\BLL\sort_BLL.c"

//文件存着包含关系，请勿随意修改！！！ 


