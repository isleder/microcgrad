#include <iostream>
#include "value.h"

using namespace std;
using namespace microcgrad;

int main()
{
    float h = 0.001;

    Value<float> a(2);
    Value<float> b1(-3);
    Value<float> c(10);
    Value<float> e = a*b1;
    //Value<float> d(a*b+c);

    Value<float> d(e+c);
    Value<float> f(-2.0);
        d+=-3.9;

    Value<float> L = d * f;

    a.setLabel("a");
    b1.setLabel("b");
    c.setLabel("c");
    e.setLabel("e");
    d.setLabel("d");
    f.setLabel("f");
    L.setLabel("L");
    //L = L;

    cout << "a " << a << "\n"; 
    cout << "b " << b1 << "\n";
    cout << "c " << c << "\n"; 
    cout << "a*b " << a*b1 << "\n"; 
    cout << "a*b+c" << a*b1+c<< "\n"; 
    cout << "d " << d << "\n"; 
    cout >> d; 
    cout << "----------------\n";
    cout << "L " << L << "\n"; 
    cout >> L;
    cout << "----------------\n";

    Value<float> o1 = L.tanh();
    o1.setLabel("o tanh");
    cout << "o " << o1 << "\n"; 
    cout >> o1;

    float r = (L.getData()+8) / h;
    cout << "r " << r << "\n"; 


    //viz(d);


    cout << "----------------\n";

    Value<double> x1(2, "x1");
    Value<double> x2(0, "x2");
    Value<double> w1(-3, "w1");
    Value<double> w2(1, "w2"); 
    Value<double> b(6.7, "b");
    
    Value<double> x1w1 = x1*w1; x1w1.setLabel("x1*w1");
    Value<double> x2w2 = x2*w2; x1w1.setLabel("x2*w2");
    Value<double> x1w1x2w2 = x1w1 + x2w2; x1w1x2w2.setLabel("x1w1 + x2w2");
    Value<double> n = x1w1x2w2 + b; n.setLabel("n");
    Value<double> o = n.tanh(); o.setLabel("o");
    cout >> o;
    return 0;
}