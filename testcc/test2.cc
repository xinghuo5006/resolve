#ifndef TEST2
#define TEST2

#include<iostream>
#include<array>

namespace CommonStack
{
	template<class Type>
	class Stack
	{
	public:
		Stack();
		~Stack();
		bool push(int stackNum, const Type value);
		bool pop(int stackNum, Type *value);
		bool isEmpty(int stackNum);
		void printbuffer();
	private:
		void initbuffer();
		std::array<int,3> m_stackPointer;
		int m_indexCurr;
		static const int m_totalSize = 300;
		class data{
		public:
		Type value;
		int preIndex;
		bool isFree{true};
		};
		std::array<data,300> buffer;
	};

	template <class  Type>  
	void Stack<Type>::initbuffer()
	{
		for(int i=0;i<300;i++)
			buffer.at(i).isFree=true;
	}

	template <class  Type>  
	Stack<Type>::Stack()
	{     
		//m_totalSize = 300;
		m_stackPointer.at(0)=-1;
		m_stackPointer.at(1)=-1;
		m_stackPointer.at(2)=-1;
		m_indexCurr =0;
		initbuffer();
	}

	template <class Type>  
	Stack<Type>::~Stack() 
	{
	}
	
	template<class Type>
	bool Stack<Type>::push(int stackNum, const Type value)
	{
		if (m_indexCurr == m_totalSize)         
			return false;

		int lastIndex = m_stackPointer[stackNum];       
     
		data tempdata;
		tempdata.value = value;            
		tempdata.preIndex = lastIndex;  
		tempdata.isFree = false;
	for(int i=0;i<m_totalSize;i++)
		{
		   if(buffer[i].isFree)
		   {
           buffer.at(i)=tempdata;
           m_indexCurr=i+1;
           m_stackPointer[stackNum] = i;
           break;
		   } 
		}                        

		return true;
	}
	
	template<class Type>
	bool Stack<Type>::pop(int stackNum, Type *value)
	{
		if (-1 == m_stackPointer[stackNum])            
			return false;

		*value = buffer[m_stackPointer[stackNum]].value;  
		
		buffer[m_stackPointer[stackNum]].isFree = true;

		m_stackPointer[stackNum] = buffer[m_stackPointer[stackNum]].preIndex;
		
		m_indexCurr = m_stackPointer[stackNum]+1;

		return true;
	}

	template<class Type>
	bool Stack<Type>::isEmpty(int stackNum)
	{
		return (-1 == m_stackPointer[stackNum]);
	}

	template<class Type>
	void Stack<Type>::printbuffer()
	{
		int i =0;
		while(buffer.at(i).isFree==false)
		{
		std::cout << buffer.at(i).value << std::endl;
		i++;
		}
	}
}
#endif
