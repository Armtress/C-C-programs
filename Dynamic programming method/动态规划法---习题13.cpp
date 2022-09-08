#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//最大值函数 
int max(int a, int b) {
	if (a > b) {
		return a;
	}
	else {
		return b;
	}
}


//动态规划求最长公共子序列 
void Lcs(char a[], char b[], int dp[][10]) {
	
	//求出两个字符串的长度
	int a_length, b_length;
	a_length = strlen(a);
	b_length = strlen(b);
	
	//初始化dp公共子序列数组 
	memset(dp, 0, sizeof(dp));
	
	//填写m+1行n+1列dp数组
	for (int m = 1; m <= a_length; m++) {
		for (int n = 1; n <= b_length; n++) {
			if (a[m - 1] == b[n - 1]) {
				dp[m][n] = dp[m - 1][n - 1] + 1;
			}
			else {
				dp[m][n] = max(dp[m - 1][n], dp[m][n - 1]);
			}
		}
	}
	
}


//构建新水果名，返回的是子水果字符串的长度 
int FindLcs(char a[], char b[], char c[],int dp[][10]){
	
	//定义循环变量 
	int i, j ,z= 0;
	i = strlen(a); 
	j = strlen(b);
	
	while (i != 0 && j != 0){
		//如果对角的dp值相等，则直接取下该字母 
		if (a[i - 2] == b[j - 2]){	
		
			c[z] = a[i-1];
			
			i--; 
			j--;
			z++;
		}
		//否则向左或者向上走，走向dp值更大的 
		
		//如果dp[i][j - 1]更大，向上走
		else if (dp[i - 1][j] < dp[i][j - 1]){
			
			c[z] = b[j-1];
			
			j--; 
			z++;
		}
		//如果dp[i - 1][j]更大，向左走 
		else if (dp[i][j - 1] <= dp[i - 1][j]){
			c[z] = a[i-1];
			
			i--; 
			z++;
		}
		
	}
	return z;
}


int main() {
	char a[10];//父水果1
	char b[10];//父水果2 
	char c[20];//子水果 
	
	int dp[10][10];//动态规划数组 
	
	printf("请输入两个父水果的名字:\n"); 
	scanf("%s", &a);
	scanf("%s", &b);
	
	//动态规划法求解两个父水果的最大子序列 
	Lcs(a, b, dp);
	
	//构建子水果，答案不唯一，并返回子水果的字符串长度 
	int c_length = FindLcs(a, b, c,dp);
	
	//打印子水果的结果
	printf("子水果的名字为:\n"); 
	for (int z = c_length -1; z >= 0; z--) {
		printf("%c", c[z]);
	}
	
	printf("\n\n\n");
	system("pause");
	
	return 0;
}

