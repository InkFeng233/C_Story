#include<stdio.h>
#include "user_mgt.h"

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
	  else if(choice=='q')
	  {
	  	 printf("您选择了退出！\n");
	  }
	  else
	  {
	  	printf("错误！非合法指令！\n");
	  	get_enterchoice();
	  }
	  printf("感谢您的使用，再见！");
	return 0;
} 
