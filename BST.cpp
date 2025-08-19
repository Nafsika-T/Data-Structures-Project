#include "BST.h"
#include "clean.h"

#include <cstring>
#include <iterator>
#include <iostream>

using namespace std;

BST::BST()
{
  root=nullptr;
}


//Αυτή η μέθοδος δημιουργεί και επιστρέφει ένα νέο κόμβο

Node* BST::newNode(string word)
{
  Node *node= new Node;
  node->wc.word = word;  //εισάγεται στο νέο κόμβο η λέξη που δόθηκε σαν όρισμα
  node->wc.count_=1;   //και το αρχικό πλήθος της που θα είναι 1
  node->left = node->right = nullptr; //τα παιδιά του νέου κόμβου αρχικά θα είναι κενά
  node->height=1;  // το ύψος του νέου κόμβου αρχικά θα είναι 1 (χρήσιμο μόνο για avl)

  return node;
}


//Αυτή η συνάρτηση δέχεται ως όρισμα μια συμβολοσειρά και την εισάγει στο δέντρο

void BST::insertNode(string word)
{
  clean(word);

  Node *curr = root; //Δημιουργείται ένας δείκτης curr τύπου Node ο οποίος αρχικά παίρνει τη τιμή της ρίζας και κάθε φορά θα παίρνει τη τιμή του επόμενου κόμβου
  Node *parent = nullptr;  //Δημιουργείται ένας δείκτης parent τύπου Node ο οποίος κάθε φορά θα έχει ως τιμή τη τιμή του γονιού του curr (αρχικά είναι nullptr αφού η ρίζα δεν έχει γονιό)

  if (root==nullptr)       //Αν η τιμή της ρίζας είναι nullptr (αυτό θα συμβεί όταν ακόμα δεν θα έχουμε δέντρο)
  {
    root = newNode(word);  //τότε με τη βοήθεια της μεθόδου newNode δημιουργείται ένας νέος κόμβος με τη λέξη (αυτή η εντολή θα εκτελεστεί για την πρώτη λέξη που θα διαβαστεί)
    return;
  }

  //με αυτο το loop διασχίζουμε ένα μονοπάτι από τη ρίζα μέχρι ένα φύλλο ή μέχρι να βρεθεί η λέξη
  while (curr != nullptr)   // όσο το curr είναι διάφορο του μηδενός, δηλαδή όσο υπάρχει κόμβος να προχωρήσουμε
  {
    parent = curr;          //το parrent παίρνει τη τιμή του curr
    if (word.compare(curr->wc.word)==0)      //αν η λέξη υπάρχει ήδη
    {
      curr->wc.count_++;                     //τότε απλά αυξάνεται το πλήθος της κατά 1
      return;                               //και η μέθοδος τερματίζει
    }
    else if (word.compare(curr->wc.word) < 0)  //αν η λέξη είναι μικρότερη από τη λέξη του curr
    {
      curr = curr->left;                        //τότε το curr θα πάρει τη τιμή του αριστερού του παιδιού
    }
    else
    {                                      // αλλιώς αν η λέξη είναι μεγαλύτερη από τη λέξη του curr
      curr = curr->right;                       //τότε το curr θα πάρει τη τιμή του δεξιού του παιδιού
    }
  }

  if (word.compare(parent->wc.word) < 0) {     //αν η λέξη είναι μικρότερη από τη λέξη του parent
    parent->left = newNode(word);          //τότε με τη βοήθεια της μεθόδου newNode η λέξη εισάγεται στο αριστερό παιδί του parent
  }
  else {                                    //αλλιώς αν η λέξη είναι μεγαλύτερη από τη λέξη του parent
    parent->right = newNode(word);          //τότε με τη βοήθεια της μεθόδου newNode η λέξη εισάγεται στο δεξί παιδί του parent
  }
  return;                                   //και η μέθοδος τερματίζει
}


//Αυτή η μέθοδος διατρέχει τους κόμβους με τη σειρά: Αριστερά, ρίζα, δεξιά (διάσχιση inorder) αναδρομικά

void BST::inorder(Node* root)
{
  if (root == nullptr) {
    return;
  }
  inorder(root->left);
  cout << root->wc.word <<" "<<root->wc.count_<<endl;
  inorder(root->right);
}


