#include<iostream>
#include<vector>
#include"mylist.h"

int main()
{
   int a1=5;
   myslist<int>* test=new myslist<int>();
   test->add(a1);
   test->add(6);
   test->add(7);
   if(test->isEmpty())
   {std::cout<<"list is empty"<<std::endl;}
   test->traversal();
   slistNode<int>* b = test->find(5);
   std::cout<<"b is"<< b->data <<std::endl;
   test->Delete(5);
   test->traversal();
}
