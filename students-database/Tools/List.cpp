template<typename T>
class List {
private:
    size_t length{};
    T * data;

    void fill(T t) {
        this->add(t);
    }

    template <typename... Args>
    void fill(T t, Args... args) {
        this->add(t);
        this->fill(args...);
    }

    void init() {
        this->data = new T[0];
        this->length = 0;
    }

public:

    typedef T* iterator;
    typedef const T* const_iterator;

    iterator begin() { return &data[0]; }
    [[nodiscard]] const_iterator begin() const { return &data[0]; }
    iterator end() { return &data[length]; }
    [[nodiscard]] const_iterator end() const { return &data[length]; }

    List() {
        this->init();
    }

    template <typename... Args>
    explicit List(T t, Args... args) {
        this->init();
        this->fill(t, args...);
    }

    T operator [] (int id) {
        return this->data[id];
    }

    void add(T elem) {
        T * newData = new T[this->length + 1];
        for(int i = 0; i < this->length; i++) {
            newData[i] = data[i];
        }
        newData[this->length] = elem;
        delete this->data;
        data = newData;
    }

    void remove(int id) {
        T * newData = new T[this->length - 1];
        int j = 0;
        for(int i = 0; i < this->length; j++) {
            if(i == id) {
                continue;
            }
            newData[i] = this->data[j];
            i++;
        }
        this->length--;
        delete this->data;
        data = newData;
    }

    T sum() {
        T s = 0;
        for(int i = 0; i < this->length; i++) {
            s += this->data[i];
        }
        return s;
    }

    size_t size() {
        return this->length;
    }
};