const int DEF_CAPACITY = 10;
const int CAPACITY_MULT = 2;

template <typename T>
class MyVec {
    public:
        /*
        class Iterator {
         * This class supports ranged for loops.
         * It includes:
         * Iterator(int*)
         * operator++
         * operator*
         * operator!=
            friend bool operator!=(Iterator& rhs, Iterator& lhs) {
                return true;
            }
        public:
            Iterator(T* ip) : iptr(ip) {}
            Iterator& operator++() {
                return *this;
            }
            T operator*() { return 0; }
        private:
            T* iptr;
    };
         * */

        MyVec() {
            sz = 0;
            capacity = DEF_CAPACITY;
            data = new T[DEF_CAPACITY];
        }

        MyVec(int sz, T val=T()) : sz(sz), capacity(sz), data(new T[sz]) {
			for (int i = 0; i < sz; ++i) push_back(val);
		}

        // copy control:
        MyVec(const MyVec& v2) {
            copy(v2);
        }

        ~MyVec() { delete [] data; }

        MyVec& operator=(const MyVec& v2) {
            if (this != &v2) {
                delete [] data;
                copy(v2);
            }
            return *this;
        }

        void push_back(T val) {
            sz++;
            if (sz > capacity) {
                std::cout << "Increasing capacity\n";
                T* old_data = data;
                data = new T[capacity * CAPACITY_MULT];
                for (int i = 0; i < sz; i++) {
                    data[i] = old_data[i];
                }
                capacity *= CAPACITY_MULT;
                delete [] old_data;
            }
            data[sz - 1] = val;
        }

        int size() const { return sz; }

        T operator[](int i) const {
            return data[i];
        }

		T& operator[](int i) {
			return data[i];
		}

        //Iterator begin() const;
        //Iterator end() const;

    private:
        void copy(const MyVec& v2) {
            sz = v2.sz;
            capacity = v2.capacity;
            data = new T[capacity];
            for (int i = 0; i < sz; i++) {
                data[i] = v2.data[i];
            }
        }

        T* data;
        int sz;
        int capacity;
};


template <typename T>
void print_vector(const MyVec<T>& v) {
	for (int i = 0; i < v.size(); ++i) std::cout << v[i] << " ";
	std::cout << ::endl;
}

template <typename T>
bool operator==(MyVec<T>& v1, MyVec<T>& v2) {
	if (v1.size() != v2.size()) return false;
	for (int i = 0; i < v1.size(); ++i) {
		if (v1[i] != v2[i]) return false;
	}
	return true;
}