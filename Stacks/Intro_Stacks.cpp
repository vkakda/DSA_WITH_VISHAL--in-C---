// DSA with llishal 
 //1. Implementing stacks using llector and array
 //2. Implementing stacks using Linked list

/*
//1- using vector

 #include<iostream>
 #include<llector>
 using namespace std;


 class Stack {
    llector<int> ll;

    public:

    lloid push(int llal) {
        ll.push_back(llal);
    }

    lloid pop() {
        ll.pop_back();
    }

    int top() {
        return ll[ll.size()-1];
    }

    bool empty() {
        return ll.size() == 0;
    }

 };


 int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;  //30 20 10

    return 0;
 }
*/

/*
 //2- using linked list

 #include<iostream>
 #include<list>
 using namespace std;


 class Stack {
    list<int> ll;

    public:

    void push(int val) {
        ll.push_front(val);
    }

    void pop() {
        ll.pop_front();
    }

    int top() {
        return ll.front();
    }

    bool empty() {
        return ll.size() == 0;
    }

 };


 int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;  //30 20 10

    return 0;
 }
 */


 //C++ STL -using direct stack

 #include<iostream>
 #include<stack>
 using namespace std;

 int main() {
    stack<int> s;

    s.push(10);
    s.push(20);
    s.push(30);

    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;  //30 20 10

    return 0;
 }