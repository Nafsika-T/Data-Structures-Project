
#include "AVL.h"
#include "clean.h"

#include <cstring>
#include <iterator>
#include <iostream>

using namespace std;

AVL::AVL()
{
  root=nullptr;
}


//Αυτή η μέθοδος επιστρέφει το ύψος του κόμβου που δίνεται σαν όρισμα
int AVL::getHeight(Node* node)
{
  if(node == nullptr)
    return 0;

  return node->height;
}


//Αυτή η μέθοδος ενημερώνει το ύψος του κόμβου που δίνεται σαν όρισμα

Node* AVL::updateHeight(Node* node)
{
  node->height = 1 +max(getHeight(node->left), getHeight(node->right));
  return node;
}


//Αυτή η μέθοδος καλεί την ανδρομική μέθοδο insert

void AVL::insertNode(string word)
{
  root=insertNode(root,word);
}

//Αυτή η μέθοδος δέχεται σαν όρισμα μια λέξη και έναν κόμβο και εισάγει την λέξη αναδρομικά στο δέντρο με ρίζα αυτόν τον κόμβο

Node* AVL::insertNode(Node* root, string word)
{
  //root -> ο τρέχον κόμβος

  clean(word);

  if(root == nullptr)   //Αν η τιμή της ρίζας είναι nullptr
  {
    root=newNode(word);   //τότε με τη βοήθεια της μεθόδου newNode δημιουργείται ένας νέος κόμβος
    return root;          //και επιστρέφεται αυτός ο κόμβος
  }
  if(word.compare(root->wc.word) > 0)   //αν η λέξη είναι μικρότερη από τη λέξη του root
  {
    root->right = insertNode(root->right, word);   //τότε εισάγεται η λέξη αναδρομικά στο υποδέντρο με ρίζα το δεξί παιδί του root
  }
  else if(word.compare(root->wc.word) <0)  //αλλιώς αν η λέξη είναι μικρότερη από τη λέξη του root
  {
    root->left = insertNode(root->left, word);  //τότε εισάγεται η λέξη αναδρομικά στο υποδέντρο με ρίζα το αριστερό παιδί του root
  }
  else             //αλλιώς αν η λέξη είναι ίση με τη λέξη του root
  {
    root->wc.count_++;  //τότε αυξάνεται το πλήθος της κατά 1
    return root;       //και επιστρέφεται το root
  }

  root = updateHeight(root);    //ενημερώνεται το ύψος του root

  int balance=getBalance(root); //με τη βοήθεια της getBalance() βρίσκεται η διαφορά του ύψους των δύο υποδέντρων του root και αποθηκεύεται στο balance

  //αν το balance είναι θετικό τότε σημαίνει πως το αριστερό υποδέντρο του root είναι το μεγαλύτερο ενώ αν το balance είναι αρνητικό τότε σημαίνει πως το δεξί υποδέντρο του root είναι το μεγαλύτερο


  if (balance > 1 && getBalance(root->left) >0)     //Αν το balance είναι μεγαλύτερο του 1 και η διαφορά των υψών των υποδέντρων του αριστερού παιδιού του root είναι μεγαλύτερο του 0 (που σημαίνει ότι το αριστερό υποδέντρο του αριστερού παιδιού του root είναι το μεγαλύτερο) τότε
    return rightRotate(root);    // γίνεται μια δεξιά περίστροφή και επιστρέφεται η νέα ρίζα του υποδέντρου που προέκυψε μετά την περιστροφή

  if (balance > 1 && getBalance(root->left) < 0)    //Αν το balance είναι μεγαλύτερο του 1 και η διαφορά των υψών των υποδέντρων του αριστερού παιδιού του root είναι μικρότερο του 0 (που σημαίνει ότι το δεξί υποδέντρο του αριστερού παιδιού του root είναι το μεγαλύτερο) τότε
  {
    root->left = leftRotate(root->left);     //γίνεται μια αριστερή περιστροφή
    return rightRotate(root);                //και μια δεξιά περίστροφή και επιστρέφεται η νέα ρίζα του υποδέντρου που προέκυψε μετά τις περιστροφές
  }

  if (balance < -1 && getBalance(root->right) < 0)  //Αν το balance είναι μικρότερο του -1 και η διαφορά των υψών των υποδέντρων του δεξιού παιδιού του root είναι μικρότερο του 0 (που σημαίνει ότι το δεξί υποδέντρο του δεξιού παιδιού του root είναι το μεγαλύτερο) τότε
    return leftRotate(root);   //γίνεται μια αριστερή περίστροφή και επιστρέφεται η νέα ρίζα του υποδέντρου που προέκυψε μετά την περιστροφή

  if (balance < -1 && getBalance(root->right) > 0)  //Αν το balance είναι μικρότερο του -1 και η διαφορά των υψών των υποδέντρων του δεξιού παιδιού του root είναι μεγαλύτερο του 0 (που σημαίνει ότι το αριστερό υποδέντρο του δεξιού παιδιού του root είναι το μεγαλύτερο) τότε
  {
    root->right = rightRotate(root->right);   //τότε γίνεται μια δεξιά περιστροφή
    return leftRotate(root);                  //και μια αριστερή περίστροφή και επιστρέφεται η νέα ρίζα του υποδέντρου που προέκυψε μετά τις περιστροφές
  }
  return root;
}


