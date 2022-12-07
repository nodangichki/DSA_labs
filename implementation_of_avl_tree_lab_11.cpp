// C++ program to insert a node in AVL tree  
#include<iostream> 
using namespace std;
typedef char datae;
struct Node {
	int data;
	Node* left;
	Node* right;
	int h;
};
// An AVL tree node  
class AVL_Tree {
	Node* root;
	datae Max(datae a, datae b);
	int Height(Node* N);
	Node* New_Node(datae key);
	Node* Right_Rotate(Node* y);
	Node* Left_Rotate(Node* x);
	int   Get_Balance(Node* N);
	void  Pre_Order(Node* node);
	Node* Insert(Node* node, datae key);
    bool Search(datae key, Node*);
public:
	AVL_Tree() { root = NULL; }
	void  Pre_Order();
	void Insert(datae key);
    bool Search(datae key);
};

bool AVL_Tree::Search(datae key) {

    return Search(key, root);

}
bool AVL_Tree::Search(datae key,Node* node) {
    bool found = false;
    // node is not present
    if (node == NULL)
        return false;
    // if node with same data is found
    if (key == node->data)
        return true;
    else if (key > node->data)
        found = Search(key, node->right);
    else
        found = Search(key, node->left);
    return found;
}
// A utility function to get maximum of two integers  
datae AVL_Tree::Max(datae a, datae b) {
	return (a > b) ? a : b;
}
int AVL_Tree::Height(Node* N) {
	if (N == NULL)
		return 0;
	return N->h;
}
Node* AVL_Tree::New_Node(datae key) {
	Node* node = new Node();
	node->data = key;
	node->left = NULL;
	node->right = NULL;
	node->h = 1; // new node is initially added at leaf  
	return(node);
}

// A utility function to right rotate subtree rooted with y  
Node* AVL_Tree::Right_Rotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;
    // Perform rotation  
    x->right = y; y->left = T2;
    // Update heights  
    y->h = Max(Height(y->left), Height(y->right)) + 1;
    x->h = Max(Height(x->left), Height(x->right)) + 1;
    return x;      // Return new root
}

// A utility function to left  rotate subtree rooted with x  
Node* AVL_Tree::Left_Rotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;
    // Perform rotation  
    y->left = x;    x->right = T2;
    // Update heights  
    x->h = Max(Height(x->left), Height(x->right)) + 1;
    y->h = Max(Height(y->left), Height(y->right)) + 1;
    return y; // Return new root  
}

// Get Balance factor of node N  
int AVL_Tree::Get_Balance(Node* N) {
    if (N == NULL)
        return 0;
    return (Height(N->left) - Height(N->right));
}

void AVL_Tree::Insert(datae key) {
    root = Insert(root, key);
}

// Recursive func. to insert a key in the subtree rooted with node 
// and returns the new root of the subtree.  
Node* AVL_Tree::Insert(Node* node, datae key) {
    /* 1. Perform the normal BST insertion */
    if (node == NULL)
        return(New_Node(key));

    if (key < node->data)
        node->left = Insert(node->left, key);
    else if (key > node->data)
        node->right = Insert(node->right, key);
    else // Equal keys are not allowed in BST  
        return node;


    /* 2. Update height of this ancestor node */
    node->h = 1 + Max(Height(node->left), Height(node->right));

    /* 3. Get the balance factor of this ancestor
        node to check whether this node became
        unbalanced */
    int b = Get_Balance(node);

    // If this node becomes unbalanced, then  
    // there are 4 cases  

    // Left Left Case  
    if (b > 1 && key < node->left->data)
        return Right_Rotate(node);

    // Right Right Case  
    if (b < -1 && key > node->right->data)
        return Left_Rotate(node);

    // Left Right Case  
    if (b > 1 && key > node->left->data) {
        node->left = Left_Rotate(node->left);
        return Right_Rotate(node);
    }

    // Right Left Case  
    if (b < -1 && key < node->right->data) {
        node->right = Right_Rotate(node->right);
        return Left_Rotate(node);
    }

    /* return the (unchanged) node pointer */
    return node;
}

void AVL_Tree::Pre_Order() {
    Pre_Order(root);
}
// A utility function to print preorder traversal of the tree.  
void AVL_Tree::Pre_Order(Node* node) {
    if (node != NULL) {
        char x = node->data;
        cout << x << " ";
        Pre_Order(node->left);
        Pre_Order(node->right);
    }
}
int main()
{
    AVL_Tree atree;
    char character;
    char choice;
    /* Constructing an AVL tree */
   
    while (1) {
        cout << "[A] - Add Character\n";
        cout << "[S] - Search Character\n";
        cout << "[P] - Pre - Order Traversal\n";
        cout << "[Q] - Quit\n";
        cin >> choice;
        switch (choice) {
        case 'a':
        case 'A':
            cout << "Enter Character: "; cin >> character;
            atree.Insert(character);
            break;
        case 's':
        case'S':
            cout << "Enter Character: "; cin >> character;
            cout << atree.Search(character) << endl;
            break;
        case 'p':
        case'P':
            atree.Pre_Order();
            cout << endl;
            break;
        case 'q':
        case 'Q':
            exit(0);
        }



    }
   
    system("PAUSE");  return 0;
}



