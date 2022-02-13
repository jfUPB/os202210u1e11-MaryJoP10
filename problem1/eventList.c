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
    Event *re = this->head;
    if (this->isEmpty != 0)
    {
        while (re != NULL)
        {
            if (*(re->eventName + 2) == *(event->eventName + 2) && *(re->eventName + 3) == *(event->eventName + 3)){
                return;
            }
            re = re->next;
        }
        this->last->next = event;
        this->last = event;
    }
    else
    {
        this->head = event;
        this->last = event;
        this->isEmpty = 1;
    }

}

void RemoveEvent(EventList *this, char *name)
{
}

void ListEvents(EventList *this)
{
     Event *re = this->head;

    if (this->isEmpty == 0){
        printf("empty\n");
    }
    else{
        while (re != NULL){
            printf("%s\n", re->eventName);
            re = re->next;
        }
    }
}
