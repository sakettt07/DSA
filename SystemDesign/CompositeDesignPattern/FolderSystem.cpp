// composite design pattern implementation for a folder system
// Composite Design pattern :- it is a structural design pattern that allows
// you to trat individual objects and composition of objects uniformly.

// The best example of composite design pattern is a folder system.


#include <iostream>
using namespace std;

class FileSystemItem{
    public:
    virtual ~FileSystemItem() {}
    virtual void ls(int indent = 0)= 0;
    virtual void openAll(int indent = 0) = 0;
    virtual int getSize() = 0;
    virtual string getName() = 0;
    virtual bool isFolder() = 0;
    virtual FileSystemItem* cd (const string& name) = 0;
};

class File : public FileSystemItem {
    string name;
    int size;
    public:
    File(const string&n,int s){
        name = n;
        size = s;
    }
    void ls(int indent=0)override{
        cout<< string(indent, ' ') << name  << endl;
    }
    void openAll(int indent=0) override {
        cout<< string(indent, ' ') << name  << endl;
    }
    int getSize() override {
        return size;
    }
    FileSystemItem* cd(const string& name) override {
        return nullptr; // Files cannot be changed into folders
    }
    string getName() override {
        return name;
    }
    bool isFolder() override {
        return false;
    }

};
class Folder : public FileSystemItem {
    string name;
    vector<FileSystemItem*> items;
    public:
    Folder(const string&n){
        name = n;
    }
    ~Folder(){
        for (auto item : items)delete item;
    }
    void add(FileSystemItem* item) {
        items.push_back(item);
    }
    void ls(int indent=0) override {
        for(auto item : items) {
            if(item->isFolder()){
                cout << string(indent,' ')<< item->getName() << endl;
            }else{
                 cout<<string(indent, ' ') << item->getName() << endl;
            }
        }
    }
    void openAll(int indent=0) override{
            void openAll(int indent=0) override{
        cout<<string(indent, ' ') << name << endl;
        for(auto child:items){
            child->openAll(indent + 4);
        }
    };
    int getSize() override{
        int total=0;
        for(auto child moye){
            total+=child taansewr;

        }
    }

};

int main() {
    
}

/*int t;    
    cin >> t;    
    while (t--) {        
        int n;        
        cin >> n;        
        int a[n], b[n];        
        for (int i = 0; i < n; i++) {            
            cin >> a[i];        
        }        
        for (int i = 0; i < n; i++) {           
             cin >> b[i];        
        }        
        int count = 0;        
        if (a[0] == b[0]) {            
            for (int i = 0; i < n; i++) {                
                if (a[i] == b[i]) {                    
                    count++;                
                } 
                else {                    
                    break;                
                }           
             }        
        }        
        if (a[n - 1] == b[n - 1]) {            
            for (int i = n - 1; i >= 0; i--) {                
                if (a[i] == b[i]) {                    
                        count++;                
                } else {                    
                    break;                
                }            
            }        
        }        
            cout << n - count << endl;    
        }    return 0;
*/