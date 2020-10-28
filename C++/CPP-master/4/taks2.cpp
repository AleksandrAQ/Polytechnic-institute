#include <vector>
#include <iostream>

using namespace std;

class factorials
{
public:
	vector<int> v;
	factorials(){
		v.clear();
		for (int i = 1;i<=10; i++)
			v.push_back(i);
	};
	~factorials(){};
	class iterator{
	public:
		typedef int  value_type; //typedef'ы для удобства
        typedef int& reference;
        typedef int* pointer;

		typedef std::bidirectional_iterator_tag iterator_category; //определяет тип вашего итератора
        typedef std::ptrdiff_t difference_type; 
        typedef std::ptrdiff_t distance_type;

        iterator (const  int* value  = pointer()) {
            position_ = const_cast<pointer>(value);
        };

        iterator& operator ++ (){
        	++position_;
        	return *this;
        }

        iterator operator ++ (int){
        	return iterator(position_++);
        }


        iterator& operator -- (){
        	--position_;
        	return *this;
        }

        iterator operator --(int){
            return(position_--);
        }
 
        value_type operator*(){
        	int num = 1;
        	for (int i=2; i<=*position_; i++)
      			num = num*i;
      		return num;
        }

        bool operator !=(const iterator& value){
        	return position_!=value.position_;
        }

        bool operator ==(const iterator& value){
        	return position_==value.position_;
        }


    private:
        pointer position_;
	};
	iterator begin(void) const {return iterator(&v[0]);};
	iterator end(void) const{return iterator(&v[9]+1);};
};

int main()
{
	factorials v;
 	for (factorials::iterator it = v.begin(); it!=v.end(); it++)
 		cout<<*it<<endl;

    cout<<endl;

 	vector<int> vect(++v.begin(),--vexit .end());

 	for (vector<int>::iterator it = vect.begin(); it!=vect.end(); it++)
 		cout<<*it<<endl;

	return 0;
}