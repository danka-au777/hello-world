#include <iostream>
#include<string.h>
class DateTime {
private:
  static int sth;
  int year, month, day;
  int hour, minute, second;
public:
  DateTime();
  DateTime(int y, int m, int d, int hour, int minute, int second); 
  DateTime(const DateTime &dt);
  ~DateTime();
  void showTime();
  void showMoon();  //作业：将当前公历转换为农历显示出来 
};

int DateTime::sth = 0;

int main() {
  DateTime dt, dt1(2020, 3, 27, 10, 40, 55);
  DateTime dt2(dt), &dt3 = dt;
  DateTime *dt4 = &dt;
  dt.showTime();
  dt1.showTime();
  dt.showMoon();
  dt1.showMoon();
  dt2.showTime();
  dt3.showTime();
  dt4->showTime();
  return 0;
}
DateTime::DateTime()
{
  year = 2020; month = 3; day = 20;
  hour = 11; minute = 27; second = 55;
  sth = 11;
}
DateTime::DateTime(int y, int m, int d, int hour, int minute, int second)
{
  year = y; month = m; day = d;
  this->hour = hour; this->minute = minute; this->second = second;
}
DateTime::DateTime(const DateTime &dt)
{
  year = dt.year; month = dt.month; day = dt.day;
  hour = dt.hour; minute = dt.minute; second = dt.second;
}
DateTime::~DateTime() 
{
  std::cout << " Go die, Ha~Ha~" << std::endl;
}
void DateTime::showTime()
{
  printf("当前时间：%d/%d/%d %d:%d:%d\n", year, month, day, hour, minute, second);
  std::cout << sth << std::endl;
}

void DateTime::showMoon(){//only 2020
	const char *Day[]={"x","初一","初二","初三","初四","初五","初六","初七","初八","初九","初十"
	            "十一","十二","十三","十四","十五","十六","十七","十八","十九","二十",
				"廿一","廿二","廿三","廿四","廿五","廿六","廿七","廿八","廿九","三十"};
    const char *Month[]={"x","正","二","三","四","闰四","五","六","七","八","九","十","冬","腊"};
    int mondays[]={0,31,29,31,30,31,30,31,31,30,31,30,31};
    int lu_days[]={0,29,30,30,30,29,30,29,29,30,29,30,29};
	char lu_year[10],lu_mon[10],lu_day[10];
    int i,j,m,d,time,extra=0;
    if(month>1||(month==1&&day>=25)){
    	strcpy(lu_year,"庚子");
    	m=month-1;d=day-25;time=0;
    	for(i=1;i<=m;i++){
    		time=time+mondays[i];
		}
		time=time+d;
		j=time;
		for(i=0;j>29;i++){
			j=j-lu_days[i];
		}
		strcpy(lu_mon,Month[i]);
		strcpy(lu_day,Day[j]);
	}
	else{
		strcpy(lu_year,"己亥");
		strcpy(lu_mon,"腊");
		int x=5+day;
		strcpy(lu_day,Day[x]);
	}
	printf("当前农历时间：%s年%s月%s %d:%d:%d\n",lu_year,lu_mon,lu_day,hour, minute, second);
} 
 
