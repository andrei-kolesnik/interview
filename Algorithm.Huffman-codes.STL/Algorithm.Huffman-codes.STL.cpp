/*
Huffman codes
*/
#include <bits/stdc++.h>

using namespace std;

struct HeapNode {
	char character;
	int frequency;
	HeapNode *left, *right;
	HeapNode(char ch, int fr, HeapNode* l = NULL, HeapNode* r = NULL) :
		character(ch), frequency(fr), left(l), right(r) {}
};

struct compareHeapNodes {
	bool operator()(HeapNode *a, HeapNode *b) { return (a->frequency > b->frequency); }
};

class HuffmanCodes {
private:
	priority_queue<HeapNode*, vector<HeapNode*>, compareHeapNodes> heap;
	map<char, string> codes;
	void makeCodes(HeapNode* root, string s) {
		if (!root) return;
		if (root->character != stop)
			codes[root->character] = s;
		makeCodes(root->left, s + "0");
		makeCodes(root->right, s + "1");
	}
public:
	const char stop = '*';
	string encode(string s) {
		if (s.size() < 1) return "";
		map<char, int> counter;
		for (auto ch : s) counter[ch]++;
		for (auto p : counter) heap.push(new HeapNode(p.first, p.second));
		while (heap.size() != 1)
		{
			HeapNode* left = heap.top(); heap.pop();
			HeapNode* right = heap.top(); heap.pop();
			heap.push(new HeapNode(stop, left->frequency + right->frequency, left, right));
		}
		makeCodes(heap.top(), "");
		stringstream ss;
		for (auto ch : s) ss << codes[ch] ; //<< " "
		return ss.str();
	}

	string decode(string s) {
		stringstream ss;
		HeapNode *p = heap.top();
		int i = 0;
		while (p && i < s.size())
			if (p->character != stop)
			{
				ss << p->character;
				p = heap.top();
			}
			else
			{
				if (s[i] == '0')
					p = p->left;
				else
					p = p->right;
				i++;
			}
		ss << p->character;
		return ss.str();
	}

	void printCodes() {
		cout << endl << "Codes:" << endl;
		for (auto code : codes)
			cout << code.first << ": " << code.second << endl;
	}
};

int main()
{
	HuffmanCodes hc;
	string original = "huffman coding is a lossless data compression algorithm";
	cout << "ORIGINAL: " << original << endl;
	string encoded = hc.encode(original);
	cout << "ENCODED: " << encoded << endl;
	string decoded = hc.decode(encoded);
	cout << "DECODED: " << decoded << endl;
	cout << (decoded == original ? "PASS" : "FAIL") << endl;
	hc.printCodes();
	system("pause");
	return 0;
}
