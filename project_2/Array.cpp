#include <iostream>
using namespace std;

class Array
{
	private:
		int array[100];
		int count;
		
	public:
		void Add(int);
		 void Insert(int,int);
		 int Delete(int);
		 int Find(int);
			
};
//--------------add----------------------------
Array::void Add(int value)
{
	   this->array[this->ccount] = value;
            count++;
}
//--------------insert-------------------------
Array::void Insert(int index,int value)
{
            for(i = count; i>= index; i--)
              {
                  this->array[i + 1] = array[i];
              }
            this->array[index] = value;
            this->count++;
}
//--------------delete-------------------------
Array::int Delete(int index)
{
	      for(int i = index; i < count; i++){
            this->array[i] = array[i + 1];
        }
        count--;
        return array[index];
}
//--------------find---------------------------
Array::int Find(int value)
{
	for(int i = 0; i < count - 1; i++){
            if(value == array[i]){
                return i;
}
