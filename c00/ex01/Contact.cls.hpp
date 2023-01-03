#ifndef CONTACT_CLS_HPP
#define CONTACT_CLS_HPP

#include "main.hpp"

class Contact
{
private:
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::string darkest_secret;

public:
    Contact(const std::string &first_name, const std::string &last_name,
            const std::string &nickname, const std::string &phone_number,
            const std::string &darkest_secret)
        : first_name(first_name), last_name(last_name), nickname(nickname),
          phone_number(phone_number),
          darkest_secret(darkest_secret)
    {
    }

    ~Contact()
    {
    }

    std::string get_first_name() const 
    {
    }
    std::string get_last_name() const
    {
    }
    std::string get_nickname() const
    {
    }
    std::string get_phone_number() const
    {
    }
    std::string get_darkest_secret() const
    {
    }
};

#endif
