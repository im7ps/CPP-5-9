#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string const& target) : AForm("Presidential Pardon Form", 25, 5)
{
    this->target = target;
    std::cout << "Presidential Form created\n";
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "Presidential Form deleted\n";
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const& cpy) : AForm(cpy)
{

}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const& src)
{
    if (this == &src)
        return *this;

    this->target = src.target;
    return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const& executor)
{
    // std::cout << executor.getGrade() << " | " << this->getGradeToExc() << std::endl;
    try
    {
        if (this->isSigned() && executor.getGrade() <= this->getGradeToExc())
        {
            std::cout << this->target << " has been pardoned by Zaphod Beeblebrox\n";
        }
        else
        {
            throw GradeTooLowException();
        }
    }
    catch(const GradeTooLowException& e)
    {
        std::cerr << "Presidential Error: " << e.what();
        throw;
    }
}
