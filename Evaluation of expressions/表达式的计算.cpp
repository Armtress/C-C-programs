#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 

#define Maxsize 100


struct Stack
{
	int *top;
	int *base;
	int stacksize;
};

//创建栈并初始化
void create(struct Stack *s)
{
    s->base=(int *)malloc(Maxsize*sizeof(int)); 
     if(!s->base)
     {
    	printf("栈的初始化失败！");
    	printf("\n");
    	printf("\n");
    	
    	return;
	}
	else
	{
		
	}
	
    s->top=s->base;
    s->stacksize=Maxsize;
    return;
}

//入栈
int push_in(struct Stack *s,int value)
{
	if(s->top-s->base==s->stacksize)
	{
		printf("栈满！");
		printf("\n");
		printf("\n");
		
		return 0;
	}
	else
	{
	
	}
	*s->top=value; 
	s->top++;
	
	return 0;
}

//出栈
int pop_out(struct Stack *s,int *elem)
{
	if(s->base==s->top)
	{
		printf("栈空！");
		printf("\n");
		printf("\n");
		
		return 0;
	}
	else
	{
	
	}
	s->top--;
	*elem=*s->top; 
	
	return 0;
}

//取栈顶元素
int GetTop(struct Stack *s) 
{
	if(s->base==s->top)
	{
	    printf("栈空！");
	    printf("\n");
	    printf("\n");
	    printf("无法取栈顶元素！");
	    printf("\n");
	    printf("\n");
	    
	    return 0;
	}
	else
	{
	 
	}
	return *(s->top-1);
}

//优先级函数
char Precede(char a,char b)
{
	int i,j;
	char pre[7][7]={
					// +   -   *   /   (   )   = 
		             {'>','>','<','<','<','>','>'},  
                     {'>','>','<','<','<','>','>'},  
                     {'>','>','>','>','<','>','>'},  
                     {'>','>','>','>','<','>','>'},  
                     {'<','<','<','<','<','=','0'},  
                     {'>','>','>','>','0','>','>'},  
                     {'<','<','<','<','<','0','='}
					
					}; 
                
    switch(a){
    	case '+': i=0; break;  
        case '-': i=1; break;  
        case '*': i=2; break;  
        case '/': i=3; break;  
        case '(': i=4; break;  
        case ')': i=5; break;
        case '=': i=6; break;
	}
	
    switch(b){
    	case '+': j=0; break;  
        case '-': j=1; break;  
        case '*': j=2; break;  
        case '/': j=3; break;  
        case '(': j=4; break;  
        case ')': j=5; break;
        case '=': j=6; break;
    }
    return(pre[i][j]);
}

//求值函数 
int Operate(int a,char theta,int b)   // a 运算符 b 
{
	int result;
	
	switch(theta){
		case'+':return a+b;
		case'-':return a-b;
		case'*':return a*b;
		case'/':             //判断除数是否为0，若除数为零返回错误提示                       
		        if(b!=0)
		        return a/b;
		        else
		        {
		        	printf("除数不能为0!");
		        	printf("\n");
		        	exit(0);
				}
	}
    
}

//判断是否为运算符，是运算符返回1，若不是返回0
int In(char c) 
{
	switch(c){
		case '+':   
        case '-':  
        case '*':   
        case '/':   
        case '(':   
        case ')': 
        case '=': 
                 return 1;
		 default:
		         return 0;		   
	}
}

//表达式求值函数
int evaluateExpression(char exp[]) 
{
	struct Stack shu,fu; //运算数栈、运算符栈
	int a,b,theta;  //用于求值函数
	int x;           //用于存放多余的出栈字符
	int X1,X2;      // 用于归并 
	char ch; //读取字符的变量
	int i=0; //指向存放表达式数组的下标指针
	
	create(&shu); //建立并初始化运算数栈
	create(&fu); //建立并初始化运算符栈
	push_in(&fu,'='); //先将“=”号压入运算符栈（表达式也必须以“=”结束）
	
	ch=exp[i]; 
	i++;         //ch读取字符数组第一个元素，并将指针i后移一位

	
	while(ch!='='||GetTop(&fu)!='=') //表达式没有扫描完毕或运算符栈顶不为“=”
	{
		if(In(ch)) //判断ch是否为操作符
		{
			
			//比较ch的与运算符栈顶元素的优先级
			switch(Precede(GetTop(&fu),ch))
			{
				case'<':
					    push_in(&fu,ch);
					    
					    ch=exp[i]; 
					    
						i++;    
						    //读取下一位字符并将指针向后偏移一位
					    break;
				
				case'>':
					    pop_out(&fu,&theta); 
					    
					    pop_out(&shu,&b);
					    
					    pop_out(&shu,&a);
					    
					    push_in(&shu,Operate(a,theta,b));
					    
					    break;
				
				case'=':
					    pop_out(&fu,&x);
					    
					    ch=exp[i]; 
					    
						i++;    
						    //读取下一位字符并将指针向后偏移一位
					    break;
					    
			}
		
		}
		
		
		
		//判断非法字符 
		
		else if(isdigit(ch)) //判断是否为数字,是数字返回1，不是返回0
		{
			X1=ch-'0'; //将字符形式转化为数字
			push_in(&shu,X1);
			
			X2=X1;
			ch=exp[i++]; //读取下一位字符并将指针向后偏移一位
			
			while(isdigit(ch)) //判断下一位是否还是数字
			{
				X1=ch-'0';
				X2=10*X2+X1; //归并至X2
				pop_out(&shu,&x);
				push_in(&shu,X2);
				ch=exp[i++]; //读取下一位字符并将指针向后偏移一位
				
				continue;
			} 
		} 
		
		else if(ch==' ') //判断是否为空格
		{
			while(ch==' ') //跳过若干个空格
			{
				ch=exp[i++];
				 //忽略空格，直接取下一位
				continue;
			}
			
		}
		
		else //若不是上述三种情况之一，则为非法字符
		{
			printf("你所输入的字符为非法字符！");
			printf("\n");
	    	printf("\n");
	    	
			printf("请重新输入...");
			printf("\n");
	    	printf("\n");
	    	
			exit(0); //返回错误提示
		}
		continue;
	}
	return(GetTop(&shu)); //最后返回操作数栈顶为运算结果
}

int main()
{
	system("mode con cols=60 lines=20");
	system("color 8b");
	
	printf("*******");
	printf("*******");
	printf("*******");
	printf("*******");
	printf("*******");
	
	printf("\n");
	printf("\n");
	
	printf("本程序的意义是：\n");
	printf("\n");
	
	printf("输入一个表达式（可带括号），以等号结束\n");
	printf("\n");
	
	printf("该程序便会自动进行计算\n"); 
	printf("\n");
	
	char exp[100]; //定义一个字符数组用于存储表达式
	int result;
	
	printf("*******");
	printf("*******");
	printf("*******");
	printf("*******");
	printf("*******");
	
	printf("\n"); 
	printf("\n");
	
	printf("请输入你的表达式:");
	printf("\n"); 
	printf("\n");
	
	
	gets(exp); //换成scanf（“%s”，exp）；也可以
	result=evaluateExpression(exp);
	printf("\n");
	printf("%s%d\n",exp,result);
  
	return 0;
}
