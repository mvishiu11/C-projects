#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct
{
	int hours;
	int minutes;
	int seconds;
}TIME;

TIME difference(TIME t1, TIME t2);
void print(TIME);

int main(void)
{
	TIME t1={10,10,30}, t2={13,10,20},diff;
	diff = difference(t1, t2);
	print(t1);
	print(t2);
	print(diff);
}

TIME difference(TIME t1, TIME t2)
{
	TIME diff;
	int time1=t1.hours*3600+t1.minutes*60+t1.seconds, time2= t2.hours * 3600 + t2.minutes * 60 + t2.seconds,time;
	time = abs(time1 - time2);
	diff.seconds = time % 60;
	diff.minutes = time/60 % 60;
	diff.hours = time/3600;
	return diff;
}

void print(TIME t)
{
	printf("%d hrs %d minutes %d seconds\n",t.hours,t.minutes,t.seconds);
}