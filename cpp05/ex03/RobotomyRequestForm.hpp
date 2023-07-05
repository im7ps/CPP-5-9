#ifndef ROBOTOMY_REQUEST_FORM_HPP
# define ROBOTOMY_REQUEST_FORM_HPP

#include "Form.hpp"
#include "Bureaucrat.hpp"

class Bureaucrat;

class RobotomyRequestForm : public AForm
{
    private:
        std::string target;

    public:
        RobotomyRequestForm(std::string const& target);
        RobotomyRequestForm(RobotomyRequestForm const& RobotForm);
        RobotomyRequestForm& operator=(RobotomyRequestForm const& RobotForm);
        ~RobotomyRequestForm();

        void execute(Bureaucrat const& executor);
};

#endif