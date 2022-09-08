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

//����ջ����ʼ��
void create(struct Stack *s)
{
    s->base=(int *)malloc(Maxsize*sizeof(int)); 
     if(!s->base)
     {
    	printf("ջ�ĳ�ʼ��ʧ�ܣ�");
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

//��ջ
int push_in(struct Stack *s,int value)
{
	if(s->top-s->base==s->stacksize)
	{
		printf("ջ����");
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

//��ջ
int pop_out(struct Stack *s,int *elem)
{
	if(s->base==s->top)
	{
		printf("ջ�գ�");
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

//ȡջ��Ԫ��
int GetTop(struct Stack *s) 
{
	if(s->base==s->top)
	{
	    printf("ջ�գ�");
	    printf("\n");
	    printf("\n");
	    printf("�޷�ȡջ��Ԫ�أ�");
	    printf("\n");
	    printf("\n");
	    
	    return 0;
	}
	else
	{
	 
	}
	return *(s->top-1);
}

//���ȼ�����
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

//��ֵ���� 
int Operate(int a,char theta,int b)   // a ����� b 
{
	int result;
	
	switch(theta){
		case'+':return a+b;
		case'-':return a-b;
		case'*':return a*b;
		case'/':             //�жϳ����Ƿ�Ϊ0��������Ϊ�㷵�ش�����ʾ                       
		        if(b!=0)
		        return a/b;
		        else
		        {
		        	printf("��������Ϊ0!");
		        	printf("\n");
		        	exit(0);
				}
	}
    
}

//�ж��Ƿ�Ϊ������������������1�������Ƿ���0
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

//���ʽ��ֵ����
int evaluateExpression(char exp[]) 
{
	struct Stack shu,fu; //������ջ�������ջ
	int a,b,theta;  //������ֵ����
	int x;           //���ڴ�Ŷ���ĳ�ջ�ַ�
	int X1,X2;      // ���ڹ鲢 
	char ch; //��ȡ�ַ��ı���
	int i=0; //ָ���ű��ʽ������±�ָ��
	
	create(&shu); //��������ʼ��������ջ
	create(&fu); //��������ʼ�������ջ
	push_in(&fu,'='); //�Ƚ���=����ѹ�������ջ�����ʽҲ�����ԡ�=��������
	
	ch=exp[i]; 
	i++;         //ch��ȡ�ַ������һ��Ԫ�أ�����ָ��i����һλ

	
	while(ch!='='||GetTop(&fu)!='=') //���ʽû��ɨ����ϻ������ջ����Ϊ��=��
	{
		if(In(ch)) //�ж�ch�Ƿ�Ϊ������
		{
			
			//�Ƚ�ch���������ջ��Ԫ�ص����ȼ�
			switch(Precede(GetTop(&fu),ch))
			{
				case'<':
					    push_in(&fu,ch);
					    
					    ch=exp[i]; 
					    
						i++;    
						    //��ȡ��һλ�ַ�����ָ�����ƫ��һλ
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
						    //��ȡ��һλ�ַ�����ָ�����ƫ��һλ
					    break;
					    
			}
		
		}
		
		
		
		//�жϷǷ��ַ� 
		
		else if(isdigit(ch)) //�ж��Ƿ�Ϊ����,�����ַ���1�����Ƿ���0
		{
			X1=ch-'0'; //���ַ���ʽת��Ϊ����
			push_in(&shu,X1);
			
			X2=X1;
			ch=exp[i++]; //��ȡ��һλ�ַ�����ָ�����ƫ��һλ
			
			while(isdigit(ch)) //�ж���һλ�Ƿ�������
			{
				X1=ch-'0';
				X2=10*X2+X1; //�鲢��X2
				pop_out(&shu,&x);
				push_in(&shu,X2);
				ch=exp[i++]; //��ȡ��һλ�ַ�����ָ�����ƫ��һλ
				
				continue;
			} 
		} 
		
		else if(ch==' ') //�ж��Ƿ�Ϊ�ո�
		{
			while(ch==' ') //�������ɸ��ո�
			{
				ch=exp[i++];
				 //���Կո�ֱ��ȡ��һλ
				continue;
			}
			
		}
		
		else //�����������������֮һ����Ϊ�Ƿ��ַ�
		{
			printf("����������ַ�Ϊ�Ƿ��ַ���");
			printf("\n");
	    	printf("\n");
	    	
			printf("����������...");
			printf("\n");
	    	printf("\n");
	    	
			exit(0); //���ش�����ʾ
		}
		continue;
	}
	return(GetTop(&shu)); //��󷵻ز�����ջ��Ϊ������
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
	
	printf("������������ǣ�\n");
	printf("\n");
	
	printf("����һ�����ʽ���ɴ����ţ����ԵȺŽ���\n");
	printf("\n");
	
	printf("�ó������Զ����м���\n"); 
	printf("\n");
	
	char exp[100]; //����һ���ַ��������ڴ洢���ʽ
	int result;
	
	printf("*******");
	printf("*******");
	printf("*******");
	printf("*******");
	printf("*******");
	
	printf("\n"); 
	printf("\n");
	
	printf("��������ı��ʽ:");
	printf("\n"); 
	printf("\n");
	
	
	gets(exp); //����scanf����%s����exp����Ҳ����
	result=evaluateExpression(exp);
	printf("\n");
	printf("%s%d\n",exp,result);
  
	return 0;
}