//Αυτή η μέθοδος καλεί την μέθοδο inorder(Node* root) με όρισμα τη ρίζα του δέντρου

void BST::inorder()
{
  inorder(root);
}


//Αυτή η μέθοδος διατρέχει τους κόμβους με τη σειρά: Αριστερά, δεξιά, ρίζα (διάσχιση postorder) αναδρομικά

void BST::postorder(Node* root)
{
  if (root == nullptr)
    return;

  postorder(root->left);
  postorder(root->right);
  cout << root->wc.word <<" "<<root->wc.count_<<endl;
}

//Αυτή η μέθοδος καλεί την μέθοδο postorder(Node* root) με όρισμα τη ρίζα του δέντρου

void BST::postorder()
{
  postorder(root);
}

//Αυτή η μέθοδος διατρέχει τους κόμβους με τη σειρά: ρίζα, αριστερά, δεξιά (διάσχιση preorder) αναδρομικά

void BST::preorder(Node* root)
{
  if (root == NULL)
    return;

  cout << root->wc.word <<" "<<root->wc.count_<<endl;
  preorder(root->left);
  preorder(root->right);
}


//Αυτή η μέθοδος καλεί την μέθοδο preorder(Node* root) με όρισμα τη ρίζα του δέντρου

void BST::preorder()
{
  preorder(root);
}



//Αυτή η μέθοδος παίρνει ως όρισμα μια συμβολοσειρά, την αναζητά και αν τη βρει επιστρέφει true ενώ αν δεν την βρει επιστρέφει false

bool BST::searchNode(string word)
{
  clean(word);
  b=false;
  if (search_(root,word))
  {
    return true;
  }
  else
  {
    return false;
  }
}

//Αυτή η μέθοδος παίρνει ως όρισμα μια συμβολοσειρά, την αναζητά και επιστρέφει κατάλληλο μήνυμα σε κάθε περίπτωση
void BST::searchHowTime(string word)
{
  clean(word);
  b=false;
  if (search_(root,word))
  {
    cout<<"the word " << found->wc.word<<" exists "<<found->wc.count_<<" times"<<endl;
  }
  else
  {
    cout<<"this word not exist"<<endl;
  }
}

//Αυτή η συνάρτηση δέχεται σαν όρισμα ένα δείκτη τύπου Node και μια συμβολοσειρά και αναζητά την συμβολοσειρά αναδρομικά

bool BST::search_(Node* root, string word)
{
  if(root!=nullptr)                          //Αν δεν βρισκόμαστε σε κενό κόμβο τότε:
  {
    if (word.compare(root->wc.word)==0)      //αν η λέξη είναι ίδια με αυτή του root
    {
      b=true;                                //θέτουμε το b ίσο με true
      found=root;                            // και κρατάμε στο found το root
    }
    else if (word.compare(root->wc.word)< 0)  //αλλιώς αν η λέξη είναι μικρότερη από αυτή του root
    {
      search_(root->left, word);     //τότε η λέξη αναζητείται αναδρομικά στο υποδέντρο με ρίζα το αριστερό παιδί του root
    }
    else
    {
      search_(root->right, word);     //αλλιώς η λέξη αναζητείται αναδρομικά στο υποδέντρο με ρίζα το δεξί παιδί του root
    }
  }
  return b;                          //και επιστρέφεται το b
}


//Αυτή η μέθοδος είναι βοηθητική για τη διαγραφή. Βρίσκει το κόμβο με το οποίο θα αντικαταστήσουμε το διαγραμένο κόμβο. Ο κόμβος-αντικαταστάτης θα είναι αυτός με τη μεγαλύτερη τιμή του αριστερού υποδέντρου του κόμβου προς διαγραφή

Node *BST::maxValue(Node* node)
{
    Node* current = node;
    while (current->right != nullptr)
        current = current->right;

    return current;
}


//Αυτή η μέθοδος είναι βοηθητική για τη διαγραφή. Βρίσκει το κόμβο που είναι αποθηκευμένη η λέξη που δίνεται για διαγραφή και το γονέα αυτού του κόμβου

