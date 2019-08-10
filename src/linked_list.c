#include <stdlib.h>
#include <stdio.h>


// Our linked list will be made of these nodes
// NOTE: `typedef` means "rename x as y". The below means "take this struct
// called `node` with the following definition and refer to it as `node`
// going forwards.
typedef struct node {
  int val;
  struct node *next;
} node;

void printList(node *head)
{
  node *current = head;
  printf("[ ");
  while (current != NULL) {
    printf("%d ", current->val);
    current = current->next;
  }
  printf("]\n");
}

void appendToList(node *head, int value)
{
  node *current = head;
  while (current->next != NULL) {
    current = current->next;
  }
  // Once we find an element whose `next` is `NULL`, add a new node
  // contaning val
  current->next = malloc(sizeof(node));
  current->next->val = value;
}

void removeFromList(node *head, int indexToRemove)
{
  node *current = head;
  node *previous = NULL;
  size_t counter = 0;
  while (counter < indexToRemove) {
    previous = current;
    current = current->next;
    counter++;
  }
  // Once we've counted up to the right index, remove it from the
  // list and deallocate the memory
  previous->next = current->next;
  free(current);
}

void insertIntoList(node *head, int valueToInsert, int indexToInsert)
{
  node *current = head;
  node *previous = NULL;
  size_t counter = 0;
  while (counter < indexToInsert) {
    previous = current;
    current = current->next;
    counter++;
  }
  // Now we've reached the index to insert. Make a new node and patch it
  // into the list.
  node *new = malloc(sizeof(node));
  new->val = valueToInsert;
  previous->next = new;
  new->next = current;
}

int main(int argc, char *argv[])
{
  // We create a pointer variable to a node_t called `head`
  node *head = NULL;

  // Allocate some heap memory for the node
  head = malloc(sizeof(node));

  // If memory allocation fails, `malloc` returns `NULL`
  if (head == NULL) {
    return 1;
  }

  for (int i = 1; i < 5; i++) {
    appendToList(head, i);
  }

  printList(head);

  // Append a new value
  appendToList(head, 6);
  printList(head);

  // Remove an item
  removeFromList(head, 3);
  printList(head);
  
  // Insert a new item
  insertIntoList(head, 20, 2);
  printList(head);
  return 0;
}
