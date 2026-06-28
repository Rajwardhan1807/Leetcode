class Solution {
public:
    int strStr(string haystack, string needle) {
        int h = haystack.size();
        int n = needle.size();
         
        //outer loop select starting index
        for(int i = 0;i <= h - n ;i++){
            int j;

            for( j = 0;j<n;j++){ 
                if(haystack[ i + j ] != needle[j]) break;
            }
            //if string matched
            if(j == n) return i;
        }
        return -1;
    }
};