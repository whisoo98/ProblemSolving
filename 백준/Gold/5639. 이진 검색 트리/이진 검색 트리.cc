#include <iostream>
#include <algorithm>
#include <functional>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <vector>
#include <set>
#include <sstream>

using namespace std;

struct bst* head=NULL;
struct bst {
	int num;
	struct bst* left;
	struct bst* right;
};

void insert(int a) {
	struct bst* temp,*temp_par=NULL;
	temp = head;
	if (temp == NULL) cout << "NULL";
	while (temp != NULL) {
		temp_par = temp;
		if (a < temp->num) {
			temp = temp->left;
		}
		else {
			temp = temp->right;
		}
	}
	temp = (struct bst*)malloc(sizeof(struct bst));
	temp->num = a;
	temp->left = NULL;
	temp->right = NULL;
	if (a < temp_par->num) {
		temp_par->left = temp;
	}
	else {
		temp_par->right = temp;
	}
}
void print(struct bst* node) {
	if (node==NULL) return;
	//cout << node->num << "\n";
	print(node->left);
	print(node->right);
	//cout << node->num<<"\n";
	printf("%d\n", node->num);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int a; 
	/*struct bst BST;
	BST.left = NULL;
	BST.right = NULL;
	BST.num = a;
	head = &BST;*/
	string s;
	while (getline(cin,s)) {
		//if (cin.eof())break;
		if (cin.eof()) break;
		//getchar();
		//cout << "!";
		
		if (head==NULL) {
			//printf("%d",a);
			struct bst* new_node = (struct bst*)malloc(sizeof(struct bst));
			new_node->num = stoi(s);
			new_node->left = NULL;
			new_node->right = NULL;
			head = new_node;
		}
		else insert(stoi(s));
	}
	//cout << "endl\n";
	print(head);
	/*while (1) {
		struct bst* temp, *temp_par;
		temp = head;
		while (temp->left != NULL || temp->right != NULL) {
			if (temp->left) {
				temp_par = temp;
				temp = temp->left;
				continue;
			}
			else if(temp->right){
				temp_par = temp;
				temp = temp->right;
				continue;
			}
		}

	}*/

	return 0;
}