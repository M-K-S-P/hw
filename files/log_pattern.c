#include <stdio.h>

#include

#define log_info(M, ...) fprintf(stderr, "[INFO] (%s:%d) " M "\n",\
        __FILE__, __LINE__, ##__VA_ARGS__)

int main2(int argc, char *argv[])
{
  log_info("Start of program");
  int var = 10;

  log_info("my variable is %d", var);

  log_info("End of program");
}

struct ListNode;
typedef struct ListNode {
  struct ListNode *next;
  struct ListNode *prev;
  void *value;
} ListNode;

typedef struct List {
  int count;
  ListNode *first;
  ListNode *last;
} List;

#define LIST_FOREACH(curr, list) \
  ListNode *curr = list->first;\
    for (ListNode *_node = list->first; \
         _node != NULL; \
         curr = _node = _node->next)

int main1(int argc, char *argv[])
{
  List *lst;

  /* Fill the linked list */

  LIST_FOREACH(curr, lst)
  {
    printf("%d\n", (int)curr->value);
  }
}