//Αυτή η μέθοδος επιστρέφει τη διαφορά των υψών των υποδέντρων του κόμβου που δίνεται σαν όρισμα

int AVL::getBalance(Node *N)
{
  if (N == nullptr)
    return 0;
  return getHeight(N->left)-getHeight(N->right);
}


//Αυτή η μέθοδος πραγματοποιεί αριστερή περιστροφή στο υποδέντρο με ρίζα τον κόμβο που δίνεται ως όρισμα

Node* AVL::leftRotate(Node* root)
{
  //root -> ο κόμβος που η διαφορα των υψών του είναι μεγαλύτερη από 1
  Node* x = root->right;   //αποθηκεύεται στο x το δεξί παιδί του root
  Node* t = x->left;       //αποθηκεύεται στο t το αριστερό παιδί του δεξιού παιδιού του root
  root->right = t;         //το δεξί παιδί του root θα είναι πλέον το t
  x->left = root;          //το αριστερό παιδί του x θα είναι το root
  root = updateHeight(root); //ενημερώνεται το ύψος του root
  x = updateHeight(x);       //ενημερώνεται το ύψος του x
  return x;    //επιστρέφεται η νέα ρίζα του υποδέντρου που προέκυψε μετά την περιστροφή
}


//Αυτή η μέθοδος πραγματοποιεί δεξιά περιστροφή στο υποδέντρο με ρίζα τον κόμβο που δίνεται ως όρισμα

Node* AVL::rightRotate(Node* root)
{
  //root -> ο κόμβος που η διαφορα των υψών του είναι μεγαλύτερη από 1
  Node *x = root->left;   //αποθηκεύεται στο x το αριστερό παιδί του root
  Node *t = x->right;     //αποθηκεύεται στο t το δεξί παιδί του αριστερού παιδιού του root
  root->left = t;         //το αριστερό παιδί του root θα είναι πλέον το t
  x->right = root;         //το δεξί παιδί του x θα είναι το root
  root = updateHeight(root);  //ενημερώνεται το ύψος του root
  x = updateHeight(x);        //ενημερώνεται το ύψος του x
  return x;          //επιστρέφεται η νέα ρίζα του υποδέντρου που προέκυψε μετά την περιστροφή
}


//Αυτή η μέθοδος καλεί την αναδρομική μέθοδο deleteNode με όρισμα τη ρίζα του δέντρου

void AVL::deleteNode(string word)
{
  root=deleteNode(root,word);
}

//Αυτή η μέθοδος διαγράφει αναδρομικά μία λέξη από το δέντρο με ρίζα το όρισμα root

