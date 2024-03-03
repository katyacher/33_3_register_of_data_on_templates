#include <iostream>
#include <vector>
#include <string>



template<typename T1, typename T2>
class Register{

    struct Pair{
        T1 key;
        T2 value;
        Pair(T1 _key, T2 _value): key(_key), value(_value){}; 
    };

    std::vector<Pair> storage;
    
public:
    Register(){};

    Register(const T1& key, const T2& value){
        storage.push_back(Pair(key, value));
    } 

    void add(const T1& key, const T2 value){
        storage.push_back(Pair(key, value));
    }

    bool find(const T1& item){
        if(storage.size() == 0) {
           throw std::invalid_argument("Error: storage is empty!");
        }

        for(const auto& _pair: storage){
            if(_pair.key == item){
                return true;
            }
        }
        return false;
    }

    void remove(const T1& item){
        
        if(storage.size() == 0) {
           throw std::invalid_argument("Error: storage is empty!");
        }

        for(auto it = storage.begin(); it != storage.end();){
            if(it->key == item){
                it = storage.erase(it);
            } else {
                ++it;
            }
        }
    }

    void print (){
        for(int i = 0; i < storage.size(); ++i){
            std::cout << "[" << i << "] key: " << storage[i].key <<
                ", value: " << storage[i].value << std::endl;
        }
    }
    
};



int main(int, char**){
    std::cout << "Hello, from 33_3_storage_of_data_on_templates!\n";

    Register<int, std::string> reg;
    reg.add(1,"one");
    reg.add(2, "two");
    reg.add(3, "tree");
    reg.add(3, "four");

    reg.print();

    std::cout << reg.find(2) << ", " << reg.find(3) << std::endl;
    reg.remove(3);
    std::cout << reg.find(2) << ", " << reg.find(3) << std::endl;

    reg.print();

    Register<double, double> reg2;
    reg2.add(1.5,1.0);
    reg2.add(2.5,2.0);
    reg2.add(3.5, 3.0);

    reg2.print();


    Register<std::string, double> reg3;
    reg3.add("one", 1.1);
    reg3.add("two", 2.2);
    reg3.add("tree", 3.3);

    reg3.print();
/*
    std::string ans;

    do{
        std::cout << "Enter command(create/add/remove/print/find/exit): ";
        std::cin >> ans;

        if(ans == "add")
            reg.add();
        else if(ans == "remove")
            reg.remove();
        else if(ans == "print")
            reg.print();
        else if(ans == "find")
            reg.find();
    }
    while(ans != "exit");

    */

}
