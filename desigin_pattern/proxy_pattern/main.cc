#include <iostream>
#include <string>

using namespace std;

class Image{
  public:
    virtual ~Image(){}
    virtual void display() = 0;
};

class RealImage : public Image {
  string fileName;

  public:
    RealImage(string fileName):fileName(fileName){
      loadFromDisk(fileName);
    }

    void display() override{
      cout << "Displaying" << fileName << endl;
    }

  private:
    void loadFromDisk(string fileName){
      cout << "Loading" << fileName << endl;
    }
};

class ProxyImage : public Image {
  RealImage *realImage;
  string fileName;

  public:
    ProxyImage(string fileName):fileName(fileName),realImage(nullptr){};

    void display(){
      if(realImage == nullptr){
        realImage = new RealImage(fileName);
      }
      realImage->display();
    }
};

int main()
{
  Image *image = new ProxyImage("test_10mb.jpg");

  image->display();
  cout << endl;

  image->display();

  RealImage realImage = RealImage("test_11mb.jpg");
  realImage.display();
  realImage.display();

  Image *imageReal = new RealImage("test_11mb,jpg");
  imageReal->display();
  imageReal->display();
  return 0;
}
