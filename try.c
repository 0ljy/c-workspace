#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node *next;
    int dig;
};
int main(){

    int n;scanf("%d",&n);
    struct node* head=(struct node*)malloc(sizeof(struct node));
    struct node* last=(struct node*)malloc(sizeof(struct node));
    head->next=NULL;
    last->next=NULL;
    for(int i=0;i<n;++i){
        struct node* x=(struct node*)malloc(sizeof(struct node));
        scanf("%d",&x->dig);
        if(head->next==NULL)head->next=x;
        else last->next=x;
        last=x;
    }
    last->next=NULL;
    int c;scanf("%d",&c);
    struct node* x=(struct node*)malloc(sizeof(struct node));
    x=head;
    if(x->dig>c){
        x=head;
        head->dig=c;
        head->next=x;
        goto A;
    }
    while(1){
        if(x->next!=NULL && x->next->dig>c){
            struct node* ll=(struct node*)malloc(sizeof(struct node));
            ll->dig=c;
            ll->next=x->next;
            x->next=ll;
            break;
        }else if(x->next!=NULL){
            x=x->next;
        }else if(x->next==NULL){
            struct node* ll=(struct node*)malloc(sizeof(struct node));
            ll->dig=c;
            x->next=ll;
            ll->next=NULL;
            break;
        }
    }
    A:;
    struct node* t=(struct node*)malloc(sizeof(struct node));
    t=head->next;
    while(1){
        printf("%d ",t->dig);
        if(t->next==NULL)break;
        else t=t->next;
    }
    return 0;
}