template<typename T>
class Vectore {
    private:
        T* data;
        size_t capacity;
        size_t length;
        void resize();

    public:
        Vector();
        ~Vector();
        void push_back(const T& val);
        T& operator[](size_t index);
        size_t size() const;
};
