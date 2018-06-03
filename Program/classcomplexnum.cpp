#include <iostream>
using namespace std;

class complexnum
{
    int realpart;
    int imagpart;

public:

    complexnum(){};
    complexnum(int rp , int ip)
    {
        realpart=rp;    imagpart=ip;
    }
    void setvalue(int rt,int ct)
    {
        realpart=rt;    imagpart=ct;
    }
    void print()
    {
        cout<<realpart; if(imagpart>=0) cout<<"+";cout<<imagpart<<"i"<<endl;
    }
    void add(complexnum c)
    {
        realpart+=c.realpart;
        imagpart+=c.imagpart;
    }
    complexnum operator+(complexnum c)
    {
        complexnum t;
        t.realpart=realpart+c.realpart;
        t.imagpart=imagpart+c.imagpart;
        return t;
    }
    void operator=(complexnum c)
    {
        realpart=c.realpart;
        imagpart=c.imagpart;
    }

    complexnum operator*(complexnum c)
    {
        complexnum t;
        t.realpart= realpart*c.realpart -imagpart*c.imagpart;
        t.imagpart= realpart*c.imagpart + c.realpart*imagpart;
        return t;
    }
    /*complexnum operator/(complexnum c)
    {
        complexnum t;
        t.realpart=c.realpart/(c.realpart*c.realpart+c.imagpart*c.imagpart);
        t.imagpart=-c.imagpart/(c.realpart*c.realpart+c.imagpart*c.imagpart);
        return t;
    }*/
    int Realpart()
    {
    return realpart;}
    int Imagpart(){
    return imagpart;}

};
ostream& operator<< (ostream &os,complexnum c)
    {
        os<<c.Realpart();
        if(c.Imagpart>=0)   os<<"+";
        os<<c.Imagpart()<<"i"<<endl;

    }
istream& operator>> (istream &is, complexnum &c)
{
    int r,i;
    is>>r>>i;
    c.setvalue(r,i);

}


int main()
{
    complexnum c1;
    c1.setvalue(2,3);
    c1.print();

    complexnum c2(5,-6);
    c2.print();
    c2.add(c1);
    c2.print();
    complexnum c3=c1+c2;
    c3.print();

    complexnum c4=c2;
    c4.print();

    complexnum c5=c1*c2;
    c5.print();

    //complexnum c6/c2;
    //c6.print();
    cout<<c5;
    complexnum c6;
    cin>>c6;
    cout<<c6;
    return 0;
}
