#include <iostream>
#include <vector>
#include <deque>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {};
};

vector< deque<ListNode *> > results;

ListNode *insert_front(ListNode *head, int n)
{
    ListNode *node;
    node = new ListNode(n);

    node->next = head;

    head = node;

    return head;
}

void display(ListNode *head)
{
    cout << "=======" << endl;
    ListNode *node = head;
    while (node != NULL)
    {
        cout << node->val << endl;
        node = node->next;
    }
    cout << "=======" << endl;
}

void weave_lists(ListNode *first, ListNode *second, deque<ListNode *> prefix) {
    
    if(first == NULL || second == NULL) {
        if(first == NULL) {
            while(second != NULL) {
                prefix.push_back(second);
                second = second->next;
            }
        }
        else if(second == NULL) {
            while(first != NULL) {
                prefix.push_back(first);
                first = first->next;
            }
        }
        
        results.push_back(prefix);
        return;
    }

   
    ListNode *headfirst = first;
    first = first->next;
    prefix.push_back(headfirst);
    weave_lists(first, second, prefix);
    ListNode *fromStack = prefix.back();
    prefix.pop_back();
    first = insert_front(first, fromStack->val);

    

    ListNode *headsecond = second;
    second = second->next;
    prefix.push_back(headsecond);
    weave_lists(first, second, prefix);
    fromStack = prefix.back();
    prefix.pop_back();
    second = insert_front(second, fromStack->val);
}

int main() {
    ListNode *list1;
    ListNode ln(3);
    list1 = &ln;
    list1 = insert_front(list1, 2);
    list1 = insert_front(list1, 1);

    ListNode *list2;
    ListNode ln2(6);
    list2 = &ln2;
    list2 = insert_front(list2, 5);
    list2 = insert_front(list2, 4);

    deque<ListNode *> prefix;
    weave_lists(list1, list2, prefix);

    cout<<results.size()<<endl;

    for(int i=0; i<results.size(); i++) {
        deque<ListNode *> lists = results[i];

        while(lists.empty()!=true) {
            ListNode *node = lists.front();
            lists.pop_front();
            cout<<node->val<<" ";
        }
        cout<<endl;
    }
}
