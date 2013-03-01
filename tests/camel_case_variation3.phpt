--TEST--
camel_case() function - variation 3 test for camel_case()
--FILE--
<?php
$input = "camel_case_me";
var_dump(camel_case($input));
$input = "camel-case-me";
var_dump(camel_case($input, "-"));
?>
--EXPECT--
string(11) "CamelCaseMe"
string(11) "CamelCaseMe"
