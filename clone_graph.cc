#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

/**
 * Definition for undirected graph.
 */
 struct UndirectedGraphNode {
   int label;
   vector<UndirectedGraphNode *> neighbors;
   UndirectedGraphNode(int x) : label(x) {};
 };

class Solution {
public:
  UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
    if (!node) {
      return NULL;
    }
    unordered_map<int, UndirectedGraphNode* > mp;
    UndirectedGraphNode* head = NULL;
    queue<UndirectedGraphNode* > q;
//    unordered_set<int> done;

    q.push(node);
    UndirectedGraphNode* n;
    vector<UndirectedGraphNode* >::iterator it;
    while (!q.empty()) {
      n = q.front();
      q.pop();
      UndirectedGraphNode* cn;
      if (mp.find(n->label) == mp.end()) {
        cn = new UndirectedGraphNode(n->label);
        mp[n->label] = cn;
      } else {
        cn = mp[n->label];
      }

      for (it = n->neighbors.begin(); it != n->neighbors.end(); it++) {
        if (mp.find((*it)->label) == mp.end()) {
          mp[(*it)->label] = new UndirectedGraphNode((*it)->label);
          q.push(*it);
        }
        cn->neighbors.push_back(mp[(*it)->label]);
      }
      if (head == NULL) {
        head = cn;
      }
    }
    return head;
  }
};

int main() {
  Solution s;
  s.cloneGraph(NULL);
  return 0;
}