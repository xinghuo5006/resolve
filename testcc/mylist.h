#include<iostream>

template<class T>
class slistNode
{
    public:
    slistNode(){next=NULL;}
    T data;//值
    slistNode* next;//指向下一个节点的指针
};
template<class T>
class myslist
{
    private:
    unsigned int listlength;
    slistNode<T>* node;//临时节点
    slistNode<T>* lastnode;//头结点
    slistNode<T>* headnode;//尾节点
    public:
        myslist();//初始化
        unsigned int length();//链表元素的个数
        void add(const T &x);//表尾添加元素
        void traversal();//遍历整个链表并打印
        bool isEmpty();//判断链表是否为空
        slistNode<T>* find(T x);//查找值为x的节点,返回节点的地址,找不到返回NULL
        void Delete(T x);//删除值为x的节点
        void insert(T x,slistNode<T>* p);//在p节点后插入值为x的节点
        void insertHead(T x);//在链表的头部插入节点

};
#include"mylist_impl.h"
