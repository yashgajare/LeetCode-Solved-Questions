//{ Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/


class Solution{
  public:
  
    Node* findMid(Node* head){
        Node* slow =head;
        Node* fast = head->next;
        
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    
    Node* merge(Node* left, Node* right){
        if(left==NULL) return right;
        if(right==NULL) return left;
        
        Node* res = new Node(-1);
        Node* tmp=res;
        
        while(left!=NULL && right!=NULL){
            if(left->data < right->data){
                tmp->next = left;
                tmp=left;
                left=left->next;
            }
            else{
                tmp->next=right;
                tmp=right;
                right=right->next;
            }
        }
        
        while(left!=NULL){
            tmp->next = left;
            tmp=left;
            left=left->next;
        }
        
        while(right!=NULL){
            tmp->next=right;
            tmp=right;
            right=right->next;
        }
        
        return res->next;
    }
  
    //Function to sort the given linked list using Merge Sort.
    Node* mergeSort(Node* head) {
        // your code here
        if(head==NULL || head->next==NULL) return head;
        
        Node* mid = findMid(head);
        Node* left = head;
        Node* right = mid->next;
        mid->next=NULL;
        
        left = mergeSort(left);
        right = mergeSort(right);
        
        Node* ans = merge(left, right);
        
        return ans;
    }
};


//{ Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}
// } Driver Code Ends