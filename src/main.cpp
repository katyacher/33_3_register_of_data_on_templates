#include <iostream>
#include <vector>
#include <string>
#include "register.h"

template<typename T1, typename T2>
class user_data_entry{
    Register<T1, T2> reg;

public: 
    void work(){
        std::string ans;
        do{
            std::cout << "Enter a command(add/remove/print/find/exit): ";
            std::cin >> ans;

            if(ans == "add"){
                std::cout << "Enter key: ";
                T1 key;
                std::cin >> key;

                if(std::cin.fail()) {
                    std::cin.clear();
                    std::string str;
                    std::getline(std::cin, str);
                    std::cout << "Wrong type. Try again." << std::endl;
                    continue;
                }
  
                std::cout << "Enter value: ";
                T2 value;
                std::cin >> value;

                if(std::cin.fail()) {
                    std::cin.clear();
                    std::string str;
                    std::getline(std::cin, str);
                    std::cout << "Wrong type. Try again." << std::endl;
                    continue;
                }

                reg.add(key, value);

            }else if(ans == "remove"){
                std::cout << "Enter key: ";
                T1 key;
                std::cin >> key;

                if(std::cin.fail()) {
                    std::cin.clear();
                    std::string str;
                    std::getline(std::cin, str);
                    std::cout << "Wrong type. Try again." << std::endl;
                    continue;
                }

                try{
                    if(reg.remove(key)){
                        std::cout << "The data has been deleted" << std::endl;
                    } else {
                        std::cout << "No such data." << std::endl;
                    } 
                } catch(std::invalid_argument& x){
                    std::cout << x.what() << std::endl;
                }
                
            }else if(ans == "print"){
                reg.print();

            } else if(ans == "find"){
                std::cout << "Enter key: ";
                T1 key;
                std::cin >> key;

                if(std::cin.fail()) {
                    std::cin.clear();
                    std::string str;
                    std::getline(std::cin, str);
                    std::cout << "Wrong type. Try again." << std::endl;
                    continue;
                }

                try{
                    if(reg.find(key)){
                        std::cout << "The data is in the registry." << std::endl;
                    } else {
                        std::cout << "No such data." << std::endl;
                    }
                }catch(std::invalid_argument& x){
                    std::cout << x.what() << std::endl;
                }
            }

        }while(ans != "exit");
    }
};



int main(int, char**){
    std::cout << "Hello, from 33_3_storage_of_data_on_templates!\n";
    
    std::cout << "\n********Storage  <int, std::string> example **********\n" << std::endl;
    user_data_entry<int, std::string> example1;
    example1.work();

    std::cout << "\n********Storage  <int, double> example **********\n" << std::endl;
    user_data_entry<int, double> example2;
    example2.work();

    std::cout << "\n********Storage  <std::string, std::string> example **********\n" << std::endl;
    user_data_entry<std::string, std::string> example3;
    example3.work();

return 0;
}
