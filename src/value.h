#ifndef VALUE_H
#define VALUE_H
#include <vector>
#include <string>
#include <cmath>

namespace microcgrad
{

template <typename T>
class Value
{

private:
    T m_data;
    std::vector<Value> m_prev;
    char m_op;
    std::string m_label;
    T m_grad;

public:
    static int depth;

public:

   Value(T data): m_data(data)
    {
        m_grad = 0;
    }
    
    Value(T data, std::vector<Value> children, char op): 
        m_data(data), m_prev(children), m_op(op) 
    {
        m_grad = 0;
    }

    Value(T data, std::string label): m_data(data), m_label(label) 
    {
        char op = '\0';
        m_grad = 0;
    }

    void setLabel(std::string label)
    {
        m_label = label;
    }

    void setData(T d)
    {
        m_data = d;
    }

    T getData()
    {
        return m_data;
    }

    Value<T> tanh() const
    {
        std::vector<Value<T>> prev {*this};
        T t = exp(2 * m_data);
        t = (t-1) / (t+1);
        Value<T> res(t, prev, 't');        
        return res;
    }

    Value<T> operator+(const Value<T> &other) const
    {
        std::vector<Value<T>> prev {*this, other};
        Value<T> res(m_data + other.m_data, prev, '+');        
        return res;
    }

    Value<T>& operator+(const T other)
    {
        m_data += other;        
        return *this;
    }

    Value<T>& operator+=(const T other)
    {
        m_data += other;        
        return *this;
    }

    Value<T> operator*(const Value<T> &other) const
    {
        std::vector<Value<T>> prev {*this, other};
        Value<T> res(m_data * other.m_data, prev, '*');        
        return res;
    }

    Value<T>& operator*=(const T other)
    {
        m_data *= other;        
        return *this;
    }

    Value<T>& operator*(const T other)
    {
        m_data *= other;        
        return *this;
    }

    Value<T>& operator=(const Value<T> &other) //const
    {
        m_data = other.m_data;
        m_label = other.m_label;
        m_op = other.m_op;  
        return *this; 
    }

    friend std::ostream& operator<<(std::ostream& os, const Value& v)
    {
        os << v.m_data << " " << v.m_op << " ";

        for (auto i : v.m_prev)
        {
            os << i << " ";
        }
        return os;
    }

    // display tree
    friend std::ostream& operator>>(std::ostream& os, const Value& v)
    {
        if (depth > 0) os << "└── ";

        os << v.m_label 
        << " " << v.m_data 
        << " g " << v.m_grad
        << " " << v.m_op << "\n";
        depth++;

        for (auto i : v.m_prev)
        {
            for (int j = 1; j < depth; j++)
            {
                os << "    ";
            }
            os >> i; // recursive call
        }
        depth--;
        return os;
    }

};

template <typename T>
int Value<T>::depth = 0;

}

#endif

