#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//���ֵ���� 
int max(int a, int b) {
	if (a > b) {
		return a;
	}
	else {
		return b;
	}
}


//��̬�滮������������� 
void Lcs(char a[], char b[], int dp[][10]) {
	
	//��������ַ����ĳ���
	int a_length, b_length;
	a_length = strlen(a);
	b_length = strlen(b);
	
	//��ʼ��dp�������������� 
	memset(dp, 0, sizeof(dp));
	
	//��дm+1��n+1��dp����
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


//������ˮ���������ص�����ˮ���ַ����ĳ��� 
int FindLcs(char a[], char b[], char c[],int dp[][10]){
	
	//����ѭ������ 
	int i, j ,z= 0;
	i = strlen(a); 
	j = strlen(b);
	
	while (i != 0 && j != 0){
		//����Խǵ�dpֵ��ȣ���ֱ��ȡ�¸���ĸ 
		if (a[i - 2] == b[j - 2]){	
		
			c[z] = a[i-1];
			
			i--; 
			j--;
			z++;
		}
		//����������������ߣ�����dpֵ����� 
		
		//���dp[i][j - 1]����������
		else if (dp[i - 1][j] < dp[i][j - 1]){
			
			c[z] = b[j-1];
			
			j--; 
			z++;
		}
		//���dp[i - 1][j]���������� 
		else if (dp[i][j - 1] <= dp[i - 1][j]){
			c[z] = a[i-1];
			
			i--; 
			z++;
		}
		
	}
	return z;
}


int main() {
	char a[10];//��ˮ��1
	char b[10];//��ˮ��2 
	char c[20];//��ˮ�� 
	
	int dp[10][10];//��̬�滮���� 
	
	printf("������������ˮ��������:\n"); 
	scanf("%s", &a);
	scanf("%s", &b);
	
	//��̬�滮�����������ˮ������������� 
	Lcs(a, b, dp);
	
	//������ˮ�����𰸲�Ψһ����������ˮ�����ַ������� 
	int c_length = FindLcs(a, b, c,dp);
	
	//��ӡ��ˮ���Ľ��
	printf("��ˮ��������Ϊ:\n"); 
	for (int z = c_length -1; z >= 0; z--) {
		printf("%c", c[z]);
	}
	
	printf("\n\n\n");
	system("pause");
	
	return 0;
}

