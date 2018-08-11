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
        int * tmp2 = new int[n1];
        for(int i = 0; i<n1; ++i) tmp2[i] = newcounts[i];
        for(int i = 0; i<n; ++i) tmp[i] = -1;
        for(int i = 0; i<m; ++i)
        {
            int j = 0;
            int k = 0;
            while(k * m + i < l)
            {
                if(mp2[k * m + i] == -1)
                {
                    j = 0;
                    k++;
                    for(int r = 0; r<n1; ++r) tmp2[r] = newcounts[r];
                }
                else
                if(j<n)
                {
                    if(tmp2[mp2[k*m+i]] == 0)
                    {
                        j = 1;
                        tmp[mp2[k * m + i]] = k;
                        for(int r = 0; r<n1; ++r) tmp2[r] = newcounts[r];
                        tmp2[mp2[k*m+i]] --;
                        k++;
                    }
                    else
                    {
                        tmp[mp2[k * m + i]] = k;
                        tmp2[mp2[k * m + i]] --;
                        j++;k++;
                    }
                }
                else 
                {
                    int j1 = j;
                    j = k - tmp[mp2[k * m + i]];
                    for(int r = k-j1;r<=k-j;++r)
                        tmp2[mp2[r * m + i]] ++;
                    k++;
                }

                if(j == n)
                {
                    result.push_back((k - j) * m + i);
                }
            }
        }
        return result;
    }
};