// AVL tree implementation in C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>


// Create Node
struct Node {
  int key;
  struct Node *left;
  struct Node *right;
  int height;
  int FatBal;
};

int max(int a, int b);

// Calculate height
int height(struct Node *N) {
  if (N == NULL)
    return 0;
  return N->height;
}

int max(int a, int b) {
  return (a > b) ? a : b;
}

// Create a node
struct Node *newNode(int key) {
  struct Node *node = (struct Node *)
    malloc(sizeof(struct Node));
  node->key = key;
  node->left = NULL;
  node->right = NULL;
  node->height = 1;
  return (node);
}

// Right rotate
struct Node *rightRotate(struct Node *y) {
  struct Node *x = y->left;
  struct Node *T2 = x->right;

  x->right = y;
  y->left = T2;

  y->height = max(height(y->left), height(y->right)) + 1;
  x->height = max(height(x->left), height(x->right)) + 1;

  return x;
}

// Left rotate
struct Node *leftRotate(struct Node *x) {
  struct Node *y = x->right;
  struct Node *T2 = y->left;

  y->left = x;
  x->right = T2;

  x->height = max(height(x->left), height(x->right)) + 1;
  y->height = max(height(y->left), height(y->right)) + 1;

  return y;
}

// Get the balance factor
int getBalance(struct Node *N) {
  if (N == NULL)
    return 0;
  return height(N->left) - height(N->right);
}

// Insert node
struct Node *insertNode(struct Node *node, int key) {
  // Find the correct position to insertNode the node and insertNode it
  if (node == NULL){
    return (newNode(key));
  }
    

  if (key < node->key)
    node->left = insertNode(node->left, key);
  else if (key > node->key)
    node->right = insertNode(node->right, key);
  else
    return node;

  // Update the balance factor of each node and
  // Balance the tree
  node->height = 1 + max(height(node->left),height(node->right));

  int balance = getBalance(node);
  
  if (balance > 1 && key < node->left->key)
    return rightRotate(node);

  if (balance < -1 && key > node->right->key)
    return leftRotate(node);

  if (balance > 1 && key > node->left->key) {
    node->left = leftRotate(node->left);
    return rightRotate(node);
  }

  if (balance < -1 && key < node->right->key) {
    node->right = rightRotate(node->right);
    return leftRotate(node);
  }

  return node;
}

struct Node *minValueNode(struct Node *node) {
  struct Node *current = node;

  while (current->left != NULL)
    current = current->left;

  return current;
}

// Delete a nodes
struct Node *deleteNode(struct Node *root, int key) {
  // Find the node and delete it
  if (root == NULL)
    return root;

  if (key < root->key)
    root->left = deleteNode(root->left, key);

  else if (key > root->key)
    root->right = deleteNode(root->right, key);

  else {
    if ((root->left == NULL) || (root->right == NULL)) {
      struct Node *temp = root->left ? root->left : root->right;

      if (temp == NULL) {
        temp = root;
        root = NULL;
      } else
        *root = *temp;
      free(temp);
    } else {
      struct Node *temp = minValueNode(root->right);

      root->key = temp->key;

      root->right = deleteNode(root->right, temp->key);
    }
  }

  if (root == NULL)
    return root;

  // Update the balance factor of each node and
  // balance the tree
  root->height = 1 + max(height(root->left),
               height(root->right));

  int balance = getBalance(root);
  if (balance > 1 && getBalance(root->left) >= 0)
    return rightRotate(root);

  if (balance > 1 && getBalance(root->left) < 0) {
    root->left = leftRotate(root->left);
    return rightRotate(root);
  }

  if (balance < -1 && getBalance(root->right) <= 0)
    return leftRotate(root);

  if (balance < -1 && getBalance(root->right) > 0) {
    root->right = rightRotate(root->right);
    return leftRotate(root);
  }

  return root;
}

// Print the tree
void printPreOrder(struct Node *root) {
  if (root != NULL) {
printf("%d FatBal[%d], ",root->key, root->FatBal);
    printPreOrder(root->left);
    printPreOrder(root->right);
  }
}

