#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

class Node {
public:
    string name;
    Node* parent;
    vector<Node*> children;
    bool is_locked;
    int locked_by;
    int locked_descendants_count;

    Node(string name) {
        this->name = name;
        this->parent = nullptr;
        this->is_locked = false;
        this->locked_by = -1;
        this->locked_descendants_count = 0;
    }
};

class MTree {
private:
    int m;
    unordered_map<string, Node*> nodes;

    // Helper function to get all ancestors of a node
    vector<Node*> getAncestors(Node* node) {
        vector<Node*> ancestors;
        while (node->parent) {
            node = node->parent;
            ancestors.push_back(node);
        }
        return ancestors;
    }

    // Helper function to get all descendants of a node
    vector<Node*> getDescendants(Node* node) {
        vector<Node*> descendants;
        vector<Node*> stack = {node};
        while (!stack.empty()) {
            Node* current = stack.back();
            stack.pop_back();
            descendants.insert(descendants.end(), current->children.begin(), current->children.end());
            stack.insert(stack.end(), current->children.begin(), current->children.end());
        }
        return descendants;
    }

    // Helper function to check if all descendants are locked by the same user
    bool validateDescendantsLock(Node* node, int uid) {
        if (node->is_locked && node->locked_by != uid) return false;
        for (Node* child : node->children) {
            if (!validateDescendantsLock(child, uid)) return false;
        }
        return true;
    }

    // Helper function to update locked_descendants_count for all ancestors
    void updateAncestorsLockCount(Node* node, int delta) {
        while (node->parent) {
            node = node->parent;
            node->locked_descendants_count += delta;
        }
    }

public:
    MTree(int m, const vector<string>& nodeNames) : m(m) {
        for (const string& name : nodeNames) {
            nodes[name] = new Node(name);
        }
    }

    void addChild(const string& parentName, const string& childName) {
        Node* parentNode = nodes[parentName];
        Node* childNode = nodes[childName];
        parentNode->children.push_back(childNode);
        childNode->parent = parentNode;
    }

    bool lock(const string& x, int uid) {
        Node* node = nodes[x];

        // Check if the node or any ancestor is locked
        if (node->is_locked) return false;
        for (Node* ancestor : getAncestors(node)) {
            if (ancestor->is_locked) return false;
        }

        // Check if any descendant is locked
        if (node->locked_descendants_count > 0) return false;

        // Lock the node
        node->is_locked = true;
        node->locked_by = uid;
        updateAncestorsLockCount(node, 1);
        return true;
    }

    bool unlock(const string& x, int uid) {
        Node* node = nodes[x];

        // Ensure the node is locked by the same user
        if (!node->is_locked || node->locked_by != uid) return false;

        // Unlock the node
        node->is_locked = false;
        node->locked_by = -1;
        updateAncestorsLockCount(node, -1);
        return true;
    }

    bool upgradeLock(const string& x, int uid) {
        Node* node = nodes[x];

        // Node should not be locked and should have locked descendants
        if (node->is_locked || node->locked_descendants_count == 0) return false;

        // Check if all descendants are locked by the same user
        if (!validateDescendantsLock(node, uid)) return false;

        // Unlock all descendants and lock this node
        for (Node* descendant : getDescendants(node)) {
            if (descendant->is_locked) {
                descendant->is_locked = false;
                descendant->locked_by = -1;
                updateAncestorsLockCount(descendant, -1);
            }
        }

        node->is_locked = true;
        node->locked_by = uid;
        updateAncestorsLockCount(node, 1);
        return true;
    }
};

int main() {
    int N, m, Q;
    cin >> N >> m >> Q;

    vector<string> nodes(N);
    for (int i = 0; i < N; ++i) {
        cin >> nodes[i];
    }

    MTree tree(m, nodes);

    
    for (int i = 1; i < N; ++i) {
        string parentName = nodes[(i - 1) / m];
        string childName = nodes[i];
        tree.addChild(parentName, childName);
    }

    // Process queries
    for (int i = 0; i < Q; ++i) {
        int operation;
        string nodeName;
        int uid;
        cin >> operation >> nodeName >> uid;

        bool result = false;
        if (operation == 1) {
            result = tree.lock(nodeName, uid);
        } else if (operation == 2) {
            result = tree.unlock(nodeName, uid);
        } else if (operation == 3) {
            result = tree.upgradeLock(nodeName, uid);
        }

        cout << (result ? "true" : "false") << endl;
    }

    return 0;
}