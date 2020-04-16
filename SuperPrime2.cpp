//作业：面向对象设计以下框架的代码细节，程序能编译运行得到正确结果 
#include <iostream>
class Prime{
	public:
		Prime(int n){
			Number=n;
		}
		~Prime(){
		}
	    bool isPrime() { 
  	  //2到number-1的因子 
  	  int temp=Number;
  	  if(Number==2)  return true;
  	  for(int i=2;i<temp;i++){
  	  	if(temp%i==0)
  	  	return false;
		}
  	  return true;
	}
  	int Number;
};
class SuperPrime {
  public:
  	SuperPrime():number(0) {  //为什么必须有？ 
  	  size = 0;
  	}
  	SuperPrime(int n):number(n) {
  	  size = 0;
  	  split();  //它就是构造对象 
	}
  	~SuperPrime() {
  	  for (int i = 0; i < size; ++i)  //销毁对象 
		delete N[i]; 
	}
  	bool isSuperPrime() {
  	  Prime num(number);
  	  Prime a(sum());   //将普通整数转变为对象 
	  Prime b(multi());
	  Prime c(squareSum());
	  if (num.isPrime() && a.isPrime() && b.isPrime() && c.isPrime())
	    return true; 
  	  return false;
	}
  private:
  	const int number;
  	Prime *N[100];
	int size;
	void split() {   //工厂方法设计模式 
	  // number split into N

	  int temp = number;
	   while(temp > 0) {
	  	int n = temp % 10;
	  	temp /=10 ; 
	  	N[size] = new Prime(n);  //构造对象 
	  	size += 1; 
	  }

	}
	int sum() {
		int Sum=0;
		for(int i=0;i<size;i++){
			Sum+=N[i]->Number;
		}
	  	return Sum;
	}
	int multi() {
		int Multi=1;
		for(int i=0;i<size;i++){
			Multi=Multi*N[i]->Number;
		}
		return Multi;
	}
	int squareSum() {
		int SquareSum=0;
		for(int i=0;i<size;i++){
			SquareSum+=N[i]->Number*N[i]->Number;
		}
	  return SquareSum;
	}
};
//class Set {
//  public:
//  	Set(int from, int to) {
//  	     size=0; 
//	}
//  	~Set() {
//	}
//  	int count() {
//  	  int count = 0;
//  	  for (int i = 0; i < size; i++)
//  	    if(set[i].isSuperPrime())
//  	      {
//			count += 1;
//		}
//	  return count; 
//	}
//  	int sum() {
//  	  int sum = 0;
//  	  for (int i = 0; i < size; i++)
//  	    if(set[i].isSuperPrime())
//  	      sum += set[i].number;
//	  return sum; 
//	}
//  private:
//  	SuperPrime set[1000];
//  	int size;
//};
int main() {
  SuperPrime sp(113);
  if (sp.isSuperPrime())
    std::cout << "113 is SuperPrime" << std::endl;
  else
    std::cout << "113 is NOT SuperPrime" << std::endl;
  return 0;
}
