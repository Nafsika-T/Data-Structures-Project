

#ifndef BST_H
#define BST_H

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string.h>
#include <ctype.h>
#include <iterator>

using namespace std;

//Αυτό το struct αναπαριστά ένα ζεύγος λέξης- πλήθος εμφανήσεων λέξης
struct WordCount3
{
  int count_;
  string word;
};

//Αυτό το struct αναπαριστά έναν κόμβο του δέντρου
struct Node
{                     //κάθε κόμβος έχει:
  WordCount3 wc;      //ένα ζεύγος λέξης-πλήθους
  Node *left, *right;  //δύο παιδιά,αριστερό και δεξί, καθένα από τα οποία είναι ένας κόμβος 
  long height;      //ύψος 
};


//Η κλάση BST αναπαριστάτη δομή του δυαδικού δέντρου αναζήτησης και των λειτουργιών του
class BST
{
  protected:
    Node* root;   //η ρίζα του δέντρου
    Node* found;  //η μεταβλητή found χρησιμοποιείται για την αποθήκευση του κόμβου που βρίσκεται από την λειτουργία της αναζήτησης
    Node* newNode(string);  //μέθοδος για την δημιουργία έου κόμβου
    void inorder(Node*);      //αναδρομική μέθοδος για διάτρεξη inorder 
    void postorder( Node*);   //αναδρομική μέθοδος για διάτρεξη postorder
    void preorder(Node*);     //αναδρομική μέθοδος για διάτρεξη preorder
    Node *maxValue(Node*);    //μέθοδος για την εύρεση του κόμβου ο οποίος θα αντικαταστήσει το κόμβο που διαγράφεται κατά τη λειτουργεία της διαγραφής
    void searchKey(Node* &, string, Node* &);  //μέθοδος βοηθητική για τη διαγραφή. Βρίσκει το κόμβο που είναι αποθηκευμένη η λέξη που δίνεται για διαγραφή και το γονέα αυτού του κόμβου
    bool search_(Node* root, string key);  //αναδρομική μέθοδος για την αναζήτηση λέξης

  public:
    BST();
    bool b;  //βοηθητική μεταβλητή για την αναζήτηση, όσο η λέξη δεν βρίσκεται είναι false, όταν βρεθεί γίνεται true 
    virtual void insertNode(string);    //μέθοδος για την εισαγωγή κόμβου που θα περιέχει τη λέξη που δίνεται σαν όρισμα
    virtual void deleteNode(string);    //μέθοδος για την διαγραφή του κόμβου που περιέχει τη λέξη που δίνεται σαν όρισμα
    bool searchNode(string);    //μέθοδος για την αναζήτηση του κόμβου που περιέχει τη λέξη που δίνεται σαν όρισμα

    void inorder();    //μέθοδος για διάτρεξη inorder (χρησιμοποιεί την μέθοδο inorder(Node*) με όρισμα τη ρίζα του δέντρου)
    void postorder();  //μέθοδος για διάτρεξη postorder (χρησιμοποιεί την μέθοδο postorder(Node*) με όρισμα τη ρίζα του δέντρου)
    void preorder();   //μέθοδος για διάτρεξη preorder (χρησιμοποιεί την μέθοδο postorder(Node*) με όρισμα τη ρίζα του δέντρου)

    void searchHowTime(string);  //μέθοδος για την αναζήτηση λέξης στο δέντρο και εμφάνισης της λέξης αυτής και του πλήθους της

    string getRoot()    //μέθοδος για την επιστροφή της ρίζας του δέντρου
    {
      return root->wc.word;
    }

};

#endif
