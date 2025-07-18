/*
#include<bits/stdc++.h>
using namespace std;

class Box
{
    int width;
    // private constructor
    Box(int _w) : width(_w)
    {
    }
  public :
    int getWidth() const
    {
        return width;
    }
    void SetWidth(int x)
    {
        width = x;
    }
};

int main()
{
    // Box b;if we do not declare the object then we can declare the constructor private
    // so answer is yes the constructoor can be made private ubtill direct intaintiation of object is
    // not there

}

*/
// BUT SOME TIMES WE WANT THAT THE OBJECT THE CLASS BOX CAN ONLY BE MADE VIA THE CLASSS BOX FACTORY
// THEN THERE IS THE NEED OF THE PRIVATE CONSTRUCTOR
// LETS SEE....

#include<bits/stdc++.h>
using namespace std;

class Box
{
    int width;
    // private constructor
    Box(int _w) : width(_w)
    {
    }
  public :
    int getWidth() const
    {
        return width;
    }
    void SetWidth(int x)
    {
        width = x;
    }
    // inorder the class Box factory can use the private constructor we have to make the
    // box factory a friend class
    friend class BoxFactory;
};

class BoxFactory
{
    int count = 0;

  public:
    Box *getbox()
    {
        count++;
        Box *b = new Box(20);
        return b;
    }
};
int main()
{
    BoxFactory *bf = new BoxFactory();
    Box *c = bf->getbox();
    cout << c->getWidth() << endl;
    // when ever we create the object using the boxfactory and call the getbox
    //  the count variable is done ++ thus it will give us the count of boxes that can be made
}