//abdelrahmanramadan s13 20200284
//ezzeldin ahmed saber s13 20200325
#include <iostream>
#include <fstream>

using namespace std;

class FloatArray
{
protected:
    float *arr;
    int s;
public:
    int num;

    FloatArray(int n)
    {
        s = n;
        arr = new float[s];
    }

    friend ifstream &operator>>(ifstream &fil, FloatArray &obj)
    {
        for (int i = 0; i < obj.s; i++)
        {
            fil >> obj.arr[i];
        }
        return fil;
    }

    friend ofstream &operator<<(ofstream &fil, FloatArray &obj)
    {
        fil<<obj.s<<"|\t";
        for (int i = 0; i < obj.s; i++)
        {
            fil << obj.arr[i] << " \t";
        }
        fil << endl;
        return fil;
    }


    virtual void add() {};


    ~FloatArray()
    {
        delete[] arr;
    }

};

class SortedArray : public FloatArray
{
public:

    SortedArray(int s) : FloatArray(s)
    {

    }

    void add()
    {

        for (int i = 0; i < s; i++)
        {
            for (int j = 0; j < (s - 1); j++)
            {
                if (arr[j] >= arr[j + 1])
                {
                    float index = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = index;
                }
            }
        }

    }

    void p()
    {
        for (int i = 0; i < s; i++)
        {
            cout << arr[i] << "  ";
        }
    }

};

class FrontArray : public FloatArray
{

    int sizee;
public:
    FrontArray(int s) : FloatArray(s)
    {
        sizee = s;
    }


    void add()
    {

        for (int i = 0; i <= sizee / 2; i++)
        {
            float index;
            index = arr[i];
            arr[i] = arr[sizee - 1 - i];
            arr[sizee - 1 - i] = index;
        }
    }
};

class PositiveArray : public SortedArray
{
    int sizee;
public:
    PositiveArray(int s) : SortedArray(s)
    {
        sizee = s;
    }

    void operator<<(ofstream &fil)
    {
        int truesize = 0;
        for (int i = 0; i < sizee; i++)
        {
            if (arr[i] > 0)
            {
                truesize++;
            }
        }


        fil << truesize << "|\t";
        for (int i = 0; i < sizee; i++)
        {
            if (arr[i] > 0)
            {
                fil << arr[i] << "\t";
            }

        }
        fil << "\n";
    }


};

class NegativeArray : public SortedArray
{
    int sizee;
public:
    NegativeArray(int s) : SortedArray(s)
    {
        sizee = s;
    }

    void operator<<(ofstream &fil)
    {
        int truesize = 0;
        for (int i = 0; i < sizee; i++)
        {
            if (arr[i] < 0)
            {
                truesize++;
            }
        }


        fil << truesize << "|\t";
        for (int i = 0; i < sizee; i++)
        {
            if (arr[i] < 0)
            {
                fil << arr[i] << "\t";
            }

        }
        fil << "\n";
    }

};

int main()
{
    FloatArray *empty,*objects[10];
    ifstream fil;
    ofstream write;
    string input, output;
    cout << "enter the file input name";
    cin >> input;
    cout << "enter the file output name: ";
    cin >> output;
    write.open(output);

    fil.open(input);

    int cnt = 10;

    while (cnt--)
    {
        string t;
        int S;
        fil >> t;
        fil >> S;


        if (t == "Sorted")
        {
            empty = new SortedArray (S);
            fil>>*empty;
            empty->add();
            write<<*empty;

        }
        else if (t == "Front")
        {
            FloatArray *pt;
            FrontArray f(S);
            empty = new FrontArray(S);
            fil>>*empty;
            empty->add();
            write<<*empty;

        }
        else if (t == "Positive")
        {
            PositiveArray p(S);
            empty = new PositiveArray(S);
            fil >> p;
            p.add();
            p<<write;
        }
        else if (t == "Array")
        {
            empty = new FrontArray(S);
            fil>>*empty;
            empty->add();
            write<<*empty;
        }
        else if (t == "Negative")
        {
            NegativeArray p(S);
            fil >> p;
            p.add();
            p<<write;
        }
    }

    return 0;
}
