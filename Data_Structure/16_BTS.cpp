#include <bits/stdc++.h>
using namespace std;

vector<string> op;
vector<string> ops = { "+", "-", "depth", "leaf", "quit" };

struct Node {
	string name;
	struct Node *LT, *RT;
};

class BTS {
private:
	Node* root;
public:
	BTS(Node *init = 0) { root = init; }
	void do_Insert(string);
	Node* do_Delete(Node*&, string);
	void do_Depth(Node*, int);
	void do_Leaf(Node*);
	bool is_Leaf(Node*);
	Node* max_Node(Node*);
	Node* min_Node(Node*);
	Node*& get_Root() { return root; }
};

void BTS::do_Insert(string name) {
	Node* p = root;
	Node* q = 0;
	while(p) {
		q = p;
		if(name == p -> name) {      return; }
		if(name  < p -> name) { p = p -> LT; }
		else				  { p = p -> RT; }
	}

	p = new Node;
	p -> LT = p -> RT = 0;
	p -> name = name;

	if	   (!root)			  {    root = p; }
	else if(name < q -> name) { q -> LT = p; }
	else					  { q -> RT = p; }
}

Node* BTS::do_Delete(Node*& node, string name) {
	if(node == 0) return node;
	else if(name < node -> name) { node -> LT = do_Delete(node -> LT, name); }
	else if(name > node -> name) { node -> RT = do_Delete(node -> RT, name); }
	else {
		Node* temp = node;
		if(is_Leaf(node)) {
			delete node;
			node = 0;
		}
		else if(node -> LT == 0) {
			temp = min_Node(node -> RT);
			node -> name = temp -> name;
			node -> RT = do_Delete(node -> RT, temp -> name);
		}
		else {
			temp = max_Node(node -> LT);
			node -> name = temp -> name;
			node -> LT = do_Delete(node -> LT, temp -> name);
		}
	}
	return node;
}

vector<string> dep;
void BTS::do_Depth(Node* node, int k) {
	if(node == 0) return;
	if(k == 1) { dep.push_back(node -> name); }
	else {
		do_Depth(node -> LT, k - 1);
		do_Depth(node -> RT, k - 1);
	}
}

void BTS::do_Leaf(Node* node) {
	if(node == 0)		   { return; }
	else if(is_Leaf(node)) { cout << node -> name << ' '; }
	else {
		do_Leaf(node -> LT);
		do_Leaf(node -> RT);
	}
}

bool BTS::is_Leaf(Node* node) {
	return node -> RT == 0 && \
		   node -> LT == 0;
}

Node* BTS::max_Node(Node* node) {
	if(node == 0) { return 0; }

	while(node -> RT != 0) { node = node -> RT; }
	return node;
}

Node* BTS::min_Node(Node* node) {
	if(node == 0) { return 0; }

	while(node -> LT != 0) { node = node -> LT; }
	return node;
}

vector<string> str_split(string str, char del) {
	string temp;
	vector<string> result;
	istringstream ss(str);

	while(getline(ss, temp, del)) { result.push_back(temp); }
	return result;
}

void Read() {
	string input;
	getline(cin, input, '\n');
	op = str_split(input, ',');
}

bool is_nline(string str) {
	return (str == "depth") || (str == "leaf");
}

void do_process() {
	BTS tree;
	while(1) {
		Read();
		for(auto i : op) {
			vector<string> cur_op = str_split(i, ' ');
			if(cur_op.size() == 3) { cur_op.erase(cur_op.begin()); }
			int idx = find(ops.begin(), ops.end(), cur_op.front()) - ops.begin();

			switch(idx) {
				case 0: {
					tree.do_Insert(cur_op.back());
					break;
				}
				case 1: {
					tree.do_Delete(tree.get_Root(), cur_op.back());
					break;
				}
				case 2: {
					int k = stoi(cur_op.back());
					tree.do_Depth(tree.get_Root(), k);
					for(auto i : dep) { cout << i << ' '; }
					dep.clear();
					break;
				}
				case 3: {
					tree.do_Leaf(tree.get_Root());
					break;
				}
				case 4: {
					return;
				}
				default: { break; }
			}
			if(any_of(cur_op.begin(), cur_op.end(), is_nline)) cout << "\n";
		}
	}
}

int main() {
	do_process();
	return 0;
}
