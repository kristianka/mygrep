// mygrep.cpp : This file contains the 'main' function. Program execution begins and ends there.
// github.com/kristianka

#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <filesystem>

void toLowercase(std::string& text);


int main(int argc, char* argv[])
{
    std::setlocale(LC_ALL, "fi");
    std::string userInput = "";
    std::string userInput2 = "";
    std::string temp = "";
    std::ifstream file;
    std::string oo = "-oo";
    std::string ol = "-ol";
    std::string olo = "-olo";
    std::string oi = "-oi";
    std::string o_r = "-or";
    std::string olori = "-olori";

    int lineCounter = 0;
    int stringMatch = 0;

    // just an integer, when changed to 1 print lines
    int y = 0;

    // --- 1. INCREMENT PART STARTS ---
    if (argc == 1)
    {
        std::cout << "Give a string from which to search for: ";
        std::getline(std::cin, userInput);
        std::cout << "Give a search string: ";
        std::getline(std::cin, userInput2);

        int found = userInput.find(userInput2);
        // if found is not -1, which means it's found
        if (found != std::string::npos) {
            std::cout << "\"" << userInput2 << "\"" << " was found in " << "\"" << userInput << "\"." << std::endl;
        }
        else {
            std::cout << "\"" << userInput2 << "\"" << " was not found in " << "\"" << userInput << "\"." << std::endl;
        }
    }
    // --- 1. INCREMENT PART ENDS ---


    // --- 2. INCREMENT PART STARTS ---
    else if (argc == 3) {

        std::string searchItem = argv[1];
        file.open(argv[2]);

        // if file has opened successfully
        if (file)
        {
            // let's read the file
            while (std::getline(file, temp)) {

                //If the string is found in the other string, find() will
                // return -1. string::npos means -1, which means no matches. 
                // so if temp has searchItem, code will be executed and print temp line
                if (temp.find(searchItem) != std::string::npos) {
                    std::cout << '\t' << temp << '\n';
                }

            }
            file.close();
        }
        else {
            std::cout << "File not found";
        }
    }
    // --- 2. INCREMENT PART ENDS ---


    // --- 3. INCREMENT PART STARTS ---

    else if (argc == 4 && argv[1] != oi && argv[1] != o_r && argv[1] != olori) {

        std::string searchItem = argv[2];
        file.open(argv[3]);

        // if file has opened successfully
        if (file)
        {
            // let's read the file
            while (std::getline(file, temp)) {

                // line counter ++
                lineCounter++;

                //If the string is found in the other string, find() will
                // return -1. string::npos means -1, which means no matches. 
                // so if temp has searchItem, code will be executed and print temp line
                if (temp.find(searchItem) != std::string::npos) {
                    stringMatch++;
                    if (argv[1] == olo) {
                        std::cout << lineCounter << ":" << '\t' << temp << '\n';
                        // let's change y = 1, so occurances will print only once.
                        y = 1;
                    }
                    else if (argv[1] == ol) {
                        std::cout << lineCounter << '\n';
                    }

                }
            }
            if (argv[1] == oo || y == 1) {
                std::cout << "\nOccurences of lines containing \"" << searchItem << "\": " << stringMatch << "\n";
            }
            file.close();
        }
        else {
            std::cout << "File not found";
        }
    }
    // --- 3. INCREMENT PART ENDS ---


    // --- 4. INCREMENT PART STARTS ---
    else if (argc == 4 && !(argv[1] == oo || argv[1] == ol || argv[1] == olo)) {

        std::string searchItem = argv[2];
        file.open(argv[3]);
        std::string str = searchItem;

        if (argv[1] == oi)
        {
            toLowercase(str);
            // if file has opened successfully
            if (file)
            {
                // let's read the file
                while (std::getline(file, temp)) {

                    std::string undercaseTemp = temp;
                    toLowercase(undercaseTemp);

                    //If the string is found in the other string, find() will
                    // return -1. string::npos means -1, which means no matches. 
                    // so if undercaseTemp has searchItem, code will be executed and print temp line
                    if (undercaseTemp.find(str) != std::string::npos) {
                        std::cout << '\t' << temp << '\n';
                    }

                }
                file.close();
            }
            else {
                std::cout << "File not found";
            }
        }

        if (argv[1] == o_r)
        {
            // if file has opened successfully
            if (file)
            {
                // let's read the file
                while (std::getline(file, temp)) {

                    //If the string is found in the other string, find() will
                    // return -1. string::npos means -1, which means no matches. 
                    // so if temp has searchItem, code will be executed and print temp line
                    if (temp.find(searchItem) == std::string::npos) {
                        std::cout << '\t' << temp << '\n';
                    }
                }
                file.close();
            }
            else {
                std::cout << "File not found";
            }
        }

        if (argv[1] == olori)
        {
            try {
                if (file)
                {
                    toLowercase(str);
                    // let's read the file
                    while (std::getline(file, temp)) {
                        std::string undercaseTemp = temp;
                        toLowercase(undercaseTemp);

                        lineCounter++;

                        //If the string is found in the other string, find() will
                        // return -1. string::npos means -1, which means no matches. 
                        // so if undercaseTemp has searchItem, code will be executed and print temp line
                        if (undercaseTemp.find(str) != std::string::npos) {
                            stringMatch++;
                        }

                        // print lines NOT containing string
                        if (undercaseTemp.find(str) == std::string::npos) {
                            std::cout << lineCounter << ":" << '\t' << temp << '\n';
                            // let's change y = 1, so occurances will print only once.
                            y = 1;
                        }
                    }
                    // print this only once
                    if (y == 1) {
                        std::cout << "\nOccurences of lines NOT containing \"" << searchItem << "\": " << lineCounter - stringMatch << "\n";
                    }
                    file.close();
                }

                else {
                    try {
                        // try to see file's size. if file size is 0 program will crash,
                        // but we counter this by using try catch
                        std::uintmax_t size = std::filesystem::file_size(argv[3]);
                    }
                    catch (const std::filesystem::filesystem_error error) {
                        throw 100;
                    }
                }
            }
            catch (int error) {

                if (error == 100)
                {
                    std::cout << "An exception occurred. Exception Nr. -1 \n";
                    std::cout << "Could not find size of file \"" << argv[3] << "\"";
                }
            }
        }
        // if first line of file is same as end of the file
        if (file.peek() == std::ifstream::traits_type::eof()) {
            std::cout << "File is empty";
        }
    }
    // --- 4. INCREMENT PART ENDS ---

    return 0;
}

void toLowercase(std::string& text) {
    // convert string to lowercase
    std::transform(text.begin(), text.end(), text.begin(), ::tolower);
}

