#include <iostream>
using namespace std;

template <class T>
class MyArray
{
protected:
    T*array;
    int size;
public:
    MyArray(){}
    MyArray(int s)
    {
        size=s;
        array=new T [s];
    }
    MyArray(const MyArray&myarray)
    {
        size=myarray.size;
        for(int i=0;i<size;i++)
        {
            array[i]=myarray.array[i];
        }
    }
    int getsize(){ return size; }
    friend istream&operator>>(istream&input,MyArray&myarray)
    {
        for(int i=0;i<myarray.size;i++)
        {
            input>>myarray.array[i];
        }
        return input;
    }
    friend ostream&operator<<(ostream&output,MyArray&myarray)
    {
        for(int i=0;i<myarray.size;i++)
        {
            output<<myarray.array[i]<<" , ";
        }
        return output;
    }
    ~MyArray()
    { delete array; }
};

template <class T>
class SearchArray : public MyArray<T>
{
public:
    SearchArray(){}
    void findElement(int index)
    {
        for(int i=0;i<this->size;i++)
        {
            if(index==i){
                cout<<"element in index "<<i<<" is "<<this->array[i]<<endl;
                break;
            }
        }
    }
    void findIndex(T element)
    {
        bool check=false;
        for(int i=0;i<this->size;i++)
        {
            if(element==this->array[i])
            {
                cout<<this->array[i]<<" this element found in index "<<i<<endl;
                check=true;
                break;
            }
        }
        if(check==false)
            cout<<" this element not found"<<endl;
    }
};

template <class T>
class ResizeArray : public MyArray<T>
{
public:
    ResizeArray(){}
    void AddElement(T element)
    {
        this->size+=1;
        this->array[this->size]=element;
        cout<<element<<" is added"<<endl;
    }
};

int main()
{
    bool c1=false,c2=false;
    int choosetype;
    cout<<"would you like to store"<<endl<<"1-integers"<<endl<<"2-strings"<<endl;
    cin>>choosetype;
    if(choosetype==1)
    {
        do{
        try{
        int capacity;
        cout<<"enter the array size"<<endl;
        cin>>capacity;
            if(capacity<0){
                c1=true;
                throw "Error";
            }
            MyArray<int>myarray(capacity);
            SearchArray<int>searcharray;
            ResizeArray<int>resizearray;
            cout<<"enter the array elements"<<endl;
            cin>>myarray;
            cout<<endl<<myarray<<endl;
            do{
            try{
                int index;
                cout<<"enter the array index"<<endl;
                cin>>index;
                if(index<0){
                    c2=true;
                    throw "please enter positive number";
                }
                else if (index>capacity){
                    c2=true;
                    throw "out of range please enter number in range";
                }
                searcharray.findElement(index);
            }
            catch(const char*o)
            { cout<<o<<endl; }
            }while(c2==true);
            int elem;
            cout<<"enter the array element"<<endl;
            cin>>elem;
            searcharray.findIndex(elem);
            cout<<"enter the new element"<<endl;
            cin>>elem;
            resizearray.AddElement(elem);
            cout<<endl<<myarray<<endl;
        }
        catch(const char*p)
        { cout<<p<<",please enter positive number"<<endl; }
        }while(c1==true);
    }
    return 0;
}
