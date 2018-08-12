class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int l = s.length();
        int n = words.size();
        vector<int> * mp = new vector<int>[n];
        vector<int> result;
        map<string,int> wordnum;
        for(string w: words)
        {
            if(wordnum.count(w) == 0)
            wordnum.insert(make_pair(w,1));
            else 
            wordnum[w]+=1;
        }
        vector<string> newwords;
        vector<int> newcounts;
        for(auto x: wordnum)
        {
            newwords.push_back(x.first);
            newcounts.push_back(x.second);
        }
        int n1 = newwords.size();
        int * mp2 = new int[l];
        for(int i = 0; i<l; ++i) mp2[i] = -1;
        int m = 0;
        for(int i = 0; i<n1; ++i)
        {
            size_t t = 0;
            while((t = s.find(newwords[i], t)) != string::npos)
            {
                mp[i].push_back(t);
                if(mp2[t] == -1)
                mp2[t] = i;
                t++;
            }
            m = newwords[i].length();
        }
        int * tmp = new int[n];

        for(int i = 0; i<n; ++i) tmp[i] = -1;
        for(int i = 0; i<m; ++i)
        {
            for(int k = 0;(k+n -1) * m + i<l; ++k)
            {
                int * tmp2 = new int[n1];
                for(int i = 0; i<n1; ++i) tmp2[i] = newcounts[i];

                bool flag = true;
                for(int r = 0;r<n;++r)
                {
                    if(mp2[(k+r) * m + i] == -1)
                        {flag = false;break;}
                    else{
                        tmp2[mp2[(k+r)*m +i]]--;
                        if(tmp2[mp2[(k+r)*m +i]]<0)
                        {flag = false; break;}
                    }
                }
                if(flag) result.push_back(k * m + i)
            }
        }
        return result;
    }
};