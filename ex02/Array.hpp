#ifndef ARRAY_HPP
#define ARRAY_HPP

template <typename T>
class Array {
	private:
		T* 				_data;
		unsigned int	_size;
	public:
		Array() : _data(NULL), _size(0) {}
		Array(unsigned int n) : _data(new T[n]()), _size(n) {} // () at the end is a C++98 trick that ensures value-initialization (setting integers to 0, for example)
		Array(const Array& src) : _data(NULL), _size(0) {
			*this = src;
		}
		Array& operator=(const Array& rhs) {
			if(this != &rhs){
				//1. Delete old memory
				delete [] _data;
				//4. Update _size
				_size = rhs._size;
				if (_size > 0) {
					//2. Allocate new memory based on other._size
					_data = new T[_size]();
					//3. Copy element from other._data to new _data
					for (unsigned int i = 0; i < _size; i++){
						_data[i] = rhs._data[i];
					}
				} else {
					_data = NULL;
				}
			}
			return *this;
		}
		~Array() {
			if(_data)
				delete[] _data;
		}

		// Subscript operator for non-const objects
		T & operator[](unsigned int index){
			if (index >= _size)
				throw std::exception(); //Subject requirement
			return _data[index];
		}

		// Subscript operator for const objects
		const T & operator[](unsigned int index) const {
			if (index >= _size)
				throw std::exception();
			return _data[index];
		}

		unsigned int size() const{
			return _size;
		}
};

#endif
