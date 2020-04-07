//作业：完成以下框架的代码细节，程序能编译运行得到正确结果 
#include <iostream>
class SuperPrime {
  public:
    int number;
  	SuperPrime(){
	}
  	~SuperPrime() {
	}
  	bool isSuperPrime() {
  	  split();
  	  int a = sum();
	  int b = multi();
	  int c = squareSum();
	  if (isPrime(number) && isPrime(a) && isPrime(b) && isPrime(c))
	    return true; 
  	  return false;
	}
  private:
  	int N[100], NumSize;
  	bool isPrime(int n) { 
  	    if(n==2)return true;
  	  	for(int j=2;j<=n/2+1;j++){
  	  		if(n%j==0)
			return false;
		}
		return true;
	}
	void split() {
	  // number split into N
	  int i,j=1,x=number;
	  for(i=0;x!=0;i++){
		j*=10;
		N[i]=(x%j)/(j/10);
		x-=N[i]*(j/10);
	   }
	  NumSize=i;
	}
	int sum() {
		int Sum=0;
		for(int i=0;i<NumSize;i++){
			Sum+=N[i];
		}
	  	return Sum;
	}
	int multi() {
		int Multi=1;
		for(int i=0;i<NumSize;i++){
			Multi=Multi*N[i];
		}
		return Multi;
	}
	int squareSum() {
		int SquareSum=0;
		for(int i=0;i<NumSize;i++){
			SquareSum+=N[i]*N[i];
		}
	  return SquareSum;
	}
};
class Set {
  public:
  	Set(int from, int to) {
  	  size =to-from+1;
  	  set[0].number=from;
  	  for(int i=1;i<size;i++){
  	  	set[i].number=set[i-1].number+1;
		}
	}
  	~Set() {
	}
  	int count() {
  	  int count = 0;
  	  for (int i = 0; i < size; i++)
  	    if(set[i].isSuperPrime())
  	      {
			count += 1;
		}
	  return count; 
	}
  	int sum() {
  	  int sum = 0;
  	  for (int i = 0; i < size; i++)
  	    if(set[i].isSuperPrime())
  	      sum += set[i].number;
	  return sum; 
	}
  private:
  	SuperPrime set[1000];
  	int size;
};
int main() {
  Set ss(100, 999);
  std::cout << "How Many: " << ss.count() << std::endl;
  std::cout << "Sum is " << ss.sum() << std::endl;
  return 0;
}
