#include<iostream>
using namespace std;

//�������ݺ��� 
void getin(int a[],int n){
	//����ѭ������ 
	int i;
	//���������е�ÿһ���� 
	for(i=0;i<n;i++){
		cout<<"�������"<<i+1<<"����\n";
		cin>>a[i]; 
	}
	system("cls");
}

//������ 
void sorting(int a[],int n){
	//����ѭ������ 
	int i,j;
	//��ӡԭ�������� 
	//��ӡ���������飬����ͳһΪ��������
	//����һ��������� 
	int temp;
	for(i=0;i<n;i++){
		for(j=i;j<n;j++){
			if(a[i]>a[j]){
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
	
}

//���η��ֽ����麯��
int divide(int a[],int n){
	//�������������ָ�� 
	int L=0,R=n-1;
	 
	//��һ����������n�ĸ���Ϊ���� 
	if(n%2!=0){
		
		//Ҫʹ���������Ԫ�ظ��������С����ʹ�������龡��ƽ�֡�
		//�������κ󣬴���һ���м������м���Ӧ���������飬ʹ��������֮��������
		
		//���θ�������
		int a1[n/2];
		for(int i=0;i<n/2;i++){
			a1[i]=a[L];
			L++;
		}
		//��ʾ�����飬˳·���
		int sum1=0;
		cout<<"\n������Ϊ��\n";
		for(int i=0;i<n/2;i++){
			cout<<"  "<<a1[i];
			sum1=sum1+a1[i];
		}
		//���θ�������
		int a2[n/2+1];//��ΪԪ������Ϊ������ԭ����������������һ����Ԫ�ռ�
		for(int i=0;i<n/2+1;i++){
			a2[i]=a[L];
			L++;
		}
		//��ʾ�����飬˳·��� 
		int sum2=0;
		cout<<"\n������Ϊ��\n";
		for(int i=0;i<n/2+1;i++){
			cout<<"  "<<a2[i];
			sum2=sum2+a2[i];
		}
		
		//����|n1-n2|��|s1-s2|������
		cout<<"\n|n1-n2|="<<(n/2+1)-(n/2)<<endl;
		
		cout<<"|s1-s2|="<<sum2-sum1<<endl;
		
		return sum2-sum1;
	}
	//��һ����������n�ĸ���Ϊż�� 
	else if(n%2==0){
		//ż�����Σ���Ϊ֮ǰ�Ѿ��Ź�������ֱ�Ӵ��м����һ�μ���
		
		//���θ�������
		int a1[n/2];
		for(int i=0;i<n/2;i++){
			a1[i]=a[L];
			L++;
		}
		//��ʾ�����飬˳·���
		int sum1=0;
		cout<<"\n������Ϊ��\n";
		for(int i=0;i<n/2;i++){
			cout<<"  "<<a1[i];
			sum1=sum1+a1[i];
		}
		//���θ�������
		int a2[n/2];
		for(int i=0;i<n/2+1;i++){
			a2[i]=a[L];
			L++;
		}
		int sum2=0;
		cout<<"\n������Ϊ��\n";
		for(int i=0;i<n/2;i++){
			cout<<"  "<<a2[i];
			sum2=sum2+a2[i];
		}
		
		//����|n1-n2|��|s1-s2|������
		cout<<"\n|n1-n2|="<<(n/2)-(n/2)<<endl;
		
		cout<<"|s1-s2|="<<sum2-sum1<<endl;
		
		return sum2-sum1;
		
	}
	
}

int main(){
	//ѯ���û�����Ԫ�صĸ��� 
	cout<<"�������б����ж��ٸ���\n";
	int n;
	cin>>n;
	
	int a[n];
	//�������뺯�������������е�ÿһ���� 
	getin(a,n);
	//����������������������Ϊ���� 
	sorting(a,n);
	//���η��ֽ����������
	divide(a,n);
	
	
	cout<<"\n";
	system("pause");
	return 0; 
}

