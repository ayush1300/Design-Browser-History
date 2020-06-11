class BrowserHistory {
public:
    BrowserHistory(string homepage) {
        s.push_back(homepage);
        curr++;
    }
    
    void visit(string url) {
        if(curr<s.size()-1) {
            s.erase(s.begin()+curr+1,s.begin()+s.size());
        }
        s.push_back(url);
        curr++;
        
    }
    
    string back(int steps) {
        if(curr<steps)
        {
            curr = 0;
        }
        else
        {
            curr = curr - steps;
        }
        
        return s[curr];
    }
    
    string forward(int steps) {
        if(curr+steps >= s.size())
        {
            curr  = s.size()-1;
        }
        else
        {
            curr = curr + steps;
        }
        
        return s[curr];
    }
    
private:
    vector<string> s;
    unsigned int curr=-1;
};
