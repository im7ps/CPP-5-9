#ifndef INTERN_HPP
# define INTERN_HPP

#include "Form.hpp"

class Intern
{
    public:
        Intern();
        Intern(Intern const& cpy);
        Intern& operator=(Intern const& src);
        ~Intern();
        AForm* makeForm(std::string const& form_name, std::string const& form_target);

    class FormNotFoundException : public std::exception
    {
        public:
            const char* what() const throw();
    };
};

#endif