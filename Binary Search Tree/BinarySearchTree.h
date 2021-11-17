// Assignment #6
// Name: Uday Yalamanchili
// ASU Email Address: uyalaman@asu.edu
// Description: The below program builds our own custom data structure by defining the methods insertElement, 
// searchElement, changeElement, printable, constructor and destructor for the class HashTable.

#include <iostream> //to use cout
#include <string> //to use strings
#include <cstdlib> //to use atoi

using namespace std;

//Club represents some club information
class Club
 {
  private: 
    string clubName;
    string universityName;
    Club * left, * right, * parent;


  public:
    //The following two functions are constructors
    Club()
     { 
      clubName = "?";
      universityName = "?";
      parent = NULL;
      left = NULL;
      right = NULL;
     }


    Club(string clubName1, string universityName1)
     {
      clubName = clubName1;
      universityName = universityName1;
     
      parent = NULL;
      left = NULL;
      right = NULL;
     }

    //The following functions are accessor functions
    Club * getLeft()
     {
      return left;
     }

    Club * getRight()
     {
      return right;
     }

    Club * getParent()
     {
      return parent;
     }
     
    string getClubName()
     {
         return clubName;
     }
     string getUniversityName()
     {
         return universityName;
     }
     

    //The following functions are mutator functions
    void setLeft(Club * other)
     {
       left = other;
     }

    void setRight(Club * other)
     {
       right = other;
     }

    void setParent(Club * other)
     {
       parent = other;
     }

    //The print method prints the clubName and universityName
    void print()
     {
         cout << "Club Name: " << clubName << endl;
         cout << "University Name: " << universityName << endl << endl;
     }

   //you can add more functions

 };

//class BinarySearchTree will contains clubs
class BinarySearchTree
 {
  private:
     Club * root;
     int size;

  public:
     BinarySearchTree();
     ~BinarySearchTree();
     int postOrderTreeDelete(Club *);
     bool isEmpty();
     void inOrderTreePrint();
     void preOrderTreePrint();
     void postOrderTreePrint();
     void inOrderTreeWalk(Club *);
     void preOrderTreeWalk(Club *);
     void postOrderTreeWalk(Club *);
     Club * treeSearchNode(Club *, string, string);
     Club * treeSearch(string, string);
     Club * treeMinimum();
     Club * treeMaximum();
     Club * treeMinimumNode(Club *);
     Club * treeMaximumNode(Club *);
     Club * treeSuccessor(string,string);
     Club * treePredecessor(string,string);
     bool treeInsert(string,string);
     bool rightRotate(string, string);
     bool leftRotate(string, string);
 };

//The constructor initialize the root to be NULL
BinarySearchTree::BinarySearchTree()
 {
  root = NULL;
 }

//The descurtor should delete all nodes in the tree 
//and perform garbage collections starting from leaves (bottom-up order). 
//The destructor should also print “The number of nodes deleted: X” 
//where X is the number of nodes deleted
BinarySearchTree::~BinarySearchTree()
 {
  size = postOrderTreeDelete(root);
  cout << "The number of nodes deleted: " << size << endl; 
 }

//Checks if the tree is empty
bool BinarySearchTree::isEmpty()
 {
   if (root == NULL)
    return true;
   else
    return false; 
 }

//prints all nodes using in-order
void BinarySearchTree::inOrderTreePrint()
 {
  if (isEmpty())
    cout << "tree is empty" << endl;
  else
   {
    cout << "\n";
    inOrderTreeWalk(root);
    cout << "\n";
   }
 }

//prints all nodes using pre-order
void BinarySearchTree::preOrderTreePrint()
 {
  if (isEmpty())
    cout << "tree is empty" << endl;
  else
   {
    cout << "\n";
    preOrderTreeWalk(root);
    cout << "\n";
   }
 }

//prints all nodes using post-order
void BinarySearchTree::postOrderTreePrint()
 {
  if (isEmpty())
    cout << "tree is empty" << endl;
  else
   {
    cout << "\n";
    postOrderTreeWalk(root);
    cout << "\n";
   }
 }

