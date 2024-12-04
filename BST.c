#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node{
    struct node *rlink;
    struct node *llink;
    int data;
};
typedef struct node *NODE;
NODE root=NULL;
NODE createnode(int);
NODE insertnode(NODE,int);
void inorder(NODE);
void preorder(NODE);
void postorder(NODE);
void search(NODE,int);
int main(){
    int ch,i,key,vals[15],n;
    printf("Enter the number of values: ");
    scanf("%d",&n);
    printf("Enter %d values: ",n);
    for(i=0;i<n;i++){
        scanf("%d",&vals[i]);
    }
    while(1){
        printf("Menu\n1.Create Binary Tree\n2.Traversals\n3.Search\n4.Exit\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                for(i=0;i<n;i++){
                    root=insertnode(root,vals[i]);
                }
                printf("Tree Constructed Successfully\n");
                break;
            case 2:
                printf("Inorder: ");
                inorder(root);
                printf("\nPreorder: ");
                preorder(root);
                printf("\nPostorder: ");
                postorder(root);
                printf("\n");
                break;
            case 3:
                printf("Enter the key you want to search in Tree: ");
                scanf("%d",&key);
                search(root,key);
                break;
            case 4:
                exit(0);
        }
    }
    return 0;
}
NODE createnode(int val){
    NODE temp=malloc(sizeof(struct node));
    temp->data=val;
    temp->llink=NULL;
    temp->rlink=NULL;
    return temp;
}
NODE insertnode(NODE temp,int val){
    if(temp==NULL){
        temp=createnode(val);
    }else if(val<temp->data){
        temp->llink=insertnode(temp->llink,val);
    }else{temp->rlink=insertnode(temp->rlink,val);}
    return temp;
}
void inorder(NODE temp){
    if(temp!=NULL){
        inorder(temp->llink);
        printf("%d ",temp->data);
        inorder(temp->rlink);
    }
}
void preorder(NODE temp){
    if(temp!=NULL){
        printf("%d ",temp->data);
        preorder(temp->llink);
        preorder(temp->rlink);
    }
}
void postorder(NODE temp){
    if(temp!=NULL){
        postorder(temp->llink);
        postorder(temp->rlink);
        printf("%d ",temp->data);
    }
}
void search(NODE temp,int key){
    while(temp!=NULL){
        if(temp->data==key){
            printf("Element Found\n");
            return;
        }else if(key<temp->data){
            temp=temp->llink;
        }else{
            temp=temp->rlink;
        }
    }
}