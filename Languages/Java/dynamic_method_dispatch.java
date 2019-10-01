package LAB3;

class A {
    void m1() {
        System.out.println("Inside A's m1 method");
    }
}
class B extends A {
    // overriding m1()
    void m1() {
        System.out.println("Inside B's m1 method");
    }
}
class C extends A {
    // overriding m1()
    void m1() {
        System.out.println("Inside C's m1 method");
    }
}
// Driver class
class dynamic_method_dispatch {
    public static void main(String args[]) {
        // object of type A
        A a = new A();
        // object of type B
        B b = new B();
        // object of type C
        C c = new C();
        // obtain a reference of type A
        A ref;
        // ref refers to an A object
        ref = a;
        // calling A's version of m1()
        ref.m1();
        // now ref refers to a B object
        ref = b;
        // calling B's version of m1()
        ref.m1();
        // now ref refers to a C object
        ref = c;
        // calling C's version of m1()
        ref.m1();
    }
}
