
namespace xunyi{
    template<class Type>
    class vector{
        private:
        Type* _start;
        Type* _finish;
        Type* _eofs;
        public:
        typedef Type* iterator;
        typedef const Type* const_iterator;
        iterator begin(){return _start;}
        iterator end(){return _finish;}
        const_iterator begin()const {return _start;}
        const_iterator end()const {return _finish;}
        int size()const {
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
            for (auto iter = --_finish; iter >= pos; --iter)
            {
                *(++iter) = *iter;
            }
            *pos = value;
            ++_finish;
            return pos;
        }
        void push_back(const Type& value){
            insert(end(),value);
        }
        vector():_start(nullptr),_finish(nullptr),_eofs(nullptr){}
        vector(initializer_list<Type> ls){
            reserve(ls.size());
            for(const auto& e: ls){
                push_back(e);
            }
        }

    };
}