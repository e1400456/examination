
#include "linkedlist.h"

int add_to_list(linked_list *ll, char *s){
    int index=0;
    linked_list *current=ll;
    while(ll->next!=NULL){
        ++index;
        ll=ll->next;
    }
    linked_list *newNode=(linked_list *)malloc(sizeof(linked_list));
    newNode->data=s;
    newNode->index=++index;
    newNode->next=NULL;
    ll->next=newNode;
    ll=current;
    return index;

}
int display_item(linked_list *ll){
    
   
    if(ll->data!=NULL){
        return 0;
    }
    else
    return -1;
}
int display_list(linked_list *ll){
    linked_list *node=ll;
    int count=0;
    while(node!=NULL){
        count++;
        printf("%s\n",node->data );
        node=node->next;

    }
    return count;


}

linked_list * search_from_list(linked_list *ll, char *s){

    linked_list *current=ll;
    char flag=0;
    while(current->data!=NULL || current->next!=NULL){
        if(current->data==NULL)
        {
            current=current->next;
            continue;
        }
        if(strcmp(current->data,s)==0){
            flag=1;
            break;

        }
        else{
            if(current->next==NULL)
            {
                flag=0;
                break;

            }
            else
                current=current->next;
        }
        

    }
    if(flag==1)
            return current;

        else
            return NULL;
}
int delete_from_list(linked_list *ll, int index){
    int i;
    int count=0;
    if(ll==NULL)
        return -1;
    linked_list *temp=ll;
    if(index==0){

        ll=temp->next;
        free(temp);
        return 1;
    }
    for(i=1;temp->next!=NULL && i<index-1;i++){
        
        temp=temp->next;
    }
    if(temp==NULL || temp->next==NULL)
        return 0;
    linked_list *next=temp->next->next;
    free(temp->next);
    temp->next=next;

    while(ll!=NULL){
        count++;
        ll=ll->next;

    }
    return count;


}


