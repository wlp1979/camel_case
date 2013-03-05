CamelCase
=========

PHP CamelCase extension

by Lee Parker

Introduction
------------

This is a PHP extension that provides a simple function to convert strings into CamelCase.


Installation
------------
Build
    phpize
    ./configure --enable-camel-case
    make

Test
    make test
    php -d extension="./modules/camel_case.so" compare.php

Usage
-----

string camel_case(string $string, string $separator = '_', boolean $lowerCaseFirst = false);

Parameters:
*  $string - The input string
*  $separator - The separator to identify the word breaks. Defaults to '_'.
*  $lowerCaseFirst - Determines if the first character should be lower case instead of upper case. Defaults to false.

Returns the newly formatted string or `NULL`.

Examples
--------

    echo camel_case("camel_case_me");
    CamelCaseMe
    
    echo camel_case("camel-case-me", '-');
    CamelCaseMe
    
    echo camel_case("camel_case_me", '_', true);
    camelCaseMe
