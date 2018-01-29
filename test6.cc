#include<iostream>
#include<vector>

using namespace std;
 
 struct Point {
      int x;
      int y;
      Point() : x(0), y(0) {}
      Point(int a, int b) : x(a), y(b) {}
 };
  int maxPoints(vector<Point> &points) { 
        if (points.size() < 3) return points.size();  
          
        int max = 0;//用于返回的结果，即共线点的最大个数  
        std::map<double, int> map;//保存同一个斜率的点的个数  
          
        for (int i = 0; i < points.size(); i++) {//以每一个点为固定点  
            map.clear();  //must clear, to get the maxnum of specific point
            int duplicate = 1;//记录跟固定点重合的个数,why not be 0 ?  
              
            for(int j = i+1 ; j < points.size(); j++){//遍历其他点，求其与固定点之间的斜率  ,must start from 0
                if (i == j) continue;//如果是自己，跳过  
                double slope = 0.0;//斜率  
                  
                if (points[i].x == points[j].x && points[i].y == points[j].y) {//如果跟固定点重合  
                    duplicate++;  
                    continue;  
                } else if (points[i].x == points[j].x) {//如果跟固定点在同一条竖线上，斜率设为最大值  
                    slope = DBL_MAX;  
                } else {//计算该点与固定点的斜率  
                    slope = 1.0 * (points[i].y - points[j].y) / (points[i].x - points[j].x);  
                }
                if(map.find(slope)!=map.end())
                {
                    map[slope]+=1;
                }
                else
                {
                    map[slope]=1;
                }
                 
            }  
              
            //更新最优解  
            if (map.size() == 0) {//如果map为空  
                max = duplicate > max ? duplicate : max;  
            } else {  
                 std::map<double ,int>::iterator  iter;
                 for( iter=map.begin(); iter!=map.end(); iter++)
                  {
                     if((iter->second + duplicate) > max) 
                         max= iter->second + duplicate;
                 }
            }  
        }  
        return max;  
    }  
  
int main()
{
  vector<Point> mynum;
  Point p1;
  p1.x=1;
  p1.y=2;
  Point* p2=new Point(2,4);
  Point* p3=new Point(3,6);
  mynum.push_back(p1);
 mynum.push_back(*p2);
 mynum.push_back(*p3);
 int maxnum=maxPoints(mynum);
  std::cout<<maxnum<<std::endl;
  return 0;

}
