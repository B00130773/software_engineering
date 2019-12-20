#include<iostream>
#include<cstdlib>
#include <windows.h>

unsigned sleep(unsigned seconds);
class tmp
{
int temp[24],i,sum,avg;
int hum[24],j,sum1,avg1;


public:
void sensing();
void processing();
void processing2();
void humidity();
void idle();
}ob;

int main()
{
int ch=1;
do
{
std::cout<<"\n\nEnter choice";
std::cout<<"\n\n1.Sensing\n2.the average temp of past 24 hours\n3.humidity\n4.the average humidity of past 24 hours\n";

std::cin>>ch;

switch(ch)
{
case 1:
	ob.sensing();
	break;
case 2:
	ob.processing();
	break;
case 3:
	ob.humidity();
	break;
case 4:
	ob.processing2();
	break;
}
}
while(ch!=4);
}

void tmp::sensing()
{
std::cout<<"the tempretures recorded for the past 24hrs are";
for(int i=0;i<24;i++)
{
temp[i]=rand()%10;
std::cout<<"\n"<<temp[i]<< " degree celcious";
Sleep(300);
}
Sleep(1000);
}
void tmp::processing()
{
for(i=0;i<24;i++)
{
sum=sum+temp[i];
}
avg=sum/24;
//std::cout<<"\nSUM:"<<sum;
std::cout<<"\n average tempreture of past 24hrs is:"<<avg<<" degree celcious";
Sleep(1000);
}
void tmp::humidity()
{
std::cout<<"the humidity recorded for the past 24hrs are";
for(int j=0;j<24;j++)
{
hum[j]=rand()%10;
std::cout<<"\n"<<hum[j]<< " % ";
Sleep(300);
}
Sleep(1000);
}
void tmp::processing2()
{
for(j=0;j<24;j++)
{
sum1=sum1+hum[j];
}
avg1=sum1/24;
//std::cout<<"\nSUM:"<<sum;
std::cout<<"\n average humidity of past 24hrs is:"<<avg1<<" % ";
Sleep(1000);
}
