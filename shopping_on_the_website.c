#include<stdio.h>
#include<string.h>
#define SIZE 100
#define LISTMAX 10

double my_pocket=100;
int my_count[LISTMAX];

char admin_login();
void admin_enter();
char user_login();
void user_enter();

struct item    //"商品"个体 
{
	char name[SIZE];
	double prize;
	char description[SIZE];
};

struct item list[LISTMAX]=
	{
			
	  {
		"苹果",
		5,
		"这是一个红红的、新鲜的苹果" 
	  },
	  {
		"西瓜",
		20,
		"炎炎夏日，何尝不来一个大大的西瓜？"
	  }
	};
	
char get_first()   //检测输入项是否符合标准 
{
	
	char ch;
	scanf(" %c",&ch);
	while(getchar()!='\n')
	{
		continue;
		ch=getchar();
	}
	return ch;
}

char get_enterchoice()    //UI设计+三大板块（管理员模式，用户模式，退出） 
{
	char ch;
	printf("\t===================================\n");
	printf("\t\t请输入您要登陆的类型:\n");
	printf("\t\ta.管理员账户登陆\n\t\tb.用户账号登陆\n\t\tc.退出\n");
	printf("\t===================================\n");
	ch=get_first();
	while(ch<'a'||ch>'c')
	{
		printf("错误！请重新输入！");
		ch=get_first();
	}
	
	return ch;
}

void purchase()
{
	int num;
	int buychoice;
	double sum;
	printf("请输入购买的商品序号：\n");
	scanf("%d",&buychoice);
	printf("请输入购买的数量:\n");
	scanf("%d",&num);
	sum=num*list[buychoice-1].prize;
	if(my_pocket>=sum)
	{
			my_pocket-=sum;
			my_count[buychoice-1]+=num;
			printf("购买成功！,您还剩下%lf CNY\n",my_pocket);
	
	}
	else
	{
		printf("钱不够哦，请充值！");
	
	}
	user_enter();
}

void store()  //控制 "已知"的商品库 
{
	int index;
	
	printf("\t=====================================================\n");
	printf("\t序号\t物品\t价格(CNY)\t描述\n");
	for(index=0;index<LISTMAX;index++)
	{
		if(strcmp(list[index].name,"")!=0)
		{
			printf("\t%d\t%s\t%.2lf\t%s\n",index+1,list[index].name,list[index].prize,list[index].description);
		}
	}
	printf("\t=====================================================\n");
}

void dealt()
{
	char key;
	int num,drop;
	printf("\t\t请选择操作:\n");
	printf("\t\ta.增加商品\n\t\tb.减少商品\n\t\tc.退出\n");
	key=get_first();
	if(key=='a')
	{
		printf("\t\t请输入您要增加物品的序号:\n");
		scanf("%d",&num);
		if(strcmp(list[num-1].name,"")==0&&num<=LISTMAX)
		{
			printf("请输入物品名:\n");
			scanf("%s",&list[num-1].name);
			printf("请制定价格:\n");
			scanf("%lf",&list[num-1].prize);
			printf("请增加描述:\n");
			scanf("%s",&list[num-1].description);
			printf("更改完成！为您返回至上一步……\n\n");
			admin_enter();
		}
		else
		{
			printf("\t\t对不起，您不能这么做\n");
			void dealt();
		}
	}
	else if(key=='b')
	{
		printf("\t\t请输入您要减少物品的序号:\n");
		scanf("%d",&drop);
		if(drop<=LISTMAX)
		{
			strcpy(list[drop-1].name,"");
			list[drop-1].prize=0;
			strcpy(list[drop-1].description,"");
			
			printf("已清除！\n");
		}
		else
		{
			printf("\t\t对不起，已超出最大范围!\n");
			void dealt();
		}
	}
	else if(key=='c')
	{
		admin_enter();
	}
	else
	{
		printf("\t\t错误！不是有效代码！\n");
		dealt();
	}
	 
}

int main()
{
	char choice;
	printf("\t===================================\n");
	printf("\t\t掏包网，掏走你喜欢的！\n");
	printf("\t***********************************\n");
      choice=get_enterchoice();
      
      if(choice=='a')
      {
      	admin_login();
	  }
	  else if(choice=='b')
	  {
	  	user_login();
	  }
	  else if(choice=='c')
	  {
	  	printf("感谢您的使用，欢迎下次光临！\n");
	  }
	  else
	  {
	  	printf("错误！非合法指令！\n");
	  	get_enterchoice();
	  	
	  }
	
	
	return 0;
} 


