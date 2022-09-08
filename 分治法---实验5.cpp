#include<iostream>
using namespace std;

//接收数据函数 
void getin(int a[],int n){
	//定义循环变量 
	int i;
	//输入数组中的每一个数 
	for(i=0;i<n;i++){
		cout<<"请输入第"<<i+1<<"个数\n";
		cin>>a[i]; 
	}
	system("cls");
}

//排序函数 
void sorting(int a[],int n){
	//定义循环变量 
	int i,j;
	//打印原来的数组 
	//打印排序后的数组，这里统一为升序排序
	//定义一个缓存变量 
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

//分治法分解数组函数
int divide(int a[],int n){
	//定义数组的左右指针 
	int L=0,R=n-1;
	 
	//第一种情况，如果n的个数为奇数 
	if(n%2!=0){
		
		//要使两个数组的元素个数相差最小，即使两个数组尽量平分。
		//奇数分治后，存在一个中间数，中间数应并入右数组，使得两数组之和相差最大。
		
		//分治给左数组
		int a1[n/2];
		for(int i=0;i<n/2;i++){
			a1[i]=a[L];
			L++;
		}
		//显示左数组，顺路求和
		int sum1=0;
		cout<<"\n左数组为：\n";
		for(int i=0;i<n/2;i++){
			cout<<"  "<<a1[i];
			sum1=sum1+a1[i];
		}
		//分治给右数组
		int a2[n/2+1];//因为元素总数为奇数的原因，右数组比左数组大一个单元空间
		for(int i=0;i<n/2+1;i++){
			a2[i]=a[L];
			L++;
		}
		//显示右数组，顺路求和 
		int sum2=0;
		cout<<"\n右数组为：\n";
		for(int i=0;i<n/2+1;i++){
			cout<<"  "<<a2[i];
			sum2=sum2+a2[i];
		}
		
		//计算|n1-n2|、|s1-s2|并返回
		cout<<"\n|n1-n2|="<<(n/2+1)-(n/2)<<endl;
		
		cout<<"|s1-s2|="<<sum2-sum1<<endl;
		
		return sum2-sum1;
	}
	//第一种情况，如果n的个数为偶数 
	else if(n%2==0){
		//偶数分治，因为之前已经排过序，所以直接从中间分治一次即可
		
		//分治给左数组
		int a1[n/2];
		for(int i=0;i<n/2;i++){
			a1[i]=a[L];
			L++;
		}
		//显示左数组，顺路求和
		int sum1=0;
		cout<<"\n左数组为：\n";
		for(int i=0;i<n/2;i++){
			cout<<"  "<<a1[i];
			sum1=sum1+a1[i];
		}
		//分治给右数组
		int a2[n/2];
		for(int i=0;i<n/2+1;i++){
			a2[i]=a[L];
			L++;
		}
		int sum2=0;
		cout<<"\n右数组为：\n";
		for(int i=0;i<n/2;i++){
			cout<<"  "<<a2[i];
			sum2=sum2+a2[i];
		}
		
		//计算|n1-n2|、|s1-s2|并返回
		cout<<"\n|n1-n2|="<<(n/2)-(n/2)<<endl;
		
		cout<<"|s1-s2|="<<sum2-sum1<<endl;
		
		return sum2-sum1;
		
	}
	
}

int main(){
	//询问用户数组元素的个数 
	cout<<"请输入列表中有多少个数\n";
	int n;
	cin>>n;
	
	int a[n];
	//调用输入函数，接收数组中的每一个数 
	getin(a,n);
	//调用排序函数，将数组排序为升序 
	sorting(a,n);
	//分治法分解出左右数组
	divide(a,n);
	
	
	cout<<"\n";
	system("pause");
	return 0; 
}

