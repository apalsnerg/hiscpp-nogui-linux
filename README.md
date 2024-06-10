# hiscpp
Repository for course IT120G for student a24birho.

-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-

->> INTRODUCTION <<-

The aim of this repository is to serve as a way to remotely store the files made during the course IT120G, "Grundläggande programmering med C++" by student Birk Höijer, with the acronym a24birho. Minor versions will be committed as v1.0.4, v.1.1.6, etc., whereas major versions will be committed as v2.0.0, v3.0.0, etc.

-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-

->> HOW TO RUN THE PROGRAMS IN THIS REPOSITORY <<-

Specific instructions will be provided here for Linux Ubuntu/Debian. Thus, they will also work with a default distro installation of Windows Subsystem for Linux (WSL). Steps may vary with other distros. For other Operating Systems, please refer to external manuals for C++/G++ installation and execution instructions.

1. Open your terminal.

2. Ensure the g++ compiler is installed by running the command "g++ --version".
2a. If it is not installed, run the command "sudo apt install g++", or equivalent for your personal distro package manager.

3. Launch your git client.
3a. If you do not have a git client, you must install one. Several options exist, but the one available at https://git-scm.com is recommended if you do not have specific usage needs. Download instructions for your distro are available on the website.

4. Clone the repo to a local folder using the command "git clone https://github.com/apalsnerg/hiscpp.git" in your git client.

5. Using your terminal, navigate to the folder into which you cloned the repo.

>> Steps 6-6b are only necessary if you are trying to run an uncompiled program! <<

6. Run the source file for your desired program using the command "g++ <FILENAME>" to generate a compiled program.
6a. To use a specific name for the compiled (output) program, run "g++ <FILENAME> -o <DESIRED_FILENAME>".
6b. If multiple files are needed for the final compiled file to work, they will be included in the main file.
You must then include these in the compilation command like "g++ file1.cpp file2.cpp file3.cpp". 6a applies here also.

7. Run the compiled program using the command "./<FILENAME>".

You have now successfully run the program. Great job!


-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-


->> DISCLAIMER <<-

All code, programs, and other data in this repository is provided "AS-IS". NO warranties of ANY kind are implied or expressly given under any circumstance. All code in this repository is run at personal risk.
