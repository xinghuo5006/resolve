#include<iostream>
#include<vector>
#include<stack>
#include <string>
#include <sstream>
#include <stdlib.h>
using namespace std;

class Solution {
public:
    Solution();   
    ~Solution();
    int evalRPN(vector<string> &tokens);
};
   Solution::Solution()
{}
    int Solution::evalRPN(vector<string> &tokens) {
        stack<int> s;
        int answer=0;
        int num1=0;
        int num2=0;
        int i =0;
        if(tokens.empty())
            return 0;
        if(tokens.size()==1 && tokens[0] >="0" &&tokens[0]<="9")
            return atoi(tokens.at(0).c_str());
        while(i<tokens.size())
        {
            if(tokens[i]!="+"&&tokens[i]!="-"&&tokens[i]!="*"&&tokens[i]!="/")
            {
            int temp = atoi(tokens.at(i).c_str());
            s.push(temp);
            i++;
            }
            else
            {
                int unn=int(tokens.at(i)[0]);
                switch(unn)
                {
                case 43:
                        num1=s.top();
                        s.pop();
                        num2=s.top();
                        s.pop();
                        answer=num1+num2;
                        s.push(answer);
                        i++;
                        break;
                case 45:
                        num1=s.top();
                        s.pop();
                        num2=s.top();
                        s.pop();
                        answer=num2-num1;
                        s.push(answer);
						i++;
                        break;
                 case 42:
                        num1=s.top();
                        s.pop();
                        num2=s.top();
                        s.pop();
                        answer=num1*num2;
                        s.push(answer);
						i++;
                        break;
                   case 47:
                        num1=s.top();
                        s.pop();
                        num2=s.top();
                        s.pop();
                        answer=num2/num1;
                        s.push(answer);
						i++;
                        break;
                    default:
						i++;
                        break;
                }
            }
        }
        return answer;
    }

int main()
{
   Solution* about= new Solution();
   vector<string> strinput;
   strinput.push_back("2");
   strinput.push_back("3");
   strinput.push_back("+");
   strinput.push_back("3");
strinput.push_back("*");
   int anser = about->evalRPN(strinput);
   std::cout<<anser<<std::endl;
   std::stringstream sstr;
	//string to int
	sstr<<"5x0";
	int value2;
	sstr>>value2;
	cout<<"string to int value2: "<<value2<<endl;
   return 0; 
}
