class Solution {
public:
    bool isPalindrome(int x) {
        long long  rev;
        int dup=x;
        while(x>0)
        {
            int d=x%10;
            rev= (rev*10)+d;
            x= x/10;
        }
        if(dup == rev)
        {
            return true;
        }
        return false;
        
    }
};