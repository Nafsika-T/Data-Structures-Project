
#ifndef AVL_H
#define AVL_H

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string.h>
#include <ctype.h>
#include <iterator>
#include "BST.h"

//Η κλάση AVL αναπαριστά τη δομή του ισοζυγισμένου δυαδικού δέντρου αναζήτησης και κληρονομεί την κλάση BST
class AVL: public BST
{
  protected:
    int getHeight(Node*);    //μέθοδος για την επιστρέφη το ύψος ενός κόμβου
    Node* updateHeight(Node*);  //μέθοδος για την ενημέρωση του ύψους ενός δέντρου
    Node* insertNode(Node*, string);   //αναδρομική μέθοδος για την εισαγωγή μιας λέξης στο δέντρο
    Node* leftRotate(Node*);   //μέθοδος για αριστερή περιστροφή στο υποδέντρο με ρίζα τον κόμβο που δίνεται ως όρισμα       
    Node* rightRotate(Node*);  //μέθοδος για δεξιά περιστροφή στο υποδέντρο με ρίζα τον κόμβο που δίνεται ως όρισμα
    Node* deleteNode(Node* &, string);  //αναδρομική μέθοδος για την διαγραφή ενός κόμβου
    int getBalance(Node*);   //μέθοδος για την επιστροφή της διαφοράς των υψών των υποδέντρων του κόμβου που δίνεται σαν όρισμα

  public:
    AVL();

    void insertNode(string);  //μέθοδος για την εισαγωγή μιας λέξης στο δέντρο (χρησιμοποιεί την μέθοδο insertNode(Node*, string) με όρισμα τη ρίζα του δέντρου)

    void deleteNode(string); //μέθοδος για την εισαγωγή μιας λέξης στο δέντρο (χρησιμοποιεί την μέθοδο deleteNode(Node* &, string) με όρισμα τη ρίζα του δέντρου)

    string getRoot()  //μέθοδος για την επιστροφή της ρίζας του δέντρου
    {
      return root->wc.word;
    }
};

#endif
