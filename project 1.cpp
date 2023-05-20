//abdelrahman ramadan abulela 20200284 S13
// Ezzeldin ahmed saber 20200325 s13
#include <iostream>
#include <windows.h>
using namespace std;
void SetColor(int ForgC)
{
    WORD wColor;
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    //We use csbi for the wAttributes word.
    if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
        //Mask out all but the background attribute, and add in the forgournd color
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
    return;
}
class ColoredBox
{
private:
    char **m;
    char **boxtrans;
    char boxchar;
    int length;
    int width;
    int color;
    int area;
    void setbox()
    {
        for(int i=0; i< length+1 ; i++)
        {
            for(int j=0; j<width+1; j++)
            {
                m[i][j]=boxchar;

            }
        }
        for(int i=0; i<width+1; i++)
        {
            for(int j=0; j<length+1; j++)
            {
                boxtrans[i][j]=boxchar;
            }
        }


    }

public:
    static int MaxArea;
    ColoredBox(int l, int w,int col=15, char boxch='#')
    {
        length=l;
        width=w;
        color=col;
        boxchar=boxch;
        m= new char *[length+1];
        for(int i=0; i< length+1; i++)
        {
            m[i]= new char[width+1];
        }
        boxtrans=new char *[width+1];
        for(int i=0; i<width+1; i++)
        {
            boxtrans[i]=new char [length+1];
        }
        setbox();

    }
    void setchar(char c)
    {
        boxchar=c;
    }
    void setColor(int co)
    {
        color=co;
    }
    char getchar()
    {
        return boxchar;
    }
    int getcolor()
    {
        return color;
    }
    void display()
    {
        for(int i=0 ; i< length; i++)
        {
            for(int j=0 ; j< width ; j++)
            {
                SetColor(color);
                cout<<m[i][j];
            }
            cout<<endl;
        }
        SetColor(15);

    }
    void displayTransposed()
    {
        for(int i=0; i<width; i++)
        {
            for(int j=0; j<length; j++)
            {
                SetColor(color);
                cout<<boxtrans[i][j];
            }
            cout<<endl;
        }
        SetColor(15);

    }
    void displayWider()
    {
        for(int i=0; i<length; i++)
        {
            for(int j=0; j<width; j++)
            {
                SetColor(color);
                cout<<m[i][j]<<" ";
            }
            cout<<endl;
        }
        SetColor(15);

    }
    void displayChess(int clr)
    {
        int c=0;
        SetColor(color);
        for(int i=0; i<length; i++)
        {
            for(int j=0 ; j<width; j++)
            {
                if(i%2== j%2)
                {
                    SetColor(color);
                }
                else
                {
                    SetColor(clr);
                }
                cout<< m[i][j];
            }
            cout<<endl;
        }
        SetColor(15);
    }
    int getArea()
    {
        area= length * width;
        return area;
    }
    int getMaxArea()
    {
        if(area > MaxArea)
        {
            MaxArea =area;
        }
        return MaxArea;
    }
    ~ColoredBox()
    {
        delete [] m;
    }





};
int ColoredBox::MaxArea=0;
int main()
{
    int len,wid,col,col2;
    char boxChar;
    cout<<"Enter length and width of the box separated by a space: ";
    cin>>len>>wid;
    ColoredBox* cb1;
    cb1 = new ColoredBox(len,wid);
    cb1->display();
    cout<<"Set the box to another color: ";
    cin>>col;
    cb1->setColor(col);
    cout<<"Displaying Transposed: "<<endl;
    cb1->displayTransposed();
    cout<<"Displaying Wider: "<<endl;
    cb1->displayWider();
    cout<<"Displaying Chess, enter the other color: "<<endl;
    cin>>col2;
    cb1->displayChess(col2);
    cout<<endl<<"Area="<<cb1->getArea();
    cout<<endl<<"Max Area="<<cb1->getMaxArea();
    delete cb1;

    cout<<"Enter length,width,color,character of the box separated by spaces: ";
    cin>>len>>wid>>col>>boxChar;
    ColoredBox* cb2;
    cb2 = new ColoredBox(len,wid,col,boxChar);
    cb2->display();
    cout<<"Displaying Transposed: "<<endl;
    cb2->displayTransposed();
    cout<<"Displaying Wider: "<<endl;
    cb2->displayWider();
    cout<<"Displaying Chess, enter the other color: "<<endl;
    cin>>col2;
    cb2->displayChess(col2);
    cout<<"Displaying original again:"<<endl;
    cb2->display();
    cout<<endl<<"Area="<<cb2->getArea();
    cout<<endl<<"Max Area="<<cb2->getMaxArea();
    delete cb2;
    return 0;
}
