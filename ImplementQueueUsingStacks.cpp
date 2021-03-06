/*Implement the following operations of a queue using stacks.
 *
 *push(x) -- Push element x to the back of queue.
 *pop() -- Removes the element from in front of queue.
 *peek() -- Get the front element.
 *empty() -- Return whether the queue is empty.
 *Notes:
 *You must use only standard operations of a stack -- which means only push to top, peek/pop from top, size, and is empty operations are valid.
 *Depending on your language, stack may not be supported natively. You may simulate a stack by using a list or deque (double-ended queue), as long as you use only standard operations of a stack.
 *You may assume that all operations are valid (for example, no pop or peek operations will be called on an empty queue).
 */
 
 class Queue {
public:
    stack <int> s,s2;
    // Push element x to the back of queue.
    void push(int x) {
        s.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        if(s.size()==1)
            s.pop();
        else
        {
            while(s.size()>1)
            {
                s2.push(s.top());
                s.pop();
            }
            s.pop();
            while(s2.size()>0)
            {
                s.push(s2.top());
                s2.pop();
            }
        }
    }

    // Get the front element.
    int peek(void) {
        if(s.size()==1)
            return s.top();
        while(s.size()>1)
        {
            s2.push(s.top());
            s.pop();
        }
        int temp=s.top();
        s2.push(s.top());
        s.pop();
        while(s2.size()>0)
        {
            s.push(s2.top());
            s2.pop();
        }
        return temp;
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return s.empty();
    }
};
