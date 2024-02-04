//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// Node Class
class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(NULL) {}
};

// Linked List Class
class LinkedList {
public:
    Node* head;
    Node* tail;

    LinkedList() : head(NULL), tail(NULL) {}

    // creates a new node with given value and appends it at the end of the linked list
    void insert(int val) {
        if (head == NULL) {
            head = new Node(val);
            tail = head;
        } else {
            tail->next = new Node(val);
            tail = tail->next;
        }
    }
};


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    Node * reverse(Node * head) {
        Node * prev = nullptr, * current = head;
        
        while(current){
            Node * nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }
        
        return prev;
    }
    
    pair<Node *, Node *> subtract(Node * num1, Node * num2) {
        LinkedList result, remainder;
        int borrow = 0;
        
        while(num1 or num2){
            int digitDifference = (num1 ? num1->data : 0) - (num2 ? num2->data : 0) - borrow;
            borrow = digitDifference < 0;
            
            if(borrow){
                if((num1 and num1->next) or (num2 and num2->next)){
                    result.insert(10 + digitDifference);
                    remainder.insert(0);
                }
                else{
                    remainder.insert(abs(digitDifference));
                }
            }
            else{
                result.insert(digitDifference);
                remainder.insert(0);
            }
            
            if(num1)
                num1 = num1->next;
            if(num2)
                num2 = num2->next;
        }
        
        if(borrow){
            return {remainder.head, result.head};
        }
        else{
            return {result.head, nullptr};
        }  
    }
    
    Node* subLinkedList(Node* number1, Node* number2) {
        number1 = reverse(number1);
        number2 = reverse(number2);
        
        pair<Node *, Node *> subtractionResult = subtract(number1, number2);
        Node * finalResult;
        
        if(subtractionResult.second){
            number1 = subtractionResult.first;
            number2 = subtractionResult.second;
            
            finalResult = subtract(number1, number2).first;
        }
        else{
            finalResult = subtractionResult.first;
        }
        
        finalResult = reverse(finalResult);
        
        while(finalResult->data == 0 and finalResult->next)
            finalResult = finalResult->next;
        
        return finalResult;
    }
};









//{ Driver Code Starts.

// prints the elements of linked list starting with head
void printList(Node* n) {
    while (n) {
        cout << n->data;
        n = n->next;
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        LinkedList LL1;
        string l1,l2;
        cin>>l1;
        for (int j = 0; j < n; ++j) {
            int x=(l1[j]-'0');
            LL1.insert(x);
        }

        int m;
        cin >> m;
        LinkedList LL2;
        cin>>l2;
        for (int j = 0; j < m; ++j) {
            int x=(l2[j]-'0');
            LL2.insert(x);
        }

        Solution ob;
        Node* res = ob.subLinkedList(LL1.head, LL2.head);
        printList(res);
    }

    return 0;
}

// } Driver Code Ends