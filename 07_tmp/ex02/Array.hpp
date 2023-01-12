#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T> class Array
{
	private:
		T* _array;
		unsigned int _size;
	
	public:
		Array():_array(NULL), _size(0) {}
		Array(unsigned int size)
		{
			this->_array = new T[size];
			this->_size = size;
		}
		Array(Array const &copy)
		{
			this->_array = new T[copy.size()];
			this->_size = copy.size();
			for(int i = 0; i < this->_size; i++)
				this->_array[i] = copy._array[i];
		}
		~Array()
		{
			delete [] this->_array;
		}
		Array &operator=(Array const &in)
		{
			if (this->size() > 0)
				delete [] this->_array;
			this->_size = in._size;
			this->_array = new T[this->_size];
			for(int i = 0; i < this->size(); i++)
				this->_array[i] = in._array[i];
			return (*this);
		}
		T& operator[](unsigned int id)
		{
			if (this->_size < id)
				throw std::out_of_range("Error: Index is out of range.");
			return (this->_array[id]);
		}
		int size()
		{
			return ((int)this->_size);
		}
		void		print()
		{
			for(int i = 0; i < this->size(); i++)
				std::cout << i << ": '" << this->_array[i] << "'" << std::endl; 
		}
};


#endif