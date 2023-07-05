#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string const& target) : AForm("Robotomy Request Form", 72, 45)
{
    this->target = target;
    std::cout << "Robotomy Form created\n";
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "Robotomy Form deleted\n";
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const& cpy)
{
    *this = cpy;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const& src)
{
    if (this == &src)
        return *this;

    this->target = src.target;
    return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const& executor)
{
    std::cout << "Drilling noises\n";

    try
    {
        if (this->isSigned() && executor.getGrade() <= this->getGradeToExc())
        {
            srand(time(0));
            if (rand() % 2 == 0)
                std::cout << this->target << " has been robotomized successfully\n";
            else
                std::cout << this->target << " robotomy failed\n";
        }
        else
        {
            throw GradeTooLowException();
        }
    }
    catch (const GradeTooLowException& e)
    {
        std::cerr << "Roboproblem " << e.what();
        throw;
    }
}