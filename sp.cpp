#include<iostream>
#include<vector>
/**
  * ������������ 
  */ 
class Prime{
public:
   	Prime(int n):num_(n){
	   }
	Prime (const Prime &obj):num_(obj.num_){}//�������캯�� 
	~Prime(){
	   }
	bool isPrime() const {//������  ֻ���ж� ���ı����� 
		return false; 
	}
	//ȱ�ٸ�ֵ�����  ;���������  �ṩ��¡�����Ա�num��¡p���� 
	Prime& operator=(const Prime &obj){//:num_(obj.num_){//ֻ�й��캯������Я����num_ 
		//this->num_ = obj.num_; //num_ read only warning 
		return *this;
	} 
private: 
    const unsigned int num_;//���������ǳ��� ��Ȼ�� 	
};
/**
 *����һ��ͳ�����������ĳ���
 *ʹ����STL������/ģ�弼��/��������
 */ 
 int main(){
    //�����������󼯺� 
 	std::vector<Prime> nums;//vector�����ȷ���ʹ�� 
 	Prime p(2); /*��2����һ������*/ //�˴�p������main������ 
 	nums.push_back(p);/*��p������뼯��vector num ��  p��numʵ�����໥�ֿ�����num�ڿ�¡��p 
	 ������������Ϊ��cpp�в���ͬһ������ 2�������������������������*/ 
	delete p;//vector�еĶ����Ƿ���ڣ����֪ͨnum �����Ѳ����ڣ� 
	//�����������󼯺ϣ�ͳ������������� 
	int count=0;
	for (std::vector<Prime>::iterator it = nums.begin();it !=nums.end();++it){
		if(it->isPrime())/*�����Խ��ͺ�����ע�⺯�������淶*/ 
			count+=1;//it����ȼ���p���� 
	} 
	std::cout << "How many: "<<count<<std::endl;
 	return 0;
 }
 //java����������������ڿ�¡��ͬ ���Ƕ�������� 
 //ʹ��delete p֮��it���ɴ���  
 //���������� p num��ʱ��ɾ��=>���������������� 
 
