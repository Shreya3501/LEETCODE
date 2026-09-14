class Solution {
public:
    int reverseNumber(int n , long long rev){

        if(n == 0) return rev;

        int digit = n % 10;
        rev = rev * 10 + digit;

        return reverseNumber(n / 10 , rev);
    }
    bool isPalindrome(int x) {
        
        if(x < 0){
            return false;
        }
        int reversed = reverseNumber(x,0);

        return x == reversed;
    }  
};