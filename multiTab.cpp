class Tab {
public:
    Tab(string homepage) {
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
        if(curr+steps >= s.size() )
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



class BrowserHistory{
public:
	BrowserHistory(string homepage) {
    	
    	if(n==-1){
		    n=0;
    		Tab* obj = new Tab(homepage);
    		defaultHomepage = homepage;
    		s.push_back(obj);
    	}
    }
	
	void addTab(){
		Tab* ob = new Tab(defaultHomepage);
		s.push_back(ob);
		n = s.size()-1;
	}
	
	void closeTab(){
		if(n>0)
		{
			s.erase(s.begin()+n);
			n=n-1;	
		}
		else if(n==0)
		{
			if(s.size()==1)
			{
				s.erase(s.begin());
				n = -1;
				defaultHomepage = "";
			}
			else if(s.size()>1)
			{
				s.erase(s.begin());
				
			}
		}
		
	}
	
	void shiftTab(int p)
	{
		if(p>=0 && p<s.size())
		{
			n = p;
		}
		else if(p>=s.size() && s.size()>0)
		{
			n = s.size()-1;
		}
		else if(p<0 && s.size()>0)
		{
			n = 0;
		}
	}
	
		
	void visit(string url) {
        
        s[n]->visit(url);
        
    }	
	
	string back(int steps) {
		
        return s[n]->back(steps);
    
	}
	
	string forward(int steps) {
        
        return s[n]->forward(steps);
    }
		
private:
	vector<Tab*> s;
    int n = -1;
    string defaultHomepage="";
		
};
