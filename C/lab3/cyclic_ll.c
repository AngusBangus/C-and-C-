#include <stdio.h>

typedef struct node {
  int value;
  struct node *next;
} node;

int has_cycle(node *head)
{
  struct node *head1 = head;
  struct node *head2 = head;
while(head2 && head1 && head2->next){
  head2 = head2->next->next;
  head1 = head1->next;

  if (head2 == head1){
    return head2;
  }





}

  return NULL;

  // head goes one node head 2 goes two nodes head 2 loops until equal to head 1
  // if(no node) then next = null
  //head1 -> next head 2 -> head -> next

	// Your code goes here:
}

void test_has_cycle(void)
{
  int i;
  node nodes[25]; //enough to run our tests
  for(i=0; i < sizeof(nodes)/sizeof(node); i++) {
    nodes[i].next = 0;
    nodes[i].value = 0;
  }
  nodes[0].next = &nodes[1];
  nodes[1].next = &nodes[2];
  nodes[2].next = &nodes[3];
  printf("Checking first list for cycles. There should be none, has_cycle says it has %s cycle\n",
    has_cycle(&nodes[0])?"a":"no");
  
  nodes[4].next = &nodes[5];
  nodes[5].next = &nodes[6];
  nodes[6].next = &nodes[7];
  nodes[7].next = &nodes[8];
  nodes[8].next = &nodes[9];
  nodes[9].next = &nodes[10];
  nodes[10].next = &nodes[4];
  printf("Checking second list for cycles. There should be a cycle, has_cycle says it has %s cycle\n",
    has_cycle(&nodes[4])?"a":"no");
  
  nodes[11].next = &nodes[12];
  nodes[12].next = &nodes[13];
  nodes[13].next = &nodes[14];
  nodes[14].next = &nodes[15];
  nodes[15].next = &nodes[16];
  nodes[16].next = &nodes[17];
  nodes[17].next = &nodes[14];
  printf("Checking third list for cycles. There should be a cycle, has_cycle says it has %s cycle\n",
    has_cycle(&nodes[11])?"a":"no");
  
  nodes[18].next = &nodes[18];
  printf("Checking fourth list for cycles. There should be a cycle, has_cycle says it has %s cycle\n",
    has_cycle(&nodes[18])?"a":"no");
  
  nodes[19].next = &nodes[20];
  nodes[20].next = &nodes[21];
  nodes[21].next = &nodes[22];
  nodes[22].next = &nodes[23];
  printf("Checking fifth list for cycles. There should be none, has_cycle says it has %s cycle\n",
    has_cycle(&nodes[19])?"a":"no");
  
  printf("Checking length-zero list for cycles. There should be none, has_cycle says it has %s cycle\n",
    has_cycle(NULL)?"a":"no");
}

int
main(void)
{
  test_has_cycle();
  return 0;
}
