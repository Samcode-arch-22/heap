class solution{
    public:

    int sortksortedarray(vector<int> v, int k ){
        priority_queue<int , vector<int>, greater<int>> minheap;
        vector<int> result;
        for(int i =0; i < v.size()-1; i++){
          minheap.push(v[i]);
          if(minheap.size ()> k){
          result.push_back(minheap.top());
            minheap.pop();
          }
        }
        while(!minheap = empty()){
            result.push_back(minheap.top());
        minheap.pop();
        }
        
        return result;
    }
};