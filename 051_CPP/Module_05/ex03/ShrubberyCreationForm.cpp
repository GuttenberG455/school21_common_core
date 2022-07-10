
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : Form(target, 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &old) : Form(old), _target(old._target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &old) {
    this->_target = old._target;
    return (*this);
}

void ShrubberyCreationForm::execute(const Bureaucrat &bur) const {
    Form::execute(bur);
    std::string fname = this->_target + "_shrubbery";
    std::ofstream outfile(fname, std::ios::out);

    if (!outfile.is_open() || outfile.bad())
        throw std::exception();
    outfile << "                                                       .\n"
               "                                              .         ;  \n"
               "                 .              .              ;%     ;;   \n"
               "                   ,           ,                :;%  %;   \n"
               "                    :         ;                   :;%;'     .,   \n"
               "           ,.        %;     %;            ;        %;'    ,;\n"
               "             ;       ;%;  %%;        ,     %;    ;%;    ,%'\n"
               "              %;       %;%;      ,  ;       %;  ;%;   ,%;' \n"
               "               ;%;      %;        ;%;        % ;%;  ,%;'\n"
               "                `%;.     ;%;     %;'         `;%%;.%;'\n"
               "                 `:;%.    ;%%. %@;        %; ;@%;%'\n"
               "                    `:%;.  :;bd%;          %;@%;'\n"
               "                      `@%:.  :;%.         ;@@%;'   \n"
               "                        `@%.  `;@%.      ;@@%;         \n"
               "                          `@%%. `@%%    ;@@%;        \n"
               "                            ;@%. :@%%  %@@%;       \n"
               "                              %@bd%%%bd%%:;     \n"
               "                                #@%%%%%:;;\n"
               "                                %@@%%%::;\n"
               "                                %@@@%(o);  . '         \n"
               "                                %@@@o%;:(.,'         \n"
               "                            `.. %@@@o%::;         \n"
               "                               `)@@@o%::;         \n"
               "                                %@@(o)::;        \n"
               "                               .%@@@@%::;         \n"
               "                               ;%@@@@%::;.          \n"
               "                              ;%@@@@%%:;;;. \n"
               "                          ...;%@@@@@%%:;;;;,.." << std::endl;
    outfile.close();
}