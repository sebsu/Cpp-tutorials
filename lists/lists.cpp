// http://www.cprogramming.com/tutorial/lesson15.html

struct node{
  int x;
  node* next;
};

typedef node* nodep; //Replace node* with nodep. 

/* Dummy main
int main(){
  node *root; //First node. Remains the same.
  root = new node; //Now root points to a node struct;
  root->next = 0;  //The node root points to has its next pointer
                   // set equal to a null pointer
  root->x = 5;     //By using the -> operator, you can modify what the node
                   // a pointer (root in this case) points to
  return 0;
}
*/
  
int main(){
  
  nodep root;     //This won't change, or we would lose the list in memory
  nodep conductor;//This will point to each node as it traverses the list

  root = new node;//root actually points to something!
  root->next = 0;
  root->x = 12;
  conductor = root; //Conductor points to the first node
  if(conductor != 0){
    while(conductor->next != 0){
      conductor = conductor->next;
    }
  }
  conductor->next = new node; //Creates a node at the end of the list
  conductor = conductor->next;//Points to the node
  conductor->next = 0;        //Prevents it from going any further
  conductor->x = 42;  

  return 0;
}
