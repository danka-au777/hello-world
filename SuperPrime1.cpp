#include<iostream>
#include<vector>
/**
  * 定义素数对象 
  */ 
class Prime{
public:
   	Prime(int n):num_(n){
	   }
	Prime (const Prime &obj):num_(obj.num_){}//拷贝构造函数 
	~Prime(){
	   }
	bool isPrime() const {//常函数  只做判断 不改变其他 
		return false; 
	}
	//缺少赋值运算符  ;运算符重载  提供克隆功能以便num克隆p对象 
	Prime& operator=(const Prime &obj){//:num_(obj.num_){//只有构造函数才能携带：num_ 
		//this->num_ = obj.num_; //num_ read only warning 
		return *this;
	} 
private: 
    const unsigned int num_;//素数属性是常量 自然数 	
};
/**
 *这是一个统计素数数量的程序
 *使用了STL的容器/模板技术/函数对象
 */ 
 int main(){
    //构建素数对象集合 
 	std::vector<Prime> nums;//vector如何正确理解使用 
 	Prime p(2); /*用2构造一个对象*/ //此处p对象是main函数的 
 	nums.push_back(p);/*把p对象放入集合vector num ，  p与num实际是相互分开的在num内克隆出p 
	 上下两个对象为在cpp中不是同一个对象 2被构造成两个对象，垃圾回收器*/ 
	delete p;//vector中的对象是否存在，如何通知num 对象已不存在？ 
	//遍历素数对象集合，统计素数量并输出 
	int count=0;
	for (std::vector<Prime>::iterator it = nums.begin();it !=nums.end();++it){
		if(it->isPrime())/*多用自解释函数，注意函数命名规范*/ 
			count+=1;//it对象等价于p对象 
	} 
	std::cout << "How many: "<<count<<std::endl;
 	return 0;
 }
 //java的虚拟机垃圾回收于克隆不同 而是对象计数器 
 //使得delete p之后it依旧存在  
 //垃圾回收器 p num何时能删除=>垃圾回收器的作用 
 
