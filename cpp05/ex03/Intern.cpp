#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern()
{
    std::cout << "Intern created\n";
}

Intern::~Intern()
{
    std::cout << "Intern deleted\n";
}

Intern::Intern(Intern const& cpy)
{
    *this = cpy;
}

Intern& Intern::operator=(Intern const& src)
{
    if (this == &src)
        return *this;

    return *this;
}

AForm* Intern::makeForm(std::string const& form_name, std::string const& target_name)
{
    std::string available_forms[3] = {"Presidential pardon", "Robotomy request", "Shrubbery creation"};
    int i = -1;

    while (++i < 3)
    {
        if (form_name.compare(available_forms[i]) == 0)
            break ;
    }

    try
    {
        switch (i + 1)
        {
            case 1:
                return (new PresidentialPardonForm(target_name));
                break;
            case 2:
                return (new RobotomyRequestForm(target_name));
                break;
            case 3:
                return (new ShrubberyCreationForm(target_name));
                break;
            default:
                throw FormNotFoundException();
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what();
        throw;
    }
    
    return nullptr;
}


const char* Intern::FormNotFoundException::what() const throw()
{
    return "Form not found\n";
}