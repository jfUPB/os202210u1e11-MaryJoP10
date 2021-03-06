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
    Event *re = this->head;
    if(this->isEmpty != 0){
        while(re != NULL){
            if(*(re->eventName + 2) == *(name + 2) && *(re->eventName + 3) == *(name + 3)){
                return re;
            }
            re = re->next;
        }
    }
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
    Event *re = this->head;
    Event *nre = SearchEvent(this, name);
    if(nre == NULL){
        return;
    }
    if(this->isEmpty == 0){
        return;
    }
    else{
        while(re != NULL){
            if(*(this->head->eventName + 2) == *(name + 2)){
                this->head = this->head->next;
                break;
            }
            else if(*(re->next->eventName + 2) == *(name + 2)){
                re->next = re->next->next;
                break;
            }
            re = re->next;
        }
        if(this->head == NULL){
            this->isEmpty = 0;
        }
    }
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
