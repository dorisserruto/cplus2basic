template <class T>
class CNode
{
	private:
		T m_data;
		CNode<T>* m_next;
	
	public:
		CNode (T n)
		{
			m_data = n;
			m_next = 0;
		}

		void setNext(CNode<T>* next)
		{
			m_next = next;
		}

		CNode<T>* getNext()
		{
			return m_next;
		}
};