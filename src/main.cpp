#include <iostream>
#include <fstream>
#include "../third-party/jsoncpp/json/json.h"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    std::cout << std::to_string(42) << std::endl;

    ifstream ifs("C:\\Users\\Matt\\CLionProjects\\untitled\\input\\alice.json");
    Json::Reader reader;
    Json::Value obj;
    reader.parse(ifs, obj); // reader can also read strings
    cout << "Book: " << obj["book"].asString() << endl;
    cout << "Year: " << obj["year"].asUInt() << endl;
    const Json::Value& characters = obj["characters"]; // array of characters
    for (int i = 0; i < characters.size(); i++){
        cout << "    name: " << characters[i]["name"].asString();
        cout << " chapter: " << characters[i]["chapter"].asUInt();
        cout << endl;
    }

    system("pause");
    return 0;
}