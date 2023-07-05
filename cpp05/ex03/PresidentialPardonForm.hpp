#ifndef PRESIDENTIAL_PARDON_FORM_HPP
# define PRESIDENTIAL_PARDON_FORM_HPP

#include "Form.hpp"
#include "Bureaucrat.hpp"

class Bureaucrat;

class PresidentialPardonForm : public AForm
{
    private:
        std::string target;
    public:
        PresidentialPardonForm(std::string const& target);
        PresidentialPardonForm(PresidentialPardonForm const& PresForm);
        PresidentialPardonForm& operator=(PresidentialPardonForm const& PresForm);
        ~PresidentialPardonForm();

        void execute(Bureaucrat const& executor);
};

#endif