#include <iostream>


struct node{
  int key;
  node* left;
  node* right;
};


class btree{
public:
  btree();
  ~btree();
  void insert(int key);
  node* search(int key);
  void destroy_tree();
  void display();

private:
  void destroy_tree(node* leaf);
  void insert(int key, node* leaf);
  node* search(int key, node* leaf);
  void display(node* node);
  node* root;
};

//Constructor
btree::btree(){ //Public
  root=NULL;
}

//Destructor
btree::~btree(){ //Public
  destroy_tree();
}

//Iterate through the tree one note at a time until it finds the last one
//  and delete them from the bottom up. Recursive.
void btree::destroy_tree(node *leaf){ //Private
  if(leaf!=NULL){
    destroy_tree(leaf->left);
    destroy_tree(leaf->right);
    delete leaf;
  }
}

//If the value is less than the current node put it in the left sub tree, else right.
void btree::insert(int key, node* leaf){
  if(key < leaf->key){
    if(leaf->left != NULL){
      insert(key, leaf->left);
    }else{
      leaf->left = new node;
      leaf->left->key = key;
      leaf->left->left = NULL;
      leaf->left->right = NULL;
    }
  }else if(key >= leaf->key){
    if(leaf->right != NULL){
      insert(key, leaf->right);
    }else{
      leaf->right = new node;
      leaf->right->key = key;
      leaf->right->left = NULL;
      leaf->right->right = NULL;
    }
  }
}

node* btree::search(int key, node* leaf){ //Private
  if(leaf != NULL){
    if(key == leaf->key){
      return leaf;
    }
    if(key < leaf->key){
      return search(key, leaf->left);
    }
    if(key >= leaf->key){
      return search(key, leaf->right);
    }
  }else{
    return NULL;
  }
}

void btree::display(node *node){ //Private
  if(node->left != NULL){
    display(node->left);
  }
  if(node->right != NULL){
    display(node->right);
  }
  std::cout << node->key << " ";
}

void btree::insert(int key){ //Public
  if(root != NULL){
    insert(key, root); //Use the private function
  }else{
    root = new node;
    root->key = key;
    root->left = NULL;
    root->right = NULL;
  }
}

node* btree::search(int key){ //Public
  return search(key, root);
}

void btree::destroy_tree(){ //Public
  destroy_tree(root);
}

void btree::display(){ //Public
  display(root);
}


int main(){ //I hope this works...
  int x,n;
  btree tree;
  std::cout << "Number of nodes in the tree: ";
  std::cin >> n;
  for(int i=0; i<n; i++){
    std::cin >> x;
    tree.insert(x);
  }
  tree.display();
  std::cout << std::endl;
  return 0;
}
