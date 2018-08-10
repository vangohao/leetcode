inline char right(char ch)
{
    switch(ch)
    {
        case '(':return ')';
        case '[':return']';
        case '{':return'}';
        default:return 0;
    }
}

bool isValid(string s)
{
    size_t l = s.length();
    if(l == 0) return true;
    char ch  = s[0];
    char rch = right(ch);
    if(rch==0) return false;
    int lc = 1,rc=0;int i = 1;
    while(lc>rc && i< l) 
    {
        if(right(s[i]) == 0)
            rc++;
        else lc++;
        i++;
    }
    if(rc!=lc || s[i-1] !=rch) return false;
    return isValid(s.substr(1,i-2)) && isValid(s.substr(i,l-(i)));
}