Node* AVL::deleteNode(Node* &root, string word)
{
  clean(word);

  if (root == nullptr)       //αν το root είναι nullptr τότε
  {
    cout<<"this word not exist"<<endl;  //εμφανίζεται κατάλληλο μήνυμα
    return root;                         //επιστρέφεται το root
  }

  if (word.compare(root->wc.word)<0)                    //αν η λέξη είναι μικρότερη από αυτή του root τότε
    root->left = deleteNode(root->left, word);       //καλείται αναδρομικά η deleteNode για το υποδέντρο με ρίζα το αριστερό παιδί του root
  else if (word.compare(root->wc.word)>0)               //αλλιώς αν η λέξη είναι μεγαλύτερη από αυτή του root τότε
    root->right = deleteNode(root->right,word);     //καλείται αναδρομικά η deleteNode για το υποδέντρο με ρίζα το δεξί παιδί του root
  else                                         //αλλιώς αν η λέξη είναι ίση με αυτή του root τότε
  {
    if (root->wc.count_ > 1)           //αν το πλήθος του root είναι μεγαλύτερο του 1
    {
      (root->wc.count_)--;             //τότε μειώνεται το πλήθος τηυ κατά 1
      return root;                   //και επιστρέφεται το root
    }
    if ((root->left == nullptr) || (root->right == nullptr))    //Αν το root έχει ένα παιδί ή κανένα τότε
    {
      Node* temp = root->left != nullptr ? root->left : root->right;   //αποθηκεύεται στο temp αυτό το παιδί (ή nullptr αν δεν έχει παιδιά)

      if (temp == nullptr)      //αν το temp είναι nullptr (θα είναι στη περίπτωση που το root δεν έχει παιδιά)
      {
        temp = root;            //τότε το temp θα πάρει τη τιμή του root
        root = nullptr;         //και το root θα διαγραφεί
      }
      else                       //αν το temp δεν είναι nullptr (η περίπτωση που το root έχει ένα παιδί)
        *root = *temp;           //το root θα πάρει τη τιμή του temp
        free(temp);              //και θα απελευθερωθεί η μνήμη που καταλαμβάνει το temp
    }
    else                        //αλλιώς αν το root έχει δύο παιδιά
    {
      Node* temp = maxValue(root->left);  //το temp χρησιμοποιείται για την αποθήκευση του κόμβου με τον οποίο θα αντικαταστήσουμε το διαγραμένο κόμβο
      root->wc.word = temp->wc.word;          //αντικαθίσταται η λέξη του root με τη λέξη του temp
      root->wc.count_ = temp->wc.count_;        //και το πλήθος του root με το πλήθος του temp
      temp->wc.count_= 1;                      // το πλήθος του temp γίνεται 1 έτσι ώστε κατά τη διαγραφή του temp να μη μειωθεί το πλήθος αλλά να διαγραφεί εντελώς
      root->left = deleteNode(root->left, temp->wc.word);    //καλείτε αναδρομικά η deleteNode για το υποδέντρο με ρίζα το δεξί παιδί του root για την διαγραφή του temp
    }
  }
  if (root == nullptr)    //αν το root είναι nullptr τότε
    return root;          //επιστρέφεται το root

  root = updateHeight(root);     //ενημερώνεται το ύψος του root

  //μετά τη διαγραφή γίνεται διόρθωση του δέντρου όπως και στην insert
  int balance = getBalance(root);

  if (balance > 1 && getBalance(root->left) >= 0) 
    return rightRotate(root); 

  if (balance > 1 && getBalance(root->left) < 0) 
  { 
    root->left = leftRotate(root->left); 
    return rightRotate(root); 
  } 
  if (balance < -1 && getBalance(root->right) <= 0) 
    return leftRotate(root); 

  if (balance < -1 && getBalance(root->right) > 0) 
  { 
    root->right = rightRotate(root->right); 
    return leftRotate(root); 
  } 
  return root; 
}