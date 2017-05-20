#include <iostream>

class A;
class B;
class C: virtual public A, virtual public B;
class D: virtual public A, virtual public B;
class E: public C, public D, virtual B;