//generates the in-order sequence of nodes based on a given node. This method is used in the above in-order print method with root as the given node
void BinarySearchTree::inOrderTreeWalk(Club * x)
{
  if (x != NULL)
  {
    inOrderTreeWalk(x->getLeft());
    x->print();
    inOrderTreeWalk(x->getRight());
  }
}

//generates the pre-order sequence of nodes based on a given node. This method is used in the above pre-order print method with root as the given node
void BinarySearchTree::preOrderTreeWalk(Club * x)
{
  if (x != NULL)
  {
    x->print();
    preOrderTreeWalk(x->getLeft());
    preOrderTreeWalk(x->getRight());
  }
}

//generates the post-order sequence of nodes based on a given node. This method is used in the above post-order print method with root as the given node
void BinarySearchTree::postOrderTreeWalk(Club * x)
{
  if (x != NULL)
  {
    postOrderTreeWalk(x->getLeft());
    postOrderTreeWalk(x->getRight());
    x->print();
  }
}

//deletes each node starting from the leaves in a post-order sequence based on a given node. This method is used in the destructor with root as the given node
int BinarySearchTree::postOrderTreeDelete(Club * x)
{
  if (x != NULL)
  {
    postOrderTreeDelete(x->getLeft());
    postOrderTreeDelete(x->getRight());
    delete x;
    size++;
  }
  return size;
}

//searches for the given key (universityName or clubName if university is identical) starting from the given node and returns it if found.
Club * BinarySearchTree::treeSearchNode(Club * x, string clubName, string universityName)
{
  if (x == NULL)
  {
    return NULL;
  }

  string a, b;
  a = x->getUniversityName();
  b = universityName;

  // if universityName is identical, compare using clubName
  if (a.compare(b) == 0)
  {
    a = x->getClubName();
    b = clubName;
  }
  if (a.compare(b) == 0)
  {
    return x;
  }
  else
  {
    if (a.compare(b) > 0)
    {
      return treeSearchNode(x->getLeft(), clubName, universityName);
    }
    else
    {
      return treeSearchNode(x->getRight(), clubName, universityName);
    }
  }
}

//searches for the given key across the whole tree (i.e. from root)
Club * BinarySearchTree::treeSearch(string clubName, string universityName)
{
  return treeSearchNode(root, clubName, universityName);
}

//returns the minimum node in the subtree of the given node
Club * BinarySearchTree::treeMinimumNode(Club * x)
{
  if (x == NULL)
  {
    return x;
  }
  else
  {
    while (x->getLeft() != NULL)
    {
      x = x->getLeft();
    }
    return x;
  }
}

//returns the minimum or the first entry in the whole tree. Uses the treeMinimumNode method with root as the argument
Club * BinarySearchTree::treeMinimum()
{
  return treeMinimumNode(root);
}

//returns the maximum node in the subtree of the given node
Club * BinarySearchTree::treeMaximumNode(Club * x)
{
  if (x == NULL)
  {
    return x;
  }
  else
  {
    while (x->getRight() != NULL)
    {
      x = x->getRight();
    }
    return x;
  }
}

//returns the maximum or the last entry in the whole tree. Uses the treeMaximumNode method with root as the argument
Club * BinarySearchTree::treeMaximum()
{
  return treeMaximumNode(root);
}

//returns the successor of the node with the given key. If the given key is not found, it'll return NULL
Club * BinarySearchTree::treeSuccessor(string clubName, string universityName)
{
  Club * x, * y;
  x = treeSearch(clubName, universityName);

  if (x == NULL)
  {
    return x;
  }
  else
  {
    if (x->getRight() != NULL)
    {
      //get the minimum (left most) node of the subtree of right child of x
      return treeMinimumNode(x->getRight());
    }
    else
    {
      y = x->getParent();
      while ((y != NULL) && (x == y->getRight()))
      {
        x = y;
        y = y->getParent();
      }
      return y;
    }
  }
}

