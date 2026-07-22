class Solution {
public:
    bool isAlphaNum(char c){
        return isalnum(c);
        }
    bool isPalindrome(string s) {
    
        int left = 0;
        int right = s.length()-1;

        while(left<right){

            if(!isAlphaNum(s[left])){
                left++;
                continue;
            }

            if(!isAlphaNum(s[right])){
                right--;
                continue;
            }

            if(tolower(s[left]) != tolower(s[right])){
                return false;
                break;
            }

            left++;
            right--;
        }
        
        return true;
    }
};