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

    bool remove(const T1& item){
        
        if(storage.size() == 0) {
           throw std::invalid_argument("Error: storage is empty!");
        }

        for(auto& pair: storage){
            if(pair.key == item){
                storage.erase(pair);
                return true;
            }
        }

        return false;
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
    reg.add(2,"two");
    reg.add(3, "tree");
    reg.add(3, "four");

    reg.remove(3);

    std::cout << reg.find(2) << ", " << reg.find(3) << std::endl;

    reg.print();

}
