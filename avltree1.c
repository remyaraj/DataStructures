//AVL Tree.

#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
}*root;

int balancevalue(struct node *);

void show(struct node *t)
{
	printf("%d->",t->data);
	if(t->left!=NULL){
		show(t->left);
	}
	if(t->right!=NULL){
		show(t->right);
	}
}


struct node * add(int a, struct node *t)
{
	if(t==NULL){
		t = (struct node *)malloc(sizeof(struct node *));
		t->data = a;
		printf("%d\n",t->data);
		t->left = t->right = NULL;
	}
	else if(t->data > a){
		t->left= add(a,t->left);
	}
	else if(t->data < a){
		t->right = add(a,t->right);
	}
		return t;
	
}

struct node* leftrotate(struct node *t)
{
	struct node *q;
	struct node *r;
	q = t->right;
        if(balancevalue(t->right)<=0){
		r = q->left;
                if(r!=NULL){
           		q->left = r->right;
                      	r->right = q;
                      	t->right = r->left;
                     	r->left = t;
                        t=r;
               	}
               	else{
                  	q->left = t;
                   	q->left->right = NULL;
                     	t = q;
              	}
     	}
        else{
               	t->right = q->left;
                q->left = t;
               	t = q;
      	}
	return t;
}

struct node* rightrotate(struct node *t)
{
	struct node *q;
	struct node *r;
     	q = t->left;
     	if(balancevalue(t->left)>=0){
            	t->left = q->right;
             	q->right = t;
               	t = q;
       	}
       	else{
           	r = q->right;
            	if(r!=NULL){
                     	q->right = r->left;
                    	r->left = q;
                    	t->left = r->right;
                     	r->right = t;
                    	t = r;
              	}
                else{
                    	q->right = t;
                    	q->right->left = NULL;
                      	t = q;
             	}
  	}

}

struct node * balance(struct node *t)
{
	int p;
	p = balancevalue(t);
	if(p==0||p==-1||p==1||(t->right == NULL && t->left == NULL)){
		return t;
	}
	else{
		if(p==-2) t = leftrotate(t);
		else if(p==2) t = rightrotate(t);
		return t;
	}

}

struct node* findmin(struct node* t)
{
	if((t==NULL)||(t->left == NULL))
		return t;
	return findmin(t->left);
}

struct node* delete(int a,struct node* t)
{
	struct node* temp;
	if(t==NULL){
		printf("Insert the elements");
	}	
	if(a<t->data){
		t->left = delete(a,t->left);
	}
	else if(a>t->data){
		t->right = delete(a,t->right);
	}
	else {
		temp = t;
		if(t->left == NULL){
			t=t->right;
		}
		else if(t->right == NULL){
			t = t->left;
		}
		else if(t->left && t->right){
			temp = findmin(t->right);
			t->data = temp->data;
			t->right = delete(t->data,t->right);
		}
		free(temp);
	}
	return t;
}

int height(struct node* t)
{
	if(t==NULL) return 0;
	else{
		if(height(t->right)>=height(t->left)) return height(t->right)+1;
		else return height(t->left)+1;
	}
}

int balancevalue(struct node* t)
{
	return (height(t->left)-height(t->right));
}


void main()
{
	int a;
	root = NULL;
	do{
		int b;
		int m;
		printf("Enter the choice:1.insertion 2.Deletion 3.height 4.exit");
		scanf("%d",&a);
		printf("");
		switch(a){
			case 1:
				printf("Enter the element to be inserted");
				scanf("%d",&b);
				root=add(b,root);
				root = balance(root);
				show(root);
				break;
			case 2:
				printf("Enter the element to de deleted");
				scanf("%d",&b);
				delete(b,root);
				root = balance(root);
				show(root);
				break;
			case 3:
				m=height(root);
				printf("The height of the node is %d",m);

			case 4:
				exit(0);
		}
	}while(a!=4);
}
