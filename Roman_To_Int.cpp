 int trans(char a){
		switch(a){
			case 'I': return 1;
			case 'V': return 5;
			case 'X': return 10;
			case 'L': return 50;
			case 'C': return 100;
			case 'D': return 500;
			case 'M': return 1000;
			default: return 0;
		}
	}
    int romanToInt(string s) {
        /*unordered_map<char,int>hm;
        hm.insert({'I',1});
        hm.insert({'V',5});
        hm.insert({'X',10});
        hm.insert({'L',50});
        hm.insert({'C',100});
        hm.insert({'D',500});
        hm.insert({'M',1000});
        int ans=hm[s[0]],n=s.size();
        for(int i=1;i<n;i++)
        {
            int temp_value=hm[s[i]];
            if(hm[s[i-1]]<hm[s[i]])
            {
                ans=ans-2*hm[s[i-1]]+hm[s[i]];

            }
            else
            ans+=temp_value;
        }
        return ans;
        */
        int ans=trans(s[0]),n=s.size();
        for(int i=1;i<n;i++)
        {
            int curr=trans(s[i]);
            int prev=trans(s[i-1]);
            if(prev<curr)
            {
                ans=ans-2*prev+curr;

            }
            else
            ans+=curr;
        }
        return ans;
    }