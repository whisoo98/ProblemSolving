#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<tuple>
#include<queue>
#include<string>

#define N 100'005
#define endl '\n';
#define ALPHABET "abcdefghijklmopqrstuvwxyz"
using namespace std;


struct word_tree {
	int num_child_word = 0;
	struct word_tree* child_word[30];
};

void make_new_word_tree(struct word_tree* par, int idx) {
	struct word_tree* new_word_tree = (struct word_tree*)malloc(sizeof(struct word_tree));
	for (int i = 0; i < 30; i++) {
		new_word_tree->child_word[i] = NULL;
	}
	par->child_word[idx] = new_word_tree;
	(par->child_word[idx]->num_child_word) = 0;
	
	(par->num_child_word)++;
}


double type_words(word_tree* now_tree, int level, char c) {
	if (now_tree == NULL) {
		return 0;
	}
	double typing = 0;
	int num_child_node = 0;
	int null_counted = 0;
	struct word_tree* node = now_tree;
	for (int i = 0; i < 30; i++) {
		if (node->child_word[i] != NULL) {
			num_child_node++;
			if (i == 29) {
				null_counted++;
			}
		}
		double add = type_words(node->child_word[i], level + 1, i + 'a');
		typing += add;
	}

	if (num_child_node == 1) {
		if (level == 1) { // top level node

			typing += (double)(node->num_child_word);
		}
		else {
			typing += 0;
		}
	}
	else {
		typing += (double)(node->num_child_word);
		if (null_counted) typing--;
		typing = max(typing, 0.0);
	}

	if (level != 1) {
		free(node);
	}

	return typing;
}

void Solution(int n, struct word_tree& base_tree) {
	double avg_typing = 0;
	avg_typing = type_words(&base_tree, 1, 0);
	cout.precision(2);
	cout << fixed;
	avg_typing /= (double)n;
	cout << avg_typing << endl;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	while (cin >> n) {
		//if (cin.eof()) break;
		
		struct word_tree base_tree;
		for (int i = 0; i < 30; i++) {
			base_tree.child_word[i] = NULL;
		}
		for (int i = 1; i <= n; i++) {
			string s; cin >> s;
			s += ((char)(29 + 'a'));

			struct word_tree* node = &base_tree;
			for (auto character : s) {

				if (node->child_word[character - 'a'] == NULL) {
					make_new_word_tree(node, character - 'a' );
					node = node->child_word[character- 'a'];
				}
				else {
					(node->num_child_word)++;
					node = node->child_word[character - 'a'];
						
				}
			}
		}
		Solution(n, base_tree);
	}
	return 0;
}
