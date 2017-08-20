#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  int data;
  struct node* next;
} node;

typedef void (*callback)(node* data);

node* create(int data, node* next)
{
  node* new_node = (node*)malloc(sizeof(node));

  new_node->data = data;
  new_node->next = next;

  return new_node;
}

node* prepend(node* head, int data)
{
  node* new_node = create(data, head);
  head = new_node;
  return head;
}

void traverse(node* head, callback f)
{
  node* cursor = head;
  while(cursor != NULL)
  {
    f(cursor);
    cursor = cursor->next;
  }
}

int count(node *head)
{
  node *cursor = head;
  int c = 0;
  while(cursor != NULL)
  {
    c++;
    cursor = cursor->next;
  }
  return c;
}

node* append(node* head, int data)
{
  node *cursor = head;
  while(cursor->next != NULL)
    cursor = cursor->next;

  node* new_node = create(data, NULL);
  cursor->next = new_node;

  return head;
}

// node* insert_before
// node* insert_after

node* search(node* head, int data)
{
  node *cursor = head;
  while(cursor != NULL)
  {
    if(cursor->data == data)
      return cursor;
    cursor = cursor->next;
  }
  return NULL;
}

node* remove_front(node* head)
{
  if(head == NULL)
    return NULL;
  node *front = head;
  head = head->next;
  front->next = NULL;

  if(front == head)
    head = NULL;
  free(front);
  return head;
}

// node* remove_back

void display(node* n)
{
  if(n != NULL)
    printf("%d ", n->data);
}

int main()
{
  node* head = NULL;

  head = create(1, NULL);
  append(head, 2);
  append(head, 3);
  traverse(head, display);

  return 0;
}
