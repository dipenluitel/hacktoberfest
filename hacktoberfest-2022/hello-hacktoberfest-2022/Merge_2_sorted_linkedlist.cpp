
struct Node {
  int data;
  struct Node *next;

  Node(int x) {
    data = x;
    next = NULL;
  }
};
//Function to merge two sorted linked list.
Node* sortedMerge(Node* head1, Node* head2)
{
    // code here
    Node* temp = new Node(-1);
    Node *p=head1,*q=head2,*t=temp;
while(p!=NULL && q!=NULL)
{
if(p->data<q->data)
{
t->next=p;
p=p->next;
}
else
{
t->next=q;
q=q->next;
}
t=t->next;
}
while(p!=NULL)
{
t->next=p;
p=p->next;
t=t->next;
}
while(q!=NULL)
{
t->next=q;
q=q->next;
t=t->next;
}
return temp->next;
}
