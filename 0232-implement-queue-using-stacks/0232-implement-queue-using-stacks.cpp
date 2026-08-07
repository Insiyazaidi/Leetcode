class MyQueue {
public:

stack<int>input;
stack<int>output;
int peakele = 0; 

    MyQueue() {
        
    }
    
    void push(int x) {
        if(input.empty()){
              peakele = x;  // agr yeh sbse phla element h 
        }
        input.push(x);
    }
    
    int pop() {
    

        // agr output empty h toh phir interchange kro 
        if(output.empty()){
    while(!input.empty()){
            output.push(input.top());
            input.pop();
        }
        }
    
        // agr output empty nhi  h toh yhi output se direct ans nikallo 
        int storing = output.top();
         output.pop();
         return storing ;
    }
    
    int peek() {
        if(output.empty()){   // output empty h toh hm yeh interchange krva process krskte the ... but hmne peek store 
        // kiya hua h phle se toh no need 
            return peakele; 
        }
        else{
          return   output.top();// vrna output se ans niklalo 
        }
        
    }
    
    bool empty() {  // dono stack empty h toh true 
       if(input.empty() == true && output.empty() == true){
        return true;
       } 
       return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */