#include<bits/stdc++.h>
using namespace std;

class IImage{
    public:
    virtual void display()=0;
    virtual ~IImage()=default;
};

class RealImage: public IImage{
    string filename;
    public:
    RealImage(string file){
        this->filename = file;
        // Time Consuming Operations 
        // Like Loading from disk 
        // Compression of the image
        // Quality adjustment.

        cout<<"Loading images: " << filename << endl;
    }
    void display() override{
        cout<<"Displaying image: " << filename << endl;
    }
};
class ImageProxy: public IImage{
    RealImage* realImage;
    string filename;
    public:
    ImageProxy(string file){
        this->filename = file;
        this->realImage = nullptr;
    }
    void display() override{
        if(realImage==nullptr){
            realImage = new RealImage(filename);
        }
        realImage->display();
    }
};

int main(){
    IImage* image1=new ImageProxy("image1.jpg");
    image1->display();
return 0;
}