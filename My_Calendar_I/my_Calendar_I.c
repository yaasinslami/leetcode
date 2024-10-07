#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 1000

typedef struct {

	int	start;
	int	end;
} Event;

typedef struct {

	Event events[MAX_SIZE];
	int count;
} MyCalendar;

MyCalendar* myCalendarCreate() {

	MyCalendar *obj = (MyCalendar *)malloc(sizeof(MyCalendar));
	if (!obj)
		return (NULL);
	obj->count = 0;

	return (obj);
}

int binarySearch(MyCalendar *obj, int start)
{
	int left = 0, right = obj->count - 1;

	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (obj->events[mid].start == start)
		{
			return (mid);
		}
		if (obj->events[mid].start < start)
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}

	return (left);
}

bool myCalendarBook(MyCalendar* obj, int start, int end)
{
	if (obj->count == 0)
	{
		obj->events[0] = (Event){start, end};
		obj->count++;
	}

	int index = binarySearch(obj, start);

	if (index > 0 && start < obj->events[index - 1].end)
		return (false);

	if (index < obj->count && end > obj->events[index].start)
	{
		return (false);
	}

	/* insert new event */
	int i = obj->count;
	while (i > index)
	{
		obj->events[i] = obj->events[i - 1];
		i--;
	}

	obj->events[index] = (Event){start, end};
	obj->count++;

	return (true);
}

void myCalendarFree(MyCalendar* obj) {
    free(obj);
}

/**
 * Your MyCalendar struct will be instantiated and called as such:
 * MyCalendar* obj = myCalendarCreate();
 * bool param_1 = myCalendarBook(obj, start, end);
 
 * myCalendarFree(obj);
*/