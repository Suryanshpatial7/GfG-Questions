//{ Driver Code Starts
#include <bits/stdc++.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

using namespace std;

void printList(Node* Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
}

Node* flatten(Node* root);

int main(void) {

    int t;
    cin >> t;
    while (t--) {
        int n, m, flag = 1, flag1 = 1;
        struct Node* temp = NULL;
        struct Node* head = NULL;
        struct Node* pre = NULL;
        struct Node* tempB = NULL;
        struct Node* preB = NULL;
        cin >> n;
        int work[n];
        for (int i = 0; i < n; i++)
            cin >> work[i];
        for (int i = 0; i < n; i++) {
            m = work[i];
            --m;
            int data;
            scanf("%d", &data);
            temp = new Node(data);
            temp->next = NULL;
            temp->bottom = NULL;

            if (flag) {
                head = temp;
                pre = temp;
                flag = 0;
                flag1 = 1;
            } else {
                pre->next = temp;
                pre = temp;
                flag1 = 1;
            }
            for (int j = 0; j < m; j++) {

                int temp_data;
                scanf("%d", &temp_data);
                tempB = new Node(temp_data);

                if (flag1) {
                    temp->bottom = tempB;
                    preB = tempB;
                    flag1 = 0;
                } else {
                    preB->bottom = tempB;
                    preB = tempB;
                }
            }
        }
        Node* fun = head;
        Node* fun2 = head;

        Node* root = flatten(head);
        printList(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends

Node* merge(Node* h1,Node* h2){
        Node* dummy=new Node(-1);
        Node* temp=dummy;
        while(h1 and h2){
            if(h1->data<h2->data){
                temp->bottom=h1;
                temp=h1;
                h1=h1->bottom;
            }
            else{
                temp->bottom=h2;
                temp=h2;
                h2=h2->bottom;
            }
            temp->next=NULL;
        }
        if(h1) temp->bottom=h1;
        if(h2) temp->bottom=h2;
        if(dummy->bottom) dummy->bottom->next=NULL;
        return dummy->bottom;
    }
    Node* flatten(Node* root){
        if(root==NULL || root->next==NULL) return root;
        Node* curr=flatten(root->next);
        return merge(root,curr);
    }
