

#include <iostream>
using namespace std;


class Fraction
{
    int denum;
    int num;
public:
    void initFrac()
    {
        cout << "Enter the numinator: ";
        cin >> num;
        cout << "Enter the denuminator: ";
        cin >> denum;
    }
    Fraction sumFrac(Fraction b)
    {
        Fraction res;
        if (denum == b.denum)
        {
            res.num = num + b.num;
            res.denum = denum;
            return res;
        }
        else if (denum % b.denum == 0)
        {
            int k = denum / b.denum;
            res.denum = denum;
            res.num = num + (b.num * k);
            return res;
        }
        else if (b.denum % denum == 0)
        {
            int k = b.denum / denum;
            res.denum = b.denum;
            res.num = b.num + (b.num * k);
            return res;
        }
        else
        {
            res.denum = denum * b.denum;
            res.num = (num * b.denum) + (b.num * denum);
            return res;
        }

    }
    Fraction subFrac(Fraction b)
    {
        Fraction res;
        if (denum == b.denum)
        {
            res.num = num - b.num;
            res.denum = denum;
            return res;
        }
        else if (denum % b.denum == 0)
        {
            int k = denum / b.denum;
            res.denum = denum;
            res.num = num - (b.num * k);
            return res;
        }
        else if (b.denum % denum == 0)
        {
            int k = b.denum / denum;
            res.denum = b.denum;
            res.num = b.num - (b.num * k);
            return res;
        }
        else
        {
            res.denum = denum * b.denum;
            res.num = (num * b.denum) - (b.num * denum);
            return res;
        }
    }
    Fraction multFrac(Fraction b)
    {
        Fraction res;
        res.num = num * b.num;
        res.denum = denum * b.denum;
        return res;
    }
    Fraction divFrac(Fraction b)
    {
        Fraction res;
        res.num = num * b.denum;
        res.denum = denum * b.num;
        return res;
    }
    void reduceFrac()
    {

        for (size_t i = num > denum ? denum : num; i >0; i--)
        {
            if (num % i == 0 && denum % i == 0)
            {
                num /= i;
                denum /= i;
            }
        }
    }
    int getNum()
    {
        return num;
    }
    int getDenum()
    {
        return denum;
    }
};

int main()
{
    Fraction a;
    Fraction b;
    a.initFrac();
    b.initFrac();
    a = a.subFrac(b);
    a = a.divFrac(b);
    a = a.multFrac(b);
    cout << "Numinator: " << a.getNum() << endl;
    cout << "Denuminator: " << a.getDenum() << endl;
    cout << "Reduced fraction: " << endl;
    a.reduceFrac();
    cout << "Numinator: " << a.getNum() << endl;
    cout << "Denuminator: " << a.getDenum() << endl;
    
}
