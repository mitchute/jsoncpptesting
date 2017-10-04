#include <iostream>
#include <fstream>
#include "../third-party/jsoncpp/json/json.h"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    std::cout << std::to_string(42) << std::endl;

    // Input file with json data
    ifstream ifs("D:\\EnergyPlus\\Projects\\jsoncpptesting\\input\\alice.json");

    // Read json data from file
    Json::Reader reader;
    Json::Value obj;
    reader.parse(ifs, obj); // reader can also read strings

    // Write to terminal
    cout << "Book: " << obj["book"].asString() << endl;
    cout << "Year: " << obj["year"].asUInt() << endl;
    const Json::Value& characters = obj["characters"]; // array of characters
    for (int i = 0; i < characters.size(); i++){
        cout << "    name: " << characters[i]["name"].asString();
        cout << " chapter: " << characters[i]["chapter"].asUInt();
        cout << endl;
    }

    // Output file to write json data
    std::ofstream ofs;
    ofs.open("out.txt");

    Json::StyledWriter styledWriter;
    ofs << styledWriter.write(obj);

    ofs.close();

    system("pause");
    return 0;
}