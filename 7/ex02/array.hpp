template <typename banana>
class Array
{
	private:
		unsigned int size;
		banana *arr;
	public:
		Array();
		Array(unsigned int n); 
		Array(Array& other);
		Array& operator=(Array& other);
		banana
		~Array();
		unsigned int size();
}