#include <iostream>
#include<string.h>
class DateTime {
private:
  int year, month, day;
  int hour, minute, second;
public:
  DateTime();
  ~DateTime();
  void showTime();
  void showMoon();  //��ҵ������ǰ����ת��Ϊũ����ʾ���� 
};
int main() {
  DateTime dt, dt1;
  std::cout << &dt << std::endl;
  std::cout << &dt1 << std::endl;
  dt.showTime();
  dt1.showTime();
  dt.showMoon();
  dt1.showMoon();
  return 0;
}
DateTime::DateTime()
{
  year = 2020; month = 12; day = 8;
  hour = 11; minute = 27; second = 55;
}
DateTime::~DateTime() 
{
  std::cout << this << " Go die, Ha~Ha~" << std::endl;
}
void DateTime::showTime()
{
  printf("��ǰʱ�䣺%d/%d/%d %d:%d:%d\n", year, month, day, hour, minute, second);
}

void DateTime::showMoon(){//only 2020
	const char *Day[]={"x","��һ","����","����","����","����","����","����","����","����","��ʮ"
	            "ʮһ","ʮ��","ʮ��","ʮ��","ʮ��","ʮ��","ʮ��","ʮ��","ʮ��","��ʮ",
				"إһ","إ��","إ��","إ��","إ��","إ��","إ��","إ��","إ��","��ʮ"};
    const char *Month[]={"x","��","��","��","��","����","��","��","��","��","��","ʮ","��","��"};
    int mondays[]={0,31,29,31,30,31,30,31,31,30,31,30,31};
    int lu_days[]={0,29,30,30,30,29,30,29,29,30,29,30,29};
	char lu_year[10],lu_mon[10],lu_day[10];
    int i,j,m,d,time,extra=0;
    if(month>1||(month==1&&day>=25)){
    	strcpy(lu_year,"����");
    	m=month-1;d=day-25;time=0;
    	for(i=1;i<=m;i++){
    		time=time+mondays[i];
		}
		time=time+d;
		j=time; printf("%d ",time);
		for(i=0;j>29;i++){
			j=j-lu_days[i];
		}
		strcpy(lu_mon,Month[i]);
		strcpy(lu_day,Day[j]);
	}
	else{
		strcpy(lu_year,"����");
		strcpy(lu_mon,"��");
		int x=5+day;
		strcpy(lu_day,Day[x]);
	}
	printf("��ǰũ��ʱ�䣺%s��%s��%s %d:%d:%d\n",lu_year,lu_mon,lu_day,hour, minute, second);
} 
 