void BST::searchKey(Node* &curr,string word, Node* &parent)
{
    while (curr != nullptr && curr->wc.word!= word)
    {
        parent = curr;

        if (word < curr->wc.word) {
            curr = curr->left;
        }
        else {
            curr = curr->right;
        }
    }
}


//Αυτή η μέθοδος δέχεται σαν όρισμα μια συμβολοσειρά/λέξη και την διαγράφει από το δέντρο αναδρομικά

void BST::deleteNode(string word)
{
  clean(word);
  Node* parent = nullptr;     //Δημιουργείται ένας δείκτης parent για την αποθήκευση του γονέος του τρέχοντος κόμβου
  Node* curr = root;          //αρχικά το curr θα είναι η ρίζα

  searchKey(curr, word, parent);  //μετά την κλήση της μεθόδου searchKey το curr θα έχει την τιμή του κόμβου προς διαγραφή και το parent του γονέα αυτού

  if (curr == nullptr) {    //Αν το curr είναι null, δηλαδή αν η λέξη δεν υπάρχει
    cout<<"this word not exists"<<endl;   //τότε εμφανίζεται κατάλληλο μήνυμα
    return;                 //και η μέθοδος τερματίζει
  }

  if (curr->wc.count_>1) {      //Αν το πλήθος της λέξης προς διαγραφή δεν είναι 1 
    curr->wc.count_--;          //απλά μειώνεται το πλήθος κάτα 1
    return;                     //και η μέθοδος τερματίζει
  }

  if (curr->left == nullptr && curr->right == nullptr)  //Αν το curr δεν έχει παιδιά τότε:
  {
    if (curr == root)       //Αν το curr είναι η ρίζα τότε
    {
       root = nullptr;      //διαγράφεται η ρίζα
    }
    else {               //αλλιώς αν το curr δεν είναι η ρίζα τότε
      if (parent->left == curr) {    //Αν το curr είναι το αριστερό παιδί του parent
        parent->left = nullptr;        //τότε διαγράφεται το αριστερό παιδί του parent
      }
      else {                         //αλλιώς αν το curr είναι το δεξί παιδί του parent
        parent->right = nullptr;       //τότε διαγράφεται το δεξί παιδί του parent
      }
    }
    free(curr);                      //απελευθερώνεται η μνήμη που καταλαμβάνει το curr
  }
  else if (curr->left!=nullptr && curr->right!=nullptr)   //Αν το curr έχει 2 παιδιά τότε:
  {
    Node* temp = maxValue(curr->left);    //το temp χρησιμοποιείται για την αποθήκευση του κόμβου με τον οποίο θα αντικαταστήσουμε το διαγραμένο κόμβο
    WordCount3 val = temp->wc;                  //αποθηκεύεται στο val η λέξη και το πλήθος που περιέχονται στο temp
    temp->wc.count_=1;           // το πλήθος του temp γίνεται 1 έτσι ώστε κατά τη διαγραφή του temp να μη μειωθεί το πλήθος αλλά να διαγραφεί εντελώς
    deleteNode(temp->wc.word);                      //διαγράφεται αναδρομικά ο κόμβος με τη λέξη του temp
    curr->wc = val;                             //αντικαθιστούμε στο κόμβο που θέλουμε να διαγράψουμε με το val
  }
  else {                                                //Αν το curr έχει μόνο ένα παιδί τότε:
    Node* child = (curr->left)? curr->left: curr->right;    //αποθηκεύεται στο child αυτό το παιδί (δεξί ή αριστερό)
    if (curr == root)         //Αν το curr είναι η ρίζα τότε
    {
      root = child;           //αντικαθιστούμε την ρίζα με το child
    }
    else {                     //αλλιώς αν το curr δεν είναι η ρίζα τότε
      if (curr == parent->left) {     //Αν το curr είναι το αριστερό παιδί του parent
        parent->left = child;             //αντικαθιστούμε το αριστερό παιδί του parent με το child
      }
      else {                          //αλλιώς αν το curr είναι το δεξί παιδί του parent
        parent->right = child;            //αντικαθιστούμε το δεξί παιδί του parent με το child
      }
    }
    free(curr);               //απελευθερώνεται η μνήμη που καταλαμβάνει το curr
  }
}

