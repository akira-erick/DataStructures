
#ifndef VECTOR_HPP
#define VECTOR_HPP

template <typename T>
class Vector {
    public:
    virtual ~Vector() = default;
    Vector(const Vector<T>& other);
    Vector<T>& operator=(const Vector<T>& other);

    virtual void push_back(const T& value) = 0;
    virtual T& operator[](size_t index) = 0;
    virtual size_t size() const = 0;
    virtual bool empty() const = 0;
    virtual void clear() = 0;
};

#endif 