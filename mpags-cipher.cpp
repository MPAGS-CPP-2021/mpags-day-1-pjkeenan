#include <iostream>
#include <string>
#include <vector>

int main(int argc, char* argv[])
{
    // Command line argument handling
    const std::vector<std::string> cmdLineArgs {argv, argv+argc};
    int i{0};
    std::string infile{""};
    std::string outfile{""};
    for (i=1; i < argc; i++){ //argc is count of num of args (includes the command as first)
        // Better as a switch case as have many options??
        if (cmdLineArgs[i] == "-h" || cmdLineArgs[i] == "--help"){
            std::cout << "\nPrinting help message\nShould be filled with usage and command line options\n" << std::endl;
            return 0;
        }

        else if (cmdLineArgs[i] == "--version" || cmdLineArgs[i] == "-v"){
            std::cout << "v0.1.0" << std::endl;
        }

        else if (cmdLineArgs[i] == "-i"){
            // check for input file? vaild file name/suffix? try opening?
            // check i+1 not out of range to prevent segfault
            // Some kind of wildcard pattern matching to "-*" better?
            if (i+1 == argc || cmdLineArgs[i+1] == "-h" || cmdLineArgs[i+1] == "--help" || cmdLineArgs[i+1] == "--version" || 
            cmdLineArgs[i+1] == "-v" || cmdLineArgs[i+1] == "-o"){
                std::cout << "No input file specified\nsee --help for usage" << std::endl;
                return 0;
            }
            else {
                infile = cmdLineArgs[i+1];
                i++; // increment to skip to next argument
                std::cout << "Input file: " <<std::endl;
                std::cout << infile <<std::endl;
            }
        }

        else if (cmdLineArgs[i] == "-o"){
            if (i+1 == argc || cmdLineArgs[i+1] == "-h" || cmdLineArgs[i+1] == "--help" || cmdLineArgs[i+1] == "--version" || 
            cmdLineArgs[i+1] == "-v" || cmdLineArgs[i+1] == "-i"){
                std::cout << "No output file specified\nsee --help for usage" << std::endl;
                return 0;
            }
            else {
                outfile = cmdLineArgs[i+1];
                i++; // increment to skip to next argument
                std::cout << "Output file: " <<std::endl;
                std::cout << outfile <<std::endl;
            }
        }

        else{
            std::cout << "\nOne or more unrecognised command line option(s) issued\nsee --help for usage" << std::endl;
            return 0;
        }
    } // end command line argument handling

    char in_char{'x'};
    std::string outstr{""};
    while(std::cin >> std::noskipws >> in_char){ // Preserve white space 
        // Loop until the user presses Enter then Ctrl+D
        
        if (std::isalnum(in_char)){// Change number characters to words
            switch (in_char){
                case '0':
                    outstr += "ZERO";
                    break;
                case '1':
                    outstr += "ONE";
                    break;
                case '2':
                    outstr += "TWO";
                    break;
                case '3':
                    outstr += "THREE";
                    break;
                case '4':
                    outstr += "FOUR";
                    break;
                case '5':
                    outstr += "FIVE";
                    break;
                case '6':
                    outstr += "SIX";
                    break;
                case '7':
                    outstr += "SEVEN";
                    break;
                case '8':
                    outstr += "EIGHT";
                    break;
                case '9':
                    outstr += "NINE";
                    break;
                default:
                    break;
            }// end switch case

            if(islower(in_char)){// Change all letters to uppercase
                outstr += toupper(in_char);
            }
            
            else if(isupper(in_char)){// Add already uppercase
                outstr += in_char;
            } 
        }// end if alphanum

        // instructions to "Ignore" punctutation etc ambiguous - I've kept them
        // -> remove else block to get rid of them
        else { // only non alphanum here
            outstr += in_char;
        }
    }// end while over in_chars
    std::cout << outstr << std::endl;
}
