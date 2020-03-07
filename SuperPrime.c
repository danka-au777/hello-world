//超级素数：它本身，各位数字的和，各位数字的平方和，都是素数。
//求 100~10000 内的所有超级素数，及它们的平均数。
#include<stdio.h>
int isPrime(int x);
int splitNum(int x, int num[]);

int main()
{
	int i,k=0,size,j,sum,sqrsum;
	int ans[1000],bit[5];
	float SUM=0.0,Ave;
	for(i=100;i<10001;i++){
		if(isPrime(i)==0){
		   sum=0;sqrsum=0;
		   size=splitNum(i,bit);
		   for(j=0;j<size;j++){
			   sum=sum+bit[j];
			   sqrsum=sqrsum+bit[j]*bit[j];
		    }
		   if(isPrime(sum)==0&&isPrime(sqrsum)==0){
			   ans[k]=i; k++;
		    }
		}
	}
	printf("The superprimes between 100 and 10000 are:");
	for(i=0;i<k;i++){
		printf("%d ",ans[i]);
		SUM+=ans[i];
	}
	printf("\n");
	Ave=SUM/k;
	printf("The average is %f\n",Ave);
    return 0;
}

int isPrime(int x){
	int i,flag=0;
	for(i=2;i<x;i++){
		if(x%i==0){
		  flag=1;break;
		}	
	}
	if(x==2)flag=0;
	return flag;
 } 
 
int splitNum(int x,int num[]){
	int i,j=1;
	for(i=0;x!=0;i++){
		j*=10;
		num[i]=(x%j)/(j/10);
		x-=num[i]*(j/10);
	}
	return i;
}
