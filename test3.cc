class Solution {
public:
    bool judgeifhassamechar(string str)
    {
        for(int k=0;k<str.length();k++)
        {
            for(int m=k+1;m<str.length();m++)
            {
                if(str[k]==str[m])
                    return true;
            }
        }
        return false;
    }
    int lengthOfLongestSubstring(string s) {
        int lengthanswer= 0;
        std::string stranswer = "";
        for(int i=0;i<s.length();i++)
        {
            for(int j=1;j<=(s.length()-i);j++)
            {
                std::string str1= s.substr(i,j);
                //judge if has same char
                if(judgeifhassamechar(str1))
                    continue;
                else
                {
                    lengthanswer=(j>=lengthanswer ? j : lengthanswer);
                    stranswer=(j == lengthanswer ? str1 : stranswer);
                }
            }
        }
        std::cout<<stranswer<<std::endl;
        return lengthanswer;
            
    }
};