#include<initializer_list>
namespace xunyi{
    template<class Type>
    class vector{
        private:
        Type* _start = nullptr;
        Type* _finish = nullptr;
        Type* _eofs = nullptr;
        public:
        typedef Type* iterator;
        typedef const Type* const_iterator;
        iterator begin(){return _start;}
        iterator end(){return _finish;}
        const_iterator begin() const { return _start; }
        const_iterator end() const { return _finish; }
        vector() = default;
        vector(const std::initializer_list<Type>& ls)
        {
            reserve(ls.size());
            for (const auto &e : ls)
            {
                push_back(e);
            }
        }
        template<class Input_iter>
        vector(Input_iter start,Input_iter end){
            while(start != end){
                push_back(*start);
                ++start;
            }
        }
        vector(int n,const Type& value = Type()){
            reserve(n);
            for(int i=0;i<n;++i){
                push_back(value);
            }
        }
        int size() const
        {
            return _finish - _start;
        }
        int storage()const {
            return _eofs - _start;
        }
        void reserve(int n){
            if(n > storage()){
                int old_size = size();
                Type *tmp = new Type[n];
                if (_start)
                {
                    for (int i = 0; i < old_size; ++i)
                    {
                        tmp[i] = _start[i];
                    }
                    delete[] _start;
                }
                _start = tmp;
                _finish = _start + old_size;
                _eofs = _start + n;
            }
        }
        iterator insert(iterator pos ,const Type& value){
            if(_finish == _eofs){
                int len = pos - _start;
                int new_capacity = storage() == 0 ? 2 : 2 * storage();
                reserve(new_capacity);
                // 扩容之后，pos失效
                pos = _start + len; // 恢复pos
            }
            for (auto iter = _finish-1; iter >= pos; --iter)
            {
                *(iter+1) = *iter;
            }
            *pos = value;
            ++_finish;
            return pos;
        }
        void push_back(const Type& value){
            insert(end(),value);
        }


        Type& operator[](int pos){
            return _start[pos];
        }
 

    };
}