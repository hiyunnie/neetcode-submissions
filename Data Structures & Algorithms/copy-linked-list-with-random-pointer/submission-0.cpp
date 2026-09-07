/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
   public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        unordered_map<Node*, Node*> umap;  // umap[old_node] = new_node;
        Node* dummyhead = new Node(0);
        Node* curr = dummyhead;
        Node* node = head;

        while (node) {
            Node* copy = new Node(node->val);
            curr->next = copy;
            copy->val = node->val;
            umap[node] = copy;

            curr = copy;
            node = node->next;
        }

        node = head;
        curr = dummyhead->next;
        while (node) {
            if (node->random) {
                curr->random = umap[node->random];
            } else {
                curr->random = nullptr;
            }
            curr = curr->next;
            node = node->next;
        }
        Node* ans = dummyhead->next;
        delete dummyhead;
        return ans;
    }
};
// hash table map[old] = new