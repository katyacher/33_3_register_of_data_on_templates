#include <iostream>
#include <string>
#include <vector>

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
        bool result = false;
        if(storage.size() == 0) {
           throw std::invalid_argument("Error: storage is empty!");
        }

        for(auto it = storage.begin(); it != storage.end();){
            if(it->key == item){
                it = storage.erase(it);
                result = true;
            } else {
                ++it;
            }
        }

        return result;
    }

    void print() const{
        for(int i = 0; i < storage.size(); ++i){
            std::cout << "[" << i << "] key: " << storage[i].key <<
                ", value: " << storage[i].value << std::endl;
        }
    }
    
};


