#include "eventList.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

EventList *CreateEventList(void)
{
    EventList *eventList = malloc(sizeof(EventList));
    eventList->head = NULL;
    eventList->last = NULL;
    eventList->isEmpty = 0;

    return eventList;
}

void DestroyEventList(EventList *this)
{


    free(this);
}

Event *SearchEvent(EventList *this, char *name)
{


    return NULL;
}

void AddEvent(EventList *this, Event *event)
{

}

void RemoveEvent(EventList *this, char *name)
{
}

void ListEvents(EventList *this)
{
    // imprime esto si la lista está vacía
    printf("empty\n");
}