//returns the predecessor of the node with the given key. If the given key is not found, it'll return NULL
Club * BinarySearchTree::treePredecessor(string clubname,string universityName)
{
  Club * x, * y;
  x = treeSearch(clubname, universityName);

  if (x == NULL)
  {
    return x;
  }
  else
  {
    if (x->getLeft() != NULL)
    {
      //get the maximum (right most) node of the subtree of left child of x
      return treeMaximumNode(x->getLeft());
    }
    else
    {
      y = x->getParent();
      while ((y != NULL) && (x == y->getLeft()))
      {
        x = y;
        y = y->getParent();
      }
      return y;
    }
  }
}

//This method adds new club and university information based on the key (universityName or clubName if university is identical). If the tree is empty, the first entry will be the root of the tree. Duplicates will not be inserted
bool BinarySearchTree::treeInsert(string clubName, string universityName)
{
  //return false if a node with identical key (duplicate) is found
  if (treeSearch(clubName, universityName) != NULL)
  {
    return false;
  }
  else
  {
    Club * x, * y;
    //z is the new node instantiated with the given clubName and universityName
    Club * z = new Club(clubName, universityName);
    string a, b;
    x = root;
    y = NULL;

    while (x != NULL)
    {
      y = x;
      a = y->getUniversityName();
      b = z->getUniversityName();

      //compare using clubName if universityName is identical
      if (a.compare(b) == 0)
      {
        a = y->getClubName();
        b = z->getClubName();
      }

      if (a.compare(b) > 0)
      {
        x = x->getLeft();
      }
      else
      {
        x = x->getRight();
      }
    }
    z->setParent(y);
    if (y == NULL)
    {
      root = z;
    }
    else
    {
      if (a.compare(b) > 0)
      {
        y->setLeft(z);
      }
      else 
      {
        y->setRight(z);
      }
    }
    return true;
  }
}

//This method helps to right rotate the tree around the given node in the tree. The node is found by using the treeSearch method using the clubName and universityName. If there is no left node to the given node or if the tree is empty, the right rotation will not happen.
bool BinarySearchTree::rightRotate(string clubName, string universityName)
{
  Club * x, * y;
  x = treeSearch(clubName, universityName);
  if (x == NULL)
  {
    return false;
  }
  else
  {
    y = x->getLeft();
    if (y == NULL)
    {
      return false;
    }
    else
    {
      //setting the left of x with the right of y
      x->setLeft(y->getRight());
      if (y->getRight() != NULL)
      {
        (y->getRight())->setParent(x);
      }
      //setting the parent of y with the parent of x. If parent of x is NULL, y is set as the root
      y->setParent(x->getParent());
      if (x->getParent() == NULL)
      {
        root = y;
      }
      else
      {
        //if x is the left child of its parent, set y as the left child and vice versa
        if (x == (x->getParent())->getLeft())
        {
          (x->getParent())->setLeft(y);
        }
        else
        {
          (x->getParent())->setRight(y);
        }
        y->setRight(x);
        x->setParent(y);
      }
      return true;
    }
  }
}

//This method helps to left rotate the tree around the given node in the tree. The node is found by using the treeSearch method using the clubName and universityName. If there is no right node to the given node or if the tree is empty, the left rotation will not happen.
bool BinarySearchTree::leftRotate(string clubName, string universityName)
{
  Club * x, * y;
  x = treeSearch(clubName, universityName);
  if (x == NULL)
  {
    return false;
  }
  else
  {
    y = x->getRight();
    if (y == NULL)
    {
      return false;
    }
    else
    {
      //setting the right of x with the left of y
      x->setRight(y->getLeft());
      if (y->getLeft() != NULL)
      {
        (y->getLeft())->setParent(x);
      }
      //setting the parent of y with the parent of x. If parent of x is NULL, y is set as the root
      y->setParent(x->getParent());
      if (x->getParent() == NULL)
      {
        root = y;
      }
      else
      {
        //if x is the left child of its parent, set y as the left child and vice versa
        if (x == (x->getParent())->getLeft())
        {
          (x->getParent())->setLeft(y);
        }
        else
        {
          (x->getParent())->setRight(y);
        }
        y->setLeft(x);
        x->setParent(y);
      }
      return true;
    }
  }
}
