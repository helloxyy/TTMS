                            //����ͷ�ļ�
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<windows.h>
#include<conio.h>
#include<time.h>
                             //��������ͷ
#include".\BLL\time_BLL.h"  		//��ȡϵͳʱ��                         
#include".\UI\init_UI.h"			//��ʼ�������� 
#include".\DAL\data.h"				//���ݴ洢 ����λ��� �۳�����Ʊ��¼�Ĵ��� 
#include".\DAL\money.h"				//Ʊ�� 
#include".\UI\home_UI.h"			//���˵� 
#include".\BLL\init_BLL.h"			//�������������Լ��ļ��Ĵ򿪲��� 
#include".\DAL\seat_operation.h"	//��λ���ļ����� 
#include".\DAL\plan.h"
#include".\BLL\plan_BLL.h"
#include".\BLL\user_BLL.h"			//�û�������߼��� 
#include".\DAL\movie_operation.h"	//ӰƬ���ļ����� 
#include".\DAL\user_operation.h"	//�û����ļ����� 
#include".\UI\manager_UI.h"			//����ϵͳ�Ľ���� 
#include".\DAL\ticket.h" 			//����Ʊ�浵 
#include".\BLL\ticket_BLL.h"		//����Ʊ���� 
#include".\UI\staff_UI.h"			//Ա���Ľ���� 
#include".\UI\tourist_UI.h"			//�ο͵Ľ���� 
#include".\UI\user_UI.h"			//��ͨ�û��Ľ���� 
#include".\UI\movie_UI.h"			//ӰƬ�Ľ���� 
#include".\BLL\movie_BLL.h"			//ӰƬ�洢���߼��� 
#include".\UI\seat_UI.h"			//��λ����Ľ���� 
#include".\BLL\seat_BLL.h"			//��λ����ĸ������ 
#include".\UI\admin_UI.h"			//������Ա�Ľ���� 
#include".\BLL\money_BLL.h"			//Ʊ�۲����� 
#include".\BLL\sort_BLL.h"			//����ͳ���ӰƱ�� 



                                 //c�ļ�
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

//�ļ����Ű�����ϵ�����������޸ģ����� 


