#include<iostream>
using namespace std;

class student
{
    protected:
    int rollno;
    public:
    void set_number(int a)
    {
        rollno=a;
    }
    void print_number()
    {
        cout<<"Your roll no is "<<rollno<<endl;
    }
};
class test: virtual public student
{
    protected:
    float maths,physics;
    public:
    void set_marks(float m1,float m2)
    {
        maths=m1;
        physics=m2;
    }
    void print_marks(void)
    {
        cout<<"your result is here "<<endl
        <<"Maths: "<<maths<<endl
        <<"physics: "<<physics<<endl;
    }
};
class Sports: virtual public student
{
    protected:
        float score;
    public:
        void set_score(float sc)
        {
            score =sc;
        }
        void print_score(void)
        {
            cout<<"Your PT score is "<<score<<endl;
        }
};
class Result : public test,public Sports
{
    private:
        float total;
        public:
            void display()
            {
                total=maths+physics+score;
                print_number();
                print_marks();
                print_score();
                cout<<"Your result is "<<total<<endl;
            }
};
int main()
{
    Result abhi;
    abhi.set_number(9);
    abhi.set_marks(78,89);
    abhi.set_score(88);
    abhi.display();
    return 0;
}
