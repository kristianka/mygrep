# mygrep

Mygrep is a course project. The program is a selfmade version of basic grep functionalities on Linux systems.

Detailed report of how everything works and the process of writing this software is explained in mygrep_report.pdf file, but only in Finnish.

## How to use

### On Linux and similiar systems: 
- Firstly download ```mygrep.cpp``` file from this repository.
- Build the file on command line with the command ```g++ -o mygrep mygrep.cpp```.
- Run it with arguments like ```./mygrep -ol following man_grep_plain_ASCII.txt``` where ```-ol``` is options and line. This command will print line numbers where ```following``` search term was found. The last argument is file which to search.

### On Windows systems
- Firstly download ```mygrep.cpp``` file from this repository.
- Build the file in ```Microsoft Developer Command Prompt for VS 2022``` command line with the command ```cl mygrep.cpp```.
- Run it with arguments like ```.\mygrep -ol following man_grep_plain_ASCII.txt``` where ```-ol``` is options and line. This command will print line numbers where ```following``` search term was found. The last argument is file which to search.
