/*
** EPITECH PROJECT, 2026
** OOP
** File description:
** 
*/

#include <criterion/criterion.h>
#include <criterion/internal/assert.h>
#include <criterion/internal/test.h>
#include "parser/Parser.hpp"
#include "Exception/Exceptions.hpp"
#include "Exception/UnknownChipsetType.hpp"

Test(Parser, missing_chipsets_section)
{
    nts::Parser parser("tests/files/missing_chipsets_section.nts");
    cr_assert_throw(parser.start(), nts::error::ChipsetArgumentError);
}

Test(Parser, bad_input)
{
    nts::Parser parser("tests/files/bad_input.nts");
    cr_assert_throw(parser.start(), nts::error::UnknownChipsetType);
}

Test(Parser, wrong_link)
{
    nts::Parser parser("tests/files/wrong_link.nts");
    cr_assert_throw(parser.start(), nts::error::LinkSyntaxError);
}

Test(Parser, FileNotFound)
{
    nts::Parser parser("tests/files/hello.nts");
    cr_assert_throw(parser.start(), nts::error::FileNotFoundException);
}

Test(Parser, ChipsetAlreadyDefined)
{
    nts::Parser parser("tests/files/already_defined.nts");
    cr_assert_throw(parser.start(), nts::error::ChipsetAlreadyDefinedError);
}

Test(Parser, PinNotANumberRight)
{
    nts::Parser parser("tests/files/not_pin_nbrRight.nts");
    cr_assert_throw(parser.start(), nts::error::LinkNoPinNumber);
    
}

Test(Parser, PinNotANumberLeft)
{
    nts::Parser parser("tests/files/not_pin_nbrLeft.nts");
    cr_assert_throw(parser.start(), nts::error::LinkNoPinNumber);
}

Test(Parser, Newlines)
{
    nts::Parser parser("tests/files/Newlines.nts");
    cr_assert_no_throw(parser.start(), std::exception);
}

Test(Parser, ComplexFile)
{
    nts::Parser parser("tests/files/complex.nts");
    cr_assert_no_throw(parser.start(), std::exception);
}
