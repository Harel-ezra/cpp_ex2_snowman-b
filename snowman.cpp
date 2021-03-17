#include <string>
#include "snowman.hpp"
#include <stdexcept>
#include <iostream>

using namespace std;

using namespace ariel;
#define megic_number 10
#define number_len 8

std::string ariel::snowman(int n) // (hnlrxytb)
{
    if (!input_checking(n))
    {
        throw std::invalid_argument("out of range");
    }

    std::string _snowman;

    std::string _base = base(n % megic_number);
    n /= megic_number;

    std::string _torso = torso(n % megic_number);
    n /= megic_number;

    bool up_right_arm = false;
    std::string __right_arm = right_arm(n % megic_number);
    if (n % megic_number == 2)
    {
        up_right_arm = true;
    }
    n /= megic_number;

    bool up_left_arm = false;
    std::string __left_arm = left_arm(n % megic_number);
    if (n % megic_number == 2)
    {
        up_left_arm = true;
    }
    n /= megic_number;

    std::string _right_eye = eye(n % megic_number);
    n /= megic_number;

    std::string _left_eye = eye(n % megic_number);
    n /= megic_number;

    std::string _nose_mouth = nose_mouth(n % megic_number);
    n /= megic_number;

    std::string _hat = hat(n % megic_number);
    if (up_right_arm && up_left_arm)
    {
        _snowman = _hat + "\n" + __left_arm + "(" + _left_eye + _nose_mouth + _right_eye + ")" + __right_arm + "\n(" + _torso + ")\n(" + _base + ")\n";
    }
    else if (up_right_arm && !up_left_arm)
    {
        _snowman = _hat + "\n" + "(" + _left_eye + _nose_mouth + _right_eye + ")" + __right_arm + "\n" + __left_arm + "(" + _torso + ")\n(" + _base + ")\n";
    }
    else if (!up_right_arm && up_left_arm)
    {
        _snowman = _hat + "\n" + __left_arm + "(" + _left_eye + _nose_mouth + _right_eye + ")" + "\n(" + _torso + ")" + __right_arm + "\n(" + _base + ")\n";
    }
    else
    {
        _snowman = _hat + "\n" + "(" + _left_eye + _nose_mouth + _right_eye + ")" + "\n" + __left_arm + "(" + _torso + ")" + __right_arm + "\n(" + _base + ")\n";
    }
    return _snowman;
}

std::string hat(int n)
{
    std::string _hat_sm;
    switch (n)
    {
    case 1:
        _hat_sm = "_===_";
        break;
    case 2:
        _hat_sm = " ___ \n.....";
        break;
    case 3:
        _hat_sm = " _  \n/_\\ ";
        break;
    case 4:
        _hat_sm = " ___ \n(_*_)";
        break;
    default:
        break;
    }
    return _hat_sm;
}
std::string nose_mouth(int n)
{
    std::string _nose_mouth_sm;
    switch (n)
    {
    case 1:
        _nose_mouth_sm = ",";
        break;
    case 2:
        _nose_mouth_sm = ".";
        break;
    case 3:
        _nose_mouth_sm = "_";
        break;
    case 4:
        _nose_mouth_sm = " ";
        break;
    default:
        break;
    }
    return _nose_mouth_sm;
}
std::string eye(int n)
{
    std::string _eye_sm;
    switch (n)
    {
    case 1:
        _eye_sm = ".";
        break;
    case 2:
        _eye_sm = "o";
        break;
    case 3:
        _eye_sm = "O";
        break;
    case 4:
        _eye_sm = "-";
        break;
    default:
        break;
    }
    return _eye_sm;
}

std::string left_arm(int n)
{
    std::string _left_arm_sm;
    switch (n)
    {
    case 1:
        _left_arm_sm = "<";
        break;
    case 2:
        _left_arm_sm = "\\";
        break;
    case 3:
        _left_arm_sm = "/";
        break;
    case 4:
        _left_arm_sm = "";
        break;
    default:
        break;
    }
    return _left_arm_sm;
}
std::string right_arm(int n)
{
    std::string _right_arm_sm;
    switch (n)
    {
    case 1:
        _right_arm_sm = ">";
        break;
    case 2:
        _right_arm_sm = "/";
        break;
    case 3:
        _right_arm_sm = "\\";
        break;
    case 4:
        _right_arm_sm = "";
        break;
    default:
        break;
    }
    return _right_arm_sm;
}
std::string torso(int n)
{
    std::string _torso_sm;
    switch (n)
    {
    case 1:
        _torso_sm = " : ";
        break;
    case 2:
        _torso_sm = "] [";
        break;
    case 3:
        _torso_sm = "> <";
        break;
    case 4:
        _torso_sm = "   ";
        break;
    default:
        break;
    }
    return _torso_sm;
}
std::string base(int n)
{
    std::string _base_sm;
    switch (n)
    {
    case 1:
        _base_sm = " : ";
        break;
    case 2:
        _base_sm = "\" \"";
        break;
    case 3:
        _base_sm = "___";
        break;
    case 4:
        _base_sm = "   ";
        break;
    default:
        break;
    }
    return _base_sm;
}

bool input_checking(int n)
{
    int counter = 0;
    while (number_len > counter)
    {
        if (0 == n)
        {
            return false;
        }
        if ((n % megic_number > 4) || (n % megic_number < 1))
        {
            return false;
        }
        n /= megic_number;
        counter++;
    }
    if (n > 0)
    {
        return false;
    }
    return true;
}

// int main()
// {
//     cout << ariel::snowman(11114412);
//     return 0;
// }