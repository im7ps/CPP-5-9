#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main(void)
{
    try
    {
        Bureaucrat b1 = Bureaucrat("Jonny", 2);

        // PresidentialPardonForm president("Casablanca");
        // ShrubberyCreationForm srub("To the moon");
        // RobotomyRequestForm robot("LeoDiCapri");

        // std::cout << president;
        // std::cout << srub;
        // std::cout << robot;

        // president.beSigned(b1);
        // b1.signForm(president);
        // president.execute(b1);

        // b1.incrementGrade();

        // std::cout << b1.getGrade() << std::endl;

        // b1.incrementGrade();
        // b1.incrementGrade();

        // Bureaucrat c("Tozio", 12);

        // srub.beSigned(b1);
        // c.signForm(srub);
        // srub.execute(c);

        // Bureaucrat a = c;

        // robot.beSigned(a);
        // a.signForm(robot);
        // robot.execute(a);

        Intern Bobby;

        Bobby.makeForm("Saint Honoré", "Marron Glacé");
        Bobby.makeForm("Presidential pardon", "Marronee");
    }
    catch(const std::exception& e)
    {
        std::cout << "Error detetched\n";
    }
    return 0;
}