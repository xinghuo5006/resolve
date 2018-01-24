#include<iostream>
#include<array>

int main()
{
	int b;
	int i;
	std::array<int,100> a;
	std::cout<<"please input your array:"<<std::endl;
	for(i=0;;i++)
		{
			std::cin>>a[i];
			if(getchar()=='\n')
				break;
			if(i==100)
			{
				std::cout<<"over range!"<<std::endl;
				break;
			}
		}
		std::cout<<"Please input the target num"<<std::endl;
		std::cin>>b;
		for(int j=0;j<i+1;j++)
			{
			if(a[j]< (b/2+1))
				{
				  for(int k=0;k<i+1;k++)
					{
						if(a[k]==(b-a[j]))
							{
							  std::cout<<a[j]<<","<<a[k]<<std::endl;
							  break;
							}
					}
				}
			}
	return 0;
}