char admin_login()  //管理员界面登陆 
{
	char admin_account[SIZE],admin_password[SIZE];
	
	    printf("\n请输入您的管理员账号:");  //账户:admin 
		scanf("%s",admin_account);        //密码 ****** 
		printf("请输入您的密码:");
		scanf("%s",admin_password);
		if(strcmp(admin_account,"admin")==0&&strcmp(admin_password,"******")==0)
		{
			admin_enter();
		}
		else
		{
			printf("账户或密码错误，请重新输入！\n\n");
			get_enterchoice();
		}
}

char user_login()  //用户界面登陆 
{
	char user_account[SIZE],user_password[SIZE];
		printf("\n请输入您的账号:");
		scanf("%s",user_account);   //账户 user 
		printf("请输入您的密码:");  //密码 123456 
		scanf("%s",user_password);
		if(strcmp(user_account,"user")==0&&strcmp(user_password,"123456")==0)
		{
			user_enter();
		}
		else
		{
			printf("账户或密码错误，请重新输入！\n\n");
			get_enterchoice();
		}
}

void admin_enter()  //登陆后的管理员界面UI+三大板块（查看商品，添加商品，退出） 
{
	char ach;
	printf("\t===================================\n");
	printf("\t\t欢迎您的登陆，管理员！\n");
	printf("\t***********************************\n");
	printf("\t\t请选择您要执行的操作:\n");
	printf("\t\ta.查看商品列表\n\t\tb.改变商品\n\t\tc.退出\n");
	ach=get_first();
	while(ach<'a'||ach>'c')
	{
		printf("错误！请重新输入!\n");
		ach=get_first();
	}
	if(ach=='a')  //"查看商品"板块
	{
	    store();
	    printf(".\n.\n.\n");
	    admin_enter();
	}
	else if(ach=='b')  //商品增减模块 
	{
		printf("\t=====================================================\n");
		printf("\t\t【为您列出当前库中商品】\n");
		printf("\t=====================================================\n");
	    store();
	    dealt();
	    admin_enter();
	    
		
	}
	else if(ach=='c') //退出模块 
	{
		get_enterchoice();
	}
	else
	{
		printf("错误！请重新输入！\n");
		admin_enter();
	}
	
}

void user_enter()  //登陆后的用户界面UI+三大板块（购买商品，个人账户，退出） 
{
	char uch;
	int index;
	char quit;
	printf("\t===================================\n");
	printf("\t\t欢迎光临小店，您需要点什么？\n");
	printf("\t***********************************\n");
	printf("\t\t请选择您要执行的操作:\n");
	printf("\t\ta.购买商品\n\t\tb.进入个人账户\n\t\tc.退出\n");
	uch=get_first();
	while(uch<'a'||uch>'c')
	{
		printf("错误！请重新输入!\n");
		uch=get_first();
	}
	userback:
	if(uch=='a')  //浏览商品+选择购买 
	{
		printf("\t=====================================================\n");
		printf("\t\t您的余额为:  %lf  CNY\n",my_pocket);
	    store();
	    purchase();
	}
	else if(uch=='b')
	{
		printf("\t=====================================================\n");
		printf("\t\t您的余额为:  %lf  CNY\n",my_pocket);
		printf("\t=====================================================\n");
		printf("\t\t购	物	记	录\n");
		printf("\t序号\t物品\t价格(CNY)\t描述\t\t购买次数\n");
		for(index=0;index<LISTMAX;index++)
		{
			if(strcmp(list[index].name,"")!=0)
			{
			  printf("\t%d\t%s\t%.2lf\t%s\t\t%d\n",index+1,list[index].name,list[index].prize,list[index].description,my_count[index]);
			}
		}
		printf("\t=============================================================================\n");
		printf("按'q'以退出\n");
		quit=get_first();
		if(quit=='q')
		{
			user_enter();
		}
		else
		{
			printf("错误！请重新输入！\n"); 
			goto userback;
		}
		
	}
	else if(uch=='c')
	{
		get_enterchoice();
	} 
	else
	{
		printf("错误！没有这一选项！\n");
		user_login();
	}
	
}

