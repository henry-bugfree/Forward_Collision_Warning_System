#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <math.h>
#include <vector>
using namespace std;

class object
{
private:
    string name;
    int originalPixel_x;
    int originalPixel_y;
    int birdPixel_x;
    int birdPixel_y;
    double distance;
public:
    object(string& label,int ox,int oy,int bx,int by,double dist)
    {
        name=label;
        originalPixel_x=ox;
        originalPixel_y=oy;
        birdPixel_x=bx;
        birdPixel_y=by;
        distance=dist;
    }
    string get_name()
    {
        return name;
    }
    int get_origCoor_x()
    {
        return originalPixel_x;
    }
    int get_origCoor_y()
    {
        return originalPixel_y;
    }
    int get_birdCoor_x()
    {
        return birdPixel_x;
    }
    int get_birdCoor_y()
    {
        return birdPixel_y;
    }
    double get_dist()
    {
        return distance;
    }
};

vector<object*> one_frame;//一帧图像，包含很多个object

int main()
{
    ifstream infile;
    //infile.open("./share/dist-2000cm.txt");
    infile.open("../../share/dist-2000cm.txt");
    
    string label;
    int ox,oy,bx,by;
    double dist;
    while(infile >> label)
    {
        infile >> ox >> oy >> bx >> by >> dist;
        object* optr = new object(label,ox,oy,bx,by,dist);
        one_frame.push_back(optr);
        cout<<one_frame[0]->get_dist()<<endl;//this is just a test!
    }
    infile.close();
    return 0;
}