void read_csv(FILE *AR,FILE *SAIDA){

  char* buffer =0;
  long length;
  //--------------------------------------------------------------------
  //------------------ converte o arquivo txt pra bufffer --------------
  //---------------------------- ---------------------------------------      
  //
  if(AR){
      fseek(AR,0,SEEK_END);
      length = ftell(AR);
      fseek(AR,0,SEEK_SET);
      buffer = malloc(length);
      if(buffer){
          fread(buffer,1,length,AR);
      }
      fclose(AR);
  }



  //--------------------------------------------------------
  //---------------------------- ler cada palavra-----------
  //---------------------------- e cria o token-------------
  //--------------------------------------------------------


  char * pch;
  // printf ("Splitting string \"%s\" into tokens:\n",buffer);

    
  pch = strtok (buffer,",' '");

  while (pch != NULL){

      fprintf (SAIDA, "%s\n",pch);   
      pch = strtok (NULL, " ,.-\"_ _Çî :' ':;' '/'");
      //imprime em um arquivo as palavras
      //fprintf("");        
  }
  fclose(SAIDA);
}





FILE *Arquivo_AbreLeitura(char *PNomeArquivo){
    return fopen(PNomeArquivo,"r");
}


int Arquivo_retorna_linhas(char *parq)
{

    FILE *AR = NULL;

    char ch;
    int characters, words, lines;
    int *wordss;
    int *c;
    AR = Arquivo_AbreLeitura(parq);
    if(AR == NULL){
    printf("Erro 1: Arquivo de Referência não pode ser aberto\n");
    }
    /*
     * Logic to count characters, words and lines.
     */
    characters = words = lines = 0;
    while ((ch = fgetc(AR)) != EOF)
    {
        characters++;

        /* Check new line */
        if (ch == '\n' || ch == '\0')
            lines++;

        /* Check words */
        if (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\0')
            words++;
    }

    /* Increment words and lines for last word */
    if (characters > 0)
    {
        words++;
        lines++;
    }

    fclose(AR);
    return lines;

}



void inorder(struct Node* root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d FatBal[%d], ",root->key, root->FatBal);
        inorder(root->right);
    }
}

int main() {

  struct Node *root = NULL;
  FILE *CSV = NULL;
  FILE *SAIDA_CSV = NULL;
  char NomeArq[30] = "";
  FILE *AR=NULL;
  char numeros[330] = "somenumbers.txt";
  SAIDA_CSV = fopen("somenumbers.txt", "wt");
  int numberArray[1000];
  int i;



  printf("Arquivo CSV: ");
  scanf("%s",NomeArq);
  if(CSV != NULL)
      fclose(CSV);
  CSV = Arquivo_AbreLeitura(NomeArq);
  if(CSV == NULL){
      printf("Erro 1: Arquivo CSV não pode ser aberto\n");
  }
  else
      printf("Arquivo %s aberto!!!\n", NomeArq);

  read_csv(CSV,SAIDA_CSV);
  int linha = Arquivo_retorna_linhas(numeros);

  AR = fopen("somenumbers.txt", "r");

  if (AR == NULL){
    printf("Error Reading File\n");
    exit (0);
  }

  for (i = 0; i < linha-1; i++){

    fscanf(AR, "%d", &numberArray[i] );
  }


  for (i = 0; i < linha-1; i++){
    root = insertNode(root, numberArray[i] );
    root->FatBal = getBalance(root);
  }
  //printPreOrder(root);
  printf("\n");
  // printLevelOrder(root);
  inorder(root);



  //printPreOrder(root);
  printf("\n%d",root->key);
  printf("\n%d",root->left->key);
  printf("\n%d",root->right->right->left->height);
  printf("\n");
  for (i = 0; i < linha-1; i++){
    root = deleteNode(root, numberArray[i] );
  }

  printf("\nAfter deletion: ");
  inorder(root);
  printf("\n");
  fclose(AR);
  return 0;
}