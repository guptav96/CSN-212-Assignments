#include<bits/stdc++.h>
using namespace std;

struct Interval {
	int low;
	int high;
};
 
struct Node
{
    Interval *interval;
    int high;
    Node *left, *right;
};
 
Node *start(Interval a)               // Inserting the first node
{
    Node *newnode = new Node;
    newnode->interval = new Interval(a);
    newnode->high = a.high;
    newnode->left = newnode->right = NULL;
};
 
Node *insert(Node *node, Interval a)   // Insert a new node
{
    if (node == NULL)
        return start(a);
 
    int l = node->interval->low;
    
    if (a.low < l)                             // Insert in left subpart when lower value of interval is less than the lower value of the interval in the node
        node->left = insert(node->left, a);
 
    else
        node->right = insert(node->right, a);   // Insertion in right part
 
    if (node->high < a.high)
        node->high = a.high;
 
    return node;
}

Node *minValueNode(Node* node)     // Returns the lowets and leftmost node which has the least left value
{
    Node* current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}

Node* deleteNode(Node* node, Interval a)
{
    if (node == NULL) return node;
 
    if (a.low < node->interval->low)      // Go for left subpart when the left value of the node is greater than the low value of the interval
        node->left = deleteNode(node->left, a);
 
    else if (a.low > node->interval->low)     // Go for right subpart 
        node->right = deleteNode(node->right, a);
 
    else      // Delete the node
    {
        if (node->left == NULL)
        {
            struct Node *temp = node->right;
            free(node);
            return temp;
        }
        else if (node->right == NULL)
        {
            struct Node *temp = node->left;
            free(node);
            return temp;
        }
 
        Node* temp = minValueNode(node->right);
        node->interval = temp->interval;
        node->high= temp->high; 		
        node->right = deleteNode(node->right, a);
    }
    return node;
}
int check(Interval a, Interval b)
{
    if (a.low <= b.high && a.high >= b.low)
        return 1;
    return 0;
}


Interval *search(Node *node, Interval toSearch)
{
    if (node == NULL) return NULL;
 
    if (check(*(node->interval), toSearch))
        return node->interval;
 
    if (node->left != NULL && node->left->high >= toSearch.low)
        return search(node->left, toSearch);
 
    return search(node->right, toSearch);
}

int main()
{
	Interval a[]= {{15, 20}, {10, 30}, {17, 19},{5, 20}, {12, 15}, {30, 40}};
	int n=6;
	Node* node=NULL;
	for(int i=0;i<n;i++)
	{
		node=insert(node,a[i]);
	}
	
	Interval toSearch = {14,16};   // Search the interval
	Interval *answer = search(node, toSearch);
	if (answer == NULL)
    	cout<<"No Overlap"<<endl;
    else
        cout << "Interval [" << toSearch.low <<"," <<toSearch.high <<"] overlaps with [" << answer->low << " ," << answer->high << "]"<<endl;
        
    Interval toDelete = {15,20};    // Deleting an interval
    node=deleteNode(node,toDelete);
	cout<<"Interval ["<< toDelete.low <<","<< toDelete.high<<"] deleted"<<endl;
	answer = search(node, toSearch);   // Search with one deleted node
	if (answer == NULL)
    	cout<<"No Overlap"<<endl;
    else
        cout << "Interval [" << toSearch.low <<"," <<toSearch.high <<"] overlaps with [" << answer->low << " ," << answer->high << "]"<<endl;
    return 0;
}
