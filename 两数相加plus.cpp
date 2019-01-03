#include<iostream>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *node1, *node2;
        if(l1==NULL)
            return l2;
        if(l2==NULL)
            return l1;
        node1 = l1;
        node2 = l2;
        int carry = 0;
        ListNode *res, *node;
        res = new ListNode(0);
        node = res;
        //cout<<"A"<<endl;
        while(node1!=NULL || node2!=NULL || carry)
        {
            ListNode *tmp = new ListNode(0);
            if(node1==NULL && node2!=NULL)
            {
                tmp->val = (node2->val + carry)%10;
                carry = (node2->val + carry)/10;
                node2 = node2->next;
            }
            else if(node1!=NULL && node2==NULL)
            {
                tmp->val = (node1->val + carry)%10;
                carry = (node1->val + carry)/10;
                node1 = node1->next;
            }
            else if(node1==NULL && node2==NULL)
            {
                tmp->val = carry;
                carry = 0;
                node->next = tmp;
                break;
            }
            else
            {
                tmp->val = (node1->val + node2->val + carry)%10;
                carry = (node1->val + node2->val + carry)/10;
                node1 = node1->next;
                node2 = node2->next;
            }
            node->next = tmp;
            node = node->next;
            //cout<<carry<<endl;
        }
        return res->next;
    }
};

void print(ListNode* L)
{
    ListNode* node = L;
    while(node!=NULL)
    {
        cout<<node->val<<" ";
        node = node->next;
    }
    cout<<endl;
}

ListNode* buildList(int a[], int length)
{
    ListNode *head, *node;
    head = new ListNode(0);
    node = head;
    for(int i=0; i<length; i++)
    {
        ListNode *tmp = new ListNode(a[i]);
        node->next = tmp;
        node = node->next;
    }
    return head->next;
}

int main()
{
    int a[] = {5,3};
    int b[] = {5};
    ListNode *la = buildList(a, 2);
    print(la);
    ListNode *lb = buildList(b, 1);
    print(lb);

    Solution solution;
    ListNode *sum = solution.addTwoNumbers(la, lb);
    print(sum);
    return 0;
